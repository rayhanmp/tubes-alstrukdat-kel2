#include "hangman.h"
#include "../ADT/mesinkata.h"
#include "../ADT/arrayGame.h"
#include "../Commands/start.h"
#include <time.h>
#include <stdlib.h>

boolean IsMemberRegArr (char *guesses, char guess) {
    for (int i = 0; guesses[i] != '\0'; i++) {
        if (guesses[i] == guess) { 
            return true;
            
        }
    }
return false;
}

boolean IsInKata(Game el, Game guess) {
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

void hangman () {
    int num;
    int wrong=0;
    int correct=0;
    char guesses[20];
    int guess=0;
    int skor=0;
    boolean gameover;
    gameover = false;
    arrGame arrKata;
    Word Paper, Rock, Scissor, Python, Javascript, Bootstrap, HTML, React, BASIC, COBOL, Fortran, Go, Haskell, Java, Kotlin, Pascal, Ruby, Swift, Typescript, Vala;

    srand(time(NULL));
    MakeArray(&arrKata);
    Paper.Length = 5;
    Rock.Length = 4;
    Scissor.Length = 7;
    React.Length = 5;
    Python.Length = 6;
    Javascript.Length = 10;
    Bootstrap.Length = 9;
    HTML.Length = 4;
    BASIC.Length = 5;
    COBOL.Length = 5;
    Fortran.Length = 7;
    Go.Length = 2;
    Haskell.Length = 7;
    Java.Length = 4;
    Kotlin.Length = 6;
    Pascal.Length = 6;
    Ruby.Length = 4;
    Swift.Length = 5;
    Typescript.Length = 10;
    Vala.Length = 4;


    React.TabWord[0] = 'R';
    React.TabWord[1] = 'E';
    React.TabWord[2] = 'A';
    React.TabWord[3] = 'C';
    React.TabWord[4] = 'T';

    Python.TabWord[0] = 'P';
    Python.TabWord[1] = 'Y';
    Python.TabWord[2] = 'T';
    Python.TabWord[3] = 'H';
    Python.TabWord[4] = 'O';
    Python.TabWord[5] = 'N';

    Javascript.TabWord[0] = 'J';
    Javascript.TabWord[1] = 'A';
    Javascript.TabWord[2] = 'V';
    Javascript.TabWord[3] = 'A';
    Javascript.TabWord[4] = 'S';
    Javascript.TabWord[5] = 'C';
    Javascript.TabWord[6] = 'R';
    Javascript.TabWord[7] = 'I';
    Javascript.TabWord[8] = 'P';
    Javascript.TabWord[9] = 'T';

    Bootstrap.TabWord[0] = 'B';
    Bootstrap.TabWord[1] = 'O';
    Bootstrap.TabWord[2] = 'O';
    Bootstrap.TabWord[3] = 'T';
    Bootstrap.TabWord[4] = 'S';
    Bootstrap.TabWord[5] = 'T';
    Bootstrap.TabWord[6] = 'R';
    Bootstrap.TabWord[7] = 'A';
    Bootstrap.TabWord[8] = 'P';

    HTML.TabWord[0] = 'H';
    HTML.TabWord[1] = 'T';
    HTML.TabWord[2] = 'M';
    HTML.TabWord[3] = 'L';

    BASIC.TabWord[0] = 'B';
    BASIC.TabWord[1] = 'A';
    BASIC.TabWord[2] = 'S';
    BASIC.TabWord[3] = 'I';
    BASIC.TabWord[4] = 'C';

    COBOL.TabWord[0] = 'C';
    COBOL.TabWord[1] = 'O';
    COBOL.TabWord[2] = 'B';
    COBOL.TabWord[3] = 'O';
    COBOL.TabWord[4] = 'L';

    Fortran.TabWord[0] = 'F';
    Fortran.TabWord[1] = 'O';
    Fortran.TabWord[2] = 'R';
    Fortran.TabWord[3] = 'T';
    Fortran.TabWord[4] = 'R';
    Fortran.TabWord[5] = 'A';
    Fortran.TabWord[6] = 'N';

    Go.TabWord[0] = 'G';
    Go.TabWord[1] = 'O';

    Haskell.TabWord[0] = 'H';
    Haskell.TabWord[1] = 'A';
    Haskell.TabWord[2] = 'S';
    Haskell.TabWord[3] = 'K';
    Haskell.TabWord[4] = 'E';
    Haskell.TabWord[5] = 'L';
    Haskell.TabWord[6] = 'L';

    Java.TabWord[0] = 'J';
    Java.TabWord[1] = 'A';
    Java.TabWord[2] = 'V';
    Java.TabWord[3] = 'A';

    Kotlin.TabWord[0] = 'K';
    Kotlin.TabWord[1] = 'O';
    Kotlin.TabWord[2] = 'T';
    Kotlin.TabWord[3] = 'L';
    Kotlin.TabWord[4] = 'I';
    Kotlin.TabWord[5] = 'N';

    Pascal.TabWord[0] = 'P';
    Pascal.TabWord[1] = 'A';
    Pascal.TabWord[2] = 'S';
    Pascal.TabWord[3] = 'C';
    Pascal.TabWord[4] = 'A';
    Pascal.TabWord[5] = 'L';

    Ruby.TabWord[0] = 'R';
    Ruby.TabWord[1] = 'U';
    Ruby.TabWord[2] = 'B';
    Ruby.TabWord[3] = 'Y';

    Swift.TabWord[0] = 'S';
    Swift.TabWord[1] = 'W';
    Swift.TabWord[2] = 'I';
    Swift.TabWord[3] = 'F';
    Swift.TabWord[4] = 'T';

    Typescript.TabWord[0] = 'T';
    Typescript.TabWord[1] = 'Y';
    Typescript.TabWord[2] = 'P';
    Typescript.TabWord[3] = 'E';
    Typescript.TabWord[4] = 'S';
    Typescript.TabWord[5] = 'C';
    Typescript.TabWord[6] = 'R';
    Typescript.TabWord[7] = 'I';
    Typescript.TabWord[8] = 'P';
    Typescript.TabWord[9] = 'T';

    Vala.TabWord[0] = 'V';
    Vala.TabWord[1] = 'A';
    Vala.TabWord[2] = 'L';
    Vala.TabWord[3] = 'A';

    InsertFirst(&arrKata, Python);
    InsertFirst(&arrKata, Javascript);
    InsertFirst(&arrKata, Bootstrap);
    InsertFirst(&arrKata, HTML);
    InsertFirst(&arrKata, React);
    InsertFirst(&arrKata, BASIC);
    InsertFirst(&arrKata, COBOL);
    InsertFirst(&arrKata, Fortran);
    InsertFirst(&arrKata, Go);
    InsertFirst(&arrKata, Haskell);
    InsertFirst(&arrKata, Java);
    InsertFirst(&arrKata, Kotlin);
    InsertFirst(&arrKata, Pascal);
    InsertFirst(&arrKata, Ruby);
    InsertFirst(&arrKata, Swift);
    InsertFirst(&arrKata, Typescript);
    InsertFirst(&arrKata, Vala);
  
    PrintArray(arrKata);
    printf("\n");


    printf("WELCOME TO HANGMAN\n");
    printf("\n");


    while (!gameover) {
        num = rand() % 17;
        int len = arrKata.A[num].Length;
        while (correct != len) {
            printRegArr(guesses, guess);
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
            printf("Masukkan tebakan: ");
            STARTWORD_INPUT();
            printf("\n");
            if (IsInKata(arrKata.A[num], currentWord)) {
                if (IsMemberRegArr(guesses, currentWord.TabWord[0])) {
                    printf("You already guessed that letter!\n");
                }
                else {
                    guesses[guess] = currentWord.TabWord[0];
                    guess++;
                    correct += countAppearance(arrKata.A[num], currentWord.TabWord[0]);
                }
            }
            else {
                printRegArr(guesses, guess);
                if (IsMemberRegArr(guesses, currentWord.TabWord[0])) {
                    printf("You already guessed that letter!");
                }
                else {
                    printf("Kesempatan: %d", 10-wrong);
                    guesses[guess] = currentWord.TabWord[0];
                    guess++;
                    wrong++;
                }
            }
        printf("\n");
        printf("\n");
        for (int i=0; i<len; i++) {
                    if (IsMemberRegArr(guesses, arrKata.A[num].TabWord[i])) {
                        printf("%c", arrKata.A[num].TabWord[i]);
                    }
                else {
                    printf("_");
                }
        }

        printf("\n");

        if (wrong == 10) {
            printf("Game over!\n");
            gameover=true;
            break;
        }
        }
        printf("Berhasil menebak kata %s! Kamu mendapatkan %d poin!\n\n", arrKata.A[num].TabWord, arrKata.A[num].Length);
        skor = skor + arrKata.A[num].Length;
        correct = 0;
        guess = 0;
        for (int j=0; j<20; j++) {
            guesses[j] = '\0';
        }
    }
    printf("Skor akhir: %d\n", skor);
}


int main () {
    hangman();
    return 0;
}