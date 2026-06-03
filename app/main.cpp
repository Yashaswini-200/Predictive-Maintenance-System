#include <Arduino.h>

#include "vibration.h"

void setup()
{
    Serial.begin(115200);

    randomSeed(analogRead(A0));

    Serial.println("Vibration Simulation Started");
}

void loop()
{
    float vibration = generate_vibration();

    Serial.print("Vibration: ");
    Serial.println(vibration, 3);

    delay(100);
}