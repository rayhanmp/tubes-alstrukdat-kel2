#include "skipgame.h"

void skipGame (arrGame arr, queueGame q, int n){
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintQueue(q);
    printf("\n");

    int i; 
    Word skippedGame, currentGame;
    if (n > LengthQ(q)){
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    } else {
        for (i = 0; i < n; i++){
            Dequeue(&q, &skippedGame);
        }
        currentGame = HEAD(q);
        printf("Loading %s ...\n", currentGame.TabWord);
        playGame(arr, q);
    }
}
/*
I.S.: q sembarang, n terdefinisi
F.S.: Elemen Game pada q terdequeue sebanyak n, sistem memainkan Game yang paling pertama di q sekarang
*/