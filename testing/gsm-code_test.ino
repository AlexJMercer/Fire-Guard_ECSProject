#include<SoftwareSerial.h>

SoftwareSerial gsm(9, 10);

void setup() {
    Serial.begin(9600);
    gsm.begin(9600);
}

void loop() {
    if (gsm.available())
    {
      Serial.write(gsm.read());
    }
    
    if (Serial.available())
    {
      byte a = Serial.read();
      if (a == '#')
      {
        gsm.write(0x1a);
      }
      else
      {
        gsm.write(a);
      }
    }
}
