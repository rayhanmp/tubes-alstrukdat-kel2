#include "scoreboard.h"

void printScoreboard(arrScore Scores, arrGame Games){
    int i = 1;
	while(i < Length(Games)){
		if(IsEmptyMap(GetArrM(Scores,i))){
			printf("***SCOREBOARD %s***\n", Get(Games, i).TabWord);
			printf("|     NAMA      |  SKOR    |\n");
			printf("----------------------------\n");
            printf("|       SCORE KOSONG       |\n");
			printf("----------------------------\n");
		}
		else{
			printf("***SCOREBOARD %s***\n", Get(Games, i).TabWord);
			printf("|     NAMA      |  SKOR    |\n");
			printf("----------------------------\n");
            PrintMap(GetArrM(Scores,i));
			printf("----------------------------\n");
		}
		i++;
    }
}
/*I.S. Sembarang*/
/*F.S. Menampilkan scoreboard yang berisi nama dan skor pemain yang telah bermain*/