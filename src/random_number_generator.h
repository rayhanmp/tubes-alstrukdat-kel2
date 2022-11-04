/* random_number_generator.h*/

#include <stdio.h>
#include <time.h>
#include <math.h>

unsigned long rng();
/* Mengembalikan angka acak dari 0 sampai 4.294.967.295 dengan menggambil seed dari time dan clock.*/