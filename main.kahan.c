#include "kahan.h"

#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char * argv[]) {
    struct Kahan ksum;
    kahan_init(&ksum);

    double sum = 0.;
    for(int i = 0; i < 1e7; ++i) {
        double v = 10.*rand()/(float) RAND_MAX;
        sum += v;
        kahan_add(&ksum, v);
    }

    printf("ordinary sum: %e\n", sum);
    printf("   kahan sum: %e\n", kahan_get(&ksum));
    printf("  difference: %e\n", kahan_get(&ksum) - sum);

    kahan_free(&ksum);
}

