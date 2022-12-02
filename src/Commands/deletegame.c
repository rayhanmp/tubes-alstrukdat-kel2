#include "deletegame.h"

void deleteGame (arrGame *games, queueGame q, arrScore *scores) {
    int val;
    /* Tuliskan daftar gim yang tersedia kepada pengguna */
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintArray(*games);
    printf("\n");

    /* Minta masukan kepada pengguna */
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTWORD_INPUT();
    val = wordToInt(currentWord);

    /* Cek kondisi */
    if (val>5) { // Jika bukan 5 gim pertama
        if (!IsMemberQ(q,currentWord)) { // Jika gim tidak terdapat di queueGame
                if(!(isKataEqual(currentWord, "RNG")) && !(isKataEqual(currentWord, "Diner Dash"))) { // Jika gim bukan bawaan sistem (RNG/Diner Dash)
                    DeleteAt(games, val);
                    DeleteAtM(scores,val);
                    int jumlah_game = Length(*games) - 1;
                    Word sum_game;
                    sum_game.Length = 0;
                    //masih bingung kenapa harus di clone 2 kali agar sempurna
                    CloneWord(&sum_game,intToWord(jumlah_game));
                    CloneWord(&sum_game,intToWord(jumlah_game));
                    DeleteFirst(games);
                    InsertFirst(games, sum_game);
                    printf("Game berhasil dihapus\n");
                    return;
                }
        }
    }
    printf("Game gagal dihapus\n"); // Hanya dieksekusi apabila salah satu dari if statement di atas bernilai false
}
