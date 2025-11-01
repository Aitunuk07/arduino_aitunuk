const int TRIG = 9;
const int ECHO = 10;

const int RED = 3;
const int YELLOW = 5;
const int GREEN = 6;

const int BUZZER = 8;


long duration;
int distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

void loop() {
 
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2; 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

 
  if (distance > 30) {
  
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);

    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW);
    delay(400);  
  } 
  else if (distance <= 30 && distance > 15) {
   
    digitalWrite(YELLOW, HIGH);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);

    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW);
    delay(200); 
  } 
  else if (distance <= 15) {
   
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);

    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW);
    delay(100);  
  }
}