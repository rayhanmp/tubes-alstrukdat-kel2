#include "towergame.h"

void printKondisi(Stack S1, Stack S2, Stack S3){
    Stack Stemp1, Stemp2, Stemp3;
    stacktype X;
    if(LengthS(S1) != 5){
        for(int i = 5; i > LengthS(S1); i--){
            printf("\n");
        }
    }
    printStack(S1);
    printf("#[TOWER A]#\n");

    if(LengthS(S2) != 5){
        for(int i = 5; i > LengthS(S2); i--){
            printf("\n");
        }
    }
    printStack(S2);
    printf("#[TOWER B]#\n");

    if(LengthS(S3) != 5){
    for(int i = 5; i > LengthS(S3); i--){
        printf("\n");
    }
    }
    printStack(S3);
    printf("#[TOWER C]#\n");


    // while(!IsEmptyS(Stemp1)){
    //     Pop(&Stemp1, &X);
    //     if(X == 1){
    //         printf("     *");
    //         printf("\n");
    //     }
    //     else if(X == 2){
    //         printf("    ***");
    //         printf("\n");
    //     }
    //     else if(X == 3){
    //         printf("   *****");
    //         printf("\n");
    //     }
    //     else if(X == 4){
    //         printf("  *******");
    //         printf("\n");
    //     }
    //     else if(X == 5){
    //         printf(" *********");
    //         printf("\n");
    //     }
    // }
}

