int ledPin = 11;
int flicker[] = {64, 22, 4, 28, 6, 130, 186, 120};
int i = 0;

void setup() {
  randomSeed(analogRead(A5));
}

void loop() {
  analogWrite(ledPin, flicker[i]);
  delay(random(100, 500));
  i++;
  if (i == (sizeof(flicker)/2)) i = 0;
}
