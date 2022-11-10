/* random_number_generator.h*/

#include <stdio.h>
#include <time.h>
#include <math.h>

long long rng(long long min, long long max);
/* Mengembalikan angka acak dari min sampai max dengan menggambil seed dari time dan clock.
NOTES : Jangan gunakan fungsi ini berturut-turut dengan waktu yang pendek, 
minimal berikan waktu kurang lebih 1 milidetik sebelum memanggil fungsi ini lagi.*/