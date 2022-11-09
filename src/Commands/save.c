#include "save.h"

void save(arrGame* arr, char* filename){
    //MEMBUAT FILE
    FILE *file = fopen(filename,"w+");

    //PENGISIAN FILE
    int i = 0;
    while(i < Length(*arr)){
        printf("<%s>\n",Get(*arr,i).TabWord);
        fputs(Get(*arr,i).TabWord,file);
        fputc('\n', file);
        i++;
    }
    fputc('.',file);
    fclose(file);
}

/*
I.S. Array game terdefinisi.
F.S. Procedure membuat sebuah file baru atau me-rewrite file dengan array game yang terdefinisi.
*/