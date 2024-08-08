// 16x2 LCD (without I2C mdule) in 4-Wire Mode

// https://www.instructables.com/Arduino-Interfacing-With-LCD-Without-Potentiometer
// https://circuitdigest.com/article/16x2-lcd-display-module-pinout-datasheet

#include <LiquidCrystal.h>  // https://www.arduino.cc/reference/en/libraries/liquidcrystal

constexpr uint8_t V0 = 6;   // Contrast // LCD voltage bias signal
constexpr uint8_t RS = 12;  // Toggles between Data/Command Register
constexpr uint8_t E  = 11;  // Enable // Must be held high to perform Read/Write Operation
constexpr uint8_t D4 = 5;   // Data/Command Pin // Pins used to send Command or Data to the LCD // In 4-Wire Mode only 4 pins are connected to MCU
constexpr uint8_t D5 = 4;   // Data/Command Pin // Pins used to send Command or Data to the LCD // In 4-Wire Mode only 4 pins are connected to MCU
constexpr uint8_t D6 = 3;   // Data/Command Pin // Pins used to send Command or Data to the LCD // In 4-Wire Mode only 4 pins are connected to MCU
constexpr uint8_t D7 = 2;   // Data/Command Pin // Pins used to send Command or Data to the LCD // In 4-Wire Mode only 4 pins are connected to MCU
constexpr uint8_t A  = 10;  // Backlight PWM pin

LiquidCrystal lcd(RS, E, D4, D5, D6, D7); // 4-Wire Mode

void setup() {
  constexpr uint8_t contrast = 60;
  constexpr uint8_t brightness = 100; // of the backlight

  analogWrite(V0, contrast);
  analogWrite(A, brightness);

  lcd.begin(16, 2); // `columns`, `rows`

  lcd.setCursor(0, 0); lcd.print("   Daniil       ");
  lcd.setCursor(0, 1); lcd.print("  Semenenko     ");
  // LCD display scroll borders: [ {_________...}3]
}


void loop() {
  constexpr uint64_t interval = 800; // miliseconds
  constexpr int shift = 3;           // columns

  for (int i = 0; i < shift; i++) {
    lcd.scrollDisplayRight();
    delay(interval);
  }
  delay(interval);

  for (int i = 0; i < shift; i++) {
    lcd.scrollDisplayLeft();
    delay(interval);
  }
  delay(interval);
}
