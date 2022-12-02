#ifndef _WORD_H_
#define _WORD_H_

#include "../boolean.h"
#include <stdio.h>
typedef char string[50];
typedef struct
{
   string TabWord;
   int Length;
} Word;

void createWord(Word * word);
void printchar(char character, int n);

boolean isKataEqual(Word word, char* string);
/*
Mengembalikan true jika word == string dan false jika word != string.
Fungsi ini dipakai untuk menyocokan command input.
*/

char intToChar(int n);
/*int to char converter*/

void CloneWord(Word *word1, Word word2);
/*Membuat duplikat word*/

void SetWordChar(Word *word, int i, char c);
/*Menset word dari char*/

void Reverse(Word *word);
/*Membalikan string word.Tabword dalam word*/

Word intToWord(int n);
/*int to word converter */

int wordToInt (Word word);
/*Mengubah word menjadi integer*/


int wordToIntDD (Word word);
/*Mengubah word dari input gim Diner Dash menjadi integer*/

boolean isIdentical(Word kata1, Word kata2);
/*Mengembalikan true jika kata1 identik dengan kata2*/

void InsertLastW(Word* word, char* str);
/*Memasukkan str ke word dari akhir word.tabword*/

void printWord(Word word);
/*Mencetak word ke layar*/

void toLower(Word *word);
/*Mengubah word menjadi huruf kecil semua*/

#endif
