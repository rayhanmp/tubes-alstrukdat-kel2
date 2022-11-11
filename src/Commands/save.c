#include "save.h"

void save(arrGame* arr, char* filename){ 
    //SET DIRECTORY
    char directory[50] = "data/";
    int i=0,j=0;
    while(directory[i]!='\0'){
        i++;  
    }
    while(filename[j]!='\0')
    {
        directory[i]=filename[j];
        j++;
        i++;
    }
  directory[i]='\0';

    //MEMBUAT FILE
    FILE *file = fopen(directory,"w+");

    //PENGISIAN FILE
    i = 0;
    while(i < Length(*arr)){
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