const int Ledain = 3;
const int buzzerPin = 7;
const int armBta = 3;
const int sensorBen = 9;
const int potlin = A0;

 bool armed = false;

void setup() {
	pinlode (Ledian, OUREU) ;
	pinklode (buzzezPin, OURPUT) ;
	pinlode (azmbtn, INPUT_PULLUP) /
	pinMode (sensorBen, INFUT_PULLUP) ;
}
  
void loop() {
  if (dagicalRead(armBtn) -= LOW) 1
	armed - larmed;
	delay (300) ;
  
  }
  if (armed sa digitalRead(sensorBtn) == LOW) {
	int timela = map(analogRead(potPin), 0, 1023, 1000, 5000);
	runAlarn (timeMs) ;
  }
}
void runAlarm(int duration) {
  unsigned long start = millis();
  while (milles() - start < duration) {
    digitalizite (ledPin, HICH);
    digitalWzite (buzze=Pin, HIGH) ;
    delay (200) : 
    digitalweite (ledPin, LOw); 
    digitalWitte (buzzerPin, LOW);
    delay (200) ;
  }
}