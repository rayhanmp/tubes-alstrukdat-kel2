#include <stdio.h>
#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M){
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M){
    return (M).Count == Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M){
    return M.Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype ValueMap(Map M, keytype k){
    boolean found = false;
	address i = 0;
	if (!IsEmpty(M)){
		while (i < M.Count && !found){
			if (isIdentical(M.Elements[i].Key,k)){
				found = true;
			} 
            else{
				i++;
			}
		}
		if (found){
			return M.Elements[i].Value;
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

void InsertMap(Map *M, keytype k, valuetype v){
    if (!IsMember(*M, k)){
		(*M).Elements[(*M).Count].Key = k;
		(*M).Elements[(*M).Count].Value = v;
		(*M).Count++;
	}
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytype k){
    if (IsMember(*M, k)){
		boolean found = false;
		address i = 0;
		while ((i < (*M).Count) && (!found)) {
			if (isIdentical(M->Elements[i].Key,k)) {
				found = true;
			} 
            else{
				i++;
			}
		}
		if (found){
			(*M).Count--;
			for (int j = i; j < (*M).Count; j++){
				(*M).Elements[j].Key = (*M).Elements[j + 1].Key;
				(*M).Elements[j].Value = (*M).Elements[j + 1].Value;
			} 
		}
	}   
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k){
    valuetype v = ValueMap(M, k);
    if (v == Undefined){
		return false;
	} 
    else{
		return true;
	}
}
/* Mengembalikan true jika k adalah member dari M */

void PrintMap(Map Creategame, Map RNG, Map dinerDash, Map hangman, Map tower, Map snake, arrGame Games){
	int i = 0;
	while(i < Length(Games)){
		if(isKataEqual(Get(Games,i),"HANGMAN")){
			if(!IsEmptyMap(hangman)){
				printf("***SCOREBOARD HANGMAN***\n");
				printf("|   NAMA    |   SKOR   |\n");
				printf("-----------------------\n");
			}
		}
		else{
				printf("***SCOREBOARD %s***\n", Get(Games, i));
				printf("|   NAMA  |    SKOR   |\n");
				printf("---SCOREBOARD KOSONG---\n");       
		}
		i++;
	}
}
/* I.S. M terdefinisi */
/* F.S. M dicetak ke layar */
