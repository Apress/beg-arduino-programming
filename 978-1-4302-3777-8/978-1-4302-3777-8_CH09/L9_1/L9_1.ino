#include <LiquidCrystal.h>
LiquidCrystal lcd(5, 6, 7, 8, 9, 10);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.print("All I want");
  lcd.setCursor(0,1);
  lcd.print("to be,");
  delay(5000);
  
  lcd.clear();
  lcd.print("is someone that");
  lcd.setCursor(0,1);
  lcd.print("makes new things");
  delay(5000);
  
  lcd.clear();
  lcd.print("And thinks");
  lcd.setCursor(0,1);
  lcd.print("about them.");
  delay(5000);
  
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("- John Maeda");
  delay(5000);
  
  lcd.clear();
  delay(5000);
}
