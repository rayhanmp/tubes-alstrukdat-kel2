#ifndef _TOWER_GAME_
#define _TOWER_GAME_

#include "../ADT/stack.h"
#include "../ADT/arrayGame.h"
#include "../ADT/mesinkata.h"
#include <math.h>

void printKondisi(Stack S1, Stack S2, Stack S3);
void towerGame();
boolean isTowerValid(Stack S, int input);
boolean isInputValid(char input);
#endif
