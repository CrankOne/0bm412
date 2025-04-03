#include <stdlib.h>
#include <assert.h>
#include "include/histogram1d.h"
//#include <math.h>
//#include <time.h>

int main() {
    struct Histogram1D h;
    histogram_init(&h, -0.23, 1.45);

    for(int i = 0; i < 1e6; ++i ) {
        int u = rand();
        float a = 1.23*((float) u)/RAND_MAX - 0.15;

        histogram_fill(&h, a);
    }

    histogram_print(&h);
    return 0;
} 
