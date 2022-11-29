#include "resetscoreboard.h"

void resetScoreboard(scoreMap RNG, scoreMap dinerDash, scoreMap hangman, scoreMap tower, scoreMap snake, arrGame Games){
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
