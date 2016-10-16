#include <Wire.h>

const int blinkM = 0x09;
const int temperaturePin = A0;

const boolean degreesF = true;

const int hot = 100;
const int cold = 40;
const int hotColor = 0;
const int coldColor = 170;
const int brightness = 255;

void setup() {
  Wire.begin();
  stopScript(blinkM);
  setFadeSpeed(blinkM, 1);
}

void loop() {
  int hue = map(temperature(), hot, cold, hotColor, coldColor);
  hue = constrain(hue, hotColor, coldColor);
  fadeToHSB(blinkM, hue, 255, brightness);
  delay(10000);
}

float temperature() {
  float voltage = (analogRead(temperaturePin) / 1024.0) * 5.0;
  float celsius = (voltage - 0.5) * 100.0;
  float fahrenheit = (celsius * 1.8) + 32.0;
  if (degreesF == true) return fahrenheit;
  else return celsius;
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
