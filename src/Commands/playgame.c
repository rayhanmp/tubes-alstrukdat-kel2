#include "playgame.h"

void playGame (queueGame* q, stackGame* s, arrGame* Games, arrScore* Scores){
    Word game;
    createWord(&game);
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
            if (isKataEqual(game, "DINER DASH")){
                diner_dash(Scores, GetArrIdx(*Games, "DINER DASH"));
            } else if (isKataEqual(game, "RNG")){
                rnggame(Scores, GetArrIdx(*Games, "RNG"));
            } else if (isKataEqual(game, "PRS")) {
                prs(Scores, GetArrIdx(*Games, "PRS"));
            } else if (isKataEqual(game, "HANGMAN")) {
                hangman(Scores, GetArrIdx(*Games, "HANGMAN"));
            } else if (isKataEqual(game, "TOWER OF HANOI")) {
                towerGame(Scores, GetArrIdx(*Games, "TOWER OF HANOI"));
            } else if (isKataEqual(game, "SNAKE ON METEOR")) {
                snake_on_meteor(Scores, GetArrIdx(*Games, "SNAKE ON METEOR"));
            }
            else {
                gametambahan(Scores, GetArrIdxW(*Games, game));
            }
        }
    }
}
/*
I.S.: q terdefinisi, currentGame Nil (?)
F.S.: q berkurang satu, currentGame adalah elemen pertama q sebelum dihapus
*/