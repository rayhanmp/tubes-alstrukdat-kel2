#ifndef diner_dash_H
#define diner_dash_H
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "../boolean.h"
#include "map.h"
#include "queuedd.h"
#include "random_number_generator.h"
#include "random_number_generator_ver_2.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include "../ADT/word.h"
#include "../ADT/arrayMap.h"

void displayCook(Map m);
/*I.S. Map m terdefinis
  F.S. isi dari m tercetak sesuai dengan format*/
void displayErrand(QueueDD q);
/*I.S. QueueDD q terdefinis
  F.S. isi dari q tercetak sesuai dengan format*/
void displayServe(Map m);
/*I.S. Map m terdefinis
  F.S. isi dari m tercetak sesuai dengan format*/
void displaySeparator();
/* I.S. sembarang
   F.S. Menceta = berkali-kali ke terminal*/
int diner_dash(arrScore *Scores, int gamebrp);



#endif 

