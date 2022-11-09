#include "ADT/mesinkata.h"
#include "ADT/mesinkarakter.h"
#include "Commands/load.h"
#include "Commands/save.h"
#include "ADT/arrayGame.h"

int main(){
    //INISIALISASI ARRAY GAME
    arrGame arr;
    MakeArray(&arr);

    //MAIN PROGRAM
    printf(" /$$$$$$$  /$$   /$$  /$$$$$$  /$$      /$$  /$$$$$$ \n");
    printf("| $$__  $$| $$$ | $$ /$$__  $$| $$$    /$$$ /$$__  $$\n");
    printf("| $$  \\ $$| $$$$| $$| $$  \\ $$| $$$$  /$$$$| $$  \\ $$\n");
    printf("| $$$$$$$ | $$ $$ $$| $$  | $$| $$ $$/$$ $$| $$  | $$\n");
    printf("| $$__  $$| $$  $$$$| $$  | $$| $$  $$$| $$| $$  | $$\n");
    printf("| $$  \\ $$| $$\\  $$$| $$  | $$| $$\\  $ | $$| $$  | $$\n");
    printf("| $$$$$$$/| $$ \\  $$|  $$$$$$/| $$ \\/  | $$|  $$$$$$/\n");
    printf("|_______/ |__/  \\__/ \\______/ |__/     |__/ \\______/ \n");

    while(true){
        clearWord();
        printf("MASUKKAN COMMAND: ");
        STARTWORD_INPUT();
        if(isKataEqual(currentWord,"SAVE")){
            ADVWORD_INPUT();
            save(&arr, currentWord.TabWord);
        }
        else if(isKataEqual(currentWord,"LOAD")){
            ADVWORD_INPUT();
            load(&arr, currentWord.TabWord);
            }
        else{
            printf("command tidak tersedia.\n");
        }
    }
    return 0;
}

