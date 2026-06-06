#include "fault.h"

static FaultState current_state = FAULT_NORMAL;
static int healthy_count = 0;

FaultState get_fault_state(float temperature, float rms) {
    int healthy  = (temperature <= 40.0f && rms <= 1.2f);
    int warning  = ((temperature > 40.0f && temperature <= 50.0f) ||
                    (rms > 1.2f && rms <= 1.5f));
    int critical = (temperature > 50.0f && rms > 1.5f);
    switch (current_state) {
        case FAULT_CRITICAL:
            if(critical){
                current_state = FAULT_CRITICAL;
            } else if (critical && healthy) {
                current_state = FAULT_WARNING;
            }
            else if (healthy) {
                current_state = FAULT_RECOVERY;
            }

        case FAULT_RECOVERY:
            if (healthy) {
                healthy_count++;
                if (healthy_count >= 10) {
                    current_state = FAULT_NORMAL;
                    healthy_count = 0;
                }
            } else {
               if (critical) {
                    current_state = FAULT_CRITICAL;
                } else if (warning) {
                    current_state = FAULT_WARNING;
                }
                healthy_count = 0;
            }
            break;

        case FAULT_NORMAL:

            break;

        case FAULT_WARNING:
            if (healthy) {
                current_state = FAULT_NORMAL;
            } else if (critical) {
                current_state = FAULT_CRITICAL;
            }
            break;
    }

    return current_state;
}
