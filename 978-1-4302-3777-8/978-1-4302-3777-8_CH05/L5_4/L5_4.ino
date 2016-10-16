const int switchPin = 2;
const int ledPin = 13;

int state = 0;
int lastState = 0;
int buttonCounter = 0;

unsigned long startTime = 0;
unsigned long interval = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  state = digitalRead(switchPin);
  if(state != lastState) {
    if (state == HIGH) {
      buttonCounter++;
      startTime = millis();
    }
  }
  lastState = state;
  
  if(startTime + interval < millis()) {

    switch (buttonCounter) {
    case 1:
      digitalWrite(ledPin, HIGH);
      delay(interval);
      digitalWrite(ledPin, LOW);
      delay(interval);
      break;
    case 2:
      for (int i=0; i<2; i++) {
        digitalWrite(ledPin, HIGH);
        delay(interval/2);
        digitalWrite(ledPin, LOW);
        delay(interval/2);
      }
      break;
    case 3:
      for (int i=0; i<3; i++) {
        digitalWrite(ledPin, HIGH);
        delay(interval/3);
        digitalWrite(ledPin, LOW);
        delay(interval/3);
      }
      break;
    case 4:
      for (int i=0; i<4; i++) {
        digitalWrite(ledPin, HIGH);
        delay(interval/4);
        digitalWrite(ledPin, LOW);
        delay(interval/4);
      }
    }
    buttonCounter = 0;
  }
  delay(20);
}
