int analogValue = 0;
int ledPin = 13;

void setup() {                
  pinMode(ledPin, OUTPUT);     
}

void loop() {
  analogValue = analogRead(A0);
  digitalWrite(ledPin, HIGH);
  delay(analogValue);
  digitalWrite(ledPin, LOW);
  delay(analogValue);
}
