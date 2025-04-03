struct Histogram1D {
    int N;
    int counters[42];
    float rangeMin;
    float rangeMax;
    float rangeLength;
};

void histogram_init(struct Histogram1D * h, float rangeMin, float rangeMax);
void histogram_fill(struct Histogram1D * h, float v );
void histogram_print(struct Histogram1D * h);

