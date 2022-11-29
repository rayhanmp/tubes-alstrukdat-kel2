#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "matrixchar.h"



void CreateEmptyMatrixChar(matrixchar *m,int h, int w){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            m->info[i][j] = ' ';
        }
    }
    m->h = h;
    m->w = w;
}

void InsertMatrixChar(matrixchar *m, char c, point p){
    m->info[Yp(p)][Xp(p)] = c;
}

void PrintMatrixChar(matrixchar m){
    for(int i = 0; i < m.h; i++){
        for(int j = 0; j < m.w; j++){
            printf("|%c",m.info[i][j]);
        }
        printf("|\n|");
        for(int j = 0; j < m.w; j++){
            printf("_|");
        }
        printf("\n");
        }
}