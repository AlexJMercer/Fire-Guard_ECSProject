#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define redLight 7
#define greenLight 6

void setup()
{
    // led setup

    pinMode(redLight, OUTPUT);
    pinMode(greenLight, OUTPUT);

    // Initialise the LCD
    lcd.init();

    lcd.setCursor(0, 0);

    // Turn on the backlight
    lcd.backlight();

    // Write to the LCD
    lcd.print("Hello world");

    digitalWrite(greenLight, HIGH);
    digitalWrite(redLight, LOW);

    // Wait for 5 seconds
    delay(5000);

    digitalWrite(redLight, HIGH);
    digitalWrite(greenLight, LOW);

    // Clear the LCD
    lcd.clear();
}

void loop() {
    // Empty loop
}