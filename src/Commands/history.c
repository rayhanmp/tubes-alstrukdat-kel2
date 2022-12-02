#include "history.h"

void history (stackGame *s, int n){
    stackGame sTemp; 
    CreateEmptySG(&sTemp);
    int i; Game game;

    printf("Berikut adalah daftar Game yang telah dimainkan\n");
    if (IsEmptySG(*s)) {
        printf("History Game Anda KOSONG!\n");
    } else if (n >= Top(*s)) {
        PrintAllSG(*s);
    } else if (n > 0) {
        PrintSomeSG(*s, n);
    } else {
        printf("Masukkan jumlah yang valid!\n");
    }
}

/*
I.S.: s sembarang, n terdefinisi
F.S.: menampilkan elemen dari s (game yang telah dimainkan) sebanyak n
      urutan teratas merupakan permainan terakhir yang dimainkan
*/
