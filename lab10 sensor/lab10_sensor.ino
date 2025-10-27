#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int tempPin = A0;  
const int ldrPin = A1;   
const int potPin = A2;    
const int ledPin = 9;     
const int buzzerPin = 8;  

const int lightThreshold = 300;

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(tempPin, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(potPin, INPUT);

  
  lcd.init();        
  lcd.backlight();   
  lcd.setCursor(0, 0);
  lcd.print("Temp&Light Sys");
  delay(1500);
  lcd.clear();
}

void loop() {
  
  int tempValue = analogRead(tempPin);
  float voltage = tempValue * (5.0 / 1023.0);
  float temperature = voltage * 100.0; 

 
  int lightValue = analogRead(ldrPin);

  
  int potValue = analogRead(potPin);
  float tempThreshold = map(potValue, 0, 1023, 20, 40); 
  
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C | Light: ");
  Serial.print(lightValue);
  Serial.print(" | Threshold: ");
  Serial.println(tempThreshold);


  if (temperature > tempThreshold || lightValue < lightThreshold) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

 
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print((char)223); 
  lcd.print("C Th:");
  lcd.print(tempThreshold, 0);
  lcd.print(" "); 

  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(lightValue);
  lcd.print("    "); 

  delay(1000);
}