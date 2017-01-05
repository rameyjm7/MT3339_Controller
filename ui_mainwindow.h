/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_28;
    QPushButton *pushButton_2;
    QPushButton *pushButton_close;
    QPushButton *pushButton_clear;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *comboBox_devicename;
    QComboBox *comboBox_baudrate;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QHBoxLayout *horizontalLayout_27;
    QPushButton *pushButton_19;
    QPushButton *pushButton_9;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *pushButton_22;
    QPushButton *pushButton_12;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_4;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_10;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_11;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_16;
    QPushButton *pushButton_15;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_14;
    QPushButton *pushButton_13;
    QPushButton *pushButton_18;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_16;
    QLineEdit *lineEdit_filename;
    QHBoxLayout *horizontalLayout_24;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_13;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_11;
    QProgressBar *progressBar;
    QProgressBar *progressBar_used;
    QPushButton *pushButton_4;
    QTabWidget *tabWidget_2;
    QWidget *tab_status;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_26;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_value_time;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_date;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_6;
    QLabel *label_firmware;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_8;
    QLabel *label_model;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_11;
    QLabel *label_interval;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QLabel *label_locus_logging;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_10;
    QLabel *label_mode;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_12;
    QLabel *label_percent;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *label_lat;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLabel *label_long;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_17;
    QLabel *label_logs;
    QWidget *tab_map;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1002, 543);
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
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(350, 16777215));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(11, 45, 1);\\ncolor: rgb(255, 255, 255);"));
        verticalLayout_13 = new QVBoxLayout(widget_2);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_28->addWidget(pushButton_2);

        pushButton_close = new QPushButton(widget_2);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_28->addWidget(pushButton_close);

        pushButton_clear = new QPushButton(widget_2);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_28->addWidget(pushButton_clear);


        verticalLayout_13->addLayout(horizontalLayout_28);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        comboBox_devicename = new QComboBox(widget_2);
        comboBox_devicename->setObjectName(QStringLiteral("comboBox_devicename"));
        comboBox_devicename->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_6->addWidget(comboBox_devicename);

        comboBox_baudrate = new QComboBox(widget_2);
        comboBox_baudrate->setObjectName(QStringLiteral("comboBox_baudrate"));
        comboBox_baudrate->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_6->addWidget(comboBox_baudrate);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_13->addLayout(verticalLayout_2);

        tabWidget = new QTabWidget(widget_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(350, 0));
        tabWidget->setStyleSheet(QLatin1String("background-color: rgb(11, 45, 1);\\ncolor: rgb(255, 255, 255);\n"
"color: rgb(255, 255, 255);"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_12->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_12->addWidget(pushButton_5);


        verticalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_17->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_17->addWidget(pushButton_6);


        verticalLayout_4->addLayout(horizontalLayout_17);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        pushButton_20 = new QPushButton(tab);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_20->addWidget(pushButton_20);

        pushButton_21 = new QPushButton(tab);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_20->addWidget(pushButton_21);


        verticalLayout_4->addLayout(horizontalLayout_20);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        pushButton_19 = new QPushButton(tab);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_27->addWidget(pushButton_19);

        pushButton_9 = new QPushButton(tab);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_27->addWidget(pushButton_9);


        verticalLayout_4->addLayout(horizontalLayout_27);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        pushButton_22 = new QPushButton(tab);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_19->addWidget(pushButton_22);

        pushButton_12 = new QPushButton(tab);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_19->addWidget(pushButton_12);


        verticalLayout_4->addLayout(horizontalLayout_19);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QLatin1String("background-color: rgb(11, 45, 1);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_18->addWidget(label_4);

        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(15, 15, 15);"));

        horizontalLayout_18->addWidget(comboBox_3);


        verticalLayout_3->addLayout(horizontalLayout_18);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_8->addWidget(pushButton_10);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_8->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_7->addWidget(pushButton_8);

        pushButton_11 = new QPushButton(groupBox_2);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 2px;\n"
"min-width: 60px;"));

        horizontalLayout_7->addWidget(pushButton_11);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_4->addWidget(groupBox_2);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_14 = new QVBoxLayout(tab_4);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton_16 = new QPushButton(tab_4);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_9->addWidget(pushButton_16);

        pushButton_15 = new QPushButton(tab_4);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_9->addWidget(pushButton_15);


        verticalLayout_14->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        pushButton_14 = new QPushButton(tab_4);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_11->addWidget(pushButton_14);

        pushButton_13 = new QPushButton(tab_4);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        horizontalLayout_11->addWidget(pushButton_13);


        verticalLayout_14->addLayout(horizontalLayout_11);

        pushButton_18 = new QPushButton(tab_4);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        verticalLayout_14->addWidget(pushButton_18);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_10->addWidget(label_3);

        comboBox_2 = new QComboBox(tab_4);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(15, 15, 15);"));

        horizontalLayout_10->addWidget(comboBox_2);


        verticalLayout_14->addLayout(horizontalLayout_10);

        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_12 = new QVBoxLayout(tab_3);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_15->setFont(font);

        verticalLayout_12->addWidget(label_15);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_16->setFont(font1);

        horizontalLayout_25->addWidget(label_16);

        lineEdit_filename = new QLineEdit(tab_3);
        lineEdit_filename->setObjectName(QStringLiteral("lineEdit_filename"));
        lineEdit_filename->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(9, 9, 9);"));

        horizontalLayout_25->addWidget(lineEdit_filename);


        verticalLayout_12->addLayout(horizontalLayout_25);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_13->setFont(font2);

        verticalLayout_5->addWidget(label_13);

        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font2);

        verticalLayout_5->addWidget(label_14);


        horizontalLayout_24->addLayout(verticalLayout_5);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        progressBar = new QProgressBar(tab_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(9, 9, 9);"));
        progressBar->setValue(0);

        verticalLayout_11->addWidget(progressBar);

        progressBar_used = new QProgressBar(tab_3);
        progressBar_used->setObjectName(QStringLiteral("progressBar_used"));
        progressBar_used->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(9, 9, 9);"));
        progressBar_used->setValue(0);

        verticalLayout_11->addWidget(progressBar_used);


        horizontalLayout_24->addLayout(verticalLayout_11);


        verticalLayout_12->addLayout(horizontalLayout_24);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setStyleSheet(QLatin1String("font: 75 12pt \"Ubuntu Mono\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"min-width: 80px;"));

        verticalLayout_12->addWidget(pushButton_4);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_13->addWidget(tabWidget);


        horizontalLayout->addWidget(widget_2);

        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab_status = new QWidget();
        tab_status->setObjectName(QStringLiteral("tab_status"));
        verticalLayout_10 = new QVBoxLayout(tab_status);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(tab_status);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(400, 0));
        widget->setMaximumSize(QSize(100000, 300));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(widget);

        groupBox = new QGroupBox(tab_status);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(600, 150));
        groupBox->setMaximumSize(QSize(16777215, 125));
        groupBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        horizontalLayout_26 = new QHBoxLayout(groupBox);
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QFont font3;
        font3.setFamily(QStringLiteral("Sans Serif"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label->setFont(font3);
        label->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        horizontalLayout_3->addWidget(label);

        label_value_time = new QLabel(groupBox);
        label_value_time->setObjectName(QStringLiteral("label_value_time"));
        label_value_time->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_value_time);


        verticalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font3);
        label_2->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        horizontalLayout_2->addWidget(label_2);

        label_date = new QLabel(groupBox);
        label_date->setObjectName(QStringLiteral("label_date"));
        label_date->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_date);


        verticalLayout_9->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_9);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font3);
        label_6->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        horizontalLayout_16->addWidget(label_6);

        label_firmware = new QLabel(groupBox);
        label_firmware->setObjectName(QStringLiteral("label_firmware"));
        label_firmware->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_16->addWidget(label_firmware);


        verticalLayout_6->addLayout(horizontalLayout_16);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font3);
        label_8->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        horizontalLayout_21->addWidget(label_8);

        label_model = new QLabel(groupBox);
        label_model->setObjectName(QStringLiteral("label_model"));
        label_model->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_21->addWidget(label_model);


        verticalLayout_6->addLayout(horizontalLayout_21);


        horizontalLayout_26->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font3);
        label_11->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        horizontalLayout_15->addWidget(label_11);

        label_interval = new QLabel(groupBox);
        label_interval->setObjectName(QStringLiteral("label_interval"));

        horizontalLayout_15->addWidget(label_interval);


        verticalLayout_7->addLayout(horizontalLayout_15);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font3);
        label_9->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        horizontalLayout_13->addWidget(label_9);

        label_locus_logging = new QLabel(groupBox);
        label_locus_logging->setObjectName(QStringLiteral("label_locus_logging"));

        horizontalLayout_13->addWidget(label_locus_logging);


        verticalLayout_7->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font3);
        label_10->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        horizontalLayout_14->addWidget(label_10);

        label_mode = new QLabel(groupBox);
        label_mode->setObjectName(QStringLiteral("label_mode"));

        horizontalLayout_14->addWidget(label_mode);


        verticalLayout_7->addLayout(horizontalLayout_14);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font3);
        label_12->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        horizontalLayout_22->addWidget(label_12);

        label_percent = new QLabel(groupBox);
        label_percent->setObjectName(QStringLiteral("label_percent"));

        horizontalLayout_22->addWidget(label_percent);


        verticalLayout_7->addLayout(horizontalLayout_22);


        horizontalLayout_26->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font3);
        label_5->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        horizontalLayout_4->addWidget(label_5);

        label_lat = new QLabel(groupBox);
        label_lat->setObjectName(QStringLiteral("label_lat"));

        horizontalLayout_4->addWidget(label_lat);


        verticalLayout_8->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font3);
        label_7->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        horizontalLayout_5->addWidget(label_7);

        label_long = new QLabel(groupBox);
        label_long->setObjectName(QStringLiteral("label_long"));

        horizontalLayout_5->addWidget(label_long);


        verticalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font3);
        label_17->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"color: rgb(49, 229, 0);"));

        horizontalLayout_23->addWidget(label_17);

        label_logs = new QLabel(groupBox);
        label_logs->setObjectName(QStringLiteral("label_logs"));

        horizontalLayout_23->addWidget(label_logs);


        verticalLayout_8->addLayout(horizontalLayout_23);


        horizontalLayout_26->addLayout(verticalLayout_8);


        verticalLayout->addWidget(groupBox);


        verticalLayout_10->addLayout(verticalLayout);

        tabWidget_2->addTab(tab_status, QString());
        tab_map = new QWidget();
        tab_map->setObjectName(QStringLiteral("tab_map"));
        tabWidget_2->addTab(tab_map, QString());

        horizontalLayout->addWidget(tabWidget_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);
        comboBox_3->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Signal Generator Controller", 0));
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
        pushButton_2->setText(QApplication::translate("MainWindow", "Open", 0));
        pushButton_close->setText(QApplication::translate("MainWindow", "Close", 0));
        pushButton_clear->setText(QApplication::translate("MainWindow", "Clear", 0));
        comboBox_devicename->clear();
        comboBox_devicename->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "/dev/ttyS1", 0)
         << QApplication::translate("MainWindow", "/dev/ttyS0", 0)
         << QApplication::translate("MainWindow", "/dev/ttyUSB0", 0)
         << QApplication::translate("MainWindow", "/dev/ttyUSB1", 0)
        );
        comboBox_baudrate->clear();
        comboBox_baudrate->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "9600", 0)
         << QApplication::translate("MainWindow", "57600", 0)
         << QApplication::translate("MainWindow", "115200", 0)
         << QApplication::translate("MainWindow", "38400", 0)
        );
        pushButton_3->setText(QApplication::translate("MainWindow", "Cold Start", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Warm Start", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Factory Reset", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Hot Start", 0));
        pushButton_20->setText(QApplication::translate("MainWindow", "Query Firmware", 0));
        pushButton_21->setText(QString());
        pushButton_19->setText(QApplication::translate("MainWindow", "Set Baud 9600", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "Set Baud 57600", 0));
        pushButton_22->setText(QApplication::translate("MainWindow", "Set Baud 38400", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "Set Baud 115200", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "NMEA Settings", 0));
        label_4->setText(QApplication::translate("MainWindow", "NMEA Rate", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "100 mHz", 0)
         << QApplication::translate("MainWindow", "200 mHz", 0)
         << QApplication::translate("MainWindow", "1 Hz", 0)
         << QApplication::translate("MainWindow", "10 Hz", 0)
         << QString()
        );
        pushButton_10->setText(QApplication::translate("MainWindow", "All NMEA", 0));
        pushButton->setText(QApplication::translate("MainWindow", "NMEA Off", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "RMC Only", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "RMC + GPA", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Settings", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "Locus Stop", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "Locus Start", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "Locus Query", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "Erase Flash", 0));
        pushButton_18->setText(QApplication::translate("MainWindow", "Parse", 0));
        label_3->setText(QApplication::translate("MainWindow", "Logging Rate", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "100 mHz", 0)
         << QApplication::translate("MainWindow", "200 mHz", 0)
         << QApplication::translate("MainWindow", "1 Hz", 0)
         << QApplication::translate("MainWindow", "5Hz", 0)
         << QString()
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Locus", 0));
        label_15->setText(QApplication::translate("MainWindow", "Download Locus Data", 0));
        label_16->setText(QApplication::translate("MainWindow", "Save file name : ", 0));
        lineEdit_filename->setText(QApplication::translate("MainWindow", "Data.txt", 0));
        label_13->setText(QApplication::translate("MainWindow", "Progess: ", 0));
        label_14->setText(QApplication::translate("MainWindow", "Used Space: ", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Download Now", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Download Data", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Status", 0));
        label->setText(QApplication::translate("MainWindow", "Time:", 0));
        label_value_time->setText(QApplication::translate("MainWindow", "4:15:14", 0));
        label_2->setText(QApplication::translate("MainWindow", "Date:", 0));
        label_date->setText(QApplication::translate("MainWindow", "1/1/1992", 0));
        label_6->setText(QApplication::translate("MainWindow", "Firmware", 0));
        label_firmware->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_8->setText(QApplication::translate("MainWindow", "Model:", 0));
        label_model->setText(QApplication::translate("MainWindow", "0", 0));
        label_11->setText(QApplication::translate("MainWindow", "Interval", 0));
        label_interval->setText(QApplication::translate("MainWindow", "1 (s)", 0));
        label_9->setText(QApplication::translate("MainWindow", "Logging", 0));
        label_locus_logging->setText(QApplication::translate("MainWindow", "Disabled", 0));
        label_10->setText(QApplication::translate("MainWindow", "Mode     ", 0));
        label_mode->setText(QApplication::translate("MainWindow", "Overlap", 0));
        label_12->setText(QApplication::translate("MainWindow", "Percent Used:", 0));
        label_percent->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_5->setText(QApplication::translate("MainWindow", "Latitude: ", 0));
        label_lat->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_7->setText(QApplication::translate("MainWindow", "Longitude:", 0));
        label_long->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_17->setText(QApplication::translate("MainWindow", "Number Logs", 0));
        label_logs->setText(QApplication::translate("MainWindow", "0.0", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_status), QApplication::translate("MainWindow", "Status", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_map), QApplication::translate("MainWindow", "Map", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
