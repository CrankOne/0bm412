#ifndef H_0BM412_ACCEPT_REJECT_H
#define H_0BM412_ACCEPT_REJECT_H 1

#ifdef __cplusplus
extern "C" {
#endif

float
accept_reject( float xMin, float xMax, float yMin, float yMax
             , float (*pdf)(float x)
             );

#ifdef __cplusplus
}
#endif

#endif
