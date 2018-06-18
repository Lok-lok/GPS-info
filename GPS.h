// Author: Lok

#ifndef _GPS_H_
#define _GPS_H_

#include "Arduino.h"
#include <SoftwareSerial.h>

enum Hemisphere{
    UNKNOWN,
    EAST,
    SOUTH,
    WEST,
    NORTH,
};

struct TimeAndDate{
  byte hour;
  byte minute;
  byte second;
  byte day;
  byte month;
  byte year;
};

struct Location{
    enum Hemisphere n_s;
    enum Hemisphere w_e;
    float latitude;
    float longitude;
};

class GPS{
    private:
        byte TX;
        byte RX;
        bool is_software_serial;
        SoftwareSerial *SWSerial;
        bool waitForNextCharAvailable();
        char getNextChar();
        bool correctPrefix(char prefix[]);
        bool skipCommas(int number);
        char* getSixChars();
        float getLatitudeOrLongitude();
        
    public:
        GPS();
        GPS(byte TXD, byte RXD);
        ~GPS();
        byte getTXDPin();
        byte getRXDPin();
        TimeAndDate getTime();
        TimeAndDate getDate();
        TimeAndDate getTimeAndDate();
        Location getLocation();
};

#endif
