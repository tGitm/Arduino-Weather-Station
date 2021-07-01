
#include <LiquidCrystal.h>
#include <Arduino.h>
 LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

int val;
int tempPin = 1; //št. pina na arduinu
const int ledWarm = 2;
const int ledCold = 4;

void blinkLED(int pin)
{
  digitalWrite(pin, HIGH); // LED on
  digitalWrite(pin, LOW); // LED off
}

void setup() {
  Serial.begin(9600);
  //nastavim resolucijo ekrančka
  lcd.begin(16, 2);
  lcd.write("Temp: ");
  
  //led -> output
  pinMode(ledWarm, OUTPUT); 
  pinMode(ledCold, OUTPUT); 
}

void loop() {
  val = analogRead(tempPin);
  double cel = val*110.0/1023;
  Serial.println(cel);
  double farh = (cel*9)/5 + 32;
  
  lcd.setCursor(7, 0);
  lcd.write(cel);
  lcd.write(" *C");
  
  lcd.setCursor(7, 1);
  lcd.write(farh);
  lcd.write(" *F");
  
  if (cel < 5.0) {
    blinkLED(ledCold);
  }
  else if (cel > 25.0) {
    blinkLED(ledWarm);
  }
}
