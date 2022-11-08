#ifndef __ARRAY_GAME_DIN__
#define __ARRAY_GAME_DIN__

#include "boolean.h"
#include <stdio.h>
#include "Word.h"


typedef int IdxType;
typedef Word Game;
typedef struct {
    Game A[100];
    int Neff;
} arrGame;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk Array kosong
 */
void MakeArray(arrGame *arr);


/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(arrGame arr);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(arrGame arr);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Game Get(arrGame arr, IdxType i);


/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(arrGame *arr, Game el, IdxType i);

// /**
//  * Fungsi untuk menambahkan elemen baru di akhir array.
//  * Prekondisi: array terdefinisi
//  */
void InsertLast(arrGame *arr, Game el);

// /**
//  * Fungsi untuk menambahkan elemen baru di awal array.
//  * Prekondisi: array terdefinisi
//  */
void InsertFirst(arrGame *arr, Game el);

// /**
//  * Fungsi untuk menghapus elemen di index ke-i Array
//  * Prekondisi: array terdefinisi, i di antara 0..Length(array).
//  */

void DeleteAt(arrGame *arr, IdxType i);

// /**
//  * Fungsi untuk menghapus elemen terakhir Array
//  * Prekondisi: array tidak kosong
//  */

void DeleteLast(arrGame*arr);

// /**
//  * Fungsi untuk menghapus elemen pertama Array
//  * Prekondisi: array tidak kosong
//  */

void DeleteFirst(arrGame *arr);

// /**
//  * Fungsi untuk melakukan print suatu Array.
//  * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
//  * dan diakhiri newline.
//  * Prekondisi: array terdefinisi
//  */
void PrintArray(arrGame arr);

#endif