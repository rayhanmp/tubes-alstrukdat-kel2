#include "towergame.h"

void printchar(char character, int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%c", character);
    }
}

void printKondisi(Stack S1, Stack S2, Stack S3, int jumlahpiringan)
{
    Stack Stemp1, Stemp2, Stemp3;
    stacktype X;
    int stars, spaces, length1, length2, length3;
    CopyStack(S1, &Stemp1);
    CopyStack(S2, &Stemp2);
    CopyStack(S3, &Stemp3);

    length1 = LengthS(Stemp1);
    length2 = LengthS(Stemp2);
    length3 = LengthS(Stemp3);
    if (length1 == jumlahpiringan)
    {
        for (int i = 1; i <= jumlahpiringan; i++)
        {
            Pop(&Stemp1, &X);
            stars = 2 * X - 1;
            spaces = ((2 * jumlahpiringan - 1) - (2 * X - 1)) / 2;
            printchar(' ', spaces);
            printchar('*', stars);
            printchar(' ', spaces);
            printf(" ");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf("|");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf(" ");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf("|");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf("\n");
            
        }
        
    }
    else if (length2 == jumlahpiringan)
    {
        for (int i = 1; i <= jumlahpiringan; i++)
        {
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf("|");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf(" ");
            Pop(&Stemp2, &X);
            stars = 2 * X - 1;
            spaces = ((2 * jumlahpiringan - 1) - (2 * X - 1)) / 2;
            printchar(' ', spaces);
            printchar('*', stars);
            printchar(' ', spaces);
            printf(" ");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf("|");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf("\n");
        }
    }
    else if(length3 == jumlahpiringan){
        for(int i = 1; i <= jumlahpiringan; i++){
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf("|");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf(" ");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf("|");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf(" ");
            Pop(&Stemp3, &X);
            stars = 2*X -1;
            spaces = ((2*jumlahpiringan - 1) - (2*X -1))/2;
            printchar(' ', spaces);
            printchar('*', stars);
            printchar(' ', spaces);
            printf("\n");
        }
    }
    else{
        int j = jumlahpiringan;
        for(int i = 1; i <= jumlahpiringan; i++){
            if(length1 >= j){
            Pop(&Stemp1, &X);
            stars = 2*X -1;
            spaces = ((2*jumlahpiringan - 1) - (2*X -1))/2;
            printchar(' ', spaces);
            printchar('*', stars);
            printchar(' ', spaces);
            }
            else{
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf("|");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            }
            if(length2 >= j){
            printf(" ");
            Pop(&Stemp2, &X);
            stars = 2*X -1;
            spaces = ((2*jumlahpiringan - 1) - (2*X -1))/2;
            printchar(' ', spaces);
            printchar('*', stars);
            printchar(' ', spaces);
            }
            else{
            printf(" ");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf("|");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            }
            if(length3 >= j){
            printf(" ");
            Pop(&Stemp3, &X);
            stars = 2*X -1;
            spaces = ((2*jumlahpiringan - 1) - (2*X -1))/2;
            printchar(' ', spaces);
            printchar('*', stars);
            printchar(' ', spaces);
            }
            else{
            printf(" ");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            printf("|");
            printchar(' ', (2 * jumlahpiringan - 1)/2);
            }
            printf("\n");
            j--;
            
        }
    }
    printchar('-', 2 * jumlahpiringan - 1);
    printf(" ");
    printchar('-', 2 * jumlahpiringan - 1);
    printf(" ");
    printchar('-', 2 * jumlahpiringan - 1);
    printf("\n");
    printchar(' ', (2 * jumlahpiringan - 1)/2);
    printf("A");
    printchar(' ', (2 * jumlahpiringan - 1)/2);
    printf(" ");
    printchar(' ', (2 * jumlahpiringan - 1)/2);
    printf("B");
    printchar(' ', (2 * jumlahpiringan - 1)/2);
    printf(" ");
    printchar(' ', (2 * jumlahpiringan - 1)/2);
    printf("C");
    printchar(' ', (2 * jumlahpiringan - 1)/2);
    printf(" ");
    printf("\n");
}

