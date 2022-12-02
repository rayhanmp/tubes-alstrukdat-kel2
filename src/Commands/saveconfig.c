#include "saveconfig.h"

void fputName(Word name, FILE *file){
    for(int i = 0; i < name.Length; i++){
        fputc(name.TabWord[i],file);
    }
}
void saveConfig(arrGame* games, arrScore* scores, stackGame* history, char* filename){ 
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
    //GAMES
    i = 0;
    while(i < Length(*games)){
        fputs(Get(*games,i).TabWord,file);
        fputc('\n', file);
        i++;
    }
    //HISTORY
    fprintf(file, "%d", LengthSG(*history));
    fputc('\n', file);
    stackGame temp;
    Game X;
    CopyStackSG(*history,&temp);
    while(!IsEmptySG(temp)){
        PopSG(&temp,&X);
        fputs(X.TabWord, file);
        fputc('\n', file);
    }
    //SCORES
    i = 1;
    while(i < LengthArrM(*scores)){
        j = 0;
        fprintf(file, "%d", countMap(GetArrM(*scores,i)));
        fputc('\n', file);
        while(j <countMap(scores->A[i])){
            fputName(GetArrM(*scores,i).Elements[j].Name,file);
            fputc(' ', file);
            fprintf(file, "%d", GetArrM(*scores,i).Elements[j].Score);
            fputc('\n', file);
            j++;
        }
        i++;
    }
    fputc('.',file);
    fclose(file);
    printf("Save file berhasil disimpan.\n"); 
}

/*
I.S. Array game terdefinisi.
F.S. Procedure membuat sebuah file baru atau me-rewrite file dengan array game yang terdefinisi.
*/