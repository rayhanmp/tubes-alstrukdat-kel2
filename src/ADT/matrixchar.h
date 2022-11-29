#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "word.h"
typedef struct
{
    Word info[20][20];
    int h;
    int w;
} matrixchar;


void CreateEmptyMatrixChar(matrixchar *m, int h, int w);
/* I.S. m sembarang  */
/* F.S. Terbentuk matrixchar kosong. Dimana isi dari info dari 0,0 sampai h,w berisi ' '. */
void InsertMatrixChar(matrixchar *m, Word c, point p);
/* I.S. m terdefinisi*/
/* F.S. m[Yp(p)][Xp(p)] adalah c*/
void PrintMatrixChar(matrixchar m);
/* I.S. m terdefinisi
   F.S. m tercetak di layar dengan pembatas | dan _*/