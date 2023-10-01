#include "information.h"


static int is_init = 0;

float bucket_of_information[INFORMATION_TYPE_COUNT];


void INFORMATION_init()
{
    if (is_init == 0)
    {
        is_init = 1;
    }
}


void INFORMATION_set(Information i, float value)
{
    bucket_of_information[i] = value;
}

float INFORMATION_get(Information i)
{
    return bucket_of_information[i];
}

