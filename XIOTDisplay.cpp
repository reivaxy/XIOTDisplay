
#include "XIOTDisplay.h"

DisplayClass::DisplayClass(SSD1306* display, bool flipScreen, uint8_t brightness):XOLEDDisplayClass(display, flipScreen, brightness) {
  init();
}
DisplayClass::DisplayClass(int addr, int sda, int scl, bool flipScreen, uint8_t brightness):XOLEDDisplayClass(addr, sda, scl, flipScreen, brightness) {
  init();
}

void DisplayClass::init() {
  XOLEDDisplayClass::resetLinesAndIcons();
  setTransientDuration(1, 3000);
  setTransientDuration(2, 3000);
  setLineAlignment(4, TEXT_ALIGN_RIGHT);
}

void DisplayClass::batteryIcon(bool blink) {
  setIcon(0, 66, blink);
}
void DisplayClass::clockIcon(bool blink) {
  setIcon(0, 75, blink);
}
void DisplayClass::emptyBatteryIcon(bool blink) {
  setIcon(0, 70, blink);
}
void DisplayClass::alertIconOn(bool blink) {
  setIcon(1, 71, blink);
}
void DisplayClass::alertIconOff() {
  setIcon(1, 32);
}
void DisplayClass::wifiIcon(bool blink, WifiType type) {
  char icon = 72;
  switch(type) {
    case AP  : 
      icon = 76;
      break;
    case AP_STA : 
      icon = 77;
      break;
    case STA:
      icon = 78;
      break;
  }
  setIcon(3, icon, blink);
}
void DisplayClass::gsmIcon(bool blink) {
  setIcon(2, 74, blink);
}
void DisplayClass::roamingIcon(bool blink) {
  setIcon(2, 73, blink);
}
void DisplayClass::refreshDateTime(const char* dateTime) {
  // If icon 0 is showing the clock, delete it.
  if (getIconChar(0) == 75) {
    setIcon(0, BLANK_ICON); // Hide clock icon
  }
  if(!_hideDateTime) {
    setLine(4, dateTime, false, false);  // Display time not blinking
  }
}

void DisplayClass::blinkDateTime(bool blink) {
  blinkLine(4, true); // blink time
}

void DisplayClass::setLine(int offset, const char *text) {
  if(offset == 1) {
    Serial.println(text);
  }
  XOLEDDisplayClass::setLine(offset, text);
}
void DisplayClass::setLine(int offset, const char *text, bool transient, bool blink) {
  // line 4 contains the date/time, refreshed every second...
  if((offset < 4) && (strlen(text) > 0)) {
    Serial.println(text);
  }
  XOLEDDisplayClass::setLine(offset, text, transient, blink);
//  refresh();
}
 
void DisplayClass::hideDateTime(bool flag) {
  _hideDateTime = flag;
} 