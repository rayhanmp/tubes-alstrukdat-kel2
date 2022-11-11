#include "Commands/deletegame.h"
#include "Commands/creategame.h"
#include "Commands/commandlain.h"
#include "Commands/load.h"
#include "Commands/quit.h"
#include "Commands/save.h"
#include "Commands/playgame.h"
#include "Commands/listGame.h"
#include "Commands/queueGame.h"
#include "Commands/skipgame.h"
#include "Commands/start.h"
#include "Commands/help.h"
#include "RNGGAME/random_number_generator_ver_2.h"
#include "diner_dash/diner_dash.h"




int main(){
    // INISIALISASI ARRAY GAME DAN QUEUE GAME
    arrGame arrayGame;
    MakeArray(&arrayGame);
    queueGame qGame;
    CreateQueue(&qGame);
    boolean play = true;

    //TITLE PROGRAM
    printf("==================SELAMAT DATANG DI==================\n");
    printf(" /$$$$$$$  /$$   /$$  /$$$$$$  /$$      /$$  /$$$$$$ \n");
    printf("| $$__  $$| $$$ | $$ /$$__  $$| $$$    /$$$ /$$__  $$\n");
    printf("| $$  \\ $$| $$$$| $$| $$  \\ $$| $$$$  /$$$$| $$  \\ $$\n");
    printf("| $$$$$$$ | $$ $$ $$| $$  | $$| $$ $$/$$ $$| $$  | $$\n");
    printf("| $$__  $$| $$  $$$$| $$  | $$| $$  $$$| $$| $$  | $$\n");
    printf("| $$  \\ $$| $$\\  $$$| $$  | $$| $$\\  $ | $$| $$  | $$\n");
    printf("| $$$$$$$/| $$ \\  $$|  $$$$$$/| $$ \\/  | $$|  $$$$$$/\n");
    printf("|_______/ |__/  \\__/ \\______/ |__/     |__/ \\______/ \n");
    printf("=====================================================\n");

    //MAIN PROGRAM
    while(play){
        clearWord();
        printf("MASUKKAN COMMAND: ");
        STARTWORD_INPUT();
        if(isKataEqual(currentWord,"START")){
            start(&arrayGame);
        }
        else if(isKataEqual(currentWord,"LOAD")){
            ADVWORD_INPUT();
            load(&arrayGame, currentWord.TabWord);
        }
        else if(isKataEqual(currentWord,"SAVE")){
            ADVWORD_INPUT();
            save(&arrayGame, currentWord.TabWord);
        }
        else if(isKataEqual(currentWord,"CREATEGAME")){
            createGame(&arrayGame);
        }
        else if(isKataEqual(currentWord,"LISTGAME")){
            listGame(arrayGame);
        }
        else if(isKataEqual(currentWord,"DELETEGAME")){
            deleteGame(&arrayGame,qGame);
        }
        else if(isKataEqual(currentWord,"QUEUEGAME")){
            QueueGame(&qGame,arrayGame);
        }
        else if(isKataEqual(currentWord,"PLAYGAME")){
            playGame(&qGame);
        }
        else if(isKataEqual(currentWord,"SKIPGAME")){
            ADVWORD_INPUT();
            skipGame(&qGame, wordToInt(currentWord));
        }
        else if(isKataEqual(currentWord,"HELP")){
            help();
        }
        else if(isKataEqual(currentWord,"QUIT")){
            quit(qGame);
            play = false;
        }
        else{
            cmdLain();
        }
    }
    return 0;
}

