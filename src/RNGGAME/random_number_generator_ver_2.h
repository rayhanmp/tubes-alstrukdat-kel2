/* random_number_generator_ver_2.h*/
#ifndef random_number_generator_2
#define random_number_generator_2
#include <stdio.h>
#include <time.h>
#include <math.h>

void seedrngver2(long long *seed);
/* I.S seed terdefinisi
   F.S seed berisi seed
Menaruh seed ke output*/
long long rngver2(long long *seed ,long long min, long long max);
/* Mengembalikan angka acak dari min sampai max dengan menggambil seed dari yang sudah tersedia dan mengubah seed menjadi yang berbeda.*/
/* HOW TO USE
   Pertama, jalankan prosedur seedrngver2 terlebih dahulu dengan cara :seedrngver2(&seed). PENTING : Jangan jalankan seedrngver2 di awal program. 
   Kedua gunakan rngver2 sesuai kepentingan dengan cara : rngver2(&seed, min, max). Dengan argumen adalah sesuai dengan argumen pada seedrngver2, dan kedua argumen
   setelahnya adalah parameter min dan max.
*/
#endif