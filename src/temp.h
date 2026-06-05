#ifndef TEMPERATURE_H
#define TEMPERATURE_H

enum TempState
{
    TEMP_NORMAL,
    TEMP_HEATING,
    TEMP_FAULT,
    TEMP_RECOVERY
};
void update_temperature_state();
float generate_temperature();
TempState get_temperature_state();
const char* get_temperature_state_string();
#endif