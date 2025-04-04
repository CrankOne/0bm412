#include "accept-reject.h"

#include <stdlib.h>

float
accept_reject( float xMin, float xMax, float yMin, float yMax
             , float (*pdf)(float x)
             ) {
    do {
        int u1 = rand()
          , u2 = rand();
        float x = (u1/((float) RAND_MAX))*(xMax - xMin) + xMin;
        float y = (u2/((float) RAND_MAX))*(yMax - yMin) + yMin;

        if(y <= pdf(x)) return x;
    } while(1);
}

