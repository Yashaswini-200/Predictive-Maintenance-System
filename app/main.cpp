#include "vibration.h"
#include "temp.h"
#include "fault.h"
#include "rms.h"
#include <Arduino.h>

void setup() {
    Serial.begin(115200);

    // ESP8266/NodeMCU has only one ADC pin (A0)
    randomSeed(analogRead(A0));

    Serial.println("Vibration Simulation Started");
    Serial.println("============================");
    Serial.println("Time\tVibration\tTemperature\tRMS\tFault State");
}

void loop() {
    // Generate vibration and temperature every loop
    float vibration = generate_vibration();
    float temperature = generate_temperature();

    Serial.print("Vibration: ");
    Serial.println(vibration, 3);

    Serial.print("Temperature: ");
    Serial.println(temperature, 3);

    // Add vibration sample to RMS buffer
    add_sample(vibration);

    if (!is_rms_ready()) {
        Serial.println("RMS: Collecting samples...");
    } else {
        float rms = get_rms();
        Serial.print("RMS: ");
        Serial.println(rms, 3);
        FaultState fault_state = get_fault_state(temperature, rms);
        Serial.print("Fault State: ");
        switch (fault_state) {
            case FAULT_NORMAL:
                Serial.println("NORMAL");
                break;
            case FAULT_WARNING:
                Serial.println("WARNING");
                break;
            case FAULT_CRITICAL:
                Serial.println("CRITICAL");
                break;
            case FAULT_RECOVERY:
                Serial.println("RECOVERY");
                break;
        }
    }
    delay(100);
}