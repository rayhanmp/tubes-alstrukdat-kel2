#include "skipgame.h"

void skipGame (queueGame *q, int n){
    int i; 
    Word skippedGame, currentGame;

    printf("Berikut adalah daftar Game-mu\n");
    PrintQueue(*q);
    printf("\n");

    if (n >= LengthQ(*q)){
        for (i = 0; i < n; i++){
            Dequeue(q, &skippedGame);
        }
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    } else {
        for (i = 0; i < n; i++){
            Dequeue(q, &skippedGame);
        }
        currentGame = HEAD(*q);
        printf("Loading %s ...\n", currentGame.TabWord);
        playGame(q);
    }
}
/*
I.S.: q sembarang, n terdefinisi
F.S.: Elemen Game pada q terdequeue sebanyak n, sistem memainkan Game yang paling pertama di q sekarang
*/