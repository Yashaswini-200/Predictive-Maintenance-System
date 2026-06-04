#include "temp.h"
#include <stdlib.h>
#include <chrono>

static unsigned long millis(void)
{
    using namespace std::chrono;
    return static_cast<unsigned long>(
        duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count());
}

static TempState current_state = TEMP_NORMAL;

static unsigned long state_start_time = 0;

static float temperature = 37.0f;

static void update_state_machine(void)
{
    unsigned long elapsed = millis() - state_start_time;

    switch(current_state)
    {
        case TEMP_NORMAL:

            if(elapsed >= 10000)
            {
                current_state = TEMP_HEATING;
                state_start_time = millis();
            }
            break;

        case TEMP_HEATING:

            if(elapsed >= 5000)
            {
                current_state = TEMP_FAULT;
                state_start_time = millis();
            }
            break;

        case TEMP_FAULT:

            if(elapsed >= 5000)
            {
                current_state = TEMP_RECOVERY;
                state_start_time = millis();
            }
            break;

        case TEMP_RECOVERY:

            if(elapsed >= 5000)
            {
                current_state = TEMP_NORMAL;
                state_start_time = millis();
            }
            break;
    }
}

float generate_temperature(void)
{
    update_state_machine();

    float fluctuation =
        (((float)rand() / RAND_MAX) - 0.5f) * 0.4f;

    float target = 37.0f;

    switch(current_state)
    {
        case TEMP_NORMAL:
            target = 37.0f;
            break;

        case TEMP_HEATING:
            target = 55.0f;
            break;

        case TEMP_FAULT:
            target = 60.0f;
            break;

        case TEMP_RECOVERY:
            target = 37.0f;
            break;
    }

    temperature += fluctuation;

    temperature +=
        0.05f * (target - temperature);

    return temperature;
}

TempState get_temperature_state(void)
{
    return current_state;
}