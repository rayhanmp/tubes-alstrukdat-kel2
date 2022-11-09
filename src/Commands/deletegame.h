#ifndef _LOAD_H_
#define _LOAD_H_

#include "../ADT/mesinkata.h"
#include "../ADT/arrayGame.h"
#include "../ADT/queueGame.h"

void deleteGame (arrGame *arr, queueGame queue);
/*
I.S.: arrGame sembarang
F.S.: Elemen arrGame tertentu dihapus apabila game tidak terdapat dalam queue, bukan 5 game pertama, dan merupakan game custom pengguna
*/


#endif
