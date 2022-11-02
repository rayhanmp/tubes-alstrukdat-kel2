#include <stdio.h>
#include <string.h>

int main(){
    int flag = 0;
    char ch[100];
    do{
        printf("ENTER COMMAND: ");
        scanf("%s", &ch);
    
        if (strcmp(ch, "QUIT") == 0)
            printf("Anda keluar dari game BNMO.\n");
            printf("Bye bye...\n");
            flag = 1;
        }
    while (flag == 0);

    return 0;
    }
