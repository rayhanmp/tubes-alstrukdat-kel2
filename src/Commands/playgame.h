#ifndef _PLAYGAME_H_
#define _PLAYGAME_H_

#include "../ADT/arrayGame.h"
#include "../ADT/queueGame.h"
#include "../diner_dash/diner_dash.h"
#include "../RNGGAME/rnggame.h"
#include "../gameTambahan/gametambahan.h"

void playGame (queueGame* q);
/*
I.S.: q terdefinisi, currentGame Nil (?)
F.S.: q berkurang satu, currentGame adalah elemen pertama q sebelum dihapus
*/

#endif