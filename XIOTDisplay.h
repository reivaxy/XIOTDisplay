
#pragma once
#include "XOLEDDisplay.h"

#define BLINKING true
#define NOT_BLINKING false
#define TRANSIENT true
#define NOT_TRANSIENT false
#define COPY_SERIAL true
#define NOT_COPY_SERIAL false

#define BLANK_ICON 65 // move this to xoled lib ?

enum WifiType { AP, STA, AP_STA };

class DisplayClass:public XOLEDDisplayClass {
public:
  DisplayClass(SSD1306* display, bool flipScreen = true, uint8_t brightness = 100);
  DisplayClass(int addr, int sda, int scl, bool flipScreen = true, uint8_t brightness = 100);
  void init();
  void hideDateTime(bool);
  void batteryIcon(bool blink);
  void clockIcon(bool blink);
  void emptyBatteryIcon(bool blink);
  void alertIconOn(bool blink);
  void alertIconOff();
  void wifiIcon(bool blink, WifiType type);
  void gsmIcon(bool blink);
  void roamingIcon(bool blink);
  void refreshDateTime(const char *dateTime);
  void blinkDateTime(bool blink);
  void setLine(int offset, const char *text);
  void setLine(int offset, const char *text, bool transient, bool blink);
  void setLine(int offset, const char *text, bool transient, bool blink, bool toSerial);
  
  bool _hideDateTime = false;
};
