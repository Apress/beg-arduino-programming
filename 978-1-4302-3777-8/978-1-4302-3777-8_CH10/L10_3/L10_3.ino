#include <Wire.h>

const int DS1307 = 0x68;

const char* days[] = 
  {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char* months[] = 
  {"January", "February", "March", "April", "May", "June", "July", "August", 
   "September", "October", "November", "December"};

byte second = 0;
byte minute = 0;
byte hour = 0;
byte weekday = 0;
byte monthday = 0;
byte month = 0;
byte year = 0;

byte lastMinute = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  readTime();
  if (minute != lastMinute) {
    printTime();
    lastMinute = minute;
  }
}

byte bcdToDec(byte val) {
  return ((val/16*10) + (val%16));
}

void printTime() {
  char buffer[3];
  const char* AMPM = 0;

  Serial.print(days[weekday-1]);
  Serial.print(" ");
  Serial.print(months[month-1]);
  Serial.print(" ");
  Serial.print(monthday);
  Serial.print(", 20");
  Serial.print(year);
  Serial.print(" ");
  
  if (hour > 12) {
    hour -= 12;
    AMPM = " PM";
  } else AMPM = " AM";
  
  Serial.print(hour);
  Serial.print(":");
  
  sprintf(buffer, "%02d", minute);
  Serial.print(buffer);
  Serial.println(AMPM);
}

void readTime() {
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.endTransmission();

  Wire.requestFrom(DS1307, 7);

  second = bcdToDec(Wire.read());
  minute = bcdToDec(Wire.read());
  hour = bcdToDec(Wire.read());
  weekday = bcdToDec(Wire.read());
  monthday = bcdToDec(Wire.read());
  month = bcdToDec(Wire.read());
  year = bcdToDec(Wire.read());
}
