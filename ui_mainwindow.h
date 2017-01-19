/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_28;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_2;
    QPushButton *pushButton_close;
    QComboBox *comboBox_interface;
    QComboBox *comboBox_baudrate;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget_2;
    QWidget *tab_parsed;
    QVBoxLayout *verticalLayout_8;
    QPlainTextEdit *edit_parsed;
    QWidget *tab_nmea;
    QVBoxLayout *verticalLayout_14;
    QWidget *edit_nmea;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_24;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_20;
    QLabel *label_21;
    QVBoxLayout *verticalLayout_13;
    QProgressBar *progressBar_download;
    QProgressBar *progressBar_used;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_18;
    QLineEdit *lineEdit_filename;
    QHBoxLayout *horizontalLayout_22;
    QPushButton *pushButton_4;
    QPushButton *pushButton_18;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_16;
    QPushButton *pushButton_19;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pushButton_26;
    QPushButton *pushButton_29;
    QHBoxLayout *horizontalLayout_26;
    QPushButton *pushButton_24;
    QComboBox *comboBox_baudrate_change_2;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_25;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *pushButton_11;
    QPushButton *pushButton_8;
    QHBoxLayout *horizontalLayout_23;
    QPushButton *pushButton_10;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_22;
    QComboBox *comboBox_setNMEA_Rate_2;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_3;
    QComboBox *comboBox_loggingrate;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_value_time;
    QLabel *label_date;
    QLabel *label_firmware;
    QLabel *label_model;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_interval;
    QLabel *label_locus_logging;
    QLabel *label_mode;
    QLabel *label_percent;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_lat;
    QLabel *label_long;
    QLabel *label_logs;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_fix;
    QLabel *label_hdop;
    QLabel *label_pdop;
    QLabel *label_vdop;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(647, 536);
        MainWindow->setStyleSheet(QLatin1String("background-color: rgb(11, 45, 1);\n"
"color: rgb(255, 255, 255);"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon1);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon2);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_28->addWidget(pushButton_clear);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_28->addWidget(pushButton_2);

        pushButton_close = new QPushButton(centralWidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_28->addWidget(pushButton_close);

        comboBox_interface = new QComboBox(centralWidget);
        comboBox_interface->setObjectName(QStringLiteral("comboBox_interface"));
        comboBox_interface->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_28->addWidget(comboBox_interface);

        comboBox_baudrate = new QComboBox(centralWidget);
        comboBox_baudrate->setObjectName(QStringLiteral("comboBox_baudrate"));
        comboBox_baudrate->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_28->addWidget(comboBox_baudrate);


        verticalLayout->addLayout(horizontalLayout_28);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setStyleSheet(QStringLiteral(""));
        tab_parsed = new QWidget();
        tab_parsed->setObjectName(QStringLiteral("tab_parsed"));
        verticalLayout_8 = new QVBoxLayout(tab_parsed);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        edit_parsed = new QPlainTextEdit(tab_parsed);
        edit_parsed->setObjectName(QStringLiteral("edit_parsed"));
        edit_parsed->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        verticalLayout_8->addWidget(edit_parsed);

        tabWidget_2->addTab(tab_parsed, QString());
        tab_nmea = new QWidget();
        tab_nmea->setObjectName(QStringLiteral("tab_nmea"));
        verticalLayout_14 = new QVBoxLayout(tab_nmea);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        edit_nmea = new QWidget(tab_nmea);
        edit_nmea->setObjectName(QStringLiteral("edit_nmea"));
        edit_nmea->setMinimumSize(QSize(400, 0));
        edit_nmea->setMaximumSize(QSize(100000, 77777));
        edit_nmea->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        verticalLayout_14->addWidget(edit_nmea);

        tabWidget_2->addTab(tab_nmea, QString());

        horizontalLayout->addWidget(tabWidget_2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setStyleSheet(QLatin1String("background-color: rgb(11, 45, 1);\\ncolor: rgb(255, 255, 255);\n"
"color: rgb(255, 255, 255);"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_6 = new QVBoxLayout(tab_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_19->setFont(font);

        verticalLayout_6->addWidget(label_19);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_20->setFont(font1);

        verticalLayout_5->addWidget(label_20);

        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        verticalLayout_5->addWidget(label_21);


        horizontalLayout_24->addLayout(verticalLayout_5);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        progressBar_download = new QProgressBar(tab_2);
        progressBar_download->setObjectName(QStringLiteral("progressBar_download"));
        progressBar_download->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(9, 9, 9);"));
        progressBar_download->setValue(0);

        verticalLayout_13->addWidget(progressBar_download);

        progressBar_used = new QProgressBar(tab_2);
        progressBar_used->setObjectName(QStringLiteral("progressBar_used"));
        progressBar_used->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(9, 9, 9);"));
        progressBar_used->setValue(0);

        verticalLayout_13->addWidget(progressBar_used);


        horizontalLayout_24->addLayout(verticalLayout_13);


        verticalLayout_6->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_18->setFont(font2);

        horizontalLayout_25->addWidget(label_18);

        lineEdit_filename = new QLineEdit(tab_2);
        lineEdit_filename->setObjectName(QStringLiteral("lineEdit_filename"));
        lineEdit_filename->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(9, 9, 9);"));

        horizontalLayout_25->addWidget(lineEdit_filename);


        verticalLayout_6->addLayout(horizontalLayout_25);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_22->addWidget(pushButton_4);

        pushButton_18 = new QPushButton(tab_2);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_22->addWidget(pushButton_18);


        verticalLayout_6->addLayout(horizontalLayout_22);

        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        verticalLayout_7 = new QVBoxLayout(tab_5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_16 = new QPushButton(tab_5);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_3->addWidget(pushButton_16);

        pushButton_19 = new QPushButton(tab_5);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_3->addWidget(pushButton_19);


        verticalLayout_7->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_14 = new QPushButton(tab_5);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_2->addWidget(pushButton_14);

        pushButton_15 = new QPushButton(tab_5);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_2->addWidget(pushButton_15);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        pushButton_26 = new QPushButton(tab_5);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        pushButton_26->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_17->addWidget(pushButton_26);

        pushButton_29 = new QPushButton(tab_5);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        pushButton_29->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_17->addWidget(pushButton_29);


        verticalLayout_7->addLayout(horizontalLayout_17);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        pushButton_24 = new QPushButton(tab_5);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_26->addWidget(pushButton_24);

        comboBox_baudrate_change_2 = new QComboBox(tab_5);
        comboBox_baudrate_change_2->setObjectName(QStringLiteral("comboBox_baudrate_change_2"));
        comboBox_baudrate_change_2->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_26->addWidget(comboBox_baudrate_change_2);


        verticalLayout_7->addLayout(horizontalLayout_26);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        pushButton_27 = new QPushButton(tab_5);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        pushButton_27->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_20->addWidget(pushButton_27);

        pushButton_28 = new QPushButton(tab_5);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        pushButton_28->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_20->addWidget(pushButton_28);


        verticalLayout_7->addLayout(horizontalLayout_20);

        pushButton_25 = new QPushButton(tab_5);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        verticalLayout_7->addWidget(pushButton_25);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        pushButton_11 = new QPushButton(tab_5);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_19->addWidget(pushButton_11);

        pushButton_8 = new QPushButton(tab_5);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_19->addWidget(pushButton_8);


        verticalLayout_7->addLayout(horizontalLayout_19);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        pushButton_10 = new QPushButton(tab_5);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_23->addWidget(pushButton_10);

        pushButton = new QPushButton(tab_5);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_23->addWidget(pushButton);


        verticalLayout_7->addLayout(horizontalLayout_23);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_22 = new QLabel(tab_5);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_4->addWidget(label_22);

        comboBox_setNMEA_Rate_2 = new QComboBox(tab_5);
        comboBox_setNMEA_Rate_2->setObjectName(QStringLiteral("comboBox_setNMEA_Rate_2"));
        comboBox_setNMEA_Rate_2->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_4->addWidget(comboBox_setNMEA_Rate_2);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_3 = new QLabel(tab_5);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_16->addWidget(label_3);

        comboBox_loggingrate = new QComboBox(tab_5);
        comboBox_loggingrate->setObjectName(QStringLiteral("comboBox_loggingrate"));
        comboBox_loggingrate->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_16->addWidget(comboBox_loggingrate);


        verticalLayout_7->addLayout(horizontalLayout_16);

        tabWidget->addTab(tab_5, QString());

        horizontalLayout->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(600, 0));
        groupBox->setMaximumSize(QSize(16777215, 125));
        groupBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        horizontalLayout_13 = new QHBoxLayout(groupBox);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font3;
        font3.setFamily(QStringLiteral("Sans Serif"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_7->setFont(font3);
        label_7->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_9->addWidget(label_7);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font3);
        label_8->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_9->addWidget(label_8);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font3);
        label_9->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_9->addWidget(label_9);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font3);
        label_10->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_9->addWidget(label_10);


        horizontalLayout_6->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_value_time = new QLabel(groupBox);
        label_value_time->setObjectName(QStringLiteral("label_value_time"));
        label_value_time->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_10->addWidget(label_value_time);

        label_date = new QLabel(groupBox);
        label_date->setObjectName(QStringLiteral("label_date"));
        label_date->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_10->addWidget(label_date);

        label_firmware = new QLabel(groupBox);
        label_firmware->setObjectName(QStringLiteral("label_firmware"));
        label_firmware->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_10->addWidget(label_firmware);

        label_model = new QLabel(groupBox);
        label_model->setObjectName(QStringLiteral("label_model"));
        label_model->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_10->addWidget(label_model);


        horizontalLayout_6->addLayout(verticalLayout_10);


        horizontalLayout_13->addLayout(horizontalLayout_6);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font3);
        label_11->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_16->addWidget(label_11);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font3);
        label_12->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_16->addWidget(label_12);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font3);
        label_13->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_16->addWidget(label_13);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font3);
        label_14->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_16->addWidget(label_14);


        horizontalLayout_12->addLayout(verticalLayout_16);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_interval = new QLabel(groupBox);
        label_interval->setObjectName(QStringLiteral("label_interval"));

        verticalLayout_11->addWidget(label_interval);

        label_locus_logging = new QLabel(groupBox);
        label_locus_logging->setObjectName(QStringLiteral("label_locus_logging"));

        verticalLayout_11->addWidget(label_locus_logging);

        label_mode = new QLabel(groupBox);
        label_mode->setObjectName(QStringLiteral("label_mode"));

        verticalLayout_11->addWidget(label_mode);

        label_percent = new QLabel(groupBox);
        label_percent->setObjectName(QStringLiteral("label_percent"));

        verticalLayout_11->addWidget(label_percent);


        horizontalLayout_12->addLayout(verticalLayout_11);


        horizontalLayout_13->addLayout(horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font3);
        label_15->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_17->addWidget(label_15);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font3);
        label_16->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_17->addWidget(label_16);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font3);
        label_17->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_17->addWidget(label_17);


        horizontalLayout_14->addLayout(verticalLayout_17);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_lat = new QLabel(groupBox);
        label_lat->setObjectName(QStringLiteral("label_lat"));

        verticalLayout_12->addWidget(label_lat);

        label_long = new QLabel(groupBox);
        label_long->setObjectName(QStringLiteral("label_long"));

        verticalLayout_12->addWidget(label_long);

        label_logs = new QLabel(groupBox);
        label_logs->setObjectName(QStringLiteral("label_logs"));

        verticalLayout_12->addWidget(label_logs);


        horizontalLayout_14->addLayout(verticalLayout_12);


        horizontalLayout_13->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setFont(font3);
        label_27->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_18->addWidget(label_27);

        label_28 = new QLabel(groupBox);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font3);
        label_28->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_18->addWidget(label_28);

        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font3);
        label_29->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_18->addWidget(label_29);

        label_30 = new QLabel(groupBox);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font3);
        label_30->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        verticalLayout_18->addWidget(label_30);


        horizontalLayout_15->addLayout(verticalLayout_18);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        label_fix = new QLabel(groupBox);
        label_fix->setObjectName(QStringLiteral("label_fix"));

        verticalLayout_20->addWidget(label_fix);

        label_hdop = new QLabel(groupBox);
        label_hdop->setObjectName(QStringLiteral("label_hdop"));

        verticalLayout_20->addWidget(label_hdop);

        label_pdop = new QLabel(groupBox);
        label_pdop->setObjectName(QStringLiteral("label_pdop"));

        verticalLayout_20->addWidget(label_pdop);

        label_vdop = new QLabel(groupBox);
        label_vdop->setObjectName(QStringLiteral("label_vdop"));

        verticalLayout_20->addWidget(label_vdop);


        horizontalLayout_15->addLayout(verticalLayout_20);


        horizontalLayout_13->addLayout(horizontalLayout_15);


        verticalLayout_2->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        comboBox_baudrate->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);
        comboBox_baudrate_change_2->setCurrentIndex(5);
        comboBox_setNMEA_Rate_2->setCurrentIndex(2);
        comboBox_loggingrate->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FTDI _Terminal", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About program", 0));
