#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "histogram1d.h"

float inv_func(float u) {
    return acos(1 - u*M_PI);  // <-- ?
}

int main() {
    struct Histogram1D h;

    float rangeX[2], rangeY[2];
    rangeX[0] = - 5;
    rangeX[1] =   5;
    rangeY[0] = 0;
    rangeY[1] = 1;

    histogram_init(&h, rangeX[0], rangeX[1], 100);

    float x = 0.;
    for(int i = 0 ; i < 1e2; ++i) {
        float u = rand()/((float) RAND_MAX);
        histogram_fill(&h, inv_func(u));
        //printf("%e\n", inv_func(u));
    }
    histogram_print(&h);
    histogram_delete(&h);
    return 0;
}

