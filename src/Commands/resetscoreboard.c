#include "resetscoreboard.h"

void resetScoreboard(arrGame games, arrScore *scores){
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    for (int i = 1; i < Length(games); i++){
        printf("%d. %s\n",i,Get(games,i).TabWord);
    }

    printf("SCOREBOARD YANG INGIN DIHAPUS:  \n");
    STARTWORD_INPUT();
    if (isKataEqual(currentWord,"0")){
        printf("APAKAH ANDA YAKIN INGIN MENGHAPUS SEMUA SCOREBOARD? (YA/TIDAK)\n");
        STARTWORD_INPUT();
        if (isKataEqual(currentWord,"YA")){
            for(int i = 1; i < scores->Neff; i++){
                CreateEmptyMap(&scores->A[i]);
            }
            printf("Scoreboard berhasil di-reset\n");
        } 
        else if (isKataEqual(currentWord,"TIDAK")){
            printf("SCOREBOARD TIDAK DI-RESET\n");
        }
    } else{
        Word game;
        createWord(&game);
        CloneWord(&game, Get(games,wordToInt(currentWord)));
        printf("APAKAH ANDA YAKIN INGIN MENGHAPUS SCOREBOARD %s? (YA/TIDAK)\n", game);
        STARTWORD_INPUT();
        if (isKataEqual(currentWord,"YA")){
            CreateEmptyMap(&scores->A[GetArrIdxW(games,game)]);
            printf("Scoreboard berhasil di-reset\n");
        } else if (isKataEqual(currentWord,"TIDAK")){
            printf("SCOREBOARD TIDAK DI-RESET\n");
        }
    // } else if (isKataEqual(currentWord, "2")){
    //     printf("APAKAH ANDA YAKIN INGIN MENGHAPUS SCOREBOARD DINER DASH? (YA/TIDAK)\n");
    //     STARTWORD_INPUT();
    //     if (isKataEqual(currentWord,"YA")){
    //         CreateEmptyMap(&dinerDash);
    //         printf("Scoreboard berhasil di-reset\n");
    //     } else if (isKataEqual(currentWord,"TIDAK")){
    //         printf("SCOREBOARD TIDAK DI-RESET\n");
    //     }
    // } else if (isKataEqual(currentWord, "3")){
    //     printf("APAKAH ANDA YAKIN INGIN MENGHAPUS SCOREBOARD HANGMAN? (YA/TIDAK)\n");
    //     STARTWORD_INPUT();
    //     if (isKataEqual(currentWord,"YA")){
    //         CreateEmptyMap(&hangman);
    //         printf("Scoreboard berhasil di-reset\n");
    //     } else if (isKataEqual(currentWord,"TIDAK")){
    //         printf("SCOREBOARD TIDAK DI-RESET\n");
    //     }
    // } else if (isKataEqual(currentWord, "4")){
    //     printf("APAKAH ANDA YAKIN INGIN MENGHAPUS SCOREBOARD TOWER OF HANOI? (YA/TIDAK)\n");
    //     STARTWORD_INPUT();
    //     if (isKataEqual(currentWord,"YA")){
    //         CreateEmptyMap(&tower);
    //         printf("Scoreboard berhasil di-reset\n");
    //     } else if (isKataEqual(currentWord,"TIDAK")){
    //         printf("SCOREBOARD TIDAK DI-RESET\n");
    //     }
    // } else if (isKataEqual(currentWord, "5")){
    //     printf("APAKAH ANDA YAKIN INGIN MENGHAPUS SCOREBOARD SNAKE ON METEOR? (YA/TIDAK)\n");
    //     STARTWORD_INPUT();
    //     if (isKataEqual(currentWord,"YA")){
    //         CreateEmptyMap(&snake);
    //         printf("Scoreboard berhasil di-reset\n");
    //     } else if (isKataEqual(currentWord,"TIDAK")){
    //         printf("SCOREBOARD TIDAK DI-RESET\n");
        }
    }
/*I.S. Sembarang*/
/*F.S. Menghapus semua data dan atau data yang diinginkan pada scoreboard*/
