#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>
Adafruit_LiquidCrystal lcd_1(0x20);
Adafruit_LiquidCrystal lcd_2(0x21);
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
 {'1', '2', '3', 'A'},
 {'4', '5', '6', 'B'},
 {'7', '8', '9', 'C'},
 {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
int keyPressCount = 0;
void setup() {
 Serial.begin(9600);
 lcd_1.begin(16, 2);
 lcd_1.setBacklight(1);
 lcd_1.print("Enter key value");
 lcd_1.setCursor(0, 1);
 lcd_2.begin(16, 2);
 lcd_2.setBacklight(1);
 lcd_2.print("Total Key Press:");
  lcd_2.setCursor(0, 1);
 lcd_2.print("Count: 0");
}
void loop() {
 char customKey = customKeypad.getKey();
 if (customKey) {
 Serial.println(customKey);
 lcd_1.setCursor(7, 1);
 lcd_1.print(" ");
 lcd_1.setCursor(7, 1);
 lcd_1.print(customKey);
 keyPressCount++;
 lcd_2.setCursor(0, 1);
 lcd_2.print("Count: ");
 lcd_2.print(keyPressCount);
 lcd_2.print(" "); // Clear extra digits if count goes down
 delay(100);
 }
}
