#include "QProcess"
#include "QDebug"
#include "QByteArray"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "QTimer"
#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>
#include "QDebug"
#include "QInputDialog"
#include "QDir"
#include "nmea_parser.h"
#include "unistd.h"
#include "QSerialPortInfo"
QProcess * proc_stty;
#include "dialog.h"
nmea_parser * parser;
float ratio_percent = 85/6;
#include "ft_serial1.h"
ft_serial1* ft4232;
#include "processwrapper.h"

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
    console = new Console(ui->edit_nmea);
    console->setEnabled(false);
    console->setMinimumSize(850,350);
    console->setReadOnly(false);

    edit = ui->edit_parsed;
    parser = new nmea_parser();
    parsed_log = ui->edit_parsed;
    connect(parser,SIGNAL(pipeParsedData(QString)),this,SLOT(appendParsedLog(QString)));
    QTimer::singleShot(100,edit,SLOT(clear()));
    parser = new nmea_parser();

    pullSettings();

    ft4232 = new ft_serial1();


}
//! [3]


void MainWindow::beginSerialRead()
{
    serial_reading = true;
    readSerial();
}
void MainWindow::stopSerialRead()
{
    serial_reading = false;
}
void MainWindow::readSerial()
{

#define size 256*10
#define loop 25

    char str[size*loop];
    for(int i =0; i<loop; i++)
    {
        ft4232->ReadLine(str,20,size);
        if(strcmp(str,""))  console->putData(QByteArray(str).append("\n"));
        parser->parseData(str);
    }
    ft4232->Flush();
    if(!downloading) updateTableValues();
    if(serial_reading) QTimer::singleShot(5,this,SLOT(readSerial()));
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
    ui->progressBar_download->setValue(100*parser->locus.current_read/parser->locus.number_of_reads);
    if(parser->locus.current_read==parser->locus.number_of_reads)
    {
        parser->locus.current_read = 0;
        downloading = false;
    }
    datafile_name = ui->lineEdit_filename->text();
    QString fix;
    if(parser->dat.fix_quality == 0 ) fix = "No Fix";
    else if(parser->dat.fix_quality == 1 ) fix = "No Fix";
    else if(parser->dat.fix_quality == 2 ) fix = "2D Fix";
    else if(parser->dat.fix_quality == 3 ) fix = "3D Fix";
    ui->label_fix->setText(fix);
    ui->label_hdop->setText(QString::number(parser->dat.hdop));
    ui->label_vdop->setText(QString::number(parser->dat.vdop));
    ui->label_pdop->setText(QString::number(parser->dat.pdop));
}

void MainWindow::pushSettings()
{
    // open file, write settings to file
    QFile file( settingsfile_name );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream <<  QString("valid_baudrates,4800,9600,19200,38400,57600,115200").append("#");; // desc, number of entries, entries
        stream <<  QString("portname,").append(portname).append("#");
        stream <<  QString("baudrate,").append(QString::number(baudrate)).append("#");
    }
    file.close();
    qDebug() << "Wrote portname " << portname << " and baudrate " << QString::number(baudrate)
             << "to " << settingsfile_name;
}

void MainWindow::pullSettings()
{
    //
    QFile inputFile(settingsfile_name);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        QByteArray ba;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            ba.append(line);
        }
        inputFile.close();


        QString data = ba.data();
        QStringList lines = data.split("#");
        //            qDebug() << "Number of settings : " << lines.count();
        qDebug() << QString(QString(lines.at(0)).split(",").at(0))
                 << "," << QString::number(QString(QString(lines.at(1)).split(",").at(1)).toInt());

        //        QStringList baudlist = QString(lines.at(0)).split(",");
        //        baudlist.pop_front(); // remove setting name
        //        ui->comboBox_baudrate->addItems(baudlist);







        qDebug() << QString(QString(lines.at(1)).split(",").at(0))
                 << "," << QString(QString(lines.at(0)).split(",").at(1));
        portname =  QString(QString(lines.at(1)).split(",").at(1));


        qDebug() << QString(QString(lines.at(2)).split(",").at(0))
                 << "," << QString::number(QString(QString(lines.at(1)).split(",").at(1)).toInt());
        baudrate = QString(QString(lines.at(2)).split(",").at(1)).toInt();


        int index=0;
        if(!strcmp(toCharP(QString::number(baudrate)),"4800")) index = 0;
        else if(!strcmp(toCharP(QString::number(baudrate)),"9600")) index = 1;
        else if(!strcmp(toCharP(QString::number(baudrate)),"19200")) index = 2;
        else if(!strcmp(toCharP(QString::number(baudrate)),"38400")) index = 3;
        else if(!strcmp(toCharP(QString::number(baudrate)),"57600")) index = 4;
        else if(!strcmp(toCharP(QString::number(baudrate)),"115200")) index = 5;
        ui->comboBox_baudrate->setCurrentIndex(index);
    }
}

