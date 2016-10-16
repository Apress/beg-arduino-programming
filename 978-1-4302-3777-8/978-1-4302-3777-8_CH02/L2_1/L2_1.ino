/* Project 1: RGB Blinky
   Uses a single RGB LED to cycle through three colors.
*/

void setup() {  
  pinMode(9, OUTPUT);      // sets digital pins as outputs  
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  digitalWrite(9, HIGH);   // turns on red
  digitalWrite(11, LOW);   // turns off blue
  delay(1000);             // waits for 1 second
  digitalWrite(10, HIGH);  // turns on green
  digitalWrite(9, LOW);    // turns off red
  delay(1000);             // waits for 1 second
  digitalWrite(11, HIGH);  // turns on blue
  digitalWrite(10, LOW);   // turns off green
  delay(1000);             // waits for 1 second
}
