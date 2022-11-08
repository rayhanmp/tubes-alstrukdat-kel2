#include "load.h"

void load(arrGame* arr, file filename){
    int i = 0;
    MakeArray(arr);
    STARTWORD(filename);
    ADVWORD();
    while(!isEndWord()){
        InsertLast(arr, currentWord);
        ADVWORD();
        i++;
    }

}
/*
I.S.: arrGame sembarang
F.S.: arrGame terisi dengan game-game dari config yang dipilih dengan nama filename
*/
