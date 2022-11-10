/* queue.c
18221152
Raditya Azka Prabaswara*/


#include "queuedd.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreateQueuedd(QueueDD *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;    
}

/* ********* Prototype ********* */
boolean isEmptydd(QueueDD q){
    return ((IDX_TAIL(q) == IDX_UNDEF) && (IDX_HEAD(q) == IDX_UNDEF));
}

boolean isFulldd(QueueDD q){
    if (IDX_HEAD(q) == 0){
        return (IDX_TAIL(q) == (CAPACITY - 1));
    } else {
        return (IDX_TAIL(q) == IDX_HEAD(q)- 1);
    }
}


int lengthdd(QueueDD q){
    if (isEmptydd(q)){
        return 0;
    }
    else {
        int i;
        int x;
        i = IDX_HEAD(q);
        x = 0;
        while (i != IDX_TAIL(q)){
            x++;
            i = (i + 1) % CAPACITY;
        }
        return (x + 1);
    }
}


/* *** Primitif Add/Delete *** */
void enqueuedd(QueueDD *q, int key, int duration, int spoliage, int price){
    if (isEmptydd(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY; 
    }
    TAIL_ID(*q) = key;
    TAIL_DUR(*q) = duration;
    TAIL_SP(*q) = spoliage;
    TAIL_PR(*q) = price;
}

void dequeuedd(QueueDD *q, int *key, int *duration, int *spoliage, int *price){
    *key = HEAD_ID(*q) ;
    *duration = HEAD_DUR(*q) ;
    *spoliage = HEAD_SP(*q) ;
    *price  = HEAD_PR(*q) ;
    if (lengthdd(*q) == 1){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        if (IDX_HEAD(*q) == (CAPACITY-1)){
            IDX_HEAD(*q) = 0;
        } else {
            IDX_HEAD(*q)++;
        }
    }
}

/* *** Display Queue *** */
void displayQueuedd(QueueDD q){
    int key,duration,spoliage,price;
    printf("[");
    if (!(isEmptydd(q))){
        dequeuedd(&q, &key, &duration, &spoliage, &price);
        printf("(%d,%d,%d,%d)",key,duration,spoliage,price);
    }
    while(!(isEmptydd(q))){
        dequeuedd(&q, &key, &duration, &spoliage, &price);
        printf(",(%d,%d,%d,%d)",key,duration,spoliage,price); 
    }
    printf("]\n");
}

void takeValue(QueueDD q, int key, int *duration, int *spoliage, int *price){
    boolean found = false;
    int i;
    while ((!found)&&(!isEmptydd(q)) ){
        dequeuedd(&q, &i, duration, spoliage, price);
        if (i == key){
            found = true;
        }
    }
}