#ifndef Smap_H
#define Smap_H
#include <stdio.h>
#include "../boolean.h"
#include "word.h"
#include "../Commands/listGame.h"
#include "../ADT/arrayGame.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
#define MaxEl 10
#define Undefined -999

// typedef int bool;
typedef Word key;
typedef int value;
typedef int Saddress;

typedef struct {
	key Name;
	value Score;
} info;

typedef struct {
	info Elements[MaxEl];
	Saddress Count;
} scoreMap;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(scoreMap *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(scoreMap M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(scoreMap M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
value ValueMap(scoreMap M, key k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void sortMap(scoreMap *M);
/* I.S. M terdefinisi */
/* F.S. M diurutkan berdasarkan nilai value dari yang terbesar ke yang terkecil */

void InsertMap(scoreMap *M, key k, value v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(scoreMap *M, key k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(scoreMap M, key k);
/* Mengembalikan true jika k adalah member dari M */

void PrintMap(scoreMap map);
/* I.S. M terdefinisi */
/* F.S. M dicetak ke layar */
int countMap(scoreMap M);

#endif
