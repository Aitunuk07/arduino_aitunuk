const int ledPin = 8;
const int sensorPin = 13;
const int buzzerPin = 4;
const int delaytime = 3000;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int sensorState = digitalRead(sensorPin);

  if (sensorState != HIGH) {  
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(delaytime); 
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
}