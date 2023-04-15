#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0,0);
}

void loop() {
  lcd.clear();
  delay(2000);
  lcd.print("Hello World");
  delay(2000);
}
