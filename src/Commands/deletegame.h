#ifndef _DELETEGAME_H_
#define _DELETEGAME_H_

#include "../ADT/arrayGame.h"
#include "../ADT/queueGame.h"
#include "../ADT/arrayMap.h"

void deleteGame (arrGame *games, queueGame q, arrScore *scores);
/*
I.S.: arrGame sembarang
F.S.: Elemen arrGame tertentu dihapus apabila game tidak terdapat dalam queue, bukan 5 game pertama, dan merupakan game custom pengguna
*/

#endif
