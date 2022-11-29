#include "resetscoreboard.h"

void resetScoreboard(Map RNG, Map dinerDash, Map hangman, Map tower, Map snake, arrGame Games){
    int i = 0;
    while(i < Length(Games)){
        if(isKataEqual(Get(Games,i),"HANGMAN")){
            CreateEmptyMap(&hangman);
        }
        if(isKataEqual(Get(Games,i),"TOWER OF HANOI")){
            CreateEmptyMap(&tower);
        }
        if(isKataEqual(Get(Games,i),"SNAKE ON METEOR")){
            CreateEmptyMap(&snake);
        }
        if(isKataEqual(Get(Games,i),"DINER DASH")){
            CreateEmptyMap(&dinerDash);
        }
    }
}
/*I.S. Sembarang*/
/*F.S. Menghapus semua data dan atau data yang diinginkan pada scoreboard*/