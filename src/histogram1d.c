#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "histogram1d.h"

void histogram_init(struct Histogram1D * h,
        float rangeMin, float rangeMax, int nBins) {
    h->N = nBins;
    h->counters = malloc(sizeof(int)*nBins);
    for(int i = 0; i < h->N; i++ ) {
        h->counters[i] = 0;
    }
    h->rangeMin = rangeMin;
    h->rangeMax = rangeMax;
    h->rangeLength = rangeMax - rangeMin;
}

void histogram_delete(struct Histogram1D * h) {
    free(h->counters);
}

void histogram_fill(struct Histogram1D * h, float v ) {
    if(v < h->rangeMin || v > h->rangeMax)
        return;
    int nBin = (v - h->rangeMin)*h->N / h->rangeLength;
    assert(nBin >= 0);
    assert(nBin < h->N);
    h->counters[nBin]++;
}

void histogram_print(struct Histogram1D * h) {
    float binBgn = h->rangeMin;
    for(int i = 0; i < h->N; i = i + 1) {
        printf( "%d %f %f %d\n", i, binBgn,
                binBgn + (h->rangeMax - h->rangeMin)/h->N, h->counters[i]);
        binBgn = binBgn + (h->rangeMax - h->rangeMin)/h->N;
    }
}
