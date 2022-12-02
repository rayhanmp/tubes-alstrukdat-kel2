#include "hangman.h"

boolean IsMemberRegArr (char *guesses, char guess) {
/* Mengembalikan true apabila guess terdapat dalam array guesses */
/* Prekondisi: sembarang */
    for (int i = 0; guesses[i] != '\0'; i++) {
        if (guesses[i] == guess) { 
            return true;
        }
    }
return false;
}

boolean IsInKata(Game el, Game guess) {
/* Mengembalikan true apabila karakter pertama dari Word guess terdapat dalam Word el */
/* Prekondisi: sembarang */
    boolean found;
    int i;
    
    i = 0;
    found = false;
    
    while (!found && i<el.Length) {
        if (el.TabWord[i] == guess.TabWord[0]) {
            found = true;
        }
        else {
            i++;
        }
    }
    return found;
}

int countAppearance(Game el, char x) {
/* Mengembalikan jumlah kemunculan x dalam suatu Word el */
/* Prekondisi: sembarang */
    int i;
    int count;
    
    i = 0;
    count = 0;
    
    while (i<el.Length) {
        if (el.TabWord[i] == x) {
            count++;
        }
        i++;
    }
    return count;
}

void printRegArr(char *guesses, int guess) {
/* I.S. Sembarang */
/* F.S. Prosedur mencetak huruf yang sudah ditebak user (dari array guesses) ke layar */
    printf("Tebakan sebelumnya: ");
    if (guess == 0) {
        printf("-");
    }
    else {
        for (int i = 0; i < guess; i++) {
            printf("%c ", guesses[i]);
        }
    }
    printf("\n");
}

boolean cekNonKapital (Game el) {
/* I.S. Sembarang */
/* F.S. Jika ada huruf nonkapital dalam el mengembalikan false*/
    int i;
    boolean found;
    
    i = 0;
    found = false;
    
    while (!found && i<el.Length) {
        if (el.TabWord[i] < 'A' || el.TabWord[i] > 'Z') {
            found = true;
        }
        else {
            i++;
        }
    }

    return found;
}

void tambahDiksi (arrGame *arrKata) {
/* I.S. arrKata terdefinisi */
/* F.S. Prosedur meminta masukan kepada pengguna hingga pengguna memberi masukan 'STOP', kemudian prosedur menyimpan masukan ke berkas kamus.txt */
    printf("Jika ingin berhenti menambahkan kata, ketik 'STOP'\n");
            while (!isKataEqual(currentWord, "STOP")) {
                printf("Masukkan kata yang ingin ditambahkan: ");
                STARTWORD_INPUT();
                if (!isKataEqual(currentWord, "STOP")) {
                    if (!IsMemberArr(*arrKata, currentWord)) {
                        if (!cekNonKapital(currentWord)) {
                            printf("Kata berhasil ditambahkan!\n");
                            InsertLast(arrKata, currentWord);
                        }
                        else {
                            printf("Kata tidak boleh mengandung huruf nonkapital!\n");
                        }
                    }
                    else {
                        printf("Kata sudah ada di kamus\n");
                    }
                }
            }
            printf("\n");
}

void freeGuesses(char *guesses) {
/* I.S. Array of char guesses terdefinisi */
/* F.S. Array of char guesses diisi dengan '.' */
    for (int i = 0; i < 20; i++) {
        guesses[i] = '\0';
    }
}

