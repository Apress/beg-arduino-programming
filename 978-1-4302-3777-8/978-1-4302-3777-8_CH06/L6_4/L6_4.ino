const int analogPin = A0;
int analogValue = 0;

void setup() {                
  Serial.begin(9600);    
}

void loop() {
  analogValue = analogRead(analogPin);
  Serial.print("analog value = " );                       
  Serial.println(analogValue, DEC);
  delay(125); 
}
