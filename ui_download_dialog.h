/********************************************************************************
** Form generated from reading UI file 'download_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOAD_DIALOG_H
#define UI_DOWNLOAD_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_download_dialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QProgressBar *progressBar_used;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *download_dialog)
    {
        if (download_dialog->objectName().isEmpty())
            download_dialog->setObjectName(QStringLiteral("download_dialog"));
        download_dialog->resize(400, 300);
        verticalLayout_3 = new QVBoxLayout(download_dialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(download_dialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_3->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(download_dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(download_dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout_2->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        progressBar = new QProgressBar(download_dialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        progressBar_used = new QProgressBar(download_dialog);
        progressBar_used->setObjectName(QStringLiteral("progressBar_used"));
        progressBar_used->setValue(0);

        verticalLayout->addWidget(progressBar_used);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(download_dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(download_dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton = new QPushButton(download_dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(download_dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        buttonBox = new QDialogButtonBox(download_dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(download_dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), download_dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), download_dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(download_dialog);
    } // setupUi

    void retranslateUi(QDialog *download_dialog)
    {
        download_dialog->setWindowTitle(QApplication::translate("download_dialog", "Dialog", 0));
        label->setText(QApplication::translate("download_dialog", "Download Locus Data", 0));
        label_3->setText(QApplication::translate("download_dialog", "Progess: ", 0));
        label_4->setText(QApplication::translate("download_dialog", "Used Space: ", 0));
        label_2->setText(QApplication::translate("download_dialog", "Save file name : ", 0));
        lineEdit->setText(QApplication::translate("download_dialog", "Data.txt", 0));
        pushButton->setText(QApplication::translate("download_dialog", "Download Now", 0));
        pushButton_2->setText(QApplication::translate("download_dialog", "print", 0));
    } // retranslateUi

};

namespace Ui {
    class download_dialog: public Ui_download_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOAD_DIALOG_H
