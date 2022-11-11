#include "../mesinkata.h"

int main(){
    //MEMINTA MASUKKAN
    STARTWORD_INPUT();
    printf("masukan:");
    //JIKA MASUKKAN LEBIH DARI 1 KATA
    while(!isEndWord()){
        printf(" %s", currentWord.TabWord);
        ADVWORD_INPUT();
    }
    return 0;
}