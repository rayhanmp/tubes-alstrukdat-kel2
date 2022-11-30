#include "arrayGame.h"
#include <stdio.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk Array kosong
 */
void MakeArray(arrGame *arr){
    arr->Neff= 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArr(arrGame arr){
    return Length(arr) == 0;
}
/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(arrGame arr){
    return arr.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Game Get(arrGame arr, IdxType i){
    return arr.A[i];
}

boolean IsMemberArr(arrGame arr, Game el) {
    boolean found;
    int i;
    
    i = 0;
    found = false;
    
    while (!found && i<Length(arr)) {
        if (isIdentical(arr.A[i], el)) {
            found = true;
        }
        else {
            i++;
        }
    }
    return found;
}
/**
 * Mengembalikan true apabila elemen el terdapat di arrGame
 * Prekondisi: arrGame terdefinisi.
 */

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(arrGame *arr, Game el, IdxType i){
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
void InsertLast(arrGame *arr, Game el){
    arr->A[arr->Neff] = el;
    arr->Neff++;
}

// /**
//  * Fungsi untuk menambahkan elemen baru di awal array.
//  * Prekondisi: array terdefinisi
//  */
void InsertFirst(arrGame *arr, Game el){
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

void DeleteAt(arrGame *arr, IdxType i){
    for (i; i <= Length(*arr); i++) {
    arr->A[i] = arr->A[i+1];
    }
    arr->Neff--;
}

// /**
//  * Fungsi untuk menghapus elemen terakhir Array
//  * Prekondisi: array tidak kosong
//  */

void DeleteLast(arrGame*arr){
    arr->A[arr->Neff-1] = arr->A[arr->Neff];
    arr->Neff--;
}

// /**
//  * Fungsi untuk menghapus elemen pertama Array
//  * Prekondisi: array tidak kosong
//  */

void DeleteFirst(arrGame *arr){
    for (int i = 0; i < Length(*arr); i++) {
    arr->A[i] = arr->A[i+1];
    }
    arr->Neff--;
}

// /**
//  * Fungsi untuk melakukan print suatu Array.
//  * Print dilakukan dengan format: 1. Game1\n 2. Game2\n ...
//  * dan diakhiri newline.
//  * Prekondisi: array terdefinisi
//  */
void PrintArray(arrGame arr){
    for(int i = 1; i < Length(arr); i++){
        printf("%d. %s\n",i,Get(arr,i).TabWord);
    }
}

int GetArrIdx(arrGame arr, char* el){
    boolean found = false;
    int i = 0;
    while(!found && i < Length(arr)){
        if(isKataEqual(Get(arr,i), el)){
            found = true;
        }
        i++;
    }
    return i - 1;
}
/**
 * Fungsi untuk melakukan searching dan mengembalikan index sebuah elemen pada array
 * Prekondisi: elemen pasti ada di dalam array
 */

// // DRIVER ADT ARRAY
// #include "mesinkarakter.h"
// #include "mesinkata.h"
// int main(){
//     arrGame arr;
//     char filename[50] = "default_config.txt";
//     int i = 0;
//     MakeArray(&arr);
//     STARTWORD(filename);
//     while(!isEndWord()){
//         InsertLast(&arr, currentWord);
//         ADVWORD();
//         i++;
//     }
//     PrintArray(arr);
// }
