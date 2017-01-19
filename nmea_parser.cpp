#include "nmea_parser.h"
#include "QString"
#include "QStringList"
#include "QFile"
#include "QMessageBox"
#include "QDebug"
QFile * filewriter;

nmea_parser::nmea_parser(QObject *parent)
{

}

void nmea_parser::Show_Locus()
{
    qDebug() << "Serial Number     : " <<  locus.serial_no;
    qDebug() << "Type              : " <<  locus.type;
    qDebug() << "Mode              : " <<  locus.mode;
    qDebug() << "Content           : " <<  locus.content;
    qDebug() << "Logging Interval  : " <<  locus.interval;
    qDebug() << "Distance          : " <<  locus.distance;
    qDebug() << "Speed             : " <<  locus.speed;
    qDebug() << "Logging Status    : " <<  locus.status;
    qDebug() << "Number of Logs    : " <<  locus.number;
    qDebug() << "Percent Used      : " <<  locus.percent;
}

void nmea_parser::Show_GPRMC()
{
    qDebug() << "Time       : " << time_formatted;
    qDebug() << "Latitude   : " << dat.latitude;
    qDebug() << "Longitude  : " << dat.longitude;
    qDebug() << "Speed      : " << dat.ground_speed_knots;
    qDebug() << "Date Raw   : " << dat.date_raw;

}

void nmea_parser::Show_Firmware()
{
    qDebug() << "Firmware : " << firmware_version;
    qDebug() << "Model No : " << model_number;
}

void nmea_parser::printData()
{
    qDebug() << "Time UTC: " << dat.time_raw_utc;
    qDebug() << "Latitude: " << dat.latitude;
    qDebug() << "Longitude: " << dat.longitude;
    qDebug() << "Altitude: " << dat.altitude;
    qDebug() << "Num Satelites: " << dat.num_satelites;
    qDebug() << "Health: " << dat.fix_quality;

}

//char* toCharP(QString in)
//{
//    QByteArray a;
//    a.append(in);
//    return a.data();
//}

