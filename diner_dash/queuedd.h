/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H_DD
#define QUEUE_H_DD

#include "boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef struct {
    int key;
    int duration;
    int spoliage;
    int price;
} ElType;
typedef struct {
	ElType buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} QueueDD;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD_ID(q) (q).buffer[(q).idxHead].key
#define     TAIL_ID(q) (q).buffer[(q).idxTail].key
#define     HEAD_DUR(q) (q).buffer[(q).idxHead].duration
#define     TAIL_DUR(q) (q).buffer[(q).idxTail].duration
#define     HEAD_SP(q) (q).buffer[(q).idxHead].spoliage
#define     TAIL_SP(q) (q).buffer[(q).idxTail].spoliage
#define     HEAD_PR(q) (q).buffer[(q).idxHead].price
#define     TAIL_PR(q) (q).buffer[(q).idxTail].price
/* *** Kreator *** */
void CreateQueuedd(QueueDD *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptydd(QueueDD q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFulldd(QueueDD q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthdd(QueueDD q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueuedd(QueueDD *q, int key, int duration, int spoliage, int price);
/* Proses: Menambahkan ElType pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeuedd(QueueDD *q, int *key, int *duration, int *spoliage, int *price);
/* Proses: Menghapus ElType pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueuedd(QueueDD q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

void takeValue(QueueDD q, int key, int *duration, int *spoliage, int *price);
/* I.S. q tidak mungkin kosong
   F.S. variabel terisi dengan nilai yang sesuai di queue dengan key*/

#endif