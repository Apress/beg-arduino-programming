#include <LiquidCrystal.h>
LiquidCrystal lcd(5, 6, 7, 8, 9, 10);

byte degree = B11011111;
byte cents = B11101100;
byte sqRoot = B11101000;
byte divide = B11111101;
byte pi = B11110111;
byte omega = B11110100;
byte rgtArrow = B01111110;
byte lftArrow = B01111111;

byte symbols[] = {degree, cents, sqRoot, divide, pi, omega, rgtArrow, lftArrow};

byte smiley[] = {B00000,B00000,B01010,B00000,B10001,B01110,B00000,B00000};
byte skull[] = {B00000,B01110,B10101,B11011,B01110,B01110,B00000,B00000};
byte bell[] = {B00000,B00100,B01110,B01110,B01110,B11111,B00100,B00000};
byte note[] = {B00000,B00100,B00110,B00101,B00101,B01100,B01100,B00000};
byte heart[] = {B00000,B00000,B01010,B11111,B11111,B01110,B00100,B00000};
byte fish[] = {B10000,B00000,B01000,B10000,B01101,B11110,B01101,B00000};
byte lock[] = {B00000,B01110,B10001,B10001,B11111,B11011,B11011,B11111};
byte unlock[] = {B00000,B01110,B10001,B10000,B11111,B11011,B11011,B11111};

byte* characters[] = {smiley, skull, bell, note, heart, fish, lock, unlock};

void setup() {
  lcd.begin(16, 2);

  for (int i=0; i<8; i++) {
    lcd.setCursor((i*2),0);
    lcd.write(symbols[i]);

    lcd.createChar(i, ((byte*)characters[i]));
    lcd.setCursor((i*2),1);
    lcd.write(i);
  } 
}

void loop() {}
