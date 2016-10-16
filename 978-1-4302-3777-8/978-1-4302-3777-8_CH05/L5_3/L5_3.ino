const int switchPin = 2;
const int ledPin = 13;

int state;
int lastState;

int buttonCounter = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  state = digitalRead(switchPin);
  if (state != lastState) {
    if (state == HIGH) {
      buttonCounter++;
    }
    lastState = state;
  }
  if (buttonCounter % 5 == 0) {
    digitalWrite(ledPin, HIGH);
    delay(20);
  } else digitalWrite(ledPin, LOW);
}
