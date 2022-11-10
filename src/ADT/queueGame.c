#include "queueGame.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(queueGame *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
   IDX_HEAD(*q) = IDX_UNDEF;
   IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean IsEmptyQ(queueGame q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
  return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}
boolean IsFullQ(queueGame q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
  return IDX_HEAD(q) == (IDX_TAIL(q) + 1) % CAPACITY;
}
boolean IsMemberQ(queueGame q, ElType val) {
/* Mengirim true jika val terdapat dalam queueGame */
   if (IsEmptyQ(q)) {
     return false;
   }
  else {
    int i = IDX_HEAD(q);
    boolean found=false;
    while (i != IDX_TAIL(q) && !found) {
      if (isIdentical(q.A[i], val)) { /* Harus buat fungsi compare Word */
        found = true;
      }
      else {
        i = (i + 1) % CAPACITY;
      }
    }
  }
}

int LengthQ(queueGame q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (IsEmptyQ(q)) {
        return 0;
    }
    else {
        return ((IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY) % CAPACITY + 1);
    }
}

/* *** Primitif Add/Delete *** */
void Enqueue(queueGame *q, Game val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (IsEmptyQ(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }
    else {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q) = val;
    }
}

void Dequeue(queueGame *q, Game *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
   if (IsEmptyQ(*q))
    {
        printf("QueueGame kosong!\n");
    }
    else
    {
        *val = HEAD(*q);
        if (IDX_HEAD(*q) == IDX_TAIL(*q))
        {
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
        }
        else
        {
            IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
        }
    }
}

/* *** Primitif DeleteQueue *** */
void DeleteQueue (queueGame *q) {
    free(q->A);
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* *** Display Queue *** */
void PrintQueue(queueGame q) {
/* Proses : Menuliskan isi queueGame dengan traversal, elemen antarqueue dipisahkan oleh newline, terdapat penomoran pada bagian depan dengan IdxHead sebagai satu*/
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai "RNG", "Diner Dash", "Feeding Frenzy" akan dicetak:
            1. RNG
            2. Diner Dash
            3. Feeding Frenzy */
/* Jika queueGame kosong tidak dilakukan apa-apa */
  if (!IsEmptyQ(q)) {
        int i, j=1;
        for (i = IDX_HEAD(q); i != IDX_TAIL(q)+1; i = (i + 1) % CAPACITY) {
            printf("%d. %s\n", j, q.A[i].TabWord);
            j++;
        }
    }
}
