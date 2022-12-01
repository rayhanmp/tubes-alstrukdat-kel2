/* File : Listdp.h */
/* ADT Listdp dengan Double Pointer */
/* Representasi berkait dengan addressldp adalah pointer */
/* infotype adalah point */

#ifndef Listdp_H
#define Listdp_H

#include <stdio.h>
#include <stdlib.h>
#include "Listdp.h"
#include "../boolean.h"
#include "point.h"


/* Definisi Type Data */

typedef struct tElmtListdp *addressldp;
typedef struct tElmtListdp { 
	point info;
	addressldp next;
	addressldp prev;
} ElmtListdp;
typedef struct {
	addressldp First;
	addressldp Last;
} Listdp;

/* Definisi Listdp : */
/* Listdp kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir Listdp: Last(L) */

/* Notasi Akses */
#define X(P) (P)->info.x
#define Y(P) (P)->info.y
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST Listdp KOSONG ******************/
boolean IsEmptyLDP (Listdp L);
/* Mengirim true jika Listdp kosong. Lihat definisi di atas. */

/****************** PEMBUATAN Listdp KOSONG ******************/
void CreateEmptyLDP (Listdp *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk Listdp kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressldp AlokasiLDP (point N);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void DealokasiLDP (addressldp P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN Listdp ******************/
addressldp SearchLDP (Listdp L, point N);
/* Mencari apakah ada elemen Listdp dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstLDP (Listdp *L, point N);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastLDP (Listdp *L, point N);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen Listdp di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstLDP (Listdp *L, point *N);
/* I.S. Listdp L tidak kosong  */
/* F.S. Elemen pertama Listdp dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastLDP (Listdp *L, point *N);
/* I.S. Listdp tidak kosong */
/* F.S. Elemen terakhir Listdp dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstLDP (Listdp *L, addressldp P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressldp P sebagai elemen pertama */
void InsertLastLDP (Listdp *L, addressldp P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterLDP (Listdp *L, addressldp P, addressldp Prec);
/* I.S. Prec pastilah elemen Listdp; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforeLDP (Listdp *L, addressldp P, addressldp Succ);
/* I.S. Succ pastilah elemen Listdp; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstLDP (Listdp *L, addressldp *P);
/* I.S. Listdp tidak kosong */
/* F.S. P adalah alamat elemen pertama Listdp sebelum penghapusan */
/*      Elemen Listdp berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastLDP (Listdp *L, addressldp *P);
/* I.S. Listdp tidak kosong */
/* F.S. P adalah alamat elemen terakhir Listdp sebelum penghapusan  */
/*      Elemen Listdp berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPLDP (Listdp *L, point X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen Listdp beraddressldp P, dengan Info(P)=X  */
/* maka P dihapus dari Listdp dan didealokasi */
/* Jika tidak ada elemen Listdp dengan Info(P)=X, maka Listdp tetap */
/* Listdp mungkin menjadi kosong karena penghapusan */
void DelAfterLDP (Listdp *L, addressldp *Pdel, addressldp Prec);
/* I.S. Listdp tidak kosong. Prec adalah anggota Listdp. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen Listdp yang dihapus  */
void DelBeforeLDP (Listdp *L, addressldp *Pdel, addressldp Succ);
/* I.S. Listdp tidak kosong. Succ adalah anggota Listdp. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen Listdp yang dihapus  */

/****************** PROSES SEMUA ELEMEN Listdp ******************/
void PrintForwardLDP (Listdp L);
/* I.S. Listdp mungkin kosong */
/* F.S. Jika Listdp tidak kosong, isi Listdp dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Listdp kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackwardLDP (Listdp L);
/* I.S. Listdp mungkin kosong */
/* F.S. Jika Listdp tidak kosong, isi Listdp dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika Listdp kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

#endif