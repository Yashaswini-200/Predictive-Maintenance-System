#include "fault.h"

static FaultState current_state = FAULT_NORMAL;
static FaultState previous_state = FAULT_NORMAL;
static int healthy_count = 0;

FaultState get_fault_state(float temperature, float rms) {
    // Basic fault classification
    if (temperature > 50.0f && rms > 1.5f) {
        current_state = FAULT_CRITICAL;
    } else if (temperature > 40.0f && temperature <= 50.0f &&
               rms > 1.2f && rms <= 1.5f || temperature > 35.0f && temperature <= 40.0f && rms>1.5f || temperature > 50.0f && rms <= 1.2f) {
        current_state = FAULT_WARNING;
    } else if (temperature > 35.0f && temperature <= 40.0f &&
               rms <= 1.2f) {
        current_state = FAULT_NORMAL;
    }
    else if (temperature > 30.0f && temperature <= 35.0f &&
               rms <= 1.0f) {
        current_state = FAULT_RECOVERY;
    } else {
        current_state = FAULT_NORMAL;
    }

    if (previous_state == FAULT_CRITICAL && current_state == FAULT_RECOVERY) {
        healthy_count++;
        if (healthy_count > 10) {
            current_state = FAULT_NORMAL;
            healthy_count = 0;
        } else {
            current_state = FAULT_RECOVERY;
        }
    } else {
        healthy_count = 0;
    }

    previous_state = current_state;
    return current_state;
}
