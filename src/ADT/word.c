#include "word.h"

void createWord(Word * word){
    for(int i = 0; i < 50; i++){
        word->TabWord[i] = '\0';
    }
    word->Length = 0;
}

void printchar(char character, int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%c", character);
    }
}

boolean isKataEqual(Word word, char* string){
/*
Mengembalikan true jika word == string dan false jika word != string.
Fungsi ini dipakai untuk menyocokan command input.
*/
    int i = 0;
    boolean equal = true;
    while(string[i] != '\0'){
        if(word.TabWord[i]!=string[i]){
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

int wordToIntDD (Word word) {
/*Mengubah word dari input gim Diner Dash menjadi integer*/
    int i=1, sum=0, len=word.Length;
    
    for (i; i<len; i++) {
        sum = sum*10 + (word.TabWord[i] - '0');
    }
    
    return sum;
}

boolean isIdentical(Word word1, Word word2){
/*Mengembalikan true jika word1 identik dengan word2*/
    int i = 0;
    boolean found = true;
    if (word1.Length == word2.Length) {
        while(i < word1.Length && (found)) {
            if(word1.TabWord[i]!=word2.TabWord[i]){
                found = false;
            }
            i++;
        }
    }
    else{
        found = false;
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

void printWord(Word word) {
/*Mencetak word ke layar*/
    int i=0;
    while (i < word.Length) {
        printf("%c", word.TabWord[i]);
        i++;
    }
}

void toLower(Word *word){
    int i = 0;
    while(i < word->Length){
        if(word->TabWord[i] >= 'A' && word->TabWord[i] <= 'Z'){
            word->TabWord[i] = word->TabWord[i] + 32;
        }
        i++;
    }
}
/*Mengubah word menjadi huruf kecil semua*/
