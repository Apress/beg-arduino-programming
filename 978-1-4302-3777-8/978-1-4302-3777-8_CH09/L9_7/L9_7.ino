#include <Stepper.h>

const int steps = 200;
Stepper stepper(steps, 8, 9, 10, 11);
int previous, val;

void setup() {
  stepper.setSpeed(30);
}

void loop() {  
  val = map(analogRead(0), 0, 1024, 0, steps);
  stepper.step(val - previous);
  previous = val;
  delay(20);
}