void hangman (arrScore *Scores, int gamebrp) {
/* I.S. Sembarang */
/* F.S. Prosedur menjalankan gim hangman */

    /* Kamus */
    arrGame arrKata;
    int num;
    int arrlen;
    int wrong;
    int correct;
    char guesses[20];
    int guess;
    int skor;
    boolean gameover;
    boolean exit;

    /* Inisiasi nilai variabel */
    wrong=0;
    correct=0;
    guess=0;
    skor=0;
    arrlen = Length(arrKata);
    exit = false;
    gameover = false;

    /* Inisiasi array */
    MakeArray(&arrKata);

    /* Inisiasi srand */
    srand(time(NULL));

    /* Load isi kamus ke arrKata */
    load(&arrKata, "kamus.txt");
    printf("\n");

    /* Pengisian array guesses dengan '\0' */
    freeGuesses(guesses);

    /* Menu utama */
    printf("WELCOME TO HANGMAN\n");
    printf("\n");

    printf("Aturan:\n");
    printf("1. Anda punya 10 kesempatan\n");
    printf("2. Jawaban dalam huruf kapital\n");
    printf("3. Jika ingin berhenti bermain, ketik EXIT\n\n");

    printf("Menu:\n");
    printf("1. MAIN\n");
    printf("2. TAMBAHKATA\n");
    printf("3. EXIT\n\n");

    /* Meminta masukan menu */
    printf("Pilihan Anda: ");
    STARTWORD_INPUT();
    printf("\n");

    /* Cek masukan pengguna */
    if (isKataEqual(currentWord, "TAMBAHKATA")) { // Jika pengguna memilih TAMBAHKATA
        tambahDiksi(&arrKata);
        hangman(Scores, gamebrp);
    }
    else if (isKataEqual(currentWord, "MAIN")) { // Jika pengguna memilih MAIN
        /* MAIN LOOP: selama gameover bernilai false */
        while (!gameover) { 
            num = rand() % Length(arrKata); // Memilih angka secara acak
            int len = arrKata.A[num].Length;

            /* SECOND LOOP: selama jumlah correct tidak sama dengan jumlah huruf dalam kata */
            while (correct != len) {
                printRegArr(guesses, guess); // Print isi array guesses (karakter yang pernah ditebak pengguna)

                printf("Kata: ");
                for (int i=0; i<len; i++) { // Traversal isi TabWord
                    if (IsMemberRegArr(guesses, arrKata.A[num].TabWord[i])) { // Jika huruf sudah ditebak
                        printf("%c", arrKata.A[num].TabWord[i]); // Cetak hurufnya
                    }
                    else { // Jika huruf belum ditebak
                        printf("_"); // Cetak underscore
                    }
                }
                printf("\n");
                printf("Kesempatan: %d\n", 10-wrong);


                /* Meminta pengguna memasukan tebakan */
                printf("Masukkan tebakan: ");
                STARTWORD_INPUT();
                printf("\n");

                /* Evaluasi tebakan pengguna dengan conditional statements */
                if (isKataEqual(currentWord, "EXIT")) { // Jika pengguna memasukan EXIT
                    gameover = true;
                    exit = true;
                    break;
                }
                else {
                if (IsInKata(arrKata.A[num], currentWord)) { // Cek apakah karakter tebakan pengguna ada di dalam kata
                    if (IsMemberRegArr(guesses, currentWord.TabWord[0])) { //Cek apakah tebakan pengguna sudah pernah ditebak
                        printf("Huruf sudah pernah ditebak!\n");
                    }
                    else { 
                        guesses[guess] = currentWord.TabWord[0];
                        guess++;
                        correct += countAppearance(arrKata.A[num], currentWord.TabWord[0]);
                    }
                }
                else { // Jika tebakan pengguna salah
                    if (IsMemberRegArr(guesses, currentWord.TabWord[0])) { // Cek apakah tebakan pengguna sudah pernah ditebak
                        printf("Huruf sudah pernah ditebak!");
                    }
                    else { 
                        guesses[guess] = currentWord.TabWord[0];
                        guess++;
                        wrong++;
                    }
                }
                }
                printf("\n");
                printf("\n");

                /* Evaluasi apakah kesempatan sudah habis */
                if (wrong == 10) {
                    printf("Game over!\n");
                    gameover=true;
                    break;
                }
                
            }
            if (wrong!=10 && !exit) { // Jika kesempatan belum habis dan exit bernilai false
                /* Print kata yang sudah tertebak semua */
                    printf("Kata: ");
                    for (int i=0; i<len; i++) {
                                if (IsMemberRegArr(guesses, arrKata.A[num].TabWord[i])) {
                                    printf("%c", arrKata.A[num].TabWord[i]);
                                }
                            else {
                                printf("_");
                            }
                    }
                    printf("\n");
                printf("Berhasil menebak kata %s! Kamu mendapatkan %d poin!\n\n", arrKata.A[num].TabWord, arrKata.A[num].Length);
                skor = skor + arrKata.A[num].Length;
            }

            /* Reset nilai correct dan guess */
            correct = 0;
            guess = 0;

            /* Kosongkan array guesses */
            freeGuesses(guesses);
        }

        /* Tuliskan skor akhir */
        printf("SCORE: %d\n", skor);
        printf("Masukkan Nama:");
        STARTWORD_INPUT();
        if(IsEmptyMap(GetArrM(*Scores, gamebrp))){
            CreateEmptyMap(&Scores->A[gamebrp]);
            InsertMap(&Scores->A[gamebrp], currentWord, skor);
            printf("Score berhasil ditambahkan!\n");
        }
        else{
            while(IsMemberMap(GetArrM(*Scores,gamebrp),currentWord)){
                printf("Nama sudah ada! silahkan input ulang: ");
                STARTWORD_INPUT();
            }
            InsertMap(&Scores->A[gamebrp], currentWord, skor);
            printf("Score berhasil ditambahkan!\n");
        }
    }
    else if (isKataEqual(currentWord, "EXIT")) { // Jika pengguna memilih EXIT
        return;
    }
    else { // Jika pengguna memasukan input selain MAIN, TAMBAHKATA, dan EXIT
        printf("Input tidak valid!\n"); 
        hangman(Scores, gamebrp);
    }
}

