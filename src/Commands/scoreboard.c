#include "scoreboard.h"

void printScoreboard(arrScore Scores, arrGame Games){
    int i = 1;
	while(i < Length(Games)){
			printf("***SCOREBOARD %s***\n", Get(Games, i).TabWord);
			printf("|     NAMA      |  SKOR    |\n");
			printf("----------------------------\n");
            PrintMap(GetArrM(Scores,i));
		i++;
    }
}
/*I.S. Sembarang*/
/*F.S. Menampilkan scoreboard yang berisi nama dan skor pemain yang telah bermain*/