#include "vibration.h"

#include <math.h>
#include <stdlib.h>

#ifndef PI
#define PI 3.14159265358979323846
#endif

float generate_vibration(void)
{
    static float t = 0.0f;

    const float dt = 0.02f;
    const float amplitude = 1.0f;

    float noise =
        (((float)rand() / RAND_MAX) - 0.5f) * 0.4f;

    float vibration =
        amplitude * sinf(t) + noise;

    t += dt;

    if (t >= (2.0f * PI))
    {
        t = 0.0f;
    }

    return vibration;
}