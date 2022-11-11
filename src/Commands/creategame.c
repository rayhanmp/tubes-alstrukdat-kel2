#include "creategame.h"

void createGame (arrGame *arr){
    int jumlah_game = Length(*arr);
    Word sum_game, game;
    sum_game.Length = 0;
    //masih bingung kenapa harus di clone 2 kali agar sempurna
    CloneWord(&sum_game,intToWord(jumlah_game));
    CloneWord(&sum_game,intToWord(jumlah_game));
    DeleteFirst(arr);
    InsertFirst(arr, sum_game);
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTWORD_INPUT();
    game = currentWord;
    ADVWORD_INPUT();
    while(!isEndWord()){
        
        InsertLastW(&game," ");
        InsertLastW(&game,currentWord.TabWord);
        ADVWORD_INPUT();
    }
    InsertLast(arr, game);
    printf("Game berhasil ditambahkan\n");
}
/*
I.S.: arrGame sembarang
F.S.: Elemen arrGame ditambahkan dengan nama game baru
*/
