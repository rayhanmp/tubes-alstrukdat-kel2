#include <stdio.h>
#include <string.h>

int main(){
    int flag = 0;
    char ch[100];
    do{
            printf("Anda keluar dari game BNMO.\n");
            printf("Bye bye...\n");
            flag = 1;
        
            while (!IsEmpty(Q)) {
                Eltype val;
                Dequeue(&Q, val);
            }
                
        }
    while (flag == 0);

    return 0;
    }
