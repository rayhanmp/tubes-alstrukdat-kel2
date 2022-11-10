#include <stdio.h>
#include "quit.h"

void quit(queueGame queue){
    int flag = 0;
    do{
            printf("Anda keluar dari game BNMO.\n");
            printf("Bye bye...\n");
            flag = 1;
        
            while (!IsEmptyQ(Q)) {
                Eltype Game;
                Dequeue(&Q, Game);
            }
                
        }
    while (flag == 0);

    return 0;
    }
