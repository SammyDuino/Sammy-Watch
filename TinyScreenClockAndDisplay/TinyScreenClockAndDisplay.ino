// Project by PacksGamingHD

#define	BLACK           0x00
#define	BLUE            0xE0
#define	RED             0x03
#define	GREEN           0x1C
#define	DGREEN           0x0C
#define YELLOW          0x1F
#define WHITE           0xFF
#define ALPHA           0xFE
#define	BROWN           0x32

  
#include "SSD1331.h"
#include <SPI.h>
#include <Wire.h>
#include "DSRTCLib.h"

#include <avr/power.h>
#include <avr/sleep.h>
SSD1331 display = SSD1331(0);
int ledPin =  13;
int INT_PIN = 3;
int int_number = 1;

DS1339 RTC = DS1339();

void setup(void) {
  Wire.begin();
  display.begin();
  RTC.start();
  display.fontColor(WHITE,BLACK);
  display.setFont(liberationSans_10ptFontInfo);
  display.setCursor(0,50);
  display.print("Sammy");
  display.print(" Watch");
  delay(2000);
}

void loop() {
  unsigned char second;
  unsigned char minute;
  unsigned char hour;
  unsigned char month;
  unsigned char day;
  unsigned int year;
  display.setFont(liberationSans_10ptFontInfo);
  display.fontColor(BLACK,BLACK);
  RTC.readTime();
        second = RTC.getSeconds();
        minute = RTC.getMinutes();
        hour = RTC.getHours();        
        day = RTC.getDays();
        month = RTC.getMonths();        
        year = RTC.getYears();
  display.setFont(liberationSans_10ptFontInfo);
  display.setCursor(0,10);
  display.fontColor(BLUE,BLACK);
  delay(10);
  display.print(day);
  display.print("/");
  display.print(month);
  display.print("/");
  display.print(year);
  display.setCursor(0,30);
  display.fontColor(GREEN,BLACK);
  if (RTC.getHours() < 9)
   {
     display.print("");
     display.print(hour);
   }
   else 
   {
  display.print(hour);
   }
  display.print(":");
  if (RTC.getMinutes() < 10)
   {
     display.fontColor(YELLOW,BLACK);
     display.print("0");
     display.print(minute);
   }
   else 
   {
     display.fontColor(YELLOW,BLACK);
     display.print(minute);
   }
  display.fontColor(GREEN,BLACK);
  display.print(":");
   if (RTC.getSeconds() < 10)
   {
     display.fontColor(RED,BLACK);
     display.print("0");
     display.print(second);
   }
   else 
   {
     display.fontColor(RED,BLACK);
     display.print(second);
   }
}
