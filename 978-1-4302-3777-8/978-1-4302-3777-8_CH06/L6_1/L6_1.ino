const int fanPin = 5;
const int sensorPin = A0;

const int minReading = 25;
const int maxReading = 400;
const int fanStart = 100;

int analogValue = 0;

void setup() { 
  Serial.begin(9600);  
}

void loop() {
  analogValue = analogRead(sensorPin);
  analogValue = constrain(analogValue, minReading, maxReading);
  analogValue = map(analogValue, minReading, maxReading, 0, 255);
  
  Serial.print("analog value = " );                       
  Serial.println(analogValue, DEC);
  
  if ((analogValue > minReading) && (analogValue < fanStart)) 
  analogWrite(fanPin, fanStart);
  else analogWrite(fanPin, analogValue);
  
  delay(250);
}
