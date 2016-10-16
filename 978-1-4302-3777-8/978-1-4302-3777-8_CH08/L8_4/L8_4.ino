int ledPin = 13;
int time = 1000;

void setup() {                
  pinMode(ledPin, OUTPUT);  
  Serial.begin(9600);
  Serial.println("\n[memCheck]");
  Serial.println(freeRAM(), DEC);  
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(time);
  digitalWrite(ledPin, LOW);
  delay(time);
}

int freeRAM() {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
