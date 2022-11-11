#include "mesinkata.h"

boolean endWord;
Word currentWord;


void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV_INPUT();
    }
}

void IgnoreEnters()
{
    /* Mengabaikan satu atau beberapa ENTER('\n')
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ ENTER atau currentChar = MARK */
    while (currentChar == ENTER)
    {
        ADV();
    } 
}

void STARTWORD(char* filename)
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START(filename);
    IgnoreEnters();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void STARTWORD_INPUT()
{

/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START_INPUT();
    IgnoreBlanks();
    if (currentChar == MARK_INPUT)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord_Input();
    }
}

void ADVWORD_INPUT()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK_INPUT)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord_Input();
        IgnoreBlanks();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreEnters();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
        IgnoreEnters();
    }
}

void CopyWord_Input()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    clearWord();
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK_INPUT)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV_INPUT();
        }
        else
            break;
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = ENTER atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    clearWord();
    currentWord.Length = 0;
    while (currentChar != ENTER && currentChar != MARK)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isEndWord() {
/*Mengembalikan boolean EndWord*/
    return endWord;
}


void clearWord(){
/*Membersihkan Word*/
    int i = 0;
    while(i < currentWord.Length){
        currentWord.TabWord[i] = '\0';
        i++;
    }
}

boolean isKataEqual(Word kata, char* string){
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
    return (n >= 0 && n <= 9)? (char)(n + '0') : n;
}

void CloneWord(Word *word1, Word word2)
{
    word1->Length = word2.Length;
    for (int i = 0; i < word2.Length; i++)
    {
        word1->TabWord[i] = word2.TabWord[i];
    }
}

void SetWordChar(Word *word, int i, char c)
{
    if (i >= word->Length)
    {
        i = word->Length;
        word->Length++;
    }
    word->TabWord[i] = c;
}


void Reverse(Word *word)
{
    Word tempword;
    tempword.Length = 0;
    CopyWord(&tempword, *word);
    int len = word->Length;
    for (int i = 0; i < len; i++)
    {
        SetWordChar(word, i, tempword.TabWord[len - i - 1]);
    }
}


Word intToWord(int n) {
    Word word;
    word.Length = 0;

    while (n > 0) {
        SetWordChar(&word, word.Length, intToChar(n%10));
        // printf("<<%s>>", word.TabWord);
        // printf("char: %c",intToChar(n%10));
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
