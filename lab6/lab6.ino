const int buttonPin = 4;
const int ledPin = 5;
const int buzzerPin = 6;
const int potPin = A1;

void setup() {
  pinMode(ledPin, OUTPUT); 
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void ringDoorbell(int duration) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(100);

    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    int potValue = analogRead(potPin);
    int durationMs = map(potValue, 0, 1023, 1000, 5000);
    ringDoorbell(durationMs);

  
    while (digitalRead(buttonPin) == LOW) {
      delay(50);
    }
  }
}