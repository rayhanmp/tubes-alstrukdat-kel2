#include "loadKamus.h"

void loadKamus(arrGame* arrKata, char* filename){
    //MEMBUAT ARRAY BARU
    MakeArray(arrKata);
    
    //MEMBACA ISI FILE
    STARTWORD(filename);
    while(!isEndWord()){
        InsertLast(arrKata, currentWord);
        ADVWORD();
    }
}
/*
ASUMSI: filename selalu benar/ada pada folder data
I.S.: arrGame sembarang
F.S.: arrGame terisi dengan game-game dari config yang dipilih dengan nama filename
*/