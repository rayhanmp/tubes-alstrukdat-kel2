#ifndef __ARRAY_CMD_DIN__
#define __ARRAY_CMD_DIN__

#include "boolean.h"
#include <stdio.h>
#include "Word.h"


typedef int IdxType;
typedef Word CMD;
typedef struct {
    CMD A[100];
    int Neff;
} arrCMD;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk Array kosong
 */
void MakeArray(arrCMD *arr);


/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(arrCMD arr);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(arrCMD arr);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
CMD Get(arrCMD arr, IdxType i);


/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(arrCMD *arr, CMD el, IdxType i);

// /**
//  * Fungsi untuk menambahkan elemen baru di akhir array.
//  * Prekondisi: array terdefinisi
//  */
void InsertLast(arrCMD *arr, CMD el);

// /**
//  * Fungsi untuk menambahkan elemen baru di awal array.
//  * Prekondisi: array terdefinisi
//  */
void InsertFirst(arrCMD *arr, CMD el);

// /**
//  * Fungsi untuk menghapus elemen di index ke-i Array
//  * Prekondisi: array terdefinisi, i di antara 0..Length(array).
//  */

void DeleteAt(arrCMD *arr, IdxType i);

// /**
//  * Fungsi untuk menghapus elemen terakhir Array
//  * Prekondisi: array tidak kosong
//  */

void DeleteLast(arrCMD *arr);

// /**
//  * Fungsi untuk menghapus elemen pertama Array
//  * Prekondisi: array tidak kosong
//  */

void DeleteFirst(arrCMD *arr);

// /**
//  * Fungsi untuk melakukan print suatu Array.
//  * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
//  * dan diakhiri newline.
//  * Prekondisi: array terdefinisi
//  */
void PrintArray(arrCMD arr);

#endif