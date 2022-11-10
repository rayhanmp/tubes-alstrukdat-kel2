/* random_number_generator_ver_2.h*/
#ifndef random_number_generator_2
#define random_number_generator_2
#include <stdio.h>
#include <time.h>
#include <math.h>

void seedrngver2(long long *seed);
long long rngver2(long long *seed ,long long min, long long max);
/* Mengembalikan angka acak dari min sampai max dengan menggambil seed dari time dan clock.
NOTES : Jangan gunakan fungsi ini berturut-turut dengan waktu yang pendek, 
minimal berikan waktu kurang lebih 1 milidetik sebelum memanggil fungsi ini lagi.*/
#endif