boolean isTowerValid(Stack S, int input)
{
    return InfoTop(S) > input;
}
boolean isInputValid(char input)
{
    return input == 'A' || input == 'B' || input == 'C';
}
void towerGame()
{
    // TITLE
    printf("=====================================================================================================================================\n");
    printf("$$$$$$$$\\  $$$$$$\\  $$\\      $$\\ $$$$$$$$\\ $$$$$$$\\         $$$$$$\\  $$$$$$$$\\       $$\\   $$\\  $$$$$$\\  $$\\   $$\\  $$$$$$\\  $$$$$$\\ \n");
    printf("\\__$$  __|$$  __$$\\ $$ | $\\  $$ |$$  _____|$$  __$$\\       $$  __$$\\ $$  _____|      $$ |  $$ |$$  __$$\\ $$$\\  $$ |$$  __$$\\ \\_$$  _|\n");
    printf("   $$ |   $$ /  $$ |$$ |$$$\\ $$ |$$ |      $$ |  $$ |      $$ /  $$ |$$ |            $$ |  $$ |$$ /  $$ |$$$$\\ $$ |$$ /  $$ |  $$ | \n");
    printf("   $$ |   $$ |  $$ |$$ $$ $$\\$$ |$$$$$\\    $$$$$$$  |      $$ |  $$ |$$$$$\\          $$$$$$$$ |$$$$$$$$ |$$ $$\\$$ |$$ |  $$ |  $$ | \n");
    printf("   $$ |   $$ |  $$ |$$$$  _$$$$ |$$  __|   $$  __$$<       $$ |  $$ |$$  __|         $$  __$$ |$$  __$$ |$$ \\$$$$ |$$ |  $$ |  $$ |\n");
    printf("   $$ |    $$$$$$  |$$  /   \\$$ |$$$$$$$$\\ $$ |  $$ |       $$$$$$  |$$ |            $$ |  $$ |$$ |  $$ |$$ | \\$$ | $$$$$$  |$$$$$$\\ \n");
    printf("   \\__|    \\______/ \\__/     \\__|\\________|\\__|  \\__|       \\______/ \\__|            \\__|  \\__|\\__|  \\__|\\__|  \\__| \\______/ \\______|\n");
    printf("=====================================================================================================================================\n");

    // INISIALISASI
    Stack A, B, C, Atemp, Btemp, Ctemp;
    int score, minsteps, sumPiringan, steps;
    stacktype var;
    char asal, tujuan;
    steps = 0;
    printf("MASUKKAN JUMLAH PIRINGAN: ");
    STARTWORD_INPUT();
    sumPiringan = wordToInt(currentWord);
    minsteps = (int)(pow(2, sumPiringan)) - 1;

    // TOWER A
    CreateEmptyS(&A);
    // Inisialisasi Tower A
    for (int i = sumPiringan; i > 0; i--)
    {
        Push(&A, i);
    }
    // TOWER B
    CreateEmptyS(&B);
    // TOWER C
    CreateEmptyS(&C);
    // TEMPORARY TOWERS
    CopyStack(A, &Atemp);
    CopyStack(B, &Btemp);
    CopyStack(C, &Ctemp);

    // ALGORITMA
    printf("=====================================================================================================================================\n");
    printKondisi(A, B, C, sumPiringan);
    while (steps < (minsteps + 10) && LengthS(C) != sumPiringan)
    {
        printf("=========================\n");
        printf("TIANG ASAL  : ");
        STARTWORD_INPUT();
        asal = currentWord.TabWord[0];
        printf("TIANG TUJUAN: ");
        STARTWORD_INPUT();
        tujuan = currentWord.TabWord[0];
        printf("=========================\n");
        if (isInputValid(asal) && isInputValid(tujuan) && asal != tujuan)
        {
            switch (asal)
            {
            case 'A':
                if (IsEmptyS(A))
                {
                    printf("TIANG ASAL A KOSONG!\n");
                }
                else
                {
                    switch (tujuan)
                    {
                    case 'B':
                        Pop(&Atemp, &var);
                        if (IsEmptyS(B))
                        {
                            Pop(&A, &var);
                            Push(&B, var);
                            steps++;
                        }
                        else if (isTowerValid(B, var))
                        {
                            Pop(&A, &var);
                            Push(&B, var);
                            steps++;
                        }
                        else
                        {
                            printf("PIRINGAN YANG DIBAWAH HARUS LEBIH BESAR DARIPADA YANG DIATAS!\n");
                        }
                        CopyStack(A, &Atemp);
                        CopyStack(B, &Btemp);
                        break;
                    case 'C':
                        Pop(&Atemp, &var);
                        if (IsEmptyS(C))
                        {
                            Pop(&A, &var);
                            Push(&C, var);
                            steps++;
                        }
                        else if (isTowerValid(C, var))
                        {
                            Pop(&A, &var);
                            Push(&C, var);
                            steps++;
                        }
                        else
                        {
                            printf("PIRINGAN YANG DIBAWAH HARUS LEBIH BESAR DARIPADA YANG DIATAS!\n");
                        }
                        CopyStack(A, &Atemp);
                        CopyStack(C, &Ctemp);
                        break;
                    }
                }
                break;
            case 'B':
                if (IsEmptyS(B))
                {
                    printf("TIANG ASAL B KOSONG!\n");
                }
                else
                {
                    switch (tujuan)
                    {
                    case 'A':
                        Pop(&Btemp, &var);
                        if (IsEmptyS(A))
                        {
                            Pop(&B, &var);
                            Push(&A, var);
                            steps++;
                        }
                        else if (isTowerValid(A, var))
                        {
                            Pop(&B, &var);
                            Push(&A, var);
                            steps++;
                        }
                        else
                        {
                            printf("PIRINGAN YANG DIBAWAH HARUS LEBIH BESAR DARIPADA YANG DIATAS!\n");
                        }
                        CopyStack(A, &Atemp);
                        CopyStack(B, &Btemp);
                        break;
                    case 'C':
                        Pop(&Btemp, &var);
                        if (IsEmptyS(C))
                        {
                            Pop(&B, &var);
                            Push(&C, var);
                            steps++;
                        }
                        else if (isTowerValid(C, var))
                        {
                            Pop(&B, &var);
                            Push(&C, var);
                            steps++;
                        }
                        else
                        {
                            printf("PIRINGAN YANG DIBAWAH HARUS LEBIH BESAR DARIPADA YANG DIATAS!\n");
                        }
                        CopyStack(B, &Btemp);
                        CopyStack(C, &Ctemp);
                        break;
                    }
                }
                break;
            case 'C':
                if (IsEmptyS(C))
                {
                    printf("TIANG ASAL C KOSONG!\n");
                }
                else
                {
                    switch (tujuan)
                    {
                    case 'B':
                        Pop(&Ctemp, &var);
                        if (IsEmptyS(B))
                        {
                            Pop(&C, &var);
                            Push(&B, var);
                            steps++;
                        }
                        else if (isTowerValid(B, var))
                        {
                            Pop(&C, &var);
                            Push(&B, var);
                            steps++;
                        }
                        else
                        {
                            printf("PIRINGAN YANG DIBAWAH HARUS LEBIH BESAR DARIPADA YANG DIATAS!\n");
                        }
                        CopyStack(C, &Ctemp);
                        CopyStack(B, &Btemp);
                        break;
                    case 'A':
                        Pop(&Ctemp, &var);
                        if (IsEmptyS(A))
                        {
                            Pop(&C, &var);
                            Push(&A, var);
                            steps++;
                        }
                        else if (isTowerValid(A, var))
                        {
                            Pop(&C, &var);
                            Push(&A, var);
                            steps++;
                        }
                        else
                        {
                            printf("PIRINGAN YANG DIBAWAH HARUS LEBIH BESAR DARIPADA YANG DIATAS!\n");
                        }
                        CopyStack(A, &Atemp);
                        CopyStack(C, &Ctemp);
                        break;
                    }
                }
                break;
            }
        }
        else
        {
            printf("MASUKKAN TIDAK VALID!\n");
            printf("MASUKKAN YANG VALID ADALAH \'A\', \'B\', \'C\' DENGAN ASAL DAN TUJUAN YANG BERBEDA!\n");
        }

        printKondisi(A, B, C, sumPiringan);
    }
    printf("=========================\n");
    score = minsteps + 10 - steps;
    printf("SCORE : %d\n", score);
    printf("=========================\n");
}
