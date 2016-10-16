const int ledPin = 13;

int state = LOW;

unsigned long startTime = 0;
unsigned long interval = 500;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  if (startTime + interval < millis()) {
    state = !state;
    digitalWrite(ledPin, state);
    startTime = millis();
  }
}
