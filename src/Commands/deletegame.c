#include "deletegame.h"

void cmpStr (char *a, char *b) {
    // masih butuh metode compare inputnya
    while ()
}

void deleteGame (arrGame *arr, queueGame queue) {
    int val;
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintArray(*arr);
    printf("\n");

    printf("Masukkan nomor game yang akan dihapus: ");
    scanf("%d", &val);

    if (val>5) {
        if (!IsMember(queue)) {
                if(cmpStr) { // Masih butuh metode compare
                    DeleteAt(arr, val);
                    printf("Game berhasil dihapus\n");
                    return 0;
                }
        }
    }
    printf("Game gagal dihapus\n");
}
