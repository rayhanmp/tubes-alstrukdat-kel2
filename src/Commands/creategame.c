#include "creategame.h"

void createGame (arrGame *arr){
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTWORD_INPUT();
    InsertLast(arr, currentWord);
    printf("Game berhasil ditambahkan\n");
}
/*
I.S.: arrGame sembarang
F.S.: Elemen arrGame ditambahkan dengan nama game baru
*/
