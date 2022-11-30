#include "arrayMap.h"
#include <stdio.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk Array kosong
 */
void MakeArrayM(arrScore *arr){
    arr->Neff= 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrM(arrScore arr){
    return LengthArrM(arr) == 0;
}
/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthArrM(arrScore arr){
    return arr.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
scoreMap GetArrM(arrScore arr, Idx i){
    return arr.A[i];
}


/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAtM(arrScore *arr, scoreMap el, Idx i){
    for (int j = LengthArrM(*arr); j > i; j--) {
        arr->A[j] = arr->A[j-1];
    }
    arr->A[i] = el;
    arr->Neff++;
}

// /**
//  * Fungsi untuk menambahkan elemen baru di akhir array.
//  * Prekondisi: array terdefinisi
//  */
void InsertLastM(arrScore *arr, scoreMap el){
    arr->A[arr->Neff] = el;
    arr->Neff++;
}

// /**
//  * Fungsi untuk menambahkan elemen baru di awal array.
//  * Prekondisi: array terdefinisi
//  */
void InsertFirstM(arrScore *arr, scoreMap el){
    for (int j = LengthArrM(*arr); j > 0; j--) {
    arr->A[j] = arr->A[j-1];
    }
    arr->A[0] = el;
    arr->Neff++;
}

// /**
//  * Fungsi untuk menghapus elemen di index ke-i Array
//  * Prekondisi: array terdefinisi, i di antara 0..Length(array).
//  */

void DeleteAtM(arrScore *arr, Idx i){
    for (i; i <= LengthArrM(*arr); i++) {
    arr->A[i] = arr->A[i+1];
    }
    arr->Neff--;
}

// /**
//  * Fungsi untuk menghapus elemen terakhir Array
//  * Prekondisi: array tidak kosong
//  */

void DeleteLastM(arrScore*arr){
    arr->A[arr->Neff-1] = arr->A[arr->Neff];
    arr->Neff--;
}

// /**
//  * Fungsi untuk menghapus elemen pertama Array
//  * Prekondisi: array tidak kosong
//  */

void DeleteFirstM(arrScore *arr){
    for (int i = 0; i < LengthArrM(*arr); i++) {
    arr->A[i] = arr->A[i+1];
    }
    arr->Neff--;
}
