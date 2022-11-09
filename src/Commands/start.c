#include "start.h"

void start(arrGame* arr){
    int i = 0;
    MakeArray(arr);
    STARTWORD(default_config);
    ADVWORD();
    while(!isEndWord()){
        InsertLast(arr, currentWord);
        ADVWORD();
        i++;
    }
}

/*
I.S.: arrGame sembarang
F.S.: arrGame terisi dengan game-game dari default config
*/
