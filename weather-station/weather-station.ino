

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int val;
int tempPin = 1;  //št. pina na arduinu
const int ledWarm = 8;
const int ledCold = 7;

void setup() {
  //nastavim resolucijo ekrančka
  lcd.begin(16, 2);
  lcd.print("Temp: ");
  
  //led -> output
  pinMode(ledWarm, OUTPUT); 
  pinMode(ledCold, OUTPUT); 
}

void loop() {
  val = analogRead(tempPin);
  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(6, 0);
  // print the number of seconds since reset:
  lcd.print(cel);
  lcd.print(" *C");
  
  lcd.setCursor(6, 1);
  // print the number of seconds since reset:
  lcd.print(farh);
  lcd.print(" *F");
  
  if (cel < 5) {
    blinkLED(ledCold);
  }
  else {
    blinkLED(ledWarm);
  }
}

void blinkLED(int pin)
{
  digitalWrite(pin, HIGH); // LED on
  digitalWrite(pin, LOW); // LED off
}
