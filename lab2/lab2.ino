const int ledRed = 4;
const int ledYellow = 6;
const int ledGreen = 2;


const int buttonStart = 12;
const int buttonStop  = 11;

void setup() {
  
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  pinMode(buttonStart, INPUT_PULLUP);
  
  pinMode(buttonStop, INPUT_PULLUP);

}

void loop() {
 
  
  if (digitalRead(buttonStart) == LOW) { 
   digitalWrite (ledRed, HIGH);
   delay (3000); 
  if (digitalRead(buttonStop) == LOW) return;
    
  digitalWrite (ledRed, LOW);
  digitalWrite (ledYellow, HIGH);
  delay (1000);
   if (digitalRead(buttonStop) == LOW) return;
    
  digitalWrite (ledYellow, LOW); 
  digitalWrite (ledGreen, HIGH);
  delay (3000);
   if (digitalRead(buttonStop) == LOW) return;
    
    digitalWrite (ledGreen, LOW);  
  }
}
