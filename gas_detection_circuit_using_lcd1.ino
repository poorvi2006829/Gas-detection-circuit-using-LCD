#include "LiquidCrystal.h"
LiquidCrystal lcd(8,7,6,5,4,3);

int GAS_VAL = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  
  lcd.setCursor(0,0);
  lcd.print("   GAS SENSOR  ");

}

void loop()
{
  GAS_VAL = analogRead(A0);
  Serial.println(GAS_VAL);


 if (GAS_VAL > 300)
 {
    lcd.setCursor(0,1);
    lcd.print("GAS Detected ");
   
  }
  else
 {
     lcd.setCursor(0,1);
     lcd.print("GAS Not Detect");
   
  }
  
  delay(10);
}