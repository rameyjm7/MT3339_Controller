#include "dialog.h"
#include "ui_dialog.h"
#include "QSerialPort"
#include "QSerialPortInfo"
#include "QLabel"
#include "QDebug"
#include "QPushButton"
#include "QMessageBox"
QString port;
int baud;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QString s = QObject::tr("Port: ") + info.portName() + "\n"
                + QObject::tr("Location: ") + info.systemLocation() + "\n"
                + QObject::tr("Description: ") + info.description() + "\n"
                + QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
                + QObject::tr("Serial number: ") + info.serialNumber() + "\n"
                + QObject::tr("Vendor Identifier: ") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
                + QObject::tr("Product Identifier: ") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n"
                + QObject::tr("Busy: ") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";



        ui->label_2->setText(s);
    }

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    port = ui->lineEdit->text();
    emit addDevice(port);
}

void Dialog::on_pushButton_2_clicked()
{
    int baud = ui->lineEdit_2->text().toInt();
    emit addBaud(baud);
}

void Dialog::on_pushButton_3_clicked()
{
    close();
}
