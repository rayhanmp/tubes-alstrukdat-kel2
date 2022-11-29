#include "scoreboard.h"

void printScoreboard(scoreMap Creategame, scoreMap RNG, scoreMap dinerDash, scoreMap hangman, scoreMap tower, scoreMap snake, arrGame Games){
    int i = 0;
	while(i < Length(Games)){
		if(isKataEqual(Get(Games,i),"HANGMAN")){
			printf("***SCOREBOARD HANGMAN***\n");
			printf("|     NAMA      |  SKOR    |\n");
			printf("----------------------------\n");
            PrintMap(hangman);
		}
        if(isKataEqual(Get(Games,i),"TOWER OF HANOI")){
			printf("***SCOREBOARD TOWER OF HANOI***\n");
			printf("|     NAMA      |  SKOR    |\n");
			printf("----------------------------\n");
            PrintMap(tower);
		}
        if(isKataEqual(Get(Games,i),"SNAKE ON METEOR")){
			printf("***SCOREBOARD SNAKE ON METEOR***\n");
			printf("|     NAMA      |  SKOR    |\n");
			printf("----------------------------\n");
            PrintMap(snake);
		}
        if(isKataEqual(Get(Games,i),"DINER DASH")){
			printf("***SCOREBOARD DINER DASH***\n");
			printf("|     NAMA      |  SKOR    |\n");
			printf("----------------------------\n");
            PrintMap(dinerDash);
		}
    }
}
/*I.S. Sembarang*/
/*F.S. Menampilkan scoreboard yang berisi nama dan skor pemain yang telah bermain*/