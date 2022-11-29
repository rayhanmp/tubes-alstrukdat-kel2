#include "resethistory.h"

void resetHistory(stackGame* s){
    Game game;
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? ");
    STARTWORD_INPUT();
    if (isKataEqual(currentWord,"YA")){
        while (!IsEmptySG(*s)){
            PopSG(s, &game);
        }
        printf("History berhasil di-reset.");
    } else if (isKataEqual(currentWord,"TIDAK")){
        printf("History tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
        history(s, Top(*s));
    } else {
        printf("Input tidak valid!\n");
    }
}
/*
I.S.: s sembarang
F.S.: menghapus semua elemen pada s (semua history permainan yang dimainkan)
*/