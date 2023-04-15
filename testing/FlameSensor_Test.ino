const int flameSensorPin = 2;

void setup()
{
    pinMode(flameSensorPin, INPUT); // Initialize Flame sensor output pin connected pin as input.
    pinMode(LED_BUILTIN, OUTPUT);   // Initialize digital pin LED_BUILTIN as an output.
    Serial.begin(9600);
}

void loop()
{
    if (digitalRead(flameSensorPin) == 0)
    {
        digitalWrite(LED_BUILTIN, HIGH); // Led ON
        Serial.println("** Warning!!!! Fire detected!!! **");
    }
    else
    {
        digitalWrite(LED_BUILTIN, LOW); // Led OFF
        Serial.println("No Fire detected");
    }
    delay(1000); // Delay by 1 second
}
