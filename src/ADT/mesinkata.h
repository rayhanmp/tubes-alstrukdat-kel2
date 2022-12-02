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

int STARTWORD(char* filename);
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

#endif
