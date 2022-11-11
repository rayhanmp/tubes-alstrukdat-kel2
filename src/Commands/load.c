#include "load.h"

void load(arrGame* arr, char* filename){
    //MEMBUAT ARRAY BARU
    MakeArray(arr);
    
    //MEMBACA ISI FILE
    STARTWORD(filename);
    while(!isEndWord()){
        InsertLast(arr, currentWord);
        ADVWORD();
    }
    printf("Save file berhasil dibaca.\n");
}
/*
ASUMSI: filename selalu benar/ada pada folder data
I.S.: arrGame sembarang
F.S.: arrGame terisi dengan game-game dari config yang dipilih dengan nama filename
*/