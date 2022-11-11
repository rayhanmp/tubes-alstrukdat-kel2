/* test_queue*/

#include "queuedd.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    QueueDD q;
    int x;
    int a,b,c,d;
    CreateQueuedd(&q);
    if (isEmptydd(q)){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    printf("Expected value : Yes");    

    for(int i = 1; i < 4; i++){
        enqueuedd(&q, i, i+10,i+20,i+30);
    }
    printf("%d\n",lengthdd(q));
    printf("Expected value : 3\n");
    displayQueuedd(q);

    printf("Expected value  [(1,11,21,31),(2,12,22,32),(3,13,23,33)]\n");
    dequeuedd(&q, &a,&b,&c,&d);
    printf("%d %d %d %d\n",a,b,c,d);
    printf("Expected value : 1 11 21 31\n");
    displayQueuedd(q);    
    printf("Expected value  [(2,12,22,32),(3,13,23,33)]\n");
    takeValue(q, 2,&b,&c,&d);
    printf("%d %d %d\n",b,c,d);
}