#include "temp.h"
#include<stdlib.h>
float generate_temperature(void){
    float fluctuations = (((float)rand()/RAND_MAX)-0.5f)*0.4f;
    const float target = 37.0f;
    static float temperature = target;
    temperature += fluctuations;
    temperature += 0.1f*(target - temperature);
    return temperature;
}