void MainWindow::addName(QString name)
{
    ui->comboBox_interface->addItem(name);
}

void MainWindow::addBaud(int val)
{
    ui->comboBox_baudrate->addItem(QString::number(val));
}

void MainWindow::on_pushButton_17_clicked()
{
    //    Dialog * d = new Dialog();
    //    d->exec();
    //    connect(d,SIGNAL(addDevice(QString)),this,SLOT(addName(QString)));
    //    connect(d,SIGNAL(addBaud(int)),this,SLOT(addBaud(int)));
    Dialog *d = new Dialog(0);
    d->show();
    connect(d,SIGNAL(addDevice(QString)),this,SLOT(addName(QString)));
    connect(d,SIGNAL(addBaud(int)),this,SLOT(addBaud(int)));
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!strcmp(toCharP(ui->comboBox_interface->currentText()),"Interface A"))   ft4232->Setup(0,0,0x6010);
    else if(!strcmp(toCharP(ui->comboBox_interface->currentText()),"Interface B"))   ft4232->Setup(0,1,0x6010);


    ft4232->SetBaudRate(ui->comboBox_baudrate->currentText().toInt());
    if (!ft4232->IsPresent())
        qDebug ("# Unable to initialize serial port ");
    beginSerialRead();

    writeSerial(PMTK_SET_NMEA_OUTPUT_ALLDATA);
    usleep(10000);
    writeSerial(PMTK_LOCUS_QUERY_STATUS);
    usleep(10000);
    writeSerial(PMTK_Q_RELEASE);
    usleep(10000);

}

bool MainWindow::openHandle(int port, int baudrate)
{

    if(ft4232->isOpen)
    {
        qDebug() << "Device is already open.";
    }
    else
    {
        ft4232->bDEBUGMODE=true;
        ft4232->Setup(port,0x6010,baudrate);
        pushSettings();
        beginSerialRead();
    }

}


void MainWindow::on_pushButton_close_clicked()
{


    ft4232->Close();
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->edit_parsed->clear();
    edit->clear();
}

void MainWindow::on_pushButton_25_clicked()
{
    writeSerial(PMTK_Q_RELEASE);
}
processWrapper * proc;
void MainWindow::on_pushButton_27_clicked()
{
    writeSerial(warmstart);
}
void MainWindow::recieveData()
{

}

void MainWindow::on_pushButton_28_clicked()
{
    writeSerial(factoryrestart);
}

