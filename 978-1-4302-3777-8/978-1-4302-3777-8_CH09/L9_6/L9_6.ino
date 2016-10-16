#include <Stepper.h>

const int steps = 200;
Stepper stepper(steps, 8, 9, 10, 11);

int stepDirection = 3;
int counter = 0;

void setup() {
  stepper.setSpeed(30);
}

void loop() {
  stepper.step(stepDirection);
  delay(909);
  counter+=3;
  if (counter > steps) {
    counter = 0;
    if (stepDirection == 3) stepDirection = -3;
    else stepDirection = 3;
  }
}
