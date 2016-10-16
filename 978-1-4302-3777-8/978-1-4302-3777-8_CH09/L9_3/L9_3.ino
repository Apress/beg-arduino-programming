#include <LiquidCrystal.h>
LiquidCrystal lcd(5, 6, 7, 8, 9, 10);

byte fishLeft[8] = {B00000,B00000,B00000,B00000,B01101,B11110,B01101,B00000};
byte fishRight[8] = {B00000,B00000,B00000,B00000,B10110,B01111,B10110,B00000};
byte fishCenter[8] = {B00000,B00000,B00000,B00000,B00100,B01110,B00100,B00000};
byte fishBubbles1[8] = {B00010,B00000,B00100,B00010,B00100,B01110,B00100,B00000};
byte fishBubbles2[8] = {B00000,B00100,B00010,B00000,B00100,B01110,B00100,B00000};
byte fishBubbles3[8] = {B00100,B00000,B00000,B00000,B00100,B01110,B00100,B00000};

byte x = 0;
byte y = 0;

int time = 600;

void setup() {
  lcd.begin(16,2);
  lcd.createChar(0, fishBubbles1);
  lcd.createChar(1, fishBubbles2);
  lcd.createChar(2, fishBubbles3);
  lcd.createChar(3, fishLeft);
  lcd.createChar(4, fishRight);
  lcd.createChar(5, fishCenter);
}

void loop() {
  scrollRight(9);
  stopCenter();
  blowBubbles();
  y = 1;
  x += 1;
  scrollLeft(5);
  stopCenter();
  blowBubbles();
  y=0;
  scrollRight(10);
  delay(time*10);
  x = 0;
  y = 0;
}

void scrollRight(int steps) {
  lcd.setCursor(x, y);
  lcd.write(4);
  delay(time);
  for (int i=0; i<steps; i++) {
    lcd.scrollDisplayRight();
    delay(time);
    x++;
  }
  lcd.clear();
}

void scrollLeft(int steps) {
  lcd.setCursor(x, y);
  lcd.write(3);
  for (int i=0; i<steps; i++) {
    lcd.scrollDisplayLeft();
    delay(time);
    x--;
  }
  lcd.clear();
}

void stopCenter() {
  lcd.setCursor(x, y);
  lcd.write(5);
  delay(time);
  lcd.clear();
}

void blowBubbles() {
  for (int i=0; i<3; i++) {
    lcd.setCursor(x, y);
    lcd.write(i);
    delay(time);
  }
  lcd.clear();
}
