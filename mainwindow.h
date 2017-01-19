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
#include "nmea_parser.h"
#include <QtCore/QtGlobal>
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include "QDebug"
QT_BEGIN_NAMESPACE

class QLabel;

#include "QTextStream"

#include "QPlainTextEdit"
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
    QString settingsfile_name = "settings.csv";
    QString datafile_name = "data.bin";
    int baudrate = 9600;
    QString portname = "/dev/ttyUSB0";
    bool update_locus=false;
    bool downloading = false;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(){};
    bool parse_data = false;
    QPlainTextEdit * parsed_log;
    // different commands to set the update rate from once a second (1 Hz) to 10 times a second (10Hz)
    // Note that these only control the rate at which the position is echoed, to actually speed up the
    // position fix you must also send one of the position fix rate commands below too.
#include "pmtkcommands.h"
    
    QPlainTextEdit * edit;
    bool locus_repeat_query = true;
    float getDownloadProgress();
    int serial_update_rate = 5; // in ms
    bool serial_reading = false;
    int serial_readlines = 10;

QByteArray dataBuff;
    void pushSettings();
    void pullSettings();



    void appendColoredText(QPlainTextEdit * edit, QString text, QString color)
    {
        QString temp = "<font color=";
        temp.append(color).append("> </font> ").append(text);
        edit->appendHtml(temp);

    }
    void appendRed( QString text,  QPlainTextEdit * edit)     {        appendColoredText(edit,text,"red");   }
    void appendGreen( QString text,  QPlainTextEdit * edit)   {        appendColoredText(edit,text,"green");   }
    void appendBlue( QString text,  QPlainTextEdit * edit)    {        appendColoredText(edit,text,"blue");   }
    void appendOrange( QString text,  QPlainTextEdit * edit)  {        appendColoredText(edit,text,"orange");   }
    void appendBlack( QString text,  QPlainTextEdit * edit)   {        appendColoredText(edit,text,"black");   }
    void appendGray( QString text,  QPlainTextEdit * edit)    {        appendColoredText(edit,text,"gray");   }
    void appendPink( QString text,  QPlainTextEdit * edit)    {        appendColoredText(edit,text,"pink");   }
    void appendWhite( QString text,  QPlainTextEdit * edit)   {        appendColoredText(edit,text,"white");   }
    void appendYellow( QString text,  QPlainTextEdit * edit)  {        appendColoredText(edit,text,"yellow");   }



    bool openHandle(int port, int baudrate);
    void closeHandle();
    void beginSerialRead();
    void stopSerialRead();
    void updateTableValues();
    void writeSerial(QString msg);
//    void writeSerial(QByteArray ba);
public slots:

    void addName(QString name);
    void addBaud(int val);

    void recieveData();
    void readSerial();
private slots:
    void on_pushButton_17_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_12_clicked();


    void on_pushButton_9_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_readlines_valueChanged(int arg1);

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_clicked();

    void on_pushButton_11_clicked();

    void on_comboBox_setNMEA_Rate_currentIndexChanged(int index);

    void on_pushButton_26_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_comboBox_loggingrate_currentIndexChanged(int index);

    void on_pushButton_18_clicked();

private:

    
    Ui::MainWindow *ui;
    QLabel *status;
    Console *console;
    nmea_parser * parser;
    SettingsDialog *settings;
    QSerialPort *serial;
};

#endif // MAINWINDOW_H
