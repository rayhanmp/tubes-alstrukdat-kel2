/*listdp.c
18221152
Raditya Azka Prabaswara */
#include "listdp.h"
/* PROTOTYPE */
/****************** TEST Listdp KOSONG ******************/
boolean IsEmptyLDP (Listdp L){
    return ( (First(L) == NULL)&&(Last(L) == NULL) );
}
/* Mengirim true jika Listdp kosong. Lihat definisi di atas. */

/****************** PEMBUATAN Listdp KOSONG ******************/
void CreateEmptyLDP (Listdp *L){
    (First(*L) = NULL);
    (Last(*L) = NULL) ;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk Listdp kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressldp AlokasiLDP (point N){
    addressldp a = (addressldp) malloc (sizeof(ElmtListdp));
    if (a != NULL){
        X(a) = Xp(N);
        Y(a) = Yp(N);
        Next(a) = NULL;
        Prev(a) = NULL;
        return(a);
    } else {
        return(NULL);
    }
    
}
/* Mengirimkan addressldp hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressldp tidak NULL. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=NULL, Prev(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL. */
void DealokasiLDP (addressldp P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressldp P */

/****************** PENCARIAN SEBUAH ELEMEN Listdp ******************/
addressldp SearchLDP (Listdp L, point N){
    addressldp p = First(L);
    boolean found = false;
    if (IsEmptyLDP(L)){
        return (NULL);
    } else {
        while ( (p != NULL) && (!found) ){
            if ((X(p) == Xp(N)) && ((Y(p) == Yp(N)))){
                found = true;
            } else {
                p = Next(p);
            }
        }
        if (found){
            return (p);
        } else {
            return (NULL);
        }
    }
}
/* Mencari apakah ada elemen Listdp dengan Info(P)=X */
/* Jika ada, mengirimkan addressldp elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

/****************** PRIMITIF BERDASARKAN NULLAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstLDP (Listdp *L, point N){
    addressldp p = AlokasiLDP(N);
    if (p != NULL){
        InsertFirstLDP(L,p);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NULLai X jika alokasi berhasil */
void InsVLastLDP (Listdp *L, point N){
    addressldp p = AlokasiLDP(N);
    if (p != NULL){
        InsertLastLDP(L,p);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen Listdp di akhir: elemen terakhir yang baru */
/* berNULLai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstLDP (Listdp *L, point *N){
    Xp(*N) = X(First(*L));
    Yp(*N) = Y(First(*L));
    addressldp p;
    DelFirstLDP(L,&p);
    DealokasiLDP(p);
}
/* I.S. Listdp L tidak kosong  */
/* F.S. Elemen pertama Listdp dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastLDP (Listdp *L, point *N){
    Xp(*N) = X(Last(*L));
    Yp(*N) = Y(Last(*L));
    addressldp p;
    DelLastLDP(L,&p);
    DealokasiLDP(p);
}
/* I.S. Listdp tidak kosong */
/* F.S. Elemen terakhir Listdp dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstLDP (Listdp *L, addressldp P){
    addressldp q = First(*L);
    Prev(P) = NULL;
    if (q != NULL){
        First(*L) = P;
        Next(P) = q;
        Prev(q) = P;
    } else {
        Next(P) = NULL;
        First(*L) = P;
        Last(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressldp P sebagai elemen pertama */
void InsertLastLDP (Listdp *L, addressldp P){
    addressldp q = Last(*L);
    Next(P) = NULL;
    if (q != NULL){
        Last(*L) = P;
        Prev(P) = q;
        Next(q) = P;
    } else {
        Prev(P) = NULL;
        Last(*L) = P;
        First(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterLDP (Listdp *L, addressldp P, addressldp Prec){
    addressldp q = Next(Prec);
    if (Last(*L) != Prec){
        Next(P) = q;
        Next(Prec) = P;
        Prev(P) = Prec;
        Prev(q) = P;
    } else {
        Next(Prec) = P;
        Prev(P) = Prec;
        Next(P) = NULL;
        Last(*L) = P;
    }
}
/* I.S. Prec pastilah elemen Listdp; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforeLDP (Listdp *L, addressldp P, addressldp Succ){
    addressldp q = Prev(Succ);
    if (First(*L) != Succ){
        Prev(P) = q;
        Prev(Succ) = P;
        Next(P) = Succ;
        Next(q) = P;
    } else {
        Prev(Succ) = P;
        Next(P) = Succ;
        Prev(P) = NULL;
        First(*L) = P;
    }
}
/* I.S. Succ pastilah elemen Listdp; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstLDP (Listdp *L, addressldp *P){
    *P = First(*L);
    addressldp q = Next(*P);
    Next(*P) = NULL;
    Prev(*P) = NULL;
    if (Last(*L) != *P){
        First(*L) = q;
        Prev(q) = NULL;
    } else {
        First(*L) = NULL;
        Last(*L) = NULL;
    }
}
/* I.S. Listdp tidak kosong */
/* F.S. P adalah alamat elemen pertama Listdp sebelum penghapusan */
/*      Elemen Listdp berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastLDP (Listdp *L, addressldp *P){
    *P = Last(*L);
    addressldp q = Prev(*P);
    Next(*P) = NULL;
    Prev(*P) = NULL;
    if (First(*L) != *P){
        Last(*L) = q;
        Next(q) = NULL;
    } else {
        First(*L) = NULL;
        Last(*L) = NULL;
    }
}
/* I.S. Listdp tidak kosong */
/* F.S. P adalah alamat elemen terakhir Listdp sebelum penghapusan  */
/*      Elemen Listdp berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPLDP (Listdp *L, point N){
    addressldp q = SearchLDP(*L,N);
    addressldp p,r;
    if (q != NULL){
        if (q == First(*L)){
            DelFirstLDP(L,&q);
        } else if (q == Last(*L)){
            DelLastLDP(L,&q);
        } else {
            Next(Prev(q)) = Next(q);
            Prev(Next(q)) = Prev(q);
        }
        DealokasiLDP(q);
    } 
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen Listdp beraddressldp P, dengan Info(P)=X  */
/* maka P dihapus dari Listdp dan didealokasi */
/* Jika tidak ada elemen Listdp dengan Info(P)=X, maka Listdp tetap */
/* Listdp mungkin menjadi kosong karena penghapusan */
void DelAfterLDP (Listdp *L, addressldp *Pdel, addressldp Prec){
    *Pdel = Next(Prec);
    addressldp r;
    if (*Pdel != NULL){
        if (*Pdel != Last(*L)){
            r = Next(*Pdel);
            Next(Prec) = r;
            Prev(r) = Prec;
            Next(*Pdel) = NULL;
            Prev(*Pdel) = NULL;
        } else {
            Last(*L) = Prec;
            Next(Prec) = NULL;
            Next(*Pdel) = NULL;
            Prev(*Pdel) = NULL;
        }
    }
}
/* I.S. Listdp tidak kosong. Prec adalah anggota Listdp. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen Listdp yang dihapus  */
void DelBeforeLDP (Listdp *L, addressldp *Pdel, addressldp Succ){
    *Pdel = Prev(Succ);
    addressldp q;
    if (*Pdel != NULL){
        if (*Pdel != First(*L)){
            q = Prev(*Pdel);
            Prev(Succ) = q;
            Next(q) = Succ;
            Prev(*Pdel) = NULL;
            Next(*Pdel) = NULL;
        } else {
            First(*L) = Succ;
            Prev(Succ) = NULL;
            Prev(*Pdel) = NULL;
            Next(*Pdel) = NULL;
        }
    }
}
/* I.S. Listdp tidak kosong. Succ adalah anggota Listdp. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen Listdp yang dihapus  */

/****************** PROSES SEMUA ELEMEN Listdp ******************/
void PrintForwardLDP (Listdp L){
    printf("[");
    addressldp p = First(L);
    if (p != NULL){
        printf("(%d,%d)",X(p),Y(p));
        p = Next(p);
    }
    while (p != NULL){
        printf(",(%d,%d)",X(p),Y(p));
        p = Next(p);
    }
    printf("]");
}
/* I.S. Listdp mungkin kosong */
/* F.S. Jika Listdp tidak kosong, isi Listdp dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNULLai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Listdp kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackwardLDP (Listdp L){
    addressldp p = Last(L);
    printf("[");
    if (p != NULL){
        printf("(%d,%d)",X(p),Y(p));
        p = Prev(p);
    }
    while (p != NULL){
        printf(",(%d,%d)",X(p),Y(p));
        p = Prev(p);
    }
    printf("]");
}
/* I.S. Listdp mungkin kosong */
/* F.S. Jika Listdp tidak kosong, isi Listdp dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen berNULLai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika Listdp kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */