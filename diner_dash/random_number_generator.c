/* random_number_generator.c*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include "random_number_generator.h"

long long rng(long long min, long long max){
    time_t x;
    time(&x);
    clock_t y = clock() * clock();
    unsigned long long n = x*y;
    n = ((((n >> 31) ^ ( (n >> 4) ^ ((n >> 2) ^ (n >> 1)) ) ) ^ n) ^ (n >> 7));
    return (n % (max - min + 1) ) + min;
}