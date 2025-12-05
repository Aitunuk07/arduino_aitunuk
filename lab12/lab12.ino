const int ledpin=5;
const int buzzerpin=7;
const int touchpin=6;

int melody [] = {262,294,330,349,392,440,494};
int notDuration=200;

  
void setup()
{
  pinMode(ledpin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(touchpin, INPUT);
  digitalWrite(ledpin, LOW);
}

void loop()
{
  int touchValue=digitalRead(touchpin);
  if (touchValue == HIGH)  {
    digitalWrite (ledpin, HIGH);
    
	for (int i=0; i<7;i++){
      tone (buzzerpin, melody [i],notDuration);
	  delay (notDuration); 
      digitalWrite (ledpin, ! digitalRead (ledpin));
}    
	noTone (buzzerpin); 
    digitalWrite (ledpin, LOW);
}else{
	noTone (buzzerpin); 
    digitalWrite (ledpin, LOW);
} 
delay (50);
}   