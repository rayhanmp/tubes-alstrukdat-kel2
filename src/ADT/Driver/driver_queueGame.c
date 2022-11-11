/*** DRIVER ADT ARRAYGAME ***/

#include "../queueGame.h"

int main () {
    queueGame q;
    Game game1, game2, game3, game4;
    Game out;
    
    game1.Length=4;
    game2.Length=4;
    game3.Length=4;
    game4.Length=4;
    
    game1.TabWord[0] = 'g';
    game1.TabWord[1] = 'i';
    game1.TabWord[2] = 'm';
    game1.TabWord[3] = '1';

    game2.TabWord[0] = 'g';
    game2.TabWord[1] = 'i';
    game2.TabWord[2] = 'm';
    game2.TabWord[3] = '2';
    
    game3.TabWord[0] = 'g';
    game3.TabWord[1] = 'i';
    game3.TabWord[2] = 'm';
    game3.TabWord[3] = '3';

    game4.TabWord[0] = 'g';
    game4.TabWord[1] = 'i';
    game4.TabWord[2] = 'm';
    game4.TabWord[3] = '4';

    /* Uji Make Array */
    CreateQueue(&q);

    /* Uji empty */
    if (IsEmptyQ(q)) {
        printf("Queue kosong.\n");
    }
    else {
        printf("Queue tidak kosong.\n");
    }
    printf("\n");
    // Expected ouput: Queue kosong.

    /* Uji Insert */
    Enqueue(&q, game1);
    Enqueue(&q, game2);
    Enqueue(&q, game3);
    Enqueue(&q, game4);
    
    printf("Isi Queue:\n");
    PrintQueue(q); 
    printf("\n");
    // Expected ouput: Game1, Game2, Game3, Game4

    /* Uji IsMember */
     if (IsMemberQ(q, game3)) {
        printf("Ada di Queue.\n");
    }
    else {
        printf("Tidak ada.\n");
    }
    printf("\n");
    // Expected ouput: Ada di Queue.
  
    /* Uji full */
    if (IsFullQ(q)) {
        printf("Queue penuh.\n");
    }
    else {
        printf("Queue tidak penuh.\n");
    }
    printf("\n");
    // Expected ouput: Queue tidak penuh.

    /* Uji Length */
    printf("Panjang arr adalah: %d\n", LengthQ(q));
    printf("\n");
    // Expected output: 4

    /* Uji Delete */
    Dequeue(&q, &out);
    printf("Isi Queue setelah Dequeue:\n");
    PrintQueue(q); 
    printf("\n");
    // Expected ouput: Game2, Game3, Game4
    printf("Elemen dequeue: ");
    for (int i=0; i<out.Length; i++) {
        printf("%c", out.TabWord[i]);
    }
    return 0;
}