#endif // QT_NO_TOOLTIP
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        actionAboutQt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "C&onnect", 0));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect to serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "&Disconnect", 0));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect from serial port", 0));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        actionConfigure->setText(QApplication::translate("MainWindow", "&Configure", 0));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "Configure serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConfigure->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        actionClear->setText(QApplication::translate("MainWindow", "C&lear", 0));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "Clear data", 0));
#endif // QT_NO_TOOLTIP
        actionClear->setShortcut(QApplication::translate("MainWindow", "Alt+L", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        pushButton_clear->setText(QApplication::translate("MainWindow", "Clear", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Open", 0));
        pushButton_close->setText(QApplication::translate("MainWindow", "Close", 0));
        comboBox_interface->clear();
        comboBox_interface->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Interface A", 0)
         << QApplication::translate("MainWindow", "Interface B", 0)
        );
        comboBox_baudrate->clear();
        comboBox_baudrate->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "115200", 0)
        );
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_parsed), QApplication::translate("MainWindow", "Parsed Output", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_nmea), QApplication::translate("MainWindow", "NMEA ", 0));
        label_19->setText(QApplication::translate("MainWindow", "Download Locus Data", 0));
        label_20->setText(QApplication::translate("MainWindow", "Progess: ", 0));
        label_21->setText(QApplication::translate("MainWindow", "Used Space: ", 0));
        label_18->setText(QApplication::translate("MainWindow", "Save file name : ", 0));
        lineEdit_filename->setText(QApplication::translate("MainWindow", "Data", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Download Now", 0));
        pushButton_18->setText(QApplication::translate("MainWindow", "Parse", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Download Data", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "Locus Stop", 0));
        pushButton_19->setText(QApplication::translate("MainWindow", "Locus Start", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "Locus Query", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "Erase Flash", 0));
        pushButton_26->setText(QApplication::translate("MainWindow", "Cold Start", 0));
        pushButton_29->setText(QApplication::translate("MainWindow", "Hot Start", 0));
        pushButton_24->setText(QApplication::translate("MainWindow", "Set Baud", 0));
        comboBox_baudrate_change_2->clear();
        comboBox_baudrate_change_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "4800", 0)
         << QApplication::translate("MainWindow", "9600", 0)
         << QApplication::translate("MainWindow", "14400", 0)
         << QApplication::translate("MainWindow", "19200", 0)
         << QApplication::translate("MainWindow", "38400", 0)
         << QApplication::translate("MainWindow", "57600", 0)
         << QApplication::translate("MainWindow", "115200", 0)
        );
        pushButton_27->setText(QApplication::translate("MainWindow", "Warm Start", 0));
        pushButton_28->setText(QApplication::translate("MainWindow", "Factory Reset", 0));
        pushButton_25->setText(QApplication::translate("MainWindow", "Query Firmware", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "RMC + GPA", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "RMC Only", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "All NMEA", 0));
        pushButton->setText(QApplication::translate("MainWindow", "NMEA Off", 0));
        label_22->setText(QApplication::translate("MainWindow", "NMEA Rate", 0));
        comboBox_setNMEA_Rate_2->clear();
        comboBox_setNMEA_Rate_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "100 mHz", 0)
         << QApplication::translate("MainWindow", "200 mHz", 0)
         << QApplication::translate("MainWindow", "1 Hz", 0)
         << QApplication::translate("MainWindow", "10 Hz", 0)
         << QString()
        );
        label_3->setText(QApplication::translate("MainWindow", "Logging Rate", 0));
        comboBox_loggingrate->clear();
        comboBox_loggingrate->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1 second", 0)
         << QApplication::translate("MainWindow", "5 seconds", 0)
         << QApplication::translate("MainWindow", "10 seconds", 0)
         << QApplication::translate("MainWindow", "15 seconds", 0)
         << QApplication::translate("MainWindow", "30 seconds", 0)
         << QApplication::translate("MainWindow", "60 seconds", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Locus", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Status", 0));
        label_7->setText(QApplication::translate("MainWindow", "Time:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Date:", 0));
        label_9->setText(QApplication::translate("MainWindow", "Firmware:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Model:", 0));
        label_value_time->setText(QApplication::translate("MainWindow", "4:15:14", 0));
        label_date->setText(QApplication::translate("MainWindow", "1/1/1992", 0));
        label_firmware->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_model->setText(QApplication::translate("MainWindow", "0", 0));
        label_11->setText(QApplication::translate("MainWindow", "Interval:", 0));
        label_12->setText(QApplication::translate("MainWindow", "Logging:", 0));
        label_13->setText(QApplication::translate("MainWindow", "Log Mode:", 0));
        label_14->setText(QApplication::translate("MainWindow", "Percent Used:", 0));
        label_interval->setText(QApplication::translate("MainWindow", "1 (s)", 0));
        label_locus_logging->setText(QApplication::translate("MainWindow", "Disabled", 0));
        label_mode->setText(QApplication::translate("MainWindow", "Overlap", 0));
        label_percent->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_15->setText(QApplication::translate("MainWindow", "Latitude: ", 0));
        label_16->setText(QApplication::translate("MainWindow", "Longitude:", 0));
        label_17->setText(QApplication::translate("MainWindow", "# Logs", 0));
        label_lat->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_long->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_logs->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_27->setText(QApplication::translate("MainWindow", "Fix:", 0));
        label_28->setText(QApplication::translate("MainWindow", "HDOP:", 0));
        label_29->setText(QApplication::translate("MainWindow", "PDOP:", 0));
        label_30->setText(QApplication::translate("MainWindow", "VDOP:", 0));
        label_fix->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_hdop->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_pdop->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_vdop->setText(QApplication::translate("MainWindow", "0.0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
