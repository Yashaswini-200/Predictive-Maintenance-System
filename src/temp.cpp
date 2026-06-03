#include "temp.h"
#include<stdlib.h>
float generate_temperature(void){
    float fluctuations = (((float)rand()/RAND_MAX)-0.5)*0.4;
    const float target=37.0f;
    static float temperature = 37.0f+fluctuations;
    temperature+=0.1f*(target-temperature);
    return temperature;
}
