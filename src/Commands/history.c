#include "history.h"

void history (stackGame *s, int n){
    stackGame sTemp; 
    CreateEmptySG(&sTemp);
    int i; Game game;

    printf("Berikut adalah daftar Game yang telah dimainkan");
    if (IsEmptySG(*s)) {
        printf("History Game Anda KOSONG!\n");
    } else if (n >= Top(*s)) {
        i = 1;
        while (!IsEmptySG(*s)) {
            PopSG(s, &game);
            printf("%d. %s\n", i, game.TabWord);
            i++;
            PushSG(&sTemp, game);
        }
        while (!IsEmptySG(sTemp)) {
            PopSG(&sTemp, &game);
            PushSG(s, game);
        }
    } else {
        for (i = 1; i <= n; i++){
            PopSG(s, &game);
            printf("%d. %s\n", i, game.TabWord);
            PushSG(&sTemp, game);
        }
        for (i = 1; i <= n; i++){
            PopSG(&sTemp, &game);
            PushSG(s, game);
        }
    }
}

/*
I.S.: s sembarang, n terdefinisi
F.S.: menampilkan elemen dari s (game yang telah dimainkan) sebanyak n
      urutan teratas merupakan permainan terakhir yang dimainkan
*/
