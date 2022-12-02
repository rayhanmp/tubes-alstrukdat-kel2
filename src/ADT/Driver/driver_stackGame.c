/*** DRIVER ADT STACKGAME ***/

#include "../stackGame.c"

int main() {
    stackGame s;
    Game game1, game2, game3, game4;
    Game out;

    game1.Length = 5;
    game2.Length = 5;
    game3.Length = 5;
    game4.Length = 5;

    game1.TabWord[0] = 'G';
    game1.TabWord[1] = 'A';
    game1.TabWord[2] = 'M';
    game1.TabWord[3] = 'E';
    game1.TabWord[4] = '1';

    game2.TabWord[0] = 'G';
    game2.TabWord[1] = 'A';
    game2.TabWord[2] = 'M';
    game2.TabWord[3] = 'E';
    game2.TabWord[4] = '2';

    game3.TabWord[0] = 'G';
    game3.TabWord[1] = 'A';
    game3.TabWord[2] = 'M';
    game3.TabWord[3] = 'E';
    game3.TabWord[4] = '3';

    game4.TabWord[0] = 'G';
    game4.TabWord[1] = 'A';
    game4.TabWord[2] = 'M';
    game4.TabWord[3] = 'E';
    game4.TabWord[4] = '4';

    /* Uji Membuat Stack Game Kosong */
    CreateEmptySG(&s);

    /* Uji Stack Game Kosong */
    if (IsEmptySG(s)){
        printf("Stack game kosong.\n");
    } else {
        printf("Stack game tidak kosong.\n");
    }
    printf("\n");
    // Expected output: Stack game kosong.

    /* Uji Push Stack Game */
    PushSG(&s, game1);
    PushSG(&s, game2);
    PushSG(&s, game3);
    PushSG(&s, game4);

    /* Uji Print Stack Game */
    printf("Isi Stack Game:\n");
    PrintAllSG(s);
    printf("\n");
    // Expected output: GAME4 GAME3 GAME2 GAME1

    /* Uji Banyak Elemen Stack Game */
    int lenSG = LengthSG(s);
    printf("Length Stack Game: %d\n", lenSG);
    printf("\n");
    // Expected output: 4                                                                                                           

    /* Uji Stack Game Penuh */
    if (IsFullSG(s)) {
        printf("Stack game penuh.\n");
    } else {
        printf("Stack game tidak penuh.\n");
    }
    printf("\n");
    // Expected output: Stack game tidak penuh.

    /* Uji Copy Stack Game */
    stackGame sCopy; CreateEmptySG(&sCopy);
    CopyStackSG(s, &sCopy);

    printf("Isi Stack Game (Awal):\n");
    PrintAllSG(s);
    // Expected output: GAME4 GAME3 GAME2 GAME1
    printf("\n");
    printf("Isi Stack Game (Copy):\n");
    PrintAllSG(s);
    // Expected output: GAME4 GAME3 GAME2 GAME1
    printf("\n");

    /* Uji Pop Stack Game */
    PopSG(&s, &out);
    printf("Isi Stack Game setelah Pop:\n");
    PrintAllSG(s);
    printf("\n");
    // Expected output: GAME3 GAME2 GAME1
    printf("Elemen Pop: ");
    for (int i=0; i < out.Length; i++){
        printf("%c", out.TabWord[i]);
    }
    printf("\n");
    // Expected output: GAME4

    return 0;
}