#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

int Gas_sen;

void setup()
{
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("SENSOR ACTIVE");

  delay(1000);
}

void loop()
{
  Gas_sen = analogRead(A0);

  Serial.print("Gas_sen = ");
  Serial.println(Gas_sen);

  lcd.setCursor(0, 1);

  if (Gas_sen >= 470)
  {
    lcd.print("  Detected    ");
  }
  else
  {
    lcd.print(" not Detected  ");
  }

  delay(500);
}
