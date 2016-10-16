#include <LiquidCrystal.h>

char* allAnswers[] = {
"  As I see it,  ",
"      yes       ",

"     It is      ", 
"    certain     ",

"     It is      ",
"  decidedly so  ",

"     Most       ",
"    likely      ",

"    Outlook     ",
"     good       ",

"  Signs point   ",
"    to yes      ",

"    Without     ", 
"    a doubt     ",

"      Yes       ",
"                ",

"      Yes -     ",
"   definitely   ",

"    You may     ",
"   rely on it   ",

"  Reply hazy,   ",
"   try again    ",

"   Ask again    ",
"     later      ",

"   Better not   ",
"  tell you now  ",

"     Cannot     ",
"  predict now   ",

"  Concentrate   ",
" and ask again  ",

"  Don't count   ",
"     on it      ",

"    My reply    ",
"     is no      ",

"   My sources   ",
"     say no     ",

"  Outlook not   ",
"    so good     ",

"      Very      ",
"    doubtful    "   };

LiquidCrystal lcd(5, 6, 7, 8, 9, 10);

const int backlight = 11;
const int axisPin[] = {A0, A1, A2};

const int threshold = 60;
const int brightness = 175;

int axis[3];
int oldAxis[3];

void setup() {
  lcd.begin(16, 2);
  randomSeed(analogRead(A5));
  getReading();
  oldReading();
}

void loop() {
  getReading();
  if (abs(axis[0]-oldAxis[0]) > threshold ||
      abs(axis[1]-oldAxis[1]) > threshold ||
      abs(axis[2]-oldAxis[2]) > threshold) {
    getAnswer();
    delay(500);
    getReading();
    oldReading();
  }
  delay(125);
}

void getReading() {
  for (int i=0; i<3; i++) axis[i] = analogRead(axisPin[i]);
}

void oldReading() {
  for (int i=0; i<3; i++) oldAxis[i] = axis[i];
}

void getAnswer() {
  int thisAnswer = random(40);
  while (thisAnswer % 2 != 0) thisAnswer = random(40);
    
  lcd.setCursor(0, 0);
  lcd.print(allAnswers[thisAnswer]);
  lcd.setCursor(0, 1);
  lcd.print(allAnswers[thisAnswer+1]);
    
  for (int i=0; i<=150; i++) {
    analogWrite(backLight, i);
    delay(30);
  }
  for (int i=150; i>=0; i--) {
    analogWrite(backLight, i);
    delay(30);
  }
  lcd.clear();
}
