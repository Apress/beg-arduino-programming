#include <Wire.h>

const int blinkM = 0x09;
const int buttonInterrupt = 0;
const int analogIn = A0;

int hue=0, saturation=0, brightness=0;

volatile int i = 0;

void setup() {                
  Wire.begin();
  stopScript(blinkM);
  setFadeSpeed(blinkM, 15);
  attachInterrupt(buttonInterrupt, selectHSB, RISING);
}

void loop() {
  switch (i) {
    case 0:
      hue = map(analogRead(analogIn), 0, 1024, 0, 255);
      fadeToHSB(blinkM, hue, 255, 255);
      break;
    case 1:
      saturation = map(analogRead(analogIn), 0, 1024, 0, 255);
      fadeToHSB(blinkM, hue, saturation, 255);
      break;
    case 2:
      brightness = map(analogRead(analogIn), 0, 1024, 0, 255);
      fadeToHSB(blinkM, hue, saturation, brightness);
  }
  delay(50);  
}

void selectHSB() {
  i = (i+1)%4;
}

void stopScript(byte address) {
  Wire.beginTransmission(address);
  Wire.write('o');
  Wire.endTransmission();
}

void setFadeSpeed(byte address, byte fadespeed) {
  Wire.beginTransmission(address);
  Wire.write('f');
  Wire.write(fadespeed);
  Wire.endTransmission();  
}

void fadeToHSB(byte address, byte hue, byte saturation, byte brightness) {
  Wire.beginTransmission(address);
  Wire.write('h');
  Wire.write(hue);
  Wire.write(saturation);
  Wire.write(brightness);
  Wire.endTransmission();
}

