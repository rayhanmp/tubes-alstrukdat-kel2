#include "loadconfig.h"

int sepScore(Word word){
    int i = 0; int j = 0;
    Word integer;
    createWord(&integer);
    while(word.TabWord[i] != ' '){
        i++;
    }
    i++;
    while(word.TabWord[i] != '\0'){
        integer.TabWord[j] = word.TabWord[i];
        integer.Length++;
        j++;
        i++;
    }
    return wordToInt(integer);
}
void loadConfig(arrGame* games, arrScore* scores, stackGame* history, char* filename){

    //MEMBACA ISI FILE
    STARTWORD(filename);
    int banyakgame, banyakscore, banyakhistory;
    banyakgame = wordToInt(currentWord);
    for(int i = 0; i < banyakgame;i++){
        InsertLast(games, currentWord);
        ADVWORD();
    }
    ADVWORD();
    banyakhistory = wordToInt(currentWord);
    ADVWORD();
        for(int i = 0; i < banyakhistory;i++){
        PushSG(history, currentWord);
        ADVWORD();
    }

    int j = 1;
    Word nama;
    createWord(&nama);
    while(!isEndWord()){
        banyakscore = wordToInt(currentWord);
        ADVWORD();
        for(int i = 0; i < banyakscore; i++){
            int k = 0;
            CloneWord(&nama, currentWord);
            while(nama.TabWord[k] != ' '){
                k++;
            }
            k++;
            while(nama.TabWord[k] != '\0'){
                nama.TabWord[k] = '\0';
                k++;
            }
            InsertMap(&scores->A[j],nama,sepScore(currentWord));
            ADVWORD();
        }
        j++;
    }
    printf("Save file berhasil dibaca.\n");
}
/*
ASUMSI: filename selalu benar/ada pada folder data
I.S.: arrGame sembarang
F.S.: arrGame terisi dengan game-game dari config yang dipilih dengan nama filename
*/