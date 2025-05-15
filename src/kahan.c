#include "kahan.h"

#include <assert.h>
#include <math.h>

void kahan_init(struct Kahan * S) {
    S->s = S->cs = S->ccs = 0.;
}

void kahan_add(struct Kahan * S, double v) {
    assert(S);
    assert( !isnan(v) );
    double c, cc, t = S->s + v;
    if( fabs(S->s) >= fabs(v) ) {
        c = (S->s - t) + v;
    } else {
        c = (v - t) + S->s;
    }
    S->s = t;
    t = S->cs + c;
    if( fabs(S->cs) >= fabs(c) ) {
        cc = (S->cs - t) + c;
    } else {
        cc = (c - t) + S->cs;
    }
    S->cs = t;
    S->ccs += cc;
}

double kahan_get(struct Kahan * S) {
    assert(S);
    return S->s + S->cs + S->ccs;
}

void kahan_free(struct Kahan * S) {
    /* nothing special */
}

