#include "download_dialog.h"
#include "ui_download_dialog.h"
#include "QByteArray"
#include "QDebug"


download_dialog::download_dialog(QWidget *parent)
{
    ui->setupUi(this);
//    serialPort = serial;
//    ui->progressBar_used->setValue(usedspace);
}

download_dialog::~download_dialog()
{
    delete ui;
}

void download_dialog::on_pushButton_clicked()
{
    QString filename = ui->lineEdit->text();
    QByteArray ba;
    ba.append(locus_downloaddata);
    writeSerial(ba);
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(appendData()));

}
void download_dialog::writeSerial(QByteArray a)
{
    a.append("\r\n");
    serialPort->write(a);
}

void download_dialog::saveData()
{


}
void download_dialog::appendData()
{
    QString temp = serialPort->readAll();
    dataBuff.append(temp);

    QStringList list = temp.split(",");
    if(toCharP(QString(list.at(0))),"")
    {

    }

}

void download_dialog::on_pushButton_2_clicked()
{
    qDebug() << dataBuff.data();
}
