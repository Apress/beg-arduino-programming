int analogValue = 0;
int ledPin = 5;

void setup() {                
}

void loop() {
  analogValue = analogRead(A0) / 4;
  analogWrite(ledPin, analogValue);
  delay(20);
}
