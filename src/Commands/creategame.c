#include "creategame.h"

void createGame (arrGame *games, arrScore *scores){
    scoreMap score;
    CreateEmptyMap(&score);
    int jumlah_game = Length(*games);
    Word sum_game, game;
    sum_game.Length = 0;
    //masih bingung kenapa harus di clone 2 kali agar sempurna
    CloneWord(&sum_game,intToWord(jumlah_game));
    CloneWord(&sum_game,intToWord(jumlah_game));
    DeleteFirst(games);
    InsertFirst(games, sum_game);
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTWORD_INPUT();
    game = currentWord;
    ADVWORD_INPUT();
    while(!isEndWord()){
        
        InsertLastW(&game," ");
        InsertLastW(&game,currentWord.TabWord);
        ADVWORD_INPUT();
    }
    InsertLast(games, game);
    InsertLastM(scores,score);
    printf("Game berhasil ditambahkan\n");
}
/*
I.S.: gamesGame sembarang
F.S.: Elemen gamesGame ditambahkan dengan nama game baru
*/
