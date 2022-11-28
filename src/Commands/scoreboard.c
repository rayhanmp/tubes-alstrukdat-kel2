#include <stdio.h>
#include "Map.h"

int getScore(){
    int i;
    int score = 0;
    for (i = 0; i < listGame; i++){
        score += listGame[i];
    }
    return score;
}

void addScore(int score){
    Map scoreName;
    int i;
    for (i = 0; i < listGame; i++){
        if (scoreName[i] == score){
            scoreName[i] += 1;
        }
    }
}

void sortScore(Map scoreName, boolean key_based){
    Map sorted; 
    CreateEmpty(&sorted);
	int loop = scoreName.Count;
	for (i = 0; i < loop; i++) {
		int keyMin = scoreName.Elements[0].Key;
		int valMin = scoreName.Elements[0].Value;
		for (j = 0; j < scoreName.Count; j++) {
			if (key_based){
				if (scoreName.Elements[j].Key < keyMin) {
					keyMin = scoreName.Elements[j].Key;
					valMin = scoreName.Elements[j].Value;
				}
			} else {	
				if (scoreName.Elements[j].Value < valMin) {
					keyMin = scoreName.Elements[j].Key;
					valMin = scoreName.Elements[j].Value;
				}
			}
		}
        Insert(&sorted, keyMin, valMin);
        Delete(&scoreName, keyMin);
    }
    return sorted;
}


