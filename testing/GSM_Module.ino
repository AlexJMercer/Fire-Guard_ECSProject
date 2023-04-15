#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);

void setup()
{
    mySerial.begin(9600);
    Serial.begin(9600);
    delay(100);
}

void loop()
{
    if (Serial.available()>0)
    switch(Serial.read())
    {
        case 's':
            mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
            delay(1000);  // Delay of 1 second
            mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); // Replace x with mobile number
            delay(1000);
            mySerial.println("Alert !! Fire has been detected !!"); // SMS text you want to send
            delay(100);
            mySerial.println((char)26); // ASCII of CTRL+Z for denoting end of SMS to module 
            delay(1000);
            break;
     
        case 'r':
            mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
            delay(1000);
            break;
    }

    if (mySerial.available() > 0)
        Serial.write(mySerial.read());
}
