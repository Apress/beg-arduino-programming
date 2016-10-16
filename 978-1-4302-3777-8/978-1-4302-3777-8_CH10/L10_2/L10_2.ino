#include <SoftwareSerial.h>

SoftwareSerial rfid(2,3);

char tag01[] = "4500B8F08489";
char tag02[] = "4500B8D36947";

char tagString[13];

void setup() {
  Serial.begin(9600);
  rfid.begin(9600);
}

void loop() {
  if (rfid.available()) {
    if (getTag()) printTag();
  }
}

boolean getTag() {
  char startByte = rfid.read();
  delay(20);
    
  if (startByte == 2) {
    int index = 0;
    while (index < 12) {
      char incomingByte = rfid.read();

      tagString[index] = incomingByte;   
      index++;
    }
  }
  rfid.flush();
  return true;
}

void printTag() {    
  for (int i=0; i<12; i++) Serial.print(tagString[i]);
  Serial.println(compareTags());
}

const char* compareTags() {
  if (strncmp(tag01, tagString, 12) == 0) return " Tag 1";
  else if (strncmp(tag02, tagString, 12) == 0) return " Tag 2";
  else return " Not recognized.";
}
