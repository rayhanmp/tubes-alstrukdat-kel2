#include <stdio.h>
#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(scoreMap *M){
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(scoreMap M){
    return (M).Count == Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(scoreMap M){
    return M.Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
value ValueMap(scoreMap M, key k){
    boolean found = false;
	Saddress i = 0;
	if (!IsEmptyMap(M)){
		while (i < M.Count && !found){
			if (isIdentical(M.Elements[i].Name, k)){
				found = true;
			} 
            else{
				i++;
			}
		}
		if (found){
			return M.Elements[i].Score;
		} 
        else{
			return Undefined;
		}
	} 
    else{
		return Undefined;
	}
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(scoreMap *M, key k, value v){
    if (!IsMemberMap(*M, k)){
		(*M).Elements[(*M).Count].Name = k;
		(*M).Elements[(*M).Count].Score = v;
		(*M).Count++;
	}
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(scoreMap *M, key k){
    if (IsMemberMap(*M, k)){
		boolean found = false;
		Saddress i = 0;
		while ((i < (*M).Count) && (!found)) {
			if (!isIdentical(M->Elements[i].Name,k)) {
				found = true;
			} 
            else{
				i++;
			}
		}
		if (found){
			(*M).Count--;
			for (int j = i; j < (*M).Count; j++){
				(*M).Elements[j].Name = (*M).Elements[j + 1].Name;
				(*M).Elements[j].Score = (*M).Elements[j + 1].Score;
			} 
		}
	}   
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(scoreMap M, key k){
    value v = ValueMap(M, k);
    if (v == Undefined){
		return false;
	} 
    else{
		return true;
	}
}
/* Mengembalikan true jika k adalah member dari M */

void PrintMap(scoreMap M){
	int Nspaces,Sspaces;
	Word score;
	for(int i = 0; i < M.Count; i++){
		Nspaces = 15 - M.Elements[i].Name.Length;
		CloneWord(&score,intToWord(M.Elements[i].Score));
		Sspaces = 10 - score.Length;
		printf("|");
		printWord(M.Elements[i].Name);
		printchar(' ', Nspaces);
		printf("|");
		printWord(score);
		printchar(' ', Sspaces);
		printf("|\n");
	}
}
/* I.S. M terdefinisi */
/* F.S. M dicetak ke layar */
