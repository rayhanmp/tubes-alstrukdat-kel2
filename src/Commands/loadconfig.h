#ifndef _LOADCFG_H_
#define _LOADCFG_H_

#include "../ADT/arrayGame.h"
#include "../ADT/word.h"
#include "../ADT/stackGame.h"
#include "../ADT/arrayMap.h"

int sepScore(Word word);
void loadConfig(arrGame* games, arrScore* scores, stackGame* history, char* filename);
/*
I.S.: arrGame sembarang
F.S.: arrGame terisi dengan game-game dari config yang dipilih dengan nama filename
*/

#endif