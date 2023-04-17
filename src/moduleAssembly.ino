#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>


#define redLight 9
#define greenLight 6


LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial gsm(8, 7);

const int flameSensorPin = 2;
int count = 0;
int flameCurr = 0;
int flamePrev = -1;

void setup()
{
    pinMode(redLight, OUTPUT);
    pinMode(greenLight, OUTPUT);
    pinMode(flameSensorPin, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0,0);

    gsm.begin(9600);
    Serial.begin(9600);
    delay(2000);
}
void loop()
{
    flameCurr = digitalRead(flameSensorPin);

    if (flameCurr != flamePrev)
    {
        flamePrev = flameCurr;
        lcd.clear();
        lcd.setCursor(0,0);

        if (flameCurr == 0)
        {
            digitalWrite(LED_BUILTIN, HIGH);
            digitalWrite(redLight, HIGH);
            digitalWrite(greenLight, LOW);
            lcd.print("Flame Detected !!!");
            Serial.println("Flame Detected !!!");
            sendSMS();
            delay(2000);
            callNumber();
            if (count == 1)
                return;
        }
        else
        {
            digitalWrite(LED_BUILTIN, LOW);
            digitalWrite(redLight, LOW);
            digitalWrite(greenLight, HIGH);
            lcd.println("Flame NOT");
            lcd.setCursor(0, 1);  
            lcd.println("Detected...");
            Serial.println("Flame NOT Detected...");
        }
        delay(1000);
    }
}

void sendSMS()
{
    gsm.println("AT+CMGF=1"); // Set SMS 
    delay(4000);
    gsm.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); // Replace xxxxxxxxxx with Recipient's Phone Number 
    delay(3000);
    Serial.println("Setting up SMS...");
    gsm.println("ALERT !!! FIRE HAS BEEN DETECTED !!!"); // Message to be sent
    delay(1000);
    gsm.println((char)26); // CTRL+Z for denoting end of message
    delay(1000);
    Serial.println("SMS Sent !");
    gsm.println();
    delay(3000); 
}

void callNumber()
{
    gsm.println("ATD+91xxxxxxxxxx;"); // Replace xxxxxxxxxxxx with Recipient's Phone Number
    Serial.println("Calling Number..."); // Print response over serial port
    delay(1000);
}
