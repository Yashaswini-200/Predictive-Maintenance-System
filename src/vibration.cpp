#include<math.h>
#include<stdlib.h>
float generate_vibration(void){
    static float t = 0.03f;
    float dt = 0.02f;
    float noise = (((float)rand() / RAND_MAX) - 0.5f) * 0.4f;
    float vib = sin(t);
    float amp = 1.0f;
    t+=dt;
    return amp*vib+noise;
}