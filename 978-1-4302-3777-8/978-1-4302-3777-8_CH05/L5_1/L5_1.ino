const int speakerPin = 5;
const int sensorPin = 2;

const int highChirp = 20;
const int lowChirp = 14;

const int chirpCycle = 70;
const int chirpPause = 8;
const int numChirps = 10;
const int midChirp = 150;
const int skittish = 5000;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  while (digitalRead(sensorPin) == LOW) {
    for (int i=1; i<=numChirps; i++) {
      
      for (int j=1; j<=highChirp; j++) {
        digitalWrite(speakerPin, HIGH);
        delayMicroseconds(chirpCycle * 10);
        digitalWrite(speakerPin, LOW);
        delayMicroseconds(1000-(chirpCycle * 10));
      }
      
      digitalWrite(speakerPin, LOW);
      
      if (i == numChirps/2) delay(midChirp);
      else delay(lowChirp);
      
    }
    if ((random(chirpPause)) == 1) delay(random(200,1000));
    else delay(midChirp);  }
  delay(skittish);
}
