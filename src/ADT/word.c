#include "word.h"



boolean isKataEqual(Word kata, char* string){
/*
Mengembalikan true jika word == string dan false jika word != string.
Fungsi ini dipakai untuk menyocokan command input.
*/
    int i = 0;
    boolean equal = true;
    while(string[i] != '\0'){
        if(kata.TabWord[i]!=string[i]){
            return equal = false;
        }
        i++;
    }
    return equal;
}

char intToChar(int n) {
    /*int to char converter*/
    return (n >= 0 && n <= 9)? (char)(n + '0') : n;
}

void CloneWord(Word *word1, Word word2)
{
    /*Membuat duplikat word*/
    word1->Length = word2.Length;
    for (int i = 0; i < word2.Length; i++)
    {
        word1->TabWord[i] = word2.TabWord[i];
    }
}

void SetWordChar(Word *word, int i, char c)
{
    /*Menset word dari char*/
    if (i >= word->Length)
    {
        i = word->Length;
        word->Length++;
    }
    word->TabWord[i] = c;
}


void Reverse(Word *word)
{
    /*Membalikan string word.Tabword dalam word*/
    Word tempword;
    tempword.Length = 0;
    CloneWord(&tempword, *word);
    int len = word->Length;
    for (int i = 0; i < len; i++)
    {
        SetWordChar(word, i, tempword.TabWord[len - i - 1]);
    }
}


Word intToWord(int n) {
    /*int to word converter */
    Word word;
    word.Length = 0;

    while (n > 0) {
        SetWordChar(&word, word.Length, intToChar(n%10));
        n /= 10;
    }
    Reverse(&word);
    return word;
}


int wordToInt(Word word) {
/*Mengubah word menjadi integer*/
    int i=0, sum=0, len=word.Length;
    
    for (i; i<len; i++) {
        sum = sum*10 + (word.TabWord[i] - '0');
    }
    
    return sum;
}

int wordToIntDD (Word kata) {
/*Mengubah kata dari input gim Diner Dash menjadi integer*/
    int i=1, sum=0, len=kata.Length;
    
    for (i; i<len; i++) {
        sum = sum*10 + (kata.TabWord[i] - '0');
    }
    
    return sum;
}

boolean isIdentical(Word kata1, Word kata2){
/*Mengembalikan true jika kata1 identik dengan kata2*/
    int i = 0;
    boolean found = true;
    
    if (kata1.Length == kata2.Length) {
        while(i < kata1.Length && (found)) {
            if(kata1.TabWord[i]!=kata2.TabWord[i]){
                found = false;
            }
            i++;
        }
    }
    return found;
}

void InsertLastW(Word* word, char* str){
/*Memasukkan str ke word dari akhir word.tabword*/
    int i=0;
    while(str[i]!='\0')
    {
        word->TabWord[word->Length]=str[i];
        word->Length++;
        i++;
    }
  word->TabWord[word->Length] ='\0';

}

void printWord(Word kata) {
/*Mencetak word ke layar*/
    int i=0;
    while (i < kata.Length) {
        printf("%c", kata.TabWord[i]);
        i++;
    }
}