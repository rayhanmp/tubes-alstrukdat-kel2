#include "playgame.h"

void playGame (arrGame arr, queueGame q){
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintQueue(q);
    printf("\n");

    Word game;
    Dequeue(&q, &game);
    if (...){
        // play game
    } else {
        printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", game.TabWord);
        printf("Silahkan pilih game lain.\n");
    }
}
/*
I.S.: q terdefinisi, currentGame Nil (?)
F.S.: q berkurang satu, currentGame adalah elemen pertama q sebelum dihapus
*/