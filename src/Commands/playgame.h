#ifndef _PLAYGAME_H_
#define _PLAYGAME_H_

#include "../ADT/arrayGame.h"
#include "../ADT/queueGame.h"
#include "../ADT/stackGame.h"
#include "../diner_dash/diner_dash.h"
#include "../RNGGAME/rnggame.h"
#include "../gameTambahan/gametambahan.h"
#include "../prs/prs.h"
#include "../hangman/hangman.h"
#include "../Tower_of_Hanoi/towergame.h"

void playGame (queueGame* q, stackGame* s, arrGame* Games, arrScore* Scores);
/*
I.S.: q terdefinisi, currentGame Nil (?)
F.S.: q berkurang satu, currentGame adalah elemen pertama q sebelum dihapus
*/

#endif