#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "maphash.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMH(HashMap *M){
    (*M).Count = Nil;
    int i;
    for (i = 0; i < MaxEl; i++){
        (*M).Elements[i].Key = Undefined;
        (*M).Elements[i].Value = Undefined;
    }
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi key & value map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K){
    return (K % MaxEl);
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype ValueMH(HashMap M, keytype k){
    int i = 0;
    boolean found = false;
    while (!found && (i < MaxEl)){
        if (M.Elements[i].Key == k){
            found = true;
        } else {
            i++;
        }
    }
    if (found) {
        return M.Elements[i].Value;
    } else {
        return Undefined;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMH(HashMap *M, keytype k, valuetype v){
    if (ValueMH(*M,k) == Undefined) {
        if ((*M).Elements[Hash(k)].Key == Undefined){
            (*M).Elements[Hash(k)].Key = k;
            (*M).Elements[Hash(k)].Value = v;
        } else {
            int i = Hash(k) + 1;
            boolean found = false;
            while (!found && (i < MaxEl)){
                if ((*M).Elements[i].Key == Undefined) {
                    (*M).Elements[i].Key = k;
                    (*M).Elements[i].Value = v;
                    found = true;
                } else {
                    i++;
                }
            }
        }
        (*M).Count += 1;
    }
}
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing linear probing dengan interval 1 jika index sudah terisi    */
