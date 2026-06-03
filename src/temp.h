#ifndef TEMPERATURE_H
#define TEMPERATURE_H

enum TempState
{
    TEMP_NORMAL,
    TEMP_HEATING,
    TEMP_FAULT,
    TEMP_RECOVERY
};

float generate_temperature(void);

TempState get_temperature_state(void);

const char* get_temperature_state_string(void);

#endif