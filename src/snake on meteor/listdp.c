/*listdp.c
18221152
Raditya Azka Prabaswara */
#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"
#include "boolean.h"
#include "point.h"
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return ( (First(L) == Nil)&&(Last(L) == Nil) );
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    (First(*L) = Nil);
    (Last(*L) = Nil) ;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (point N){
    address a = (address) malloc (sizeof(ElmtList));
    if (a != Nil){
        X(a) = Xp(N);
        Y(a) = Yp(N);
        Next(a) = Nil;
        Prev(a) = Nil;
        return(a);
    } else {
        return(Nil);
    }
    
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, point N){
    address p = First(L);
    boolean found = false;
    if (IsEmpty(L)){
        return (Nil);
    } else {
        while ( (p != Nil) && (!found) ){
            if ((X(p) == Xp(N)) && ((Y(p) == Yp(N)))){
                found = true;
            } else {
                p = Next(p);
            }
        }
        if (found){
            return (p);
        } else {
            return (Nil);
        }
    }
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, point N){
    address p = Alokasi(N);
    if (p != Nil){
        InsertFirst(L,p);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, point N){
    address p = Alokasi(N);
    if (p != Nil){
        InsertLast(L,p);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, point *N){
    Xp(*N) = X(First(*L));
    Yp(*N) = Y(First(*L));
    address p;
    DelFirst(L,&p);
    Dealokasi(p);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, point *N){
    Xp(*N) = X(Last(*L));
    Yp(*N) = Y(Last(*L));
    address p;
    DelLast(L,&p);
    Dealokasi(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    address q = First(*L);
    Prev(P) = Nil;
    if (q != Nil){
        First(*L) = P;
        Next(P) = q;
        Prev(q) = P;
    } else {
        Next(P) = Nil;
        First(*L) = P;
        Last(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
    address q = Last(*L);
    Next(P) = Nil;
    if (q != Nil){
        Last(*L) = P;
        Prev(P) = q;
        Next(q) = P;
    } else {
        Prev(P) = Nil;
        Last(*L) = P;
        First(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
    address q = Next(Prec);
    if (Last(*L) != Prec){
        Next(P) = q;
        Next(Prec) = P;
        Prev(P) = Prec;
        Prev(q) = P;
    } else {
        Next(Prec) = P;
        Prev(P) = Prec;
        Next(P) = Nil;
        Last(*L) = P;
    }
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ){
    address q = Prev(Succ);
    if (First(*L) != Succ){
        Prev(P) = q;
        Prev(Succ) = P;
        Next(P) = Succ;
        Next(q) = P;
    } else {
        Prev(Succ) = P;
        Next(P) = Succ;
        Prev(P) = Nil;
        First(*L) = P;
    }
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L);
    address q = Next(*P);
    Next(*P) = Nil;
    Prev(*P) = Nil;
    if (Last(*L) != *P){
        First(*L) = q;
        Prev(q) = Nil;
    } else {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
    *P = Last(*L);
    address q = Prev(*P);
    Next(*P) = Nil;
    Prev(*P) = Nil;
    if (First(*L) != *P){
        Last(*L) = q;
        Next(q) = Nil;
    } else {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, point N){
    address q = Search(*L,N);
    address p,r;
    if (q != Nil){
        if (q == First(*L)){
            DelFirst(L,&q);
        } else if (q == Last(*L)){
            DelLast(L,&q);
        } else {
            Next(Prev(q)) = Next(q);
            Prev(Next(q)) = Prev(q);
        }
        Dealokasi(q);
    } 
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    address r;
    if (*Pdel != Nil){
        if (*Pdel != Last(*L)){
            r = Next(*Pdel);
            Next(Prec) = r;
            Prev(r) = Prec;
            Next(*Pdel) = Nil;
            Prev(*Pdel) = Nil;
        } else {
            Last(*L) = Prec;
            Next(Prec) = Nil;
            Next(*Pdel) = Nil;
            Prev(*Pdel) = Nil;
        }
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ){
    *Pdel = Prev(Succ);
    address q;
    if (*Pdel != Nil){
        if (*Pdel != First(*L)){
            q = Prev(*Pdel);
            Prev(Succ) = q;
            Next(q) = Succ;
            Prev(*Pdel) = Nil;
            Next(*Pdel) = Nil;
        } else {
            First(*L) = Succ;
            Prev(Succ) = Nil;
            Prev(*Pdel) = Nil;
            Next(*Pdel) = Nil;
        }
    }
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
    printf("[");
    address p = First(L);
    if (p != Nil){
        printf("(%d,%d)",X(p),Y(p));
        p = Next(p);
    }
    while (p != Nil){
        printf(",(%d,%d)",X(p),Y(p));
        p = Next(p);
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L){
    address p = Last(L);
    printf("[");
    if (p != Nil){
        printf("(%d,%d)",X(p),Y(p));
        p = Prev(p);
    }
    while (p != Nil){
        printf(",(%d,%d)",X(p),Y(p));
        p = Prev(p);
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */