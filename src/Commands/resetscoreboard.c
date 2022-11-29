#include "resetscoreboard.h"

void resetScoreboard(scoreMap RNG, scoreMap dinerDash, scoreMap hangman, scoreMap tower, scoreMap snake, arrGame Games){
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    for (int i = 1; i <= Length(Games); i++){
        printf("%d. %s\n",i,Get(Games,i).TabWord);
    }

    printf("SCOREBOARD YANG INGIN DIHAPUS:  \n");
    STARTWORD_INPUT();
    if (isKataEqual(currentWord,"0")){
        printf("APAKAH ANDA YAKIN INGIN MENGHAPUS SEMUA SCOREBOARD? (YA/TIDAK)\n");
        STARTWORD_INPUT();
        if (isKataEqual(currentWord,"YA")){
            CreateEmptyMap(&RNG);
            CreateEmptyMap(&dinerDash);
            CreateEmptyMap(&hangman);
            CreateEmptyMap(&tower);
            CreateEmptyMap(&snake);
            printf("Scoreboard berhasil di-reset\n");
        } else if (isKataEqual(currentWord,"TIDAK")){
            printf("SCOREBOARD TIDAK DI-RESET\n");
        }
    } else if (isKataEqual(currentWord,"1")){
        printf("APAKAH ANDA YAKIN INGIN MENGHAPUS SCOREBOARD RNG? (YA/TIDAK)\n");
        STARTWORD_INPUT();
        if (isKataEqual(currentWord,"YA")){
            CreateEmptyMap(&RNG);
            printf("Scoreboard berhasil di-reset\n");
        } else if (isKataEqual(currentWord,"TIDAK")){
            printf("SCOREBOARD TIDAK DI-RESET\n");
        }
    } else if (isKataEqual(currentWord, "2")){
        printf("APAKAH ANDA YAKIN INGIN MENGHAPUS SCOREBOARD DINER DASH? (YA/TIDAK)\n");
        STARTWORD_INPUT();
        if (isKataEqual(currentWord,"YA")){
            CreateEmptyMap(&dinerDash);
            printf("Scoreboard berhasil di-reset\n");
        } else if (isKataEqual(currentWord,"TIDAK")){
            printf("SCOREBOARD TIDAK DI-RESET\n");
        }
    } else if (isKataEqual(currentWord, "3")){
        printf("APAKAH ANDA YAKIN INGIN MENGHAPUS SCOREBOARD HANGMAN? (YA/TIDAK)\n");
        STARTWORD_INPUT();
        if (isKataEqual(currentWord,"YA")){
            CreateEmptyMap(&hangman);
            printf("Scoreboard berhasil di-reset\n");
        } else if (isKataEqual(currentWord,"TIDAK")){
            printf("SCOREBOARD TIDAK DI-RESET\n");
        }
    } else if (isKataEqual(currentWord, "4")){
        printf("APAKAH ANDA YAKIN INGIN MENGHAPUS SCOREBOARD TOWER OF HANOI? (YA/TIDAK)\n");
        STARTWORD_INPUT();
        if (isKataEqual(currentWord,"YA")){
            CreateEmptyMap(&tower);
            printf("Scoreboard berhasil di-reset\n");
        } else if (isKataEqual(currentWord,"TIDAK")){
            printf("SCOREBOARD TIDAK DI-RESET\n");
        }
    } else if (isKataEqual(currentWord, "5")){
        printf("APAKAH ANDA YAKIN INGIN MENGHAPUS SCOREBOARD SNAKE ON METEOR? (YA/TIDAK)\n");
        STARTWORD_INPUT();
        if (isKataEqual(currentWord,"YA")){
            CreateEmptyMap(&snake);
            printf("Scoreboard berhasil di-reset\n");
        } else if (isKataEqual(currentWord,"TIDAK")){
            printf("SCOREBOARD TIDAK DI-RESET\n");
        }
    }
}
/*I.S. Sembarang*/
/*F.S. Menghapus semua data dan atau data yang diinginkan pada scoreboard*/
