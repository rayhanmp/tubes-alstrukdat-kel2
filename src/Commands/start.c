#include "start.h"

void start(arrGame* arr){
    int i = 0;
    MakeArray(arr);
    STARTWORD("default_config.txt");
    while(!isEndWord()){
        InsertLast(arr, currentWord);
        ADVWORD();
        i++;
    }
    printf("Save file berhasil dibaca.\n");
}

/*
I.S.: arrGame sembarang
F.S.: arrGame terisi dengan game-game dari default config
*/
