#include <SD.h>

File file;

const int interval = 10;   // time in milliseconds
const int LED = 9;
const int SDcs = 4;

byte oldValue = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);
  
  if (!SD.begin(SDcs)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

void loop() {
  Serial.println("Reading from data.txt. ");
  file = SD.open("data.txt");
  if (file) {
    while (file.available()) {
      byte value = file.read();    
      
      if (oldValue < value) {
        for (byte i=oldValue;  i<value; i++) {
          analogWrite(LED, i);
          delay(interval);
        }
      } else {
        for (byte i=oldValue;  i>value; i--) {
          analogWrite(LED, i);
          delay(interval);
        }
      }
      oldValue = value;
    }
    file.close();
    Serial.println("File closed.");
  } else {
    Serial.println("Error opening data.txt.");
  }
}
