/*** DRIVER ADT ARRAYGAME ***/

#include "../arrayGame.h"

int main () {
    arrGame arr;

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
    InsertFirst(&arr, "Game1");
    InsertFirst(&arr, "Game2");
    InsertLast(&arr, "Game4");
    InserAt(&arr, "Game3", 2);
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
