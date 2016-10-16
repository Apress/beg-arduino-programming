#include <Servo.h> 
 
Servo servo;

unsigned long startTime = 0;
unsigned long interval = 600000;

void setup() {
  servo.attach(10);
  servo.write(90);
}

void loop() {
  if (startTime + interval < millis()) {
    servo.write(96);
    delay(90);
    servo.write(90);
    startTime = millis();
  }
}
