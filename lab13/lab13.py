#include <Servo.h>

const int tempPin = A0;     
const int lightPin = A1;    
const int servoPin = 9;     

const float TEMP_LIMIT = 28.0; 
const int LIGHT_LIMIT = 600;   
const float VREF = 5.0;        

Servo windowServo;

void setup() {
  Serial.begin(9600);
  windowServo.attach(servoPin);
  windowServo.write(0); 
  Serial.println("System started...");
}

void loop() {
  
  int tempValue = analogRead(tempPin);
  float voltage = tempValue * (VREF / 1023.0);
  float temperature = voltage * 100.0; 

  
  int lightValue = analogRead(lightPin);

  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Light: ");
  Serial.println(lightValue);

  
  if (temperature > TEMP_LIMIT || lightValue > LIGHT_LIMIT) {
    windowServo.write(90); 
  } else {
    windowServo.write(0);  
  }

  delay(500); 
}