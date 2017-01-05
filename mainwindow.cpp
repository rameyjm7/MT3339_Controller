#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"
#include "QTimer"
#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>
#include "QDebug"
#include "QInputDialog"
#include "QDir"
#include "nmea_parser.h"
#include "unistd.h"
nmea_parser * parser;
float ratio_percent = 85/6;



char* toCharP(QString in)
{
    QByteArray a;
    a.append(in);
    return a.data();
}


//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    console = new Console(ui->widget);
    console->setEnabled(false);
    console->setMinimumSize(850,300);

    serial = new QSerialPort(this);

    settings = new SettingsDialog;
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    status = new QLabel;
    ui->statusBar->addWidget(status);
    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &MainWindow::handleError);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    connect(console, &Console::getData, this, &MainWindow::writeData);
    parser = new nmea_parser();
    connect(parser,SIGNAL(downloadFinished()),this,SLOT(downloadComplete()));

    filename = ui->lineEdit_filename->text();
}
//! [3]

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}

//! [4]
void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    serial->setReadBufferSize(1024*64);


    if (serial->open(QIODevice::ReadWrite)) {
        console->setEnabled(true);
        console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }


}
void MainWindow::openSerialPorts(QString portname, int baud )
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(portname);
    serial->setBaudRate(baud);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    serial->setReadBufferSize(1024);

    if (serial->open(QIODevice::ReadWrite)) {
        console->setEnabled(true);
        console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2")
                          .arg(ui->comboBox_devicename->currentText()).arg(ui->comboBox_baudrate->currentText()));
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }
    usleep(1000*50);    writeSerialQuick(locus_querystatus);
    usleep(1000*50);    writeSerialQuick(PMTK_Q_RELEASE);
    usleep(1000*50);    writeSerialQuick(PMTK_SET_NMEA_OUTPUT_RMCONLY);
}

void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
    console->setEnabled(false);
    showStatusMessage(tr("Disconnected"));
}


void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);

}

QByteArray dataBuff;
bool firmware_read = false;
void MainWindow::handleData()
{

    parser->parseData(dataBuff);
    updateTableValues();
    dataBuff.clear();


}

void MainWindow::updateTableValues()
{
    ui->label_date->setText(parser->date_formatted);
    ui->label_value_time->setText(parser->time_formatted);
    ui->label_lat->setText(QString::number(parser->dat.latitude));
    ui->label_long->setText(QString::number(parser->dat.longitude));
    ui->label_locus_logging->setText(parser->locus.status == 0 ? "Enabled" : "Disabled");
    ui->label_mode->setText((parser->locus.mode == 0 ? "Overlap" : "Full stop"));
    ui->label_interval->setText(QString(" (s)").prepend(QString::number(parser->locus.interval)));
    ui->label_firmware->setText(parser->firmware_version);
    ui->label_model->setText(QString::number(parser->model_number));
    ui->label_percent->setText(QString::number(parser->locus.percent));
    ui->progressBar_used->setValue(parser->locus.percent);
    ui->label_logs->setText(QString::number(parser->locus.number));
    ui->progressBar->setValue(getDownloadProgress());
    if(parser->locus.current_read==parser->locus.number_of_reads)
    {
        //        QMessageBox msgBox;
        //        msgBox.setText(QString("Download complete! \n File saved as ").append(parser->locus.filename) );
        //        msgBox.exec();
        //        parser->locus.current_read=0;
    }
    filename = ui->lineEdit_filename->text();
}

void MainWindow::readData()
{
    dataBuff.append(serial->readLine());
    console->putData(dataBuff );
    if(downloading)
    {
        QString filename="Data.txt";
        QFile file( filename );
        if ( file.open(QIODevice::Append) )
        {
            QTextStream stream( &file );
            stream << dataBuff << endl;
        }
        file.close();
    }
    QTimer::singleShot(50,this,SLOT(handleData()));
}
//! [7]
void MainWindow::updateSettings()
{
    writeSerial(PMTK_Q_RELEASE);

    writeSerial(PMTK_LOCUS_QUERY_STATUS);
}


void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}


void MainWindow::on_pushButton_4_clicked()
{
    serial->flush();
    //    serial->
    writeSerial(PMTK_SET_NMEA_OUTPUT_OFF);
    usleep(100*1000); // 50ms
    QString filename = ui->lineEdit_filename->text();
    parser->locus.filename=filename;
    QByteArray ba;
    ba.append(locus_downloaddata);
    writeSerial(ba);
}



void MainWindow::on_pushButton_2_clicked()
{
    openSerialPorts(ui->comboBox_devicename->currentText(),ui->comboBox_baudrate->currentText().toInt());
}

void MainWindow::on_pushButton_6_clicked()
{
    QByteArray ba;
    ba.append(hotstart);
    writeSerial(ba);
}

void MainWindow::on_pushButton_5_clicked()
{

    QByteArray ba;
    ba.append(warmstart);
    writeSerial(ba);
}
void MainWindow::on_pushButton_3_clicked()
{
    QString a;
    QByteArray ba;
    a.append("");
    ba.append(a);
    writeSerial(ba);

}

void MainWindow::on_pushButton_12_clicked()
{

    writeSerial(PMTK_SET_BAUD_115200);
}

void MainWindow::on_pushButton_15_clicked()
{
    QByteArray ba;
    ba.append(locus_start);
    writeSerial(ba);
    LOCUSqueryStatus();
}

void MainWindow::on_pushButton_16_clicked()
{
    QByteArray ba;
    ba.append(PMTK_LOCUS_STOPLOG);
    writeSerial(ba);
    LOCUSqueryStatus();
}

void MainWindow::on_pushButton_14_clicked()
{
    QByteArray ba;
    ba.append(locus_querystatus.toLocal8Bit());
    writeSerial(ba);
}

void MainWindow::on_pushButton_13_clicked()
{

    QStringList items;
    items << tr("Erase") << tr("Cancel");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("Are you sure?"),
                                         tr("Option:"), items, 0, false, &ok);
    if (ok && !item.isEmpty())
    {
        if(!strcmp(toCharP(item),"Erase"))
        {

            LOCUSeraseFlash();
        }
        else if(!strcmp(toCharP(item),"Cancel"))
        {
            qDebug() << "Cancelled";
        }

    }


}
void MainWindow::LOCUSeraseFlash()
{
    QByteArray ba;
    ba.append(locus_flasherase);
    writeSerial(ba);
    LOCUSqueryStatus();
}
void MainWindow::LOCUSqueryStatus()
{
    QByteArray ba;
    ba.append(locus_querystatus);
    writeSerial(ba);
    //    QTimer::singleShot(10*1000,this,SLOT(LOCUSqueryStatus()));
}



void MainWindow::writeSerial(QByteArray a)
{
    a.append("\r\n");
    serial->write(a);
}
void MainWindow::writeSerialQuick(QString a)
{
    QByteArray ba; ba.append(a);
    ba.append("\r\n");
    serial->write(ba);
}

#include "download_dialog.h"
download_dialog* downloader;
void MainWindow::on_pushButton_17_clicked()
{


}

void MainWindow::on_pushButton_18_clicked()
{

}

void MainWindow::on_pushButton_7_clicked()
{

}

void MainWindow::on_pushButton_8_clicked()
{
    writeSerial(PMTK_SET_NMEA_OUTPUT_RMCONLY);
}
void MainWindow::on_pushButton_clicked()
{
    writeSerial(PMTK_SET_NMEA_OUTPUT_OFF);

}

void MainWindow::on_pushButton_11_clicked()
{
    writeSerial(PMTK_SET_NMEA_OUTPUT_RMCGGA);
}



void MainWindow::on_pushButton_10_clicked()
{
    writeSerial(PMTK_SET_NMEA_OUTPUT_ALLDATA);
}

void MainWindow::on_pushButton_19_clicked()
{
    writeSerial(PMTK_SET_BAUD_9600);

}

void MainWindow::on_pushButton_9_clicked()
{
    writeSerial(PMTK_SET_BAUD_57600);
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    if(index == 0 )  writeSerial(PMTK_API_SET_FIX_CTL_100_MILLIHERTZ);
    else if(index == 1 )  writeSerial(PMTK_API_SET_FIX_CTL_200_MILLIHERTZ);
    else if(index == 2 )  writeSerial(PMTK_API_SET_FIX_CTL_1HZ);
    else if(index == 3 )  writeSerial(PMTK_API_SET_FIX_CTL_5HZ);
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    if(index == 0 )  writeSerial(PMTK_SET_NMEA_UPDATE_100_MILLIHERTZ);
    else if(index == 1 )  writeSerial(PMTK_SET_NMEA_UPDATE_200_MILLIHERTZ);
    else if(index == 2 )  writeSerial(PMTK_SET_NMEA_UPDATE_1HZ);
    else if(index == 3 )  writeSerial(PMTK_SET_NMEA_UPDATE_10HZ);
}

void MainWindow::on_pushButton_20_clicked()
{
    writeSerial(PMTK_Q_RELEASE);
}
void MainWindow::queryFirmware()
{
    writeSerial(PMTK_Q_RELEASE);
}

void MainWindow::saveData()
{


}

void MainWindow::downloadComplete()
{
    writeSerial(PMTK_SET_NMEA_OUTPUT_RMCONLY);
}

void MainWindow::on_pushButton_close_clicked()
{
    closeSerialPort();
}

void MainWindow::on_pushButton_clear_clicked()
{
    console->clear();
}
float MainWindow::getDownloadProgress()
{
    return 100*((parser->locus.current_read)/(parser->locus.percent*ratio_percent));
}
