#include <stdio.h>
#include "help.h"

void help(){
  pritf("===========================NINUNINUNINU===========================\n");
  pritf("===========================HELP===========================");
  pritf("===========================NINUNINUNINU===========================\n");
  printf("1. START - membaca file konfigurasi sistem yang berisi list game yang dapat dimainkan\n");
  printf("2. LOAD - membaca save file yang berisi list game yang dapat dimainkan, histori, dan scoreboard game \n");
  printf("3. SAVE - menyimpan kondisi state game pemain terkini \n");
  printf("4. CREATEGAME - menambahkan game baru pada daftar game \n");
  printf("5. LISTGAME - menampilkan daftar game yang ada pada sistem \n");
  printf("6. DELETEGAME - menghapus sebuah game dari daftar game\n");
  printf("7. QUEUEGAME - mendaftarkan game ke dalam list\n");
  printf("8. PLAYGAME - memainkan sebuah permainan\n");
  printf("9. SKIPGAME - melewatkan permainan sebanyak n \n");
  printf("10. QUIT - keluar dari game\n");
  printf("11. HELP - berisi bantuan atas command-command yang ada\n");
  printf("12. COMMAND LAIN - input command tidak valid atau tidak terdapat \n");
}
