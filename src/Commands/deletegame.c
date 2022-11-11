#include "deletegame.h"

void deleteGame (arrGame *arr, queueGame q) {
    int val;
    /* Tuliskan daftar gim yang tersedia kepada pengguna */
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintArray(*arr);
    printf("\n");

    /* Minta masukan kepada pengguna */
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTWORD_INPUT();
    val = wordToInt(currentWord);

    /* Cek kondisi */
    if (val>5) { // Jika bukan 5 gim pertama
        if (!IsMemberQ(q)) { // Jika gim tidak terdapat di queueGame
                if(!(isKataEqual(currentWord, "RNG")) && !(isKataEqual(currentWord, "Diner Dash"))) { // Jika gim bukan bawaan sistem (RNG/Diner Dash)
                    DeleteAt(arr, val);
                    printf("Game berhasil dihapus\n");
                    return 0; // Early return agar printf di bawahnya tidak dieksekusi
                }
        }
    }
    printf("Game gagal dihapus\n"); // Hanya dieksekusi apabila salah satu dari if statement di atas bernilai false
}
