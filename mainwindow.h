/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>

#include <QMainWindow>

#include <QtSerialPort/QSerialPort>

QT_BEGIN_NAMESPACE

class QLabel;

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class Console;
class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    bool update_locus=false;
    bool downloading = false;
    QString filename = "RawData.txt";
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString locus_start = "$PMTK185,0*22";
    QString locus_stop = "$PMTK185,1*23";
    QString locus_querystatus = "$PMTK183*38";
    QString locus_downloaddata = "$PMTK622,1*29";
    QString locus_flasherase = "$PMTK184,1*22";
    QString locus_alwayslocateON = "$PMTK255,8*23";
    QString locus_alwayslocateOFF = "$PMTK255,0*2B";
    QString locus_powersaveset = "$PMTK161,0*28";
    QString locus_easyON = "$PMTK869,1,1*35";
    QString locus_easyOFF = "$PMTK869,1,1*34";
    QString locus_easyQUERY = "$PMTK869,0*29";
    QString coldstart = "$PMTK102*31";
    QString warmstart = "$PMTK103*30";
    QString hotstart = "$PMTK101*32";
    QString factoryrestart = "$PMTK102*31";
    bool parse_data = false;
    // different commands to set the update rate from once a second (1 Hz) to 10 times a second (10Hz)
    // Note that these only control the rate at which the position is echoed, to actually speed up the
    // position fix you must also send one of the position fix rate commands below too.
#define PMTK_SET_NMEA_UPDATE_100_MILLIHERTZ  "$PMTK220,10000*2F" // Once every 10 seconds, 100 millihertz.
#define PMTK_SET_NMEA_UPDATE_200_MILLIHERTZ  "$PMTK220,5000*1B"  // Once every 5 seconds, 200 millihertz.
#define PMTK_SET_NMEA_UPDATE_1HZ  "$PMTK220,1000*1F"
#define PMTK_SET_NMEA_UPDATE_5HZ  "$PMTK220,200*2C"

#define PMTK_SET_NMEA_UPDATE_10HZ "$PMTK220,100*2F"
    // Position fix update rate commands.
#define PMTK_API_SET_FIX_CTL_100_MILLIHERTZ  "$PMTK300,10000,0,0,0,0*2C" // Once every 10 seconds, 100 millihertz.
#define PMTK_API_SET_FIX_CTL_200_MILLIHERTZ  "$PMTK300,5000,0,0,0,0*18"  // Once every 5 seconds, 200 millihertz.
#define PMTK_API_SET_FIX_CTL_1HZ  "$PMTK300,1000,0,0,0,0*1C"
#define PMTK_API_SET_FIX_CTL_5HZ  "$PMTK300,200,0,0,0,0*2F"
    // Can't fix position faster than 5 times a second!

#define PMTK_SET_BAUD_57600 "$PMTK251,57600*2C"
#define PMTK_SET_BAUD_9600 "$PMTK251,9600*17"
#define PMTK_SET_BAUD_115200 "$PMTK251,115200*1F"
#define PMTK_SET_BAUD_38400 "$PMTK251,38400*27"




    // turn on only the second sentence (GPRMC)
#define PMTK_SET_NMEA_OUTPUT_RMCONLY "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29"
    // turn on GPRMC and GGA
#define PMTK_SET_NMEA_OUTPUT_RMCGGA "$PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28"
    // turn on ALL THE DATA
#define PMTK_SET_NMEA_OUTPUT_ALLDATA "$PMTK314,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0*28"
    // turn off output
#define PMTK_SET_NMEA_OUTPUT_OFF "$PMTK314,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28"

    // to generate your own sentences, check out the MTK command datasheet and use a checksum calculator
    // such as the awesome http://www.hhhh.org/wiml/proj/nmeaxor.html

#define PMTK_LOCUS_STARTLOG  "$PMTK185,0*22"
#define PMTK_LOCUS_STOPLOG "$PMTK185,1*23"
#define PMTK_LOCUS_STARTSTOPACK "$PMTK001,185,3*3C"
#define PMTK_LOCUS_QUERY_STATUS "$PMTK183*38"
#define PMTK_LOCUS_ERASE_FLASH "$PMTK184,1*22"
#define LOCUS_OVERLAP 0
#define LOCUS_FULLSTOP 1

#define PMTK_ENABLE_SBAS "$PMTK313,1*2E"
#define PMTK_ENABLE_WAAS "$PMTK301,2*2E"

    // standby command & boot successful message
#define PMTK_STANDBY "$PMTK161,0*28"
#define PMTK_STANDBY_SUCCESS "$PMTK001,161,3*36"  // Not needed currently
#define PMTK_AWAKE "$PMTK010,002*2D"

    // ask for the release and version
#define PMTK_Q_RELEASE "$PMTK605*31"

    // request for updates on antenna status
#define PGCMD_ANTENNA "$PGCMD,33,1*6C"
#define PGCMD_NOANTENNA "$PGCMD,33,0*6D"

    // how long to wait when we're looking for a response
#define MAXWAITSENTENCE 5
    
    

    float getDownloadProgress();
public slots:
    void LOCUSeraseFlash();
    void LOCUSqueryStatus();
    void updateSettings();
    void handleData();
    void queryFirmware();
    void writeSerial(QByteArray a);
    void writeSerialQuick(QString a);
    void saveData();
    //    void appendData();
    void updateTableValues();

    void downloadComplete();
    void showStatusMessage(const QString &message);
private slots:
    void openSerialPort();
    void openSerialPorts(QString portname, int baud);
    void closeSerialPort();
    void writeData(const QByteArray &data);
    void readData();
    
    void handleError(QSerialPort::SerialPortError error);
    
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    
    
    void on_pushButton_clicked();
    
    void on_pushButton_2_clicked();
    
    void on_pushButton_6_clicked();
    
    void on_pushButton_5_clicked();
    
    void on_pushButton_12_clicked();
    
    void on_pushButton_15_clicked();
    
    void on_pushButton_16_clicked();
    
    void on_pushButton_14_clicked();
    
    void on_pushButton_13_clicked();
    
    void on_pushButton_17_clicked();
    
    void on_pushButton_18_clicked();
    
    void on_pushButton_7_clicked();
    
    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();



    void on_pushButton_10_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_9_clicked();


    void on_comboBox_2_currentIndexChanged(int index);

    
    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_20_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_clear_clicked();
    
private:

    
    Ui::MainWindow *ui;
    QLabel *status;
    Console *console;
    SettingsDialog *settings;
    QSerialPort *serial;
};

#endif // MAINWINDOW_H
