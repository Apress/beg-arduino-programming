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

void setup() {
  Wire.begin();
  Serial.begin(9600);
  
  delay(2000);
  Serial.print("The current date and time is: ");
  printTime();
  Serial.println("To set the date and time please select Newline ending to continue.");
  Serial.println("Would you like to set the date and time now? Y/N");
  while (!Serial.available()) delay(10);
  if (Serial.read() == 'y' || Serial.read() == 'Y') {
    Serial.read();
    setTime();
    Serial.print("The current date and time is now: ");
    printTime();
  }
  Serial.println("Goodbye.");
}

void loop() {}

byte decToBcd(byte val) {
  return ((val/10*16) + (val%10));
}

byte bcdToDec(byte val) {
  return ((val/16*10) + (val%16));
}

void setTime() {
  Serial.print("Please enter the current year, 00-99.  -  ");
  year = readByte();
  Serial.println(year);
  Serial.print("Please enter the current month, 1-12.  -  ");
  month = readByte();
  Serial.println(months[month-1]);
  Serial.print("Please enter the current day of the month, 1-31.  -  ");
  monthday = readByte();
  Serial.println(monthday);
  Serial.println("Please enter the current day of the week, 1-7.");
  Serial.print("1 Sun | 2 Mon | 3 Tues | 4 Weds | 5 Thu | 6 Fri | 7 Sat  -  ");
  weekday = readByte();
  Serial.println(days[weekday-1]);
  Serial.print("Please enter the current hour in 24hr format, 0-23.  -  ");
  hour = readByte();
  Serial.println(hour);
  Serial.print("Please enter the current minute, 0-59.  -  ");
  minute = readByte();
  Serial.println(minute);
  second = 0;
  Serial.println("Thank you.");

  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));

  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));

  Wire.write(byte(0));
  Wire.endTransmission();
}

byte readByte() {
  while (!Serial.available()) delay(10);
  byte reading = 0;
  byte incomingByte = Serial.read();
  while (incomingByte != '\n') {
    if (incomingByte >= '0' && incomingByte <= '9') reading = reading * 10 + (incomingByte - '0');
    else;
    incomingByte = Serial.read();
  }
  Serial.flush();
  return reading;
}

void printTime() {
  char buffer[3];
  const char* AMPM = 0;
  
  readTime();
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