boolean isTowerValid(Stack S, int input){
    return InfoTop(S) > input; 
}
boolean isInputValid(char input){
    return input == 'A' | input == 'B' | input == 'C';
}
void towerGame(){
    //TITLE
    printf("=====================================================================================================================================\n");
    printf("$$$$$$$$\\  $$$$$$\\  $$\\      $$\\ $$$$$$$$\\ $$$$$$$\\         $$$$$$\\  $$$$$$$$\\       $$\\   $$\\  $$$$$$\\  $$\\   $$\\  $$$$$$\\  $$$$$$\\ \n");
    printf("\\__$$  __|$$  __$$\\ $$ | $\\  $$ |$$  _____|$$  __$$\\       $$  __$$\\ $$  _____|      $$ |  $$ |$$  __$$\\ $$$\\  $$ |$$  __$$\\ \\_$$  _|\n");
    printf("   $$ |   $$ /  $$ |$$ |$$$\\ $$ |$$ |      $$ |  $$ |      $$ /  $$ |$$ |            $$ |  $$ |$$ /  $$ |$$$$\\ $$ |$$ /  $$ |  $$ | \n");
    printf("   $$ |   $$ |  $$ |$$ $$ $$\\$$ |$$$$$\\    $$$$$$$  |      $$ |  $$ |$$$$$\\          $$$$$$$$ |$$$$$$$$ |$$ $$\\$$ |$$ |  $$ |  $$ | \n");
    printf("   $$ |   $$ |  $$ |$$$$  _$$$$ |$$  __|   $$  __$$<       $$ |  $$ |$$  __|         $$  __$$ |$$  __$$ |$$ \\$$$$ |$$ |  $$ |  $$ |\n");
    printf("   $$ |    $$$$$$  |$$  /   \\$$ |$$$$$$$$\\ $$ |  $$ |       $$$$$$  |$$ |            $$ |  $$ |$$ |  $$ |$$ | \\$$ | $$$$$$  |$$$$$$\\ \n");
    printf("   \\__|    \\______/ \\__/     \\__|\\________|\\__|  \\__|       \\______/ \\__|            \\__|  \\__|\\__|  \\__|\\__|  \\__| \\______/ \\______|\n");
    printf("=====================================================================================================================================\n");

    //INISIALISASI
    Stack A, B, C, Atemp, Btemp, Ctemp;
    int score, minsteps, sumPiringan, steps;
    stacktype var;
    char asal, tujuan;
    score = 10;
    steps = 0;
    minsteps = pow(2,sumPiringan) - 1;

    printf("MASUKKAN JUMLAH PIRINGAN: ");
    STARTWORD_INPUT();
    sumPiringan = wordToInt(currentWord);
    //TOWER A
    CreateEmptyS(&A);
    //Inisialisasi Tower A
    for(int i = sumPiringan; i > 0; i--){ 
        Push(&A, i);
    }
    //TOWER B
    CreateEmptyS(&B);
    //TOWER C
    CreateEmptyS(&C);
    //TEMPORARY TOWERS
    CopyStack(A,&Atemp);
    CopyStack(B,&Btemp);
    CopyStack(C,&Ctemp);

    //ALGORITMA
    printf("=====================================================================================================================================\n");
    printKondisi(A,B,C);
    while(steps < (minsteps + 10) && LengthS(C) != sumPiringan){
        printf("=================\n");
        printf("TIANG ASAL  : ");
        STARTWORD_INPUT();
        asal = currentWord.TabWord[0];
        printf("TIANG TUJUAN: ");
        STARTWORD_INPUT();
        tujuan = currentWord.TabWord[0];
        printf("=================\n");
        if(isInputValid(asal) && isInputValid(tujuan) && asal != tujuan){
            switch(asal){
            case 'A':
                if(IsEmptyS(A)){
                    printf("TIANG ASAL A KOSONG!\n");
                }
                else{
                    switch (tujuan)
                    {
                    case 'B':
                        Pop(&Atemp,&var);
                        if(IsEmptyS(B)){
                            Pop(&A, &var);
                            Push(&B, var);
                            steps++;
                        }
                        else if(isTowerValid(B,var)){
                            Pop(&A, &var);
                            Push(&B, var);
                            steps++;
                        }
                        else{
                            printf("PIRINGAN YANG DIBAWAH HARUS LEBIH BESAR DARIPADA YANG DIATAS!\n");
                        }
                        CopyStack(A, &Atemp);
                        CopyStack(B, &Btemp);
                        break;
                    case 'C':
                        Pop(&Atemp,&var);
                        if(IsEmptyS(C)){
                            Pop(&A, &var);
                            Push(&C, var);
                            steps++;
                        }
                        else if(isTowerValid(C,var)){
                            Pop(&A, &var);
                            Push(&C, var);
                            steps++;
                        }
                        else{
                            printf("PIRINGAN YANG DIBAWAH HARUS LEBIH BESAR DARIPADA YANG DIATAS!\n");
                        }
                        CopyStack(A, &Atemp);
                        CopyStack(C, &Ctemp);
                        break;
                    
                    }
                }
                break;
            case 'B':
                if(IsEmptyS(B)){
                    printf("TIANG ASAL B KOSONG!\n");
                }
                else{
                    switch (tujuan)
                    {
                    case 'A':
                        Pop(&Btemp,&var);
                        if(IsEmptyS(A)){
                            Pop(&B, &var);
                            Push(&A, var);
                            steps++;
                        }
                        else if(isTowerValid(A,var)){
                            Pop(&B, &var);
                            Push(&A, var);
                            steps++;
                        }
                        else{
                            printf("PIRINGAN YANG DIBAWAH HARUS LEBIH BESAR DARIPADA YANG DIATAS!\n");
                        }
                        CopyStack(A, &Atemp);
                        CopyStack(B, &Btemp);
                        break;
                    case 'C':
                        Pop(&Btemp,&var);
                        if(IsEmptyS(C)){
                            Pop(&B, &var);
                            Push(&C, var);
                            steps++;
                        }
                        else if(isTowerValid(C,var)){
                            Pop(&B, &var);
                            Push(&C, var);
                            steps++;
                        }
                        else{
                            printf("PIRINGAN YANG DIBAWAH HARUS LEBIH BESAR DARIPADA YANG DIATAS!\n");
                        }
                        CopyStack(B, &Btemp);
                        CopyStack(C, &Ctemp);
                        break;
                    
                    }
                }
                break;
            case 'C':
                if(IsEmptyS(C)){
                    printf("TIANG ASAL C KOSONG!\n");
                }
                else{
                    switch (tujuan)
                    {
                    case 'B':
                        Pop(&Ctemp,&var);
                        if(IsEmptyS(B)){
                            Pop(&C, &var);
                            Push(&B, var);
                            steps++;
                        }
                        else if(isTowerValid(B,var)){
                            Pop(&C, &var);
                            Push(&B, var);
                            steps++;
                        }
                        else{
                            printf("PIRINGAN YANG DIBAWAH HARUS LEBIH BESAR DARIPADA YANG DIATAS!\n");
                        }
                        CopyStack(C, &Ctemp);
                        CopyStack(B, &Btemp);
                        break;
                    case 'A':
                        Pop(&Ctemp,&var);
                        if(IsEmptyS(A)){
                            Pop(&C, &var);
                            Push(&A, var);
                            steps++;
                        }
                        else if(isTowerValid(A,var)){
                            Pop(&C, &var);
                            Push(&A, var);
                            steps++;
                        }
                        else{
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
        else{
            printf("MASUKKAN TIDAK VALID!\n");
            printf("MASUKKAN YANG VALID ADALAH \'A\', \'B\', \'C\' DENGAN ASAL DAN TUJUAN YANG BERBEDA!\n");
        }

    printKondisi(A,B,C);
    }

}
