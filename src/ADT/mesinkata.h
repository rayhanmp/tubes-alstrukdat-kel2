/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "mesinkarakter.h"
#include "word.h"
#include <stdio.h>
#include <stdlib.h>

#define NMax 100
#define BLANK ' '
#define ENTER '\n'

extern boolean endWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */


void IgnoreEnters();
/* Mengabaikan satu atau beberapa ENTER('\n')
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ ENTER atau currentChar = MARK */

void STARTWORD_INPUT();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORD(char* filename);
/* I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK;
         atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
         currentChar karakter pertama sesudah karakter terakhir kata */



void ADVWORD_INPUT();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
         currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
         Jika currentChar = MARK, endWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
         currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
         Jika currentChar = MARK, endWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */


void CopyWord_Input();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
         currentChar = ENTER atau currentChar = MARK;
         currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
         Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
         currentChar = BLANK atau currentChar = MARK;
         currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
         Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

boolean isEndWord();
/*Mengembalikan boolean EndWord*/

void clearWord();
/*Membersihkan Word*/

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

void printWord(Word kata);
/*Mencetak word ke layar*/

#endif
