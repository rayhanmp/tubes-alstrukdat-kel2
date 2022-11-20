#include "stack.h"
/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyS(Stack *S){
    S->TOP = SNil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS(Stack S){
    return S.TOP == SNil;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullS(Stack S){
    return S.TOP == SMaxEl - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, stacktype X){
    S->TOP++;
    InfoTop(*S) = X;

}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, stacktype* X){
    *X = InfoTop(*S);
    S->TOP--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void CopyStack(Stack Sin, Stack *Sout){
    Stack Stemp;
    stacktype X;
    CreateEmptyS(Sout);
    CreateEmptyS(&Stemp);
    while(!IsEmptyS(Sin)){
        Pop(&Sin,&X);
        Push(&Stemp, X);
    }
    while(!IsEmptyS(Stemp)){
        Pop(&Stemp,&X);
        Push(&Sin, X);
        Push(Sout, X);
    }
}

int LengthS(Stack S){
    Stack S2;
    int length = 0;
    stacktype X;
    CopyStack(S,&S2);
    while(!IsEmptyS(S2) && length <= SMaxEl){
        Pop(&S2, &X);
        length++;
    }
    return length;
}

void printStack(Stack S){
    Stack Stemp;
    stacktype X;
    CopyStack(S, &Stemp);
    while(!IsEmptyS(Stemp)){
        Pop(&Stemp, &X);
        printf("     %d\n", X);
    }
}