nmea_parser::GPSData nmea_parser::parseData(QByteArray serial_data)
{
    QString temp = serial_data.data();
    QStringList csvdata = temp.split(",");
    QString ident = csvdata.at(0);
    int count = csvdata.count();
    if(!strcmp("$GPGGA",toCharP(ident)))
    {

    }
    if(!strcmp("$GPGSA",toCharP(ident)))
    {
        if(!strcmp(toCharP(QString(csvdata.at(1))),"A"))
        {
            //            qDebug() << "Automatic mode";
            dat.automatic=true;
        }
        else
        {
            dat.automatic=false;
            //            qDebug() << "Manual mode";
        }
        dat.fix_quality = QString(csvdata.at(2)).toFloat();

        if(csvdata.count()>15) dat.hdop = QString(csvdata.at(15)).toFloat();

        if(csvdata.count()>17) dat.vdop = QString(QString(csvdata.at(17)).split("*").at(0)).toFloat();

        if(csvdata.count()>16) dat.pdop = QString(csvdata.at(16)).toFloat();
        if((((int) dat.time_seconds)%10 == 0))
        {
            qDebug() << "Fix :" <<  dat.fix_quality
                     << "HDOP :" <<  dat.hdop
                     << "VDOP :" <<  dat.vdop
                     << "PDOP :" << dat.pdop;

        }

    }
    if(!strcmp("$PMTKLOX,0,86*67",toCharP(temp)))
    {
        qDebug() << "PMTKLOX,0,86*67";
    }
    if(!strcmp("$PMTKLOX,2,47",toCharP(temp)))
    {
        qDebug() << "PMTKLOX,2,47";
    }
    if(!strcmp("$PMTKLOX",toCharP(csvdata.at(0))))
    {

        if(!strcmp(toCharP(QString(csvdata.at(1))),"0"))
        {
            int num_reads = QString(QString(csvdata.at(2)).split("*").at(0)).toInt();
            qDebug() << "Number of Reads: " <<  num_reads;
            locus.number_of_reads=num_reads-2;

        }
        else if(!strcmp(toCharP(QString(csvdata.at(1))),"1"))
        {
            locus.current_read = QString(csvdata.at(2)).toInt();
            if(locus.current_read % 5 == 0) // once every 5, print
                qDebug() << "Current Read: " << csvdata.at(2);
            float progress = 100*locus.current_read/locus.number_of_reads;
            //            qDebug() << QString::number(progress);
            emit updateProgressBar(progress);

        }
        else if(!strcmp(toCharP(QString(QString(csvdata.at(1)).split("*").at(0))),"2"))
        {

            QString filename=locus.filename;
            filewriter = new QFile("data.log");
            flashData.append("$PMTK001,622,3*36");
            QStringList list = QString(flashData).split("$");
            if ( filewriter->open(QIODevice::ReadWrite) )
            {
                QTextStream stream( filewriter );

                for(int i=0; i<list.count()-1; i++)
                    stream << QString(list.at(i)).prepend("$") << endl;
            }
            qDebug() << "#################### Locus dump finished.";
            filewriter->close();
            qDebug() << "#################### File " << locus.filename << " wrote successfully.";
            emit downloadFinished();
        }

        flashData.append(serial_data);
    }
    if(!strcmp("$GPRMC",toCharP(ident)))
    {
        //        1   220516     Time Stamp
        //        2   A          validity - A-ok, V-invalid
        //        3   5133.82    current Latitude
        //        4   N          North/South
        //        5   00042.24   current Longitude
        //        6   W          East/West
        //        7   173.8      Speed in knots
        //        8   231.8      True course
        //        9   130694     Date Stamp
        //        10  004.2      Variation
        //        11  W          East/West
        //        12  *70        checksum
        if(csvdata.count()>1) dat.time_raw_utc = QString(csvdata.at(1)).toFloat();
        if(csvdata.count()>3) dat.latitude = QString(csvdata.at(3)).toFloat();
        if(csvdata.count()>5) dat.longitude =  QString(csvdata.at(5)).toFloat();
        if(csvdata.count()>8) dat.ground_speed_knots =  QString(csvdata.at(7)).toFloat();
        if(csvdata.count()>9) dat.date_raw =  QString(csvdata.at(9)).toFloat();


        int hours, minutes, seconds;
        hours  = dat.time_raw_utc/10000;
        minutes = dat.time_raw_utc/100;
        seconds = dat.time_raw_utc;
        int temp = dat.time_raw_utc;
        temp = temp/100; temp = temp*100; // truncated
        seconds = seconds - temp;
        temp = dat.time_raw_utc;
        temp = temp/10000; temp = temp*100;
        minutes = minutes - temp;

        hours = hours -5; // EST
        if(hours < 0)
        {
            hours = hours+12; // 12 hour time, no negative time, AM
            dat.time_amPM = false;
        }
        if(hours > 12)
        {
            hours = hours-12; // PM
            dat.time_amPM = true;
        }
        if((hours == 0))
        {
            hours = 12;
        }

        dat.time_hours_utc = hours+5;
        dat.time_hours_est = hours;
        dat.time_minutes = minutes;
        dat.time_seconds = seconds;

        QString thours = QString("%1").arg(hours, 2, 10, QChar('0'));
        QString tmins = QString("%1").arg(minutes, 2, 10, QChar('0'));
        QString tsecs = QString("%1").arg(seconds, 2, 10, QChar('0'));

        QString time; time.append(thours)
                .append(":").append(tmins)
                .append(":").append(tsecs)
                .append(" ").append(dat.time_amPM == 0 ? "AM" : "PM");

        time_formatted = time;



        int days, months, years;
        days  = dat.date_raw/10000;
        months = dat.date_raw/100;
        years = dat.date_raw;
        temp = dat.date_raw;
        temp = temp/100; temp = temp*100; // truncated
        years = years - temp;
        temp = dat.date_raw;
        temp = temp/10000; temp = temp*100;
        months = months - temp;

        if(days > 31) days = days - 30;
        if(days < 0) days = days + 30;

        QString tdays = QString("%1").arg(days, 2, 10, QChar('0'));
        QString tmonths = QString("%1").arg(months, 2, 10, QChar('0'));
        QString tyears = QString("%1").arg(years, 2, 10, QChar('0'));

        QString date; date.append(tmonths)
                .append("/").append(tdays)
                .append("/").append(tyears);
        date_formatted = date;


        if((((int) dat.time_seconds)%5 == 0))
        {

            qDebug() << "Latitude : " << dat.latitude << "          " // << " " << dat.lat_NS ? "S" : "N";
                     << "Longitude : " << dat.longitude; // << " "  << dat.long_WE ? "W" : "E";

            qDebug() << "Time : " <<  time_formatted
                     << "Date : " <<  date_formatted;

        }

        if((((int) dat.time_seconds)%200 == 0)) emit SIGNALqueryLocus();

    }
    // locus end dump 622, 3*36
    else   if( (!strcmp("$PMTK001",toCharP(ident))))
    {


    }
    else   if(!strcmp("$PMTKLOG",toCharP(ident))) // locus status
    {
        //$PMTKLOG, Serial#, Type, Mode, Content, Interval, Distance, Speed, Status, Number,
        //        Percent*CH
        locus.serial_no = QString(csvdata.at(1)).toInt();
        locus.type = QString(csvdata.at(2)).toInt();
        locus.mode = QString(csvdata.at(3)).toInt();
        locus.content = QString(csvdata.at(4)).toInt();
        locus.interval = QString(csvdata.at(5)).toInt();
        locus.distance = QString(csvdata.at(6)).toInt();
        locus.speed = QString(csvdata.at(7)).toInt();
        locus.status = QString(csvdata.at(8)).toInt();
        locus.number = QString(csvdata.at(9)).toInt();
        if(csvdata.count() >=10)  locus.percent = QString(QString(csvdata.at(10)).split("*").at(0)).toInt();
        else qDebug() << "# Count is " << csvdata.count();
        Show_Locus();
    }
    else   if(!strcmp("$PMTK705",toCharP(ident))) // firmware version
    {
        //        qDebug() << "PMTK705";
        firmware_version = QString(QString(serial_data).split("_").at(1));
        model_number = QString(QString(serial_data).split("_").at(2)).toInt();

    }





}






