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
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
  uint8_t day;
  uint8_t month;
  uint8_t year;
};

struct Location{
    enum Hemisphere n_s;
    enum Hemisphere w_e;
    float latitude;
    float longitude;
};

class GPS{
    private:
        uint8_t TX;
        uint8_t RX;
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
        GPS(uint8_t TXD, uint8_t RXD);
        ~GPS();
        uint8_t getTXDPin();
        uint8_t getRXDPin();
        TimeAndDate getTime();
        TimeAndDate getDate();
        TimeAndDate getTimeAndDate();
        Location getLocation();
};

#endif
