#ifndef NMEA_PARSER_H
#define NMEA_PARSER_H

#include <QObject>
#include "QDebug"
#include "QString"
class nmea_parser : public
        QObject
{
    Q_OBJECT
public:
    QString date_formatted;
    QString time_formatted;
    QString firmware_version;

    int model_number;
    QByteArray flashData;
    nmea_parser(QObject * parent = 0);
    char * toCharP(QString a)
    {
        QByteArray ba;
        ba.append(a);
        return ba.data();
    }
    struct GPSData
    {

        float latitude;
        int lat_NS; // north is 0, south is 1
        float longitude;
        int long_WE; // west is 0, east is 1

        float altitude;
        float time_zone_correction = -5;
        float time_raw_utc;
        float time_hours_utc;
        float time_amPM; // 0 is am 1 is PM
        float time_minutes_utc;
        float time_seconds_utc;
        float time_hours_est;
        float time_minutes_est;
        float time_seconds_est;
        float time_zone;
        float date_raw;
        float date_day;
        float date_month;
        float date_year;



        int num_satelites;
        float ground_speed_knots;
        int fix_quality;
        float hdop; // horizontal dilution of precision, relative accuracty of horizontal position
        float height_from_wgs84;
        float checksum;
    };
    GPSData dat;

    struct LOCUSStatus
    {
        //        $PMTKLOG, Serial#, Type, Mode, Content, Interval, Distance, Speed, Status, Number,

        int serial_no;
        int type; // interval or no
        int mode;
        int content;
        int interval; // secs/log
        int distance;
        int speed;
        int status; // 0 logging 1 not logging
        int number; // of logs
        int percent; // used space
        int number_of_reads=1;
        int current_read=0;
        QString filename = "data.txt"; // for saving flash data
    };
    LOCUSStatus locus;
    void Show_Locus()
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
    void Show_GPRMC()
    {
        qDebug() << "Time       : " << time_formatted;
        qDebug() << "Latitude   : " << dat.latitude;
        qDebug() << "Longitude  : " << dat.longitude;
        qDebug() << "Speed      : " << dat.ground_speed_knots;
        qDebug() << "Date Raw   : " << dat.date_raw;

    }
    void Show_Firmware()
    {
        qDebug() << "Firmware : " << firmware_version;
        qDebug() << "Model No : " << model_number;
    }


    typedef GPSData GPGGA_Data;
    typedef GPSData GPRMC_Data;
    void printData()
    {
        qDebug() << "Time UTC: " << dat.time_raw_utc;
        qDebug() << "Latitude: " << dat.latitude;
        qDebug() << "Longitude: " << dat.longitude;
        qDebug() << "Altitude: " << dat.altitude;
        qDebug() << "Num Satelites: " << dat.num_satelites;
        qDebug() << "Health: " << dat.fix_quality;

    }
    GPSData parseData(QByteArray serial_data);
signals:
    void downloadFinished();
};




//LOCUS data format and size as follows:
//UTC: 4 bytes
//Fix: 1 byte
//Lat: 4 bytes
//Lon: 4 bytes
//Alt: 2 bytes
//Spd: 2 bytes
//Sat: 2 bytes
//Cks: 1 byte


//<?xml version="1.0"?>
//<dataset2 xmlns="xsdbooks">
//        <Count Data="1">
//              <UTC>2017-01-03,00:01:32</UTC>
//              <FixType>3D-fix</FixType>
//              <Lat>37.541267</Lat>
//              <Lon>-77.524765</Lon>
//              <HGT>72</HGT>
//        </Count>
//</dataset2>




#endif // NMEA_PARSER_H
