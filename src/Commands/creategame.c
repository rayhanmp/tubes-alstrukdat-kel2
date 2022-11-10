#include "creategame.h"

void createGame (arrGame *arr){
    Game game;
    int jumlah_game;
    jumlah_game = wordToInt(Get(*arr,0));
    jumlah_game++;
    game = intToWord(jumlah_game);
    DeleteFirst(arr);
    InsertFirst(arr, game);
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTWORD_INPUT();
    InsertLast(arr, currentWord);
    printf("Game berhasil ditambahkan\n");
}
/*
I.S.: arrGame sembarang
F.S.: Elemen arrGame ditambahkan dengan nama game baru
*/
