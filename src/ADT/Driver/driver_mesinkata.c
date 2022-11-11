// #include "../word.h"
// #include <stdio.h>

// char intToChar(int n) {
//     return (n >= 0 && n <= 9)? (char)(n + '0') : n;
// }

// void CopyWord(Word *kata1, Word kata2)
// {
//     kata1->Length = kata2.Length;
//     for (int i = 0; i < kata2.Length; i++)
//     {
//         kata1->TabWord[i] = kata2.TabWord[i];
//     }
// }

// void SetWordChar(Word *kata, int i, char c)
// {
//     if (i >= kata->Length)
//     {
//         i = kata->Length;
//         kata->Length++;
//     }
//     kata->TabWord[i] = c;
// }


// void Reverse(Word *kata)
// {
//     Word tempKata;
//     tempKata.Length = 0;
//     CopyWord(&tempKata, *kata);
//     int len = kata->Length;
//     for (int i = 0; i < len; i++)
//     {
//         SetWordChar(kata, i, tempKata.TabWord[len - i - 1]);
//     }
// }


// Word intToWord(int n) {
//     Word kata;
//     kata.Length = 0;

//     while (n > 0) {
//         SetWordChar(&kata, kata.Length, intToChar(n%10));
//         // printf("<<%s>>", kata.TabWord);
//         // printf("char: %c",intToChar(n%10));
//         n /= 10;
//     }
//     Reverse(&kata);
//     return kata;
// }



// int main(){
//     int i = 7;
//     Word word;
//     word = intToWord(i);
//     // printf("%d",i);

//     printf("<%s>",word.TabWord);
//     return 0;
// }