#include "deletegame.h"

void deleteGame (arrGame *arr, queueGame q) {
    int val;
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintArray(*arr);
    printf("\n");

    printf("Masukkan nomor game yang akan dihapus: ");
    clearWord();
    STARTWORD_INPUT();
    val = wordToInt(currentWord);

    if (val>5) {
        if (!IsMember(q)) {
                if(!(isKataEqual(currentWord, "RNG")) && !(isKataEqual(currentWord, "Diner Dash"))) {
                    DeleteAt(&arr, val);
                    printf("Game berhasil dihapus\n");
                    return 0;
                }
        }
    }
    printf("Game gagal dihapus\n");
}
