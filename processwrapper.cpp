#include "processwrapper.h"


processWrapper::processWrapper(QString prog, QStringList args, bool debug, QObject *parent)
{
    program = prog; arguments = args; debugmode = debugmode;
    process = new QProcess();
    connect(process,SIGNAL(readyRead()),this,SLOT(recieveData()));
}

processWrapper::processWrapper(QString prog,bool debug, QObject *parent)
{
    debugmode = debug;
    program = prog;
    process = new QProcess();
    connect(process,SIGNAL(readyRead()),this,SLOT(recieveData()));
}

void processWrapper::_ls(QString dir)
{
    program = dir.prepend("ls ");
    process->start(program);
}
void processWrapper::_rm_dir(QString dir)
{
    program = dir.prepend("rm -r ");
    process->execute(program);
}
void processWrapper::_rm(QString dir)
{
    program = dir.prepend("rm ");
    process->execute(program);
}
void processWrapper::_writeValue(QString filename, int value)
{
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << value << endl;
    }
    file.close();
}
void processWrapper::startProcess()
{
    process->start(program.toLatin1().data());
    process->waitForReadyRead(1000);
}
int processWrapper::rp_readGPIO(int pin)
{
    QString parent_dir = "/home/jake/gpio_test/";
    QString gpio_num = QString::number(pin);
    program = "cat "; program.append(parent_dir).append("gpio")
            .append(gpio_num).append("/value");
    startProcess();
    if(debugmode)
    {
        qDebug(QString("GPIO ").append(QString::number(pin)).append(" : ").append(recieved).toLatin1().data());
    }

    return recieved.toInt();
}
void processWrapper::startProcess(QString program)
{
    process->start(program.toLatin1().data());
    process->waitForReadyRead(1000);
}
void processWrapper::rp_listGPIO(int num_pins)
{
    int num_gpio=num_pins;
    for(int i =0; i<num_gpio; i++)
    {
        rp_readGPIO(i);
        process->waitForFinished();
    }

}

int processWrapper::rp_setGPIO(int pin, int value)
{
    QString parent_dir = "/home/jake/gpio_test/";
    QString gpio_num = QString::number(pin);
    QString file;
    file.append(parent_dir).append("gpio")
            .append(gpio_num).append("/value");
    _rm(file);
    process->waitForFinished();
    _writeValue(file,value);
    process->waitForFinished();
    int r = rp_readGPIO(pin);
//    qDebug() << "Value is " << r;
    if(r!=value)
    {
        qDebug() << "Failed to set GPIO" << pin <<  " to " << value;
        return 1;
    }
    else
    {
        qDebug() << "Set GPIO " << pin << " to " << value <<  " successfully";
        return 0;
    }
    return recieved.toInt();
}

void processWrapper::startProcessWArgs()
{
    QString run = program;
    for(int i =0; i<arguments.count()-1; i++)
    {
        run.append(arguments.at(i)).append("\n");
    }
    process->execute(run);
}

QString processWrapper::recieveData()
{
    recieved  = process->readAll();

    return recieved;
}

QString processWrapper::returnParsed()
{
    QStringList list = recieved.split("\n");
    QByteArray a;
    for(int i=0; i<list.count()-1; i++)
    {
        a.append(list.at(i)).append(" ");

    }
    QString parsed(a);
    return parsed;
}

void processWrapper::printParsed()
{
    QStringList list = recieved.split("\n");

    for(int i=0; i<list.count()-1; i++)
    {
        //       qDebug() << QString(list.at(i)).toLatin1().data();
        qDebug (QString(list.at(i)).append(" ").toLatin1().data());

    }
}
