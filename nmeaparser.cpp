#include "nmeaparser.h"


#include "nmeaparser.h"
#include "QString"
#include "QStringList"
#include "QFile"
#include "QMessageBox"

//char* toCharP(QString in)
//{
//    QByteArray a;
//    a.append(in);
//    return a.data();
//}

nmeaparser::GPSData nmeaparser::parseData(QByteArray serial_data)
{
    QString temp = serial_data.data();
    QStringList csvdata = temp.split(",");
    QString ident = csvdata.at(0);
    int count = csvdata.count();
    if(!strcmp("$GPGGA",toCharP(ident)))
    {
//        qDebug() << "GPGGA";
    }
    else   if(!strcmp("$GPRMC",toCharP(ident)))
    {
//        qDebug() << "GPRMC";
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
        dat.time_raw_utc = QString(csvdata.at(1)).toFloat();
        dat.latitude = QString(csvdata.at(3)).toFloat();
        dat.longitude =  QString(csvdata.at(5)).toFloat();
        dat.ground_speed_knots =  QString(csvdata.at(7)).toFloat();
        dat.date_raw =  QString(csvdata.at(9)).toFloat();


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

        QString thours = QString("%1").arg(hours, 2, 10, QChar('0'));
        QString tmins = QString("%1").arg(minutes, 2, 10, QChar('0'));
        QString tsecs = QString("%1").arg(seconds, 2, 10, QChar('0'));

        QString time; time.append(thours)
                .append(":").append(tmins)
                .append(":").append(tsecs)
                .append(" ").append(dat.time_amPM == 0 ? "PM" : "AM");
//        qDebug() << "Time : " <<  time;
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
//        qDebug() << "Date : " <<  date;
        date_formatted = date;
    }
    else   if(!strcmp("$PMTKLOG",toCharP(ident))) // locus status
    {
        qDebug() << "PMTKLOG";
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
    }
    else   if(!strcmp("$PMTK705",toCharP(ident))) // firmware version
    {
//        qDebug() << "PMTK705";
        firmware_version = QString(QString(serial_data).split("_").at(1));
        model_number = QString(QString(serial_data).split("_").at(2)).toInt();

    }
    else if(!strcmp("$PMTKLOX",toCharP(csvdata.at(0))))
    {
        flashData.append(serial_data);
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
            if(locus.current_read == locus.number_of_reads)
            {
                qDebug() << flashData.data();
                QString filename=locus.filename;
                QFile file( filename );
                if ( file.open(QIODevice::ReadWrite) )
                {
                    QTextStream stream( &file );
                    stream << flashData.data();
                }
                file.close();
                QMessageBox msgBox;
                msgBox.setText(QString("Download complete! \n File saved as ").append(parser->locus.filename) );
                msgBox.exec();
            }
        }


    }

}






