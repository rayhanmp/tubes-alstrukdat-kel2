#include <stdio.h>
#include "arrayCMD.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk Array kosong
 */
void MakeArray(arrCMD *arr){
    arr->Neff= 0;
}


/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(arrCMD arr){
    return Length(arr) == 0;
}
/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(arrCMD arr){
    return arr.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
CMD Get(arrCMD arr, IdxType i){
    return arr.A[i];
}


/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(arrCMD *arr, CMD el, IdxType i){
    for (int j = Length(*arr); j > i; j--) {
        arr->A[j] = arr->A[j-1];
    }
    arr->A[i] = el;
    arr->Neff++;
}

// /**
//  * Fungsi untuk menambahkan elemen baru di akhir array.
//  * Prekondisi: array terdefinisi
//  */
void InsertLast(arrCMD *arr, CMD el){
    arr->A[arr->Neff] = el;
    arr->Neff++;
}

// /**
//  * Fungsi untuk menambahkan elemen baru di awal array.
//  * Prekondisi: array terdefinisi
//  */
void InsertFirst(arrCMD *arr, CMD el){
    for (int j = Length(*arr); j > 0; j--) {
    arr->A[j] = arr->A[j-1];
    }
    arr->A[0] = el;
    arr->Neff++;
}

// /**
//  * Fungsi untuk menghapus elemen di index ke-i Array
//  * Prekondisi: array terdefinisi, i di antara 0..Length(array).
//  */

void DeleteAt(arrCMD *arr, IdxType i){
    for (i; i <= Length(*arr); i++) {
    arr->A[i] = arr->A[i+1];
    }
    arr->Neff--;
}

// /**
//  * Fungsi untuk menghapus elemen terakhir Array
//  * Prekondisi: array tidak kosong
//  */

void DeleteLast(arrCMD *arr){
    arr->A[arr->Neff-1] = arr->A[arr->Neff];
    arr->Neff--;
}

// /**
//  * Fungsi untuk menghapus elemen pertama Array
//  * Prekondisi: array tidak kosong
//  */

void DeleteFirst(arrCMD *arr){
    for (int i = 0; i < Length(*arr); i++) {
    arr->A[i] = arr->A[i+1];
    }
    arr->Neff--;
}

// /**
//  * Fungsi untuk melakukan print suatu Array.
//  * Print dilakukan dengan format: 1. CMD1\n 2. CMD2\n ...
//  * dan diakhiri newline.
//  * Prekondisi: array terdefinisi
//  */
void PrintArray(arrCMD arr){
    for(int i = 0; i < Length(arr); i++){
        printf("%d. %s\n",i+1,Get(arr,i).TabWord);
    }
}