#include <SD.h>

File file;

const long runningTime = 5;  // time in minutes
const long msMin = 60000;    // milliseconds in 1 minute
const int interval = 2000;   // time in milliseconds

const int sensorMin = 30;
const int sensorMax = 1000;
const int sensor = A0;
const int SDcs = 4;

void setup() {
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);
  
  if (!SD.begin(SDcs)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  file = SD.open("data.txt", FILE_WRITE);
  
  if (file) {
    while (millis() < (runningTime * msMin)) {
      byte value = map(analogRead(sensor), sensorMin, sensorMax, 0, 255);
      
      Serial.print("Writing ");
      Serial.print(value, DEC);
      Serial.print(" to data.txt... ");
      file.write(value);
      Serial.println("done.");
      delay(interval);
    }
    file.close();
    Serial.println("File closed.");
  } else {
    Serial.println("Error opening data.txt.");
  }
}

void loop() {}
