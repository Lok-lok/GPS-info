#include "GPS.h"

#define TX 7
#define RX 8

GPS gps(TX, RX);

char getEnumHemisphereChar(enum Hemisphere h){
  char c;
  switch (h){
    case UNKNOWN:
      c = 'U';
      break;
    case EAST:
      c = 'E';
      break;
    case SOUTH:
      c = 'S';
      break;
    case WEST:
      c = 'W';
      break;
    case NORTH:
      c = 'N';
      break;
    default:
      c = 'U';
      break;
  }
  return c;
}

void printTime(TimeAndDate time){
  if (time.hour > 24 || time.minute > 60 || time.second > 60)
    Serial.println("Time Not Available");
  else{
    if (time.hour < 10) Serial.print("0");
    Serial.print(time.hour);
    Serial.print(":");
    if (time.minute < 10) Serial.print("0");
    Serial.print(time.minute);
    Serial.print(":");
    if (time.second < 10) Serial.print("0");
    Serial.print(time.second);
    Serial.println();
  }
}

void printDate(TimeAndDate date){
  if (date.day > 31 || date.month > 12 || date.year > 99)
    Serial.println("Date Not Available");
  else{
    if (date.day < 10) Serial.print("0");
    Serial.print(date.day);
    Serial.print("/");
    if (date.month < 10) Serial.print("0");
    Serial.print(date.month);
    Serial.print("/");
    if (date.year < 10) Serial.print("0");
    Serial.print(date.year);
    Serial.println();
  }
}

void printTimeAndDate(TimeAndDate time_and_date){
  if (time_and_date.hour > 24 || time_and_date.minute > 60 || time_and_date.second > 60 || time_and_date.day > 31 || time_and_date.month > 12 || time_and_date.year > 99)
    Serial.println("Time and Date Not Available");
  else{
    if (time_and_date.hour < 10) Serial.print("0");
    Serial.print(time_and_date.hour);
    Serial.print(":");
    if (time_and_date.minute < 10) Serial.print("0");
    Serial.print(time_and_date.minute);
    Serial.print(":");
    if (time_and_date.second < 10) Serial.print("0");
    Serial.print(time_and_date.second);
    Serial.print(" ");
    if (time_and_date.day < 10) Serial.print("0");
    Serial.print(time_and_date.day);
    Serial.print("/");
    if (time_and_date.month < 10) Serial.print("0");
    Serial.print(time_and_date.month);
    Serial.print("/");
    if (time_and_date.year < 10) Serial.print("0");
    Serial.print(time_and_date.year);
    Serial.println();
  }
}

void printLocation(Location loc){
  char n_s = getEnumHemisphereChar(loc.n_s);
  char w_e = getEnumHemisphereChar(loc.w_e);
  if (loc.latitude < 0 || loc.longitude < 0 || n_s == 'U' || w_e == 'U')
    Serial.println("Location Not Available");
  else{
    Serial.print(loc.latitude, 7);
    Serial.print(" ");
    Serial.print(n_s);
    Serial.print(" ");
    Serial.print(loc.longitude, 7);
    Serial.print(" ");
    Serial.print(w_e);
    Serial.println();
  }
}

void setup() {  
  Serial.begin(9600);
  Location loc = gps.getLocation();
  printLocation(loc);
}

void loop() {
  TimeAndDate time_and_date = gps.getTimeAndDate();
  printTimeAndDate(time_and_date);
//  TimeAndDate time_and_date = gps.getTime();
//  printTime(time_and_date);
}
