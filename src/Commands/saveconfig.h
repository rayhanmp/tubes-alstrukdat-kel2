#ifndef _SAVECFG_H_
#define _SAVECFG_H_

#include "../ADT/mesinkata.h"
#include "../ADT/arrayGame.h"
#include "../ADT/arrayMap.h"
#include "../ADT/stackGame.h"

void saveConfig(arrGame* games, arrScore* scores, stackGame* history, char* filename);
/*
I.S. Array game terdefinisi.
F.S. Procedure membuat sebuah file baru atau me-rewrite file dengan array game yang terdefinisi.
*/

#endif