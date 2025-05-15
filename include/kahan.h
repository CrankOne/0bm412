#ifndef H_0BM412_KAHAN_H
#define H_0BM412_KAHAN_H 1

#ifdef __cplusplus
extern "C" {
#endif

struct Kahan {
    double s, cs, ccs;
};

void kahan_init(struct Kahan *);
void kahan_add(struct Kahan *, double value);
double kahan_get(struct Kahan *);
void kahan_free(struct Kahan *);

#ifdef __cplusplus
}
#endif

#endif

