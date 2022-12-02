/*** DRIVER ADT MAP ***/

#include "../map.h"

int main(){
    scoreMap M;
    Word name1, name2, name3, name4;
    CreateEmptyMap(&M);
    if (IsEmptyMap(M)){
        printf("Map kosong.");
    }
    else{
        printf("Map tidak kosong.");
    }
    // Expected output: Map kosong.
    InsertMap(&M, name1, 100);
    InsertMap(&M, name2, 200);
    InsertMap(&M, name3, 300);
    InsertMap(&M, name4, 400);
    countMap(M);
    printf("%d", countMap(M));
    // Expected output: 4
    PrintMap(M);
    // Expected output: name1: 100, name2: 200, name3: 300, name4: 400
    if(IsFullMap(M)){
        printf("Map penuh.");
    }
    else{
        printf("Map tidak penuh.");
    }
    // Expected output: Map tidak penuh.
    if(IsMemberMap(M, name1)){
        printf("name1 ada di Map.");
    }
    else{
        printf("name1 tidak ada di Map.");
    }
    // Expected output: name1 ada di Map.
    DeleteMap(&M, name2);
    printf("%d", countMap(M));
    // Expected output: 3
    PrintMap(M);
    // Expected output: name1: 100, name3: 300, name4: 400

}
