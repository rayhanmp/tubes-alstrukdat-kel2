#include "gametambahan.h"

void gametambahan(arrScore *Scores, int gamebrp){
    long long skor = rng(1,1000); // min max?
    printf("GAME OVER!\n");
    printf("Skor Akhir: %lld\n", skor);
        printf("Masukkan Nama:");
        STARTWORD_INPUT();
    if(IsEmptyMap(GetArrM(*Scores, gamebrp))){
        CreateEmptyMap(&Scores->A[gamebrp]);
        InsertMap(&Scores->A[gamebrp], currentWord, skor);
        printf("Score berhasil ditambahkan!\n");
    }
    else{
        while(IsMemberMap(GetArrM(*Scores,gamebrp),currentWord)){
            printf("Nama sudah ada! silahkan input ulang: ");
            STARTWORD_INPUT();
        }
        InsertMap(&Scores->A[gamebrp], currentWord, skor);
        printf("Score berhasil ditambahkan!\n");
    }

}