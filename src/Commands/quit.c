#include <stdio.h>
#include "quit.h"

void quit(queueGame queue){
    int flag = 0;
            printf("Anda keluar dari game BNMO.\n");
            printf("Bye bye...\n");
            flag = 1;
        
            while (!IsEmptyQ(queue)) {
                Game Game;
                Dequeue(&queue, &Game);
            }

    }
