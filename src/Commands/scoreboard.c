#include "scoreboard.h"

void sortScoreboard(Map m3, boolean key_based){
	Map m4; 
    	CreateEmpty(&m4);
	int loop = m3.Count;
	for (i = 0; i < loop; i++) {
		int keyMin = m3.Elements[0].Key;
		int valMin = m3.Elements[0].Value;
		for (j = 0; j < m3.Count; j++) {
			if (key_based) {
				if (m3.Elements[j].Key < keyMin) {
					keyMin = m3.Elements[j].Key;
					valMin = m3.Elements[j].Value;
				}
			} else {	
				if (m3.Elements[j].Value < valMin) {
					keyMin = m3.Elements[j].Key;
					valMin = m3.Elements[j].Value;
				}
			}
		}
		Insert(&m4, keyMin, valMin);
		Delete(&m3, keyMin);
	}
	return m4;
}
/* Masih copas-an */
	
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
