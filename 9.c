#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

int tempPin = A0;
int humPin = A2;
int pressurePin = A1;

int buttons[] = {3, 4, 5, 6, 9};
int leds[] = {7, 8};

float temperature, humidity, pressure;

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  Serial.begin(9600);

  for (int i = 0; i < 5; i++)
    pinMode(buttons[i], INPUT_PULLUP);

  for (int i = 0; i < 2; i++)
    pinMode(leds[i], OUTPUT);

  lcd.print("Weather Station");
  delay(2000);
}

void loop() {
  temperature = analogRead(tempPin) * 500.0 / 1023.0;
  humidity = map(analogRead(humPin), 0, 1023, 0, 100);
  pressure = analogRead(pressurePin) / 10.0;

  digitalWrite(leds[0], temperature > 30 ? HIGH : LOW);
  digitalWrite(leds[1], humidity > 80 ? HIGH : LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C H:");
  lcd.print(humidity);

  lcd.setCursor(0, 1);
  lcd.print("P:");
  lcd.print(pressure, 1);

  for (int i = 0; i < 5; i++) {
    if (digitalRead(buttons[i]) == LOW) {
      lcd.clear();
      lcd.setCursor(0, 0);

      if (i == 0)
        lcd.print("Temperature");
      else if (i == 1)
        lcd.print("Humidity");
      else if (i == 2)
        lcd.print("Pressure");
      else if (i == 3)
        lcd.print("Temp Alert:30C");
      else
        lcd.print("Hum Alert:80%");

      delay(500);
    }
  }

  delay(1000);
}
