int ledRed = 11;
int pot = A0;
int button = 5;
int mode = 0;
bool lastButtonState = HIGH;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(A1, INPUT);
}

void loop() {
  bool buttonState = digitalRead(button);

  if (lastButtonState == HIGH && buttonState == LOW) {
    mode = 1 - mode;
    delay(200);
  }
  lastButtonState = buttonState;

  if (mode == 0) {
    int val = analogRead(pot);
    val = val / 4;   
    analogWrite(ledRed, val);
  } else {
    analogWrite(ledRed, brightness);

    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    delay(30);
  }
}