#include "rms.h"
#include<math.h>
#include<stdint.h>
#define RMS_BUFFER_SIZE 10
static float rms_buffer[RMS_BUFFER_SIZE];
static uint8_t rms_index = 0;
static uint8_t rms_count = 0;
void add_sample(float sample){
    rms_buffer[rms_index]=sample;
    rms_index=(rms_index+1)% RMS_BUFFER_SIZE;
    if(rms_count<RMS_BUFFER_SIZE){
        rms_count++;
    }
}
bool is_rms_ready(void){
    return rms_count>=RMS_BUFFER_SIZE;
}
float get_rms(void){
    if(!is_rms_ready()){
        return -1.0f;
    }
    float sum = 0.0f;
    for(uint8_t i=0 ; i<RMS_BUFFER_SIZE ; i++){
        sum += rms_buffer[i]*rms_buffer[i];

    }
    return sqrtf(sum / RMS_BUFFER_SIZE);
}