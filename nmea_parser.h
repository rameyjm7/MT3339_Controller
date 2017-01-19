#ifndef NMEA_PARSER_H
#define NMEA_PARSER_H

#include <QObject>
#include "QDebug"
#include "QString"
#include "QFile"
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
        float time_hours_est;
        float time_amPM; // 0 is am 1 is PM
        float time_minutes;
        float time_seconds;

        float time_zone;
        float date_raw;
        float date_day;
        float date_month;
        float date_year;


        bool automatic=false;           //  1
        int num_satelites=0;
        float ground_speed_knots=0;
        int fix_quality=0;
        float hdop=0,pdop=0,vdop=0; // horizontal dilution of precision, relative accuracty of horizontal position
        float height_from_wgs84=0;
        float checksum=0;
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
    void Show_Locus();
    void Show_GPRMC();
    void Show_Firmware();


    typedef GPSData GPGGA_Data;
    typedef GPSData GPRMC_Data;
    void printData();
    GPSData parseData(QByteArray serial_data);




signals:
    void downloadFinished();
    void pipeParsedData(QString data);
    void SIGNALqueryLocus();
    void updateProgressBar(float progress);
    void appendRed(QString msg);
    void appendBlue(QString msg);
    void appendGreen(QString msg);
    void appendWhite(QString msg);
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
