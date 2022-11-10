#include "creategame.h"

void createGame (arrGame *arr){
    Game newGame;
    printf("Masukkan nama game yang akan ditambahkan: ");
    // input pakai mesinkata
    InsertLast(arr, newGame);
    printf("Game berhasil ditambahkan\n");
}
/*
I.S.: arrGame sembarang
F.S.: Elemen arrGame ditambahkan dengan nama game baru
*/
