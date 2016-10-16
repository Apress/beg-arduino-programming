#include <EEPROM.h>

boolean writeEEPROM = true;

int ledPin = 11;
byte flicker[] = {64, 22, 4, 28, 6, 130, 186, 120};
int i = 0;

void setup() {
  randomSeed(analogRead(A5));
  if (writeEEPROM == true) 
    for (int i=0; i<(sizeof(flicker)/2); i++)
      EEPROM.write(i, flicker[i]); 
  i = 0;
}

void loop() {
  analogWrite(ledPin, EEPROM.read(i));
  delay(random(100, 500));
  i++;
  if (i == (sizeof(flicker)/2)) i = 0;
}
