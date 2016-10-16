#include <Servo.h> 
 
Servo leftServo;
Servo rightServo;

void setup() {
  leftServo.attach(10);
  rightServo.attach(9);
}

void loop() {
  for (int angle=0; angle<180; angle+=2) {
    leftServo.write(angle);
    rightServo.write(180-angle);
    delay(20);
  }
  for (int angle=180; angle>0; angle-=2) {
    leftServo.write(angle);
    rightServo.write(180-angle);
    delay(20);
  }
}
