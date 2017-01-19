#include <QtGlobal>
#include <stdio.h>
#include <stdlib.h>
#include <QApplication>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include "QDebug"
#include "QPlainTextEdit"
MainWindow *w;
#include <qapplication.h>
#include <stdio.h>
#include <stdlib.h>
bool appStarted;
#include <QMainWindow>
#include "QPlainTextEdit"

#include <qapplication.h>
#include <stdio.h>
#include <stdlib.h>


void myMessageOutputqt5(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {

    case QtDebugMsg:
    {
        qDebug("%s", localMsg.constData());
         if(appStarted) w->edit->appendHtml(localMsg.data());
        break;

    }
    case QtWarningMsg:
    {
        if(appStarted) w->appendGreen(localMsg.data(),w->parsed_log);
        break;
    }
    }
}


void myMessageOutputqt4(QtMsgType type, const char *msg)
{
    switch (type)
    {
    case QtDebugMsg:
    {
        fprintf(stderr, "Debug: %s\n", msg);
        if(appStarted) w->edit->appendHtml(msg);
        break;
    }
    case QtWarningMsg:
    {
        fprintf(stderr, "Warning: %s\n", msg);
        if(appStarted) w->edit->appendHtml(msg);
        break;
    }
    case QtCriticalMsg:
    {
        fprintf(stderr, "Critical: %s\n", msg);
        if(appStarted) w->edit->appendHtml(msg);
        break;
    }
    case QtFatalMsg:
    {
        fprintf(stderr, "Fatal: %s\n", msg);
        if(appStarted) w->edit->appendHtml(msg);
        abort();
    }
    }
}

int main(int argc, char **argv)
{
    appStarted = false;
    qInstallMessageHandler(myMessageOutputqt5);
//    qInstallMsgHandler(myMessageOutput);
    QApplication app(argc, argv);
    w = new MainWindow();
    appStarted = true;
    w->show();
    return app.exec();
}
