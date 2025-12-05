#include <IRremote.hpp>
const int irPin = 11;


const int leftTurn = 2;
const int rightTurn = 3;
const int headlight = 4;
const int lightSensor = A5;
const int rearLight = 12;


const int buzzer = A4;
bool alarmActive = false;
unsigned long alarmEndTime = 0;

bool leftActive = false;
unsigned long leftEndTime = 0;

bool rightActive = false;
unsigned long rightEndTime = 0;

const int humiditySensor = A2;
const int wiperLED = 5; // дворники
const int windowRedLED = 6;
const int windowGreenLED = 7;


void setup() {
  Serial.begin(9600);
   IrReceiver.begin(irPin, ENABLE_LED_FEEDBACK);
   pinMode(leftTurn, OUTPUT);
   pinMode (rightTurn, OUTPUT);
   pinMode (headlight, OUTPUT);
   pinMode (lightSensor, INPUT);
   pinMode (rearLight, OUTPUT);
   
   pinMode (buzzer, OUTPUT);
  
   pinMode(wiperLED, OUTPUT);
   pinMode(windowRedLED, OUTPUT);
   pinMode(windowGreenLED, OUTPUT);
  
  }

void loop() {
  unsigned long now = millis();
 
 if (IrReceiver.decode()) {
    unsigned long cmd = IrReceiver.decodedIRData.command;

    Serial.print("IR command = 0x");
    Serial.println(cmd, HEX);

   switch (cmd) {

     case 0x0:
    Serial.println("Power (red button)");
    digitalWrite(headlight, !digitalRead(headlight)); // вкл/выкл фары
    break;
     
      case 0x4: // стрелка вправо
        digitalWrite(rightTurn, HIGH);
        delay(300);
        digitalWrite(rightTurn, LOW);
        Serial.println("Right turn signal");
        break;

     case 0x6: // стрелка влево
        digitalWrite(leftTurn, HIGH);
        delay(300);
        digitalWrite(leftTurn, LOW);
        Serial.println("Left turn signal");
        break;
     
     case 0x8: // стрелка вниз
        digitalWrite(rearLight, !digitalRead(rearLight));
        Serial.println("Rear light toggled");
        break;
     
  case 0x5: //  - сигнализация
        if (!alarmActive) {
          digitalWrite(leftTurn, HIGH);
          digitalWrite(rightTurn, HIGH);
          digitalWrite(buzzer, HIGH);
          alarmEndTime = millis() + 500; // 0,5 сек
          alarmActive = true;
        }
        Serial.println("Alarm signal activated");
        break;

     
      default:
        Serial.print("Кнопка 0x");
        Serial.print(cmd, HEX);
        Serial.println(" не назначена");
        break;
    }

    IrReceiver.resume();  
  }

  // Сигнализация (↑)
  if (alarmActive && now >= alarmEndTime) {
    digitalWrite(leftTurn, LOW);
    digitalWrite(rightTurn, LOW);
    digitalWrite(buzzer, LOW);
    alarmActive = false;
  }

  // Поворотники влево/вправо
  if (leftActive && now >= leftEndTime) {
    digitalWrite(leftTurn, LOW);
    leftActive = false;
  }
  if (rightActive && now >= rightEndTime) {
    digitalWrite(rightTurn, LOW);
    rightActive = false;
  }
// === датчик влажности ===
  int humidity = analogRead(humiditySensor); /
  if (humidity > 500) {
    digitalWrite(wiperLED, HIGH);        // дворники
    digitalWrite(windowRedLED, LOW);     // окно открыто
    digitalWrite(windowGreenLED, HIGH);
  } else {
    digitalWrite(wiperLED, LOW);
    digitalWrite(windowRedLED, HIGH);    // окно закрыто
    digitalWrite(windowGreenLED, LOW);
  }
  delay(50); 
}
