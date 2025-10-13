const int LDR_PIN = A0;
const int POT_PIN = A1;
const int LED_PIN = 9;
const int BUZZ_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(POT_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(LDR_PIN);    
  int threshold = analogRead(POT_PIN);

  Serial.print("Light: ");
  Serial.print(light);
  Serial.print("  Threshold: ");
  Serial.println(threshold);

  if (light < threshold) {
    digitalWrite(LED_PIN, HIGH);    
    digitalWrite(BUZZ_PIN, HIGH); 
    
  } else {
    digitalWrite(LED_PIN, LOW);     
    digitalWrite(BUZZ_PIN, LOW);  
  }

  delay(100);
}
