#ifndef _TOWER_GAME_
#define _TOWER_GAME_

#include "../ADT/stack.h"
#include "../ADT/arrayGame.h"
#include "../ADT/mesinkata.h"
#include "../ADT/Map.h"
#include <math.h>
#include "../ADT/arrayMap.h"

void printKondisi(Stack S1, Stack S2, Stack S3, int jumlahpiringan);
boolean isTowerValid(Stack S, int input);
boolean isInputValid(char input);
void towerGame(arrScore *Scores, int gamebrp);

#endif
