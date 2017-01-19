#ifndef PROCESSWRAPPER_H
#define PROCESSWRAPPER_H

#include <QObject>
#include "QProcess"
#include "QFile"
#include "QDebug"

class processWrapper : public QObject
{
    Q_OBJECT
public:
    explicit processWrapper(QString prog, QStringList args, bool debug=false, QObject *parent = 0);
    explicit processWrapper(QString prog, bool debug=false, QObject *parent = 0);
    QString program;
    QString recieved;
    QStringList arguments;
    QProcess *process;
    bool debugmode;

    void _ls(QString dir);

    void startProcessWArgs(); // starts it with the program plus the arguments
    void startProcess(QString program); // starts it with the one specified
        void startProcess();  // starts it with the program stored in program
    void _rm(QString file); // removes a file
    void _rm_dir(QString dir); // removes a directory
    QString returnParsed();
    void printParsed();

    void setup_rp(QString gpio_dir);
    QString gpio_directory;
    int  rp_readGPIO(int pin);
    void rp_listGPIO(int num_pins=7);
    int rp_setGPIO(int pin, int value);
    void _writeValue(QString filename, int value);
signals:

public slots:
    QString recieveData();
};

#endif // PROCESSWRAPPER_H
