#include "boolean.h"
#include <stdio.h>
#include "map.h"

int main(){
    Map m;
    int x;
    CreateEmpty(&m);
    Insert(&m,1,5);
    printf("%d\n",Value(m,1));
    printf("expected output : 5\n");
    if (IsMember(m,1)){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    printf("expected output : Yes\n");
    Delete(&m,1);
    if (IsEmpty(m)){
        printf("Yes\n");
    } else {
        printf("No\n");
    }   
    printf("expected output : Yes\n");
    if (IsMember(m,1)){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    printf("expected output : No\n");
    if (IsFull(m)){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    printf("expected output : No\n");
}