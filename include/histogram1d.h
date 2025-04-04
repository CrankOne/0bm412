struct Histogram1D {
    int N;
    int * counters;
    float rangeMin;
    float rangeMax;
    float rangeLength;
};

// intializes histogram instance
void histogram_init(struct Histogram1D * h, float rangeMin, float rangeMax, int nBins);

// adds value to histogram
void histogram_fill(struct Histogram1D * h, float v );

// prints histogram instance
void histogram_print(struct Histogram1D * h);

void histogram_delete(struct Histogram1D * h);