void MainWindow::on_pushButton_24_clicked()
{
    if(!strcmp(toCharP(ui->comboBox_baudrate_change_2->currentText()),"4800"))
    {
        writeSerial(PMTK_SET_BAUD_4800);
    }
    if(!strcmp(toCharP(ui->comboBox_baudrate_change_2->currentText()),"9600"))
    {
        writeSerial(PMTK_SET_BAUD_9600);
    }
    if(!strcmp(toCharP(ui->comboBox_baudrate_change_2->currentText()),"14400"))
    {
        writeSerial(PMTK_SET_BAUD_14400);
    }
    if(!strcmp(toCharP(ui->comboBox_baudrate_change_2->currentText()),"19200"))
    {
        writeSerial(PMTK_SET_BAUD_19200);
    }
    if(!strcmp(toCharP(ui->comboBox_baudrate_change_2->currentText()),"38400"))
    {
        writeSerial(PMTK_SET_BAUD_38400);
    }
    if(!strcmp(toCharP(ui->comboBox_baudrate_change_2->currentText()),"57600"))
    {
        writeSerial(PMTK_SET_BAUD_57600);
    }
    if(!strcmp(toCharP(ui->comboBox_baudrate_change_2->currentText()),"115200"))
    {
        writeSerial(PMTK_SET_BAUD_115200);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    downloading = true;
    QProcess::execute(QString("rm ").append(ui->lineEdit_filename->text()));
    writeSerial(PMTK_SET_NMEA_OUTPUT_OFF);
    usleep(100*1000); // 50ms
    QString filename = ui->lineEdit_filename->text();
    parser->locus.filename=filename;
    QByteArray ba;
    ba.append(locus_downloaddata);
    writeSerial(ba);

}

void MainWindow::on_pushButton_12_clicked()
{
    beginSerialRead();
}


void MainWindow::on_pushButton_9_clicked()
{
    ft4232->SetBaudRate(ui->comboBox_baudrate_change_2->currentText().toInt());
}

void MainWindow::on_pushButton_20_clicked()
{
    ft4232->findDevices();
}

void MainWindow::on_pushButton_3_clicked()
{
    ft4232->readEEPROM();
}

void MainWindow::on_pushButton_5_clicked()
{
    stopSerialRead();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    serial_update_rate = arg1;
}

void MainWindow::on_spinBox_readlines_valueChanged(int arg1)
{
    serial_readlines = arg1;
}

void MainWindow::on_pushButton_8_clicked()
{
    //    ft4232->WriteLine(PMTK_SET_NMEA_OUTPUT_RMCONLY);
    //    console->putData(PMTK_SET_NMEA_OUTPUT_RMCONLY);
    writeSerial(PMTK_SET_NMEA_OUTPUT_RMCONLY);
}

void MainWindow::on_pushButton_10_clicked()
{
    //    ft4232->WriteLine(PMTK_SET_NMEA_OUTPUT_ALLDATA);
    //    console->putData(PMTK_SET_NMEA_OUTPUT_ALLDATA);
    writeSerial(PMTK_SET_NMEA_OUTPUT_ALLDATA);
}

void MainWindow::on_pushButton_clicked()
{
    //    ft4232->WriteLine(PMTK_SET_NMEA_OUTPUT_OFF);
    //    console->putData(PMTK_SET_NMEA_OUTPUT_OFF);
    writeSerial(PMTK_SET_NMEA_OUTPUT_OFF);
}

void MainWindow::on_pushButton_11_clicked()
{
    writeSerial(PMTK_SET_NMEA_OUTPUT_RMCGGA);
    //    ft4232->WriteLine(PMTK_SET_NMEA_OUTPUT_RMCGGA);
    //    console->putData(PMTK_SET_NMEA_OUTPUT_RMCGGA);
}

void MainWindow::on_comboBox_setNMEA_Rate_currentIndexChanged(int index)
{
    if(index == 0 )  writeSerial(PMTK_SET_NMEA_UPDATE_100_MILLIHERTZ);
    else if(index == 1 )  writeSerial(PMTK_SET_NMEA_UPDATE_200_MILLIHERTZ);
    else if(index == 2 )  writeSerial(PMTK_SET_NMEA_UPDATE_1HZ);
    else if(index == 3 )  writeSerial(PMTK_SET_NMEA_UPDATE_10HZ);
}
void MainWindow::writeSerial(QString msg)
{
    ft4232->WriteLine(toCharP(msg));
    console->putData(toCharP(msg));
}
//void MainWindow::writeSerial(QByteArray ba)
//{
//    ft4232->WriteLine(ba.data());
//    console->putData(ba);
//}

void MainWindow::on_pushButton_26_clicked()
{
    writeSerial(coldstart);
}

void MainWindow::on_pushButton_29_clicked()
{
    writeSerial(hotstart);
}

void MainWindow::on_pushButton_16_clicked()
{
    writeSerial(locus_stop);
}

void MainWindow::on_pushButton_19_clicked()
{
    writeSerial(locus_start);
}

void MainWindow::on_pushButton_14_clicked()
{
    writeSerial(locus_querystatus);
}

void MainWindow::on_pushButton_15_clicked()
{
    writeSerial(locus_flasherase);
}

void MainWindow::on_comboBox_loggingrate_currentIndexChanged(int index)
{
    if(index == 0 )  writeSerial(PMTK_API_SET_FIX_CTL_100_MILLIHERTZ);
    else if(index == 1 )  writeSerial(PMTK_API_SET_FIX_CTL_200_MILLIHERTZ);
    else if(index == 2 )  writeSerial(PMTK_API_SET_FIX_CTL_1HZ);
    else if(index == 3 )  writeSerial(PMTK_API_SET_FIX_CTL_5HZ);
}

void MainWindow::on_pushButton_18_clicked()
{
    proc = new processWrapper("sh parse_data.kml");
    proc->startProcess();
    qDebug() << "File parsed and output as output.kml."; // ;
}
