#include "playgame.h"

void playGame (queueGame* q, stackGame* s, arrGame* Games, arrScore* Scores){
    Word game;
    if (IsEmptyQ(*q)){
        printf("Daftar Game kosong\n");
    } else {
        Dequeue(q, &game);
        PushSG(s, game);
        if (isKataEqual(game, "DINOSAUR IN EARTH") || isKataEqual(game, "RISEWOMAN") || isKataEqual(game, "EIFFEL TOWER")){
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", game.TabWord);
            printf("Silahkan pilih game lain.\n");
        } else {
            printf("Loading %s ...\n", game.TabWord);
            if (isKataEqual(game, "Diner DASH")){
                diner_dash();
            } else if (isKataEqual(game, "RNG")){
                rnggame();
            } else if (isKataEqual(game, "PRS")) {
                prs();
            } else if (isKataEqual(game, "HANGMAN")) {
                hangman();
            } else if (isKataEqual(game, "TOWER OF HANOI")) {
                towerGame(Scores, GetArrIdx(*Games, "TOWER OF HANOI"));
            }
            else {
                gametambahan();
            }
        }
    }
}
/*
I.S.: q terdefinisi, currentGame Nil (?)
F.S.: q berkurang satu, currentGame adalah elemen pertama q sebelum dihapus
*/