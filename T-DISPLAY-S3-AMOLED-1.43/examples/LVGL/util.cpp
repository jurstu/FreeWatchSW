#include "util.h"



float UTIL_limit(float x, float low, float high)
{
    float out = x;
    if (x < low)
        x = low;
    
    if (x > high)
        x = high;

    return x;
}