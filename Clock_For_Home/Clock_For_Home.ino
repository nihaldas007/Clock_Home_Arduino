
#include <Wire.h>
#include "RTClib.h"
#include <SPI.h>       
#include <DMD.h>    
#include <TimerOne.h>  
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#include "Font_12x5.h" //-> This font only contains numbers from 0-9
#define DISPLAYS_ACROSS 1 //-> Number of P10 panels used, side to side.
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);
RTC_DS1307 rtc; //-> RTC Declaration
int _day, _month, _year, _hour24, _hour12, _minute, _second, _dtw;
int hr24;
int timeScroll = 150;
String st;
char nameoftheday[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char month_name[12][12] = {"January","February", "March", "April", "May", "June", "Jult", "August", "September", "October", "November", "December"};
const long interval = 1000; //-> Retrieve time and date data every 1 second
unsigned long previousMillis = 0;
const long interval_for_date = 50; //-> For scroll speed
unsigned long previousMillis_for_date = 0;
char hr_24 [3];
String str_hr_24;
char mn [3];
String str_mn;
void ScanDMD() { 
  dmd.scanDisplayBySPI();
}


void setup() {
  Serial.begin(9600);
  Serial.println("Arduino RTC DS1307");
  delay(1000);
  
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled (Set the time and date based on your computer time and date)
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //-> Set the time and date based on your computer time and date. If that doesn't work, use this line of code outside of "if (! rtc.isrunning())"
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  // following line sets the RTC to the date & time this sketch was compiled (Set the time and date based on your computer time and date)
//  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //-> Set the time and date based on your computer time and date. Use this line of code if it doesn't work in "if (! rtc.isrunning())"
//  rtc.adjust(DateTime(2021, 1, 21, 0, 0, 0));
  // If the time and date are successfully set, then deactivate the code line (make the code a comment), then re-upload the code.
  // if not done then the time and date will return to the beginning when it was set when arduino is reset or restarted.

  Timer1.initialize(1000);          
  Timer1.attachInterrupt(ScanDMD);  
  dmd.clearScreen(true);  
}

void loop() {
  
Clock();
 
}
