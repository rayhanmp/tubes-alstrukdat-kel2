#include <stdio.h>
#include <time.h>
#include <math.h>
#include "random_number_generator_ver_2.h"


void seedrngver2(long long *seed){
    time_t x;
    time(&x);
    clock_t y = clock() * clock();
    *seed = x*y;
}
long long rngver2(long long *seed ,long long min, long long max){
    *seed = ((((*seed >> 31) ^ ( (*seed >> 4) ^ ((*seed >> 2) ^ (*seed >> 1)) ) ) ^ *seed) ^ (*seed >> 7));
    return (*seed % (max - min + 1) ) + min;;
}