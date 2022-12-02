#include "saveKamus.h"

void saveKamus(arrGame* arrKata, char* filename){ 
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
    while(i < Length(*arrKata)){
        fputs(Get(*arrKata,i).TabWord,file);
        fputc('\n', file);
        i++;
    }
    fputc('.',file);
    fclose(file);
    printf("Kamus berhasil diperbaharui.\n"); 
}

/*
I.S. arrKataay game terdefinisi.
F.S. Procedure membuat sebuah file baru atau me-rewrite file dengan arrKata yang terdefinisi.
*/