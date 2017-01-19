#ifndef PMTKCOMMANDS_H
#define PMTKCOMMANDS_H
#include "QString"
#define PMTK_SET_NMEA_UPDATE_100_MILLIHERTZ  "$PMTK220,10000*2F" // Once every 10 seconds, 100 millihertz.
#define PMTK_SET_NMEA_UPDATE_200_MILLIHERTZ  "$PMTK220,5000*1B"  // Once every 5 seconds, 200 millihertz.
#define PMTK_SET_NMEA_UPDATE_1HZ  "$PMTK220,1000*1F"
#define PMTK_SET_NMEA_UPDATE_5HZ  "$PMTK220,200*2C"

#define PMTK_SET_NMEA_UPDATE_10HZ "$PMTK220,100*2F"
    // Position fix update rate commands.
#define PMTK_API_SET_FIX_CTL_100_MILLIHERTZ  "$PMTK300,10000,0,0,0,0*2C" // Once every 10 seconds, 100 millihertz.
#define PMTK_API_SET_FIX_CTL_200_MILLIHERTZ  "$PMTK300,5000,0,0,0,0*18"  // Once every 5 seconds, 200 millihertz.
#define PMTK_API_SET_FIX_CTL_1HZ  "$PMTK300,1000,0,0,0,0*1C"
#define PMTK_API_SET_FIX_CTL_5HZ  "$PMTK300,200,0,0,0,0*2F"
    // Can't fix position faster than 5 times a second!

#define PMTK_SET_BAUD_57600 "$PMTK251,57600*2C"
#define PMTK_SET_BAUD_9600 "$PMTK251,9600*17"
#define PMTK_SET_BAUD_115200 "$PMTK251,115200*1F"
#define PMTK_SET_BAUD_38400 "$PMTK251,38400*27"
#define PMTK_SET_BAUD_19200 "$PMTK251,19200*22"
#define PMTK_SET_BAUD_14400 "$PMTK251,14400*29"
#define PMTK_SET_BAUD_4800 "$PMTK251,4800*14"

QString locus_start = "$PMTK185,0*22";
QString locus_stop = "$PMTK185,1*23";
QString locus_querystatus = "$PMTK183*38";
QString locus_downloaddata = "$PMTK622,1*29";
QString locus_flasherase = "$PMTK184,1*22";
QString locus_alwayslocateON = "$PMTK255,8*23";
QString locus_alwayslocateOFF = "$PMTK255,0*2B";
QString locus_interval_5s = "$PMTK187,1,5*38";

QString locus_interval_1s = "$PMTK187,1,1*18";
QString locus_interval_10s = "$PMTK187,1,10*0C";
QString locus_interval_15s = "$PMTK187,1,15*09";
QString locus_interval_30s = "$PMTK187,1,30*0E";
QString locus_interval_60s = "$PMTK187,1,60*0B";

QString locus_powersaveset = "$PMTK161,0*28";
QString locus_easyON = "$PMTK869,1,1*35";
QString locus_easyOFF = "$PMTK869,1,1*34";
QString locus_easyQUERY = "$PMTK869,0*29";
QString coldstart = "$PMTK102*31";
QString warmstart = "$PMTK103*30";
QString hotstart = "$PMTK101*32";
QString factoryrestart = "$PMTK102*31";


    // turn on only the second sentence (GPRMC)
#define PMTK_SET_NMEA_OUTPUT_RMCONLY "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29"
    // turn on GPRMC and GGA
#define PMTK_SET_NMEA_OUTPUT_RMCGGA "$PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28"
    // turn on ALL THE DATA
#define PMTK_SET_NMEA_OUTPUT_ALLDATA "$PMTK314,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0*28"
    // turn off output
#define PMTK_SET_NMEA_OUTPUT_OFF "$PMTK314,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28"

    // to generate your own sentences, check out the MTK command datasheet and use a checksum calculator
    // such as the awesome http://www.hhhh.org/wiml/proj/nmeaxor.html

#define PMTK_LOCUS_STARTLOG  "$PMTK185,0*22"
#define PMTK_LOCUS_STOPLOG "$PMTK185,1*23"
#define PMTK_LOCUS_STARTSTOPACK "$PMTK001,185,3*3C"
#define PMTK_LOCUS_QUERY_STATUS "$PMTK183*38"
#define PMTK_LOCUS_ERASE_FLASH "$PMTK184,1*22"
#define LOCUS_OVERLAP 0
#define LOCUS_FULLSTOP 1

#define PMTK_ENABLE_SBAS "$PMTK313,1*2E"
#define PMTK_ENABLE_WAAS "$PMTK301,2*2E"

    // standby command & boot successful message
#define PMTK_STANDBY "$PMTK161,0*28"
#define PMTK_STANDBY_SUCCESS "$PMTK001,161,3*36"  // Not needed currently
#define PMTK_AWAKE "$PMTK010,002*2D"

    // ask for the release and version
#define PMTK_Q_RELEASE "$PMTK605*31"

    // request for updates on antenna status
#define PGCMD_ANTENNA "$PGCMD,33,1*6C"
#define PGCMD_NOANTENNA "$PGCMD,33,0*6D"

    // how long to wait when we're looking for a response
#define MAXWAITSENTENCE 5


#endif // PMTKCOMMANDS_H

