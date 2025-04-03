#include <stdlib.h>
#include <assert.h>
#include "include/histogram1d.h"
#include <math.h>
//#include <time.h>

float func(float x) {
    return exp( - x*x/2.5);
}

float accept_reject( float xMin, float xMax, float yMin, float yMax
             , float (*pdf)(float x)
             ) {
    do {
        int u1 = rand()
          , u2 = rand()
          ;
        float x = (u1/((float) RAND_MAX))*(xMax - xMin) + xMin;
        float y = (u2/((float) RAND_MAX))*(yMax - yMin) + yMin;

        if(y <= pdf(x)) return x;
    } while(1);
}

int main() {
    struct Histogram1D h;

    float rangeX[2], rangeY[2];
    rangeX[0] = - 5;
    rangeX[1] =   5;
    rangeY[0] = 0;
    rangeY[1] = 1;

    histogram_init(&h, rangeX[0], rangeX[1]);

    for(int i = 0; i < 1e6; ++i ) {
        float x = accept_reject(rangeX[0], rangeX[1]
                , rangeY[0], rangeY[1], func);

        histogram_fill(&h, x);
    }

    histogram_print(&h);
    return 0;
} 
