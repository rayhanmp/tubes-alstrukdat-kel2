#ifndef __ARRAY_MAP_DIN__
#define __ARRAY_MAP_DIN__

#include <stdio.h>
#include "word.h"
#include "mesinkata.h"
#include "../boolean.h"
#include "map.h"

typedef int Idx;
typedef struct {
    scoreMap A[100];
    int Neff;
} arrScore;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk Array kosong
 */
void MakeArrayM(arrScore *arr);


/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrM(arrScore arr);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthArrM(arrScore arr);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
scoreMap GetArrM(arrScore arr, Idx i);


/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */

boolean IsMemberArrM(arrScore arr, scoreMap el);
/**
 * Mengembalikan true apabila elemen el terdapat di arrScore
 * Prekondisi: arrScore terdefinisi.
 */

void InsertAtM(arrScore *arr, scoreMap el, Idx i);

// /**
//  * Fungsi untuk menambahkan elemen baru di akhir array.
//  * Prekondisi: array terdefinisi
//  */
void InsertLastM(arrScore *arr, scoreMap el);

// /**
//  * Fungsi untuk menambahkan elemen baru di awal array.
//  * Prekondisi: array terdefinisi
//  */
void InsertFirstM(arrScore *arr, scoreMap el);

// /**
//  * Fungsi untuk menghapus elemen di index ke-i Array
//  * Prekondisi: array terdefinisi, i di antara 0..Length(array).
//  */

void DeleteAtM(arrScore *arr, Idx i);

// /**
//  * Fungsi untuk menghapus elemen terakhir Array
//  * Prekondisi: array tidak kosong
//  */

void DeleteLastM(arrScore*arr);

// /**
//  * Fungsi untuk menghapus elemen pertama Array
//  * Prekondisi: array tidak kosong
//  */

void DeleteFirstM(arrScore *arr);

// /**
//  * Fungsi untuk melakukan print suatu Array.
//  * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
//  * dan diakhiri newline.
//  * Prekondisi: array terdefinisi
//  */
void setNeffM(arrScore *arr, int n);

#endif
