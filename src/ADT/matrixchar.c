#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "matrixchar.h"



void CreateEmptyMatrixChar(matrixchar *m,int h, int w){
    Word space;
    createWord(&space);
    InsertLastW(&space, "  ");
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            CloneWord(&m->info[i][j], space);
        }
    }
    m->h = h;
    m->w = w;
}

void InsertMatrixChar(matrixchar *m, Word c, point p){
    CloneWord(&m->info[Yp(p)][Xp(p)], c);
}

void PrintMatrixChar(matrixchar m){
    for(int i = 0; i < m.h; i++){
        for(int j = 0; j < m.w; j++){
            printf("|");
            printWord(m.info[i][j]);
        }
        printf("|\n|");
        for(int j = 0; j < m.w; j++){
            printf("__|");
        }
        printf("\n");
        }
}