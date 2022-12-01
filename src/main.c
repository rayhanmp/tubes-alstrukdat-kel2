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

// TUGAS BESAR 2
#include "Commands/history.h"
#include "Commands/resethistory.h"
#include "Commands/scoreboard.h"
#include "Commands/saveconfig.h"
#include "Commands/loadconfig.h"



int main(){
    // INISIALISASI ARRAY GAME DAN QUEUE GAME
    arrGame arrayGame;
    MakeArray(&arrayGame);
    arrScore arrayScore;
    MakeArrayM(&arrayScore);
    queueGame qGame;
    CreateQueue(&qGame);
    stackGame sGame;
    CreateEmptySG(&sGame);
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
            setNeffM(&arrayScore, Length(arrayGame));
        }
        else if(isKataEqual(currentWord,"LOAD")){
            ADVWORD_INPUT();
            loadConfig(&arrayGame,&arrayScore, &sGame, currentWord.TabWord);
            setNeffM(&arrayScore, Length(arrayGame));
        }
        else if(isKataEqual(currentWord,"SAVE")){
            ADVWORD_INPUT();
            saveConfig(&arrayGame, &arrayScore, &sGame, currentWord.TabWord);
        }
        else if(isKataEqual(currentWord,"CREATE")){
            ADVWORD_INPUT();
            if(isKataEqual(currentWord,"GAME")){
            createGame(&arrayGame);
            }
            else{
            cmdLain();
            }
        }
        else if(isKataEqual(currentWord,"LIST")){
            ADVWORD_INPUT();
            if(isKataEqual(currentWord,"GAME")){
            listGame(arrayGame);
            }
            else{
            cmdLain();
            }
        }
        else if(isKataEqual(currentWord,"DELETE")){
            ADVWORD_INPUT();
            if(isKataEqual(currentWord,"GAME")){
            deleteGame(&arrayGame,qGame);
            }
            else{
            cmdLain();
            }
        }
        else if(isKataEqual(currentWord,"QUEUE")){
            ADVWORD_INPUT();
            if(isKataEqual(currentWord,"GAME")){
            QueueGame(&qGame,arrayGame);
            }
            else{
            cmdLain();
            }
        }
        else if(isKataEqual(currentWord,"PLAY")){
            ADVWORD_INPUT();
            if(isKataEqual(currentWord,"GAME")){
            printf("Berikut adalah daftar Game-mu\n");
            PrintQueue(qGame);
            printf("\n");
            playGame(&qGame, &sGame, &arrayGame, &arrayScore);
            }
            else{
            cmdLain();
            }
        }
        else if(isKataEqual(currentWord,"SKIP")){
            ADVWORD_INPUT();
            if(isKataEqual(currentWord,"GAME")){
            ADVWORD_INPUT();
            skipGame(&qGame, &sGame, &arrayGame, &arrayScore, wordToInt(currentWord));
            }
            else{
            cmdLain();
            }
        }
        else if(isKataEqual(currentWord,"SCOREBOARD")){
            printScoreboard(arrayScore, arrayGame);
        }
        else if(isKataEqual(currentWord,"HELP")){
            help();
        }
        else if(isKataEqual(currentWord,"QUIT")){
            quit(qGame);
            play = false;
        }
        else if(isKataEqual(currentWord,"HISTORY")){
            ADVWORD_INPUT();
            history(&sGame, wordToInt(currentWord));
        }
        else if(isKataEqual(currentWord,"RESETHISTORY")){
            resetHistory(&sGame);
        }
        else{
            cmdLain();
        }
    }
    return 0;
}

