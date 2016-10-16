const int switchPin = 2;
const int ledPin = 13;

int state;
int lastState;
int ledState;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  state = digitalRead(switchPin);
  if (state != lastState) {
    if (state == HIGH) {
      if (ledState == HIGH) ledState = LOW;
      else ledState = HIGH;
    }
    lastState = state;
  }
  digitalWrite(ledPin, ledState);
  delay(20);
}
