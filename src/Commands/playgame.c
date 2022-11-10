#include "playgame.h"

void playGame (queueGame* q){
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintQueue(*q);
    printf("\n");

    Word game;
    Dequeue(q, &game);
    if (IsEmptyQ(*q)){
        printf("Daftar Game kosong\n");
    } else {
        if (isKataEqual(game, "DINOSAUR IN EARTH") || isKataEqual(game, "RISEWOMAN") || isKataEqual(game, "EIFFEL TOWER")){
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", game.TabWord);
            printf("Silahkan pilih game lain.\n");
        } else {
            printf("Loading %s ...\n", game.TabWord);
            if (isKataEqual(game, "Diner DASH")){
                diner_dash();
            } else if (isKataEqual(game, "RNG")){
                rnggame();
            } else {
                gametambahan();
            }
        }
    }
}
/*
I.S.: q terdefinisi, currentGame Nil (?)
F.S.: q berkurang satu, currentGame adalah elemen pertama q sebelum dihapus
*/