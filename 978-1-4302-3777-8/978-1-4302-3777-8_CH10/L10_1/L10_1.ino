#include <Servo.h> 

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach( 10);
}

void loop() {
  int angle = 0;
  if (Serial.available()) {
    byte incomingByte = Serial.read();
    
    while (incomingByte != '\n') {
      if (incomingByte >= '0' && incomingByte <= '9') angle = angle * 10 + (incomingByte - '0');
      incomingByte = Serial.read();
    }
    
    if (angle >= 0 && angle <= 180) {
      servo.write(angle);
      Serial.println(angle);
      
    } else Serial.println("Choose an angle between 0 and 180.");
  }
}
