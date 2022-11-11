#ifndef __QUEUE_GAME_DIN__
#define __QUEUE_GAME_DIN__

#include "../boolean.h"
#include "word.h"
#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef Word ElType;
typedef Word Game;
typedef struct {
	Game A[CAPACITY]; 
	int idxHead;
	int idxTail;
} queueGame;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah queueGame, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).A[(q).idxHead]
#define     TAIL(q) (q).A[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(queueGame *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean IsEmptyQ(queueGame q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean IsFullQ(queueGame q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
boolean IsMemberQ(queueGame q, Game val);
/* Mengirim true jika val terdapat dalam queueGame */
int LengthQ(queueGame q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void Enqueue(queueGame *q, Game val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void Dequeue(queueGame *q, Game *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Primitif DeleteQueue *** */
void DeleteQueue (queueGame *q);

/* *** Display Queue *** */
void PrintQueue(queueGame q);
/* Proses : Menuliskan isi queueGame dengan traversal, elemen antarqueue dipisahkan oleh newline, terdapat penomoran pada bagian depan dengan IdxHead sebagai satu*/
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai "RNG", "Diner Dash", "Feeding Frenzy" akan dicetak:
            1. RNG
            2. Diner Dash
            3. Feeding Frenzy */
/* Jika queueGame kosong : menulis [] */

#endif
