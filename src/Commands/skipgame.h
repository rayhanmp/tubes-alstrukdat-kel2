#ifndef _SKIPGAME_H_
#define _SKIPGAME_H_

#include "../ADT/arrayGame.h"
#include "../ADT/queueGame.h"
#include "../Commands/playgame.h"

void skipGame(queueGame* q, stackGame* s, arrGame* Games, arrScore* Scores, int n);
/*
I.S.: q sembarang, n terdefinisi
F.S.: Elemen Game pada q terdequeue sebanyak n, sistem memainkan Game yang paling pertama di q sekarang
*/

#endif