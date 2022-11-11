/*** DRIVER ADT ARRAYGAME ***/

#include "../arrayGame.h"

int main () {
    arrGame arr;
    Game game1, game2, game3, game4;
    

    /* Uji Make Array */
    MakeArray(&arr);

    /* Uji empty */
    if (IsEmpty(arr)) {
        printf("arr kosong.");
    }
    else {
        printf("arr tidak kosong.");
    }

    /* Uji Insert */
    InsertFirst(&arr, game1);
    InsertFirst(&arr, game2);
    InsertLast(&arr, game3);
    InserAt(&arr, game4, 3);
    PrintArray(arr); 
    // Expected ouput: Game1, Game2, Game3, Game4

    /* Uji Length */
    printf("Panjang arr adalah: %d", Length(arr));
    // Expected output: 4

    /* Uji Delete */
    DeleteFirst(&arr);
    DeleteAt(&arr, 1);
    DeleteLast(&arr);
    PrintArray(arr); 
    // Expected ouput: Game2

    return 0;
}
