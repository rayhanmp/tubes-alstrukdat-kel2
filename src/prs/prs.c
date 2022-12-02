#include "prs.h"

void prs(arrScore *Scores, int gamebrp) {
  /* Definisikan, inisiasi, dan isi variabel*/
  int round, num, i, skorAnda, skorLawan;
  arrGame arrKata;
  Word Paper, Rock, Scissor;
  MakeArray(&arrKata);
  
  skorAnda = 0;
  skorLawan = 0;
  
  /* Pengisian Kata ke Array */
  
  Paper.Length = 5;
  Rock.Length = 4;
  Scissor.Length = 7;
  
  Paper.TabWord[0] = 'P';
  Paper.TabWord[1] = 'A';
  Paper.TabWord[2] = 'P';
  Paper.TabWord[3] = 'E';
  Paper.TabWord[4] = 'R';

  Rock.TabWord[0] = 'R';
  Rock.TabWord[1] = 'O';
  Rock.TabWord[2] = 'C';
  Rock.TabWord[3] = 'K';

  
  Scissor.TabWord[0] = 'S';
  Scissor.TabWord[1] = 'C';
  Scissor.TabWord[2] = 'I';
  Scissor.TabWord[3] = 'S';
  Scissor.TabWord[4] = 'S';
  Scissor.TabWord[5] = 'O';
  Scissor.TabWord[6] = 'R';
  
  InsertLast(&arrKata, Rock);
  InsertLast(&arrKata, Paper);
  InsertLast(&arrKata, Scissor);
  
  /* Inisiasi srand */
  srand(time(NULL));
  
  /* Tuliskan tampilan awal dan aturan */
  printf("___  ____ ___  ____ ____    ____ ____ ____ _  _    ____ ____ _ ____ ____ ____ ____ \n");
  printf("|__] |__| |__] |___ |__/    |__/ |  | |    |_/     [__  |    | [__  [__  |  | |__/ \n");
  printf("|    |  | |    |___ |  \\    |  \\ |__| |___ | \\_    ___] |___ | ___] ___] |__| |  \\ \n");
  printf("\n");
  printf("\n");
  
  printf("Aturan:\n");
  printf("Rock vs Paper -> Paper\n");
  printf("Rock vs Scissor -> Rock\n");
  printf("Paper vs Scissor -> Scissor\n");
  printf("Paper vs Rock -> Paper\n");
  
  printf("INPUT HARUS DALAM HURUF KAPITAL\n");

  /* Minta masukan dari pengguna */
  printf("Masukan jumlah ronde (3/5/7/9): ");
  STARTWORD_INPUT();
  round = wordToInt(currentWord);
  
  while (!(round == 3 || round==5 || round==7 || round ==9)) {
    printf("Input tidak valid.\n");
    printf("Masukan jumlah ronde (3/5/7/9): ");
    STARTWORD_INPUT();
    round = wordToInt(currentWord);
  }
  
  printf("\n");
  printf("\n");
  
  /* Bagian utama permainan */
  printf("GAME DIMULAI...\n");
  printf("----------------------------------------------------------------\n");
  
  /* Main loop */
  for (i=0; i<round; i++) {
    printf("ROUND %d...\n", i+1);
    printf("Pilihan Anda (ROCK/PAPER/SCISSOR): ");
    STARTWORD_INPUT();
    printf("\n");
    
    while (!((isIdentical(currentWord, arrKata.A[0]) || (isIdentical(currentWord, arrKata.A[1]) || (isIdentical(currentWord, arrKata.A[2])))))) {
      printf("Input tidak valid.\n");
      printf("Input harus ditulis dengan huruf kapital, misal: ROCK\n");
      STARTWORD_INPUT();
    }
    if (isIdentical(currentWord, arrKata.A[0])) {
      num = rand() % 3;
            if (num==0) {
              printf("Pilihan Anda: %s\n", arrKata.A[0].TabWord);
              printf("Pilihan Lawan: %s\n", arrKata.A[0].TabWord);
              printf("Hasil: SERI\n");
            }
            else if (num==1) {            
              printf("Pilihan Anda: %s\n", arrKata.A[0].TabWord);
              printf("Pilihan Lawan: %s\n", arrKata.A[1].TabWord);
              printf("Hasil: KALAH\n");
              printf("SkorLawan +100\n");
              skorLawan += 100;
            }
            else {            
              printf("Pilihan Anda: %s\n", arrKata.A[0].TabWord);
              printf("Pilihan Lawan: %s\n", arrKata.A[2].TabWord);
              printf("Hasil: MENANG\n");
              printf("SkorAnda +100\n");
              skorAnda += 100;
            }
        }
    else if (isIdentical(currentWord, arrKata.A[1])) {
            num = rand() % 3;
            if (num==0) {            
              printf("Pilihan Anda: %s\n", arrKata.A[1].TabWord);
              printf("Pilihan Lawan: %s\n", arrKata.A[0].TabWord);
              printf("Hasil: MENANG\n");
              printf("SkorAnda +100\n");
              skorAnda += 100;
            }
            else if (num==1) {            
              printf("Pilihan Anda: %s\n", arrKata.A[1].TabWord);
              printf("Pilihan Lawan: %s\n", arrKata.A[1].TabWord);
              printf("Hasil: SERI\n");
            }
            else {            
              printf("Pilihan Anda: %s\n", arrKata.A[1].TabWord);
              printf("Pilihan Lawan: %s\n", arrKata.A[2].TabWord);
              printf("Hasil: KALAH\n");
              printf("skorLawan +100\n");
              skorLawan += 100;
            }
        }
    else if (isIdentical(currentWord, arrKata.A[2])) {
            num = rand() % 3;
            if (num==0) {            
              printf("Pilihan Anda: %s\n", arrKata.A[2].TabWord);
              printf("Pilihan Lawan: %s\n", arrKata.A[0].TabWord);
              printf("Hasil: KALAH\n");
              printf("skorLawan +100\n");
              skorLawan += 100;
            }
            else if (num==1) {            
              printf("Pilihan Anda: %s\n", arrKata.A[2].TabWord);
              printf("Pilihan Lawan: %s\n", arrKata.A[1].TabWord);
              printf("Hasil: MENANG\n");
              printf("SkorAnda +100\n");
              skorAnda += 100;
            }
            else {            
              printf("Pilihan Anda: %s\n", arrKata.A[2].TabWord);
              printf("Pilihan Lawan: %s\n", arrKata.A[2].TabWord);
              printf("Hasil: SERI\n");
            }
        }
  printf("----------------------------------------------------------------\n");
        }  
  
  /* Menuliskan hasil pertandingan PRS ke layar */
  printf("Skor Anda: %d\n", skorAnda);
  printf("Skor Lawan: %d\n", skorLawan);
    printf("Masukkan Nama:");
    STARTWORD_INPUT();
    if(IsEmptyMap(GetArrM(*Scores, gamebrp))){
        CreateEmptyMap(&Scores->A[gamebrp]);
        InsertMap(&Scores->A[gamebrp], currentWord, skorAnda);
        printf("Score berhasil ditambahkan!\n");
    }
    else{
        toLower(&currentWord);
        while(IsMemberMap(GetArrM(*Scores,gamebrp),currentWord)){
            printf("Nama sudah ada! silahkan input ulang: ");
            STARTWORD_INPUT();
        }
        InsertMap(&Scores->A[gamebrp], currentWord, skorAnda);
        printf("Score berhasil ditambahkan!\n");
    }
  if (skorAnda>skorLawan) {
    printf("Anda menang!\n");
  }
  else if (skorAnda==skorLawan) {
    printf("Seri!\n");
  }   
  else {
    printf("Anda kalah!\n");
  }
}
