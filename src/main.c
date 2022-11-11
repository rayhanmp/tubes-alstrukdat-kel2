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
    // INISIALISASI ARRAY GAME
    arrGame arrayGame;
    MakeArray(&arrayGame);
    queueGame qGame;
    CreateQueue(&qGame);
    boolean play = true;

    //MAIN PROGRAM
    printf(" /$$$$$$$  /$$   /$$  /$$$$$$  /$$      /$$  /$$$$$$ \n");
    printf("| $$__  $$| $$$ | $$ /$$__  $$| $$$    /$$$ /$$__  $$\n");
    printf("| $$  \\ $$| $$$$| $$| $$  \\ $$| $$$$  /$$$$| $$  \\ $$\n");
    printf("| $$$$$$$ | $$ $$ $$| $$  | $$| $$ $$/$$ $$| $$  | $$\n");
    printf("| $$__  $$| $$  $$$$| $$  | $$| $$  $$$| $$| $$  | $$\n");
    printf("| $$  \\ $$| $$\\  $$$| $$  | $$| $$\\  $ | $$| $$  | $$\n");
    printf("| $$$$$$$/| $$ \\  $$|  $$$$$$/| $$ \\/  | $$|  $$$$$$/\n");
    printf("|_______/ |__/  \\__/ \\______/ |__/     |__/ \\______/ \n");

    
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
            ADVWORD_INPUT();
            createGame(&arrayGame);
        }
        else if(isKataEqual(currentWord,"LISTGAME")){
            ADVWORD_INPUT();
            listGame(arrayGame);
        }
        else if(isKataEqual(currentWord,"DELETEGAME")){
            ADVWORD_INPUT();
            deleteGame(&arrayGame,qGame);
        }
        else if(isKataEqual(currentWord,"QUEUEGAME")){
            ADVWORD_INPUT();
            QueueGame(&qGame,arrayGame);
        }
        else if(isKataEqual(currentWord,"PLAYGAME")){
            ADVWORD_INPUT();
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

