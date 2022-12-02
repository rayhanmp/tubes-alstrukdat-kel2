#include <stdio.h>
#include "help.h"

void help(){  
  printf("██╗░░██╗███████╗██╗░░░░░██████╗░\n");
  printf("██║░░██║██╔════╝██║░░░░░██╔══██╗\n");
  printf("███████║█████╗░░██║░░░░░██████╔╝\n");
  printf("██╔══██║██╔══╝░░██║░░░░░██╔═══╝░\n");
  printf("██║░░██║███████╗███████╗██║░░░░░\n");
  printf("╚═╝░░╚═╝╚══════╝╚══════╝╚═╝░░░░░\n");
  printf("\nWelcome to the help menu!\n");
  printf("Here are the available commands:\n");
  printf("1. START - membaca file konfigurasi sistem yang berisi list game yang dapat dimainkan\n");
  printf("2. LOAD - membaca save file yang berisi list game yang dapat dimainkan, histori, dan scoreboard game \n");
  printf("3. SAVE - menyimpan kondisi state game pemain terkini \n");
  printf("4. CREATEGAME - menambahkan game baru pada daftar game \n");
  printf("5. LISTGAME - menampilkan daftar game yang ada pada sistem \n");
  printf("6. DELETEGAME - menghapus sebuah game dari daftar game\n");
  printf("7. QUEUEGAME - mendaftarkan game ke dalam list\n");
  printf("8. PLAYGAME - memainkan sebuah permainan\n");
  printf("9. SKIPGAME - melewatkan permainan sebanyak n \n");
  printf("10. SCOREBOARD - menampilkan nama pemain dan score\n");
  printf("11. RESET SCOREBOARD - mengosongkan data pemain dan score pada scoreboard\n");
  printf("12. HISTORY - menampilkan riwayat permainan yang pernah dimainkan\n");
  printf("13. RESET HISTORY - mengosongkan riwayat game yang dimainkan pemain\n");
  printf("14. QUIT - keluar dari game\n");
  printf("15. HELP - berisi bantuan atas command-command yang ada\n");
  printf("16. COMMAND LAIN - input command tidak valid atau tidak terdapat \n");
}
