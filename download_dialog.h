#ifndef DOWNLOAD_DIALOG_H
#define DOWNLOAD_DIALOG_H

#include <QDialog>
#include "QSerialPort"
#include "nmea_parser.h"
namespace Ui {
class download_dialog;
}

class download_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit download_dialog(QWidget *parent = 0);
    ~download_dialog();
    int nlogs;
    QSerialPort * serialPort;
    QString locus_querystatus = "$PMTK183*38";
    QString locus_downloaddata = "$PMTK622,1*29";
    QByteArray dataBuff;
    nmea_parser * parse;
    char * toCharP(QString in)
    {
        QByteArray a;
        a.append(in);
        return a.data();
    }
public slots:
    void writeSerial(QByteArray a);
    void saveData();
    void appendData();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::download_dialog *ui;
};

#endif // DOWNLOAD_DIALOG_H
