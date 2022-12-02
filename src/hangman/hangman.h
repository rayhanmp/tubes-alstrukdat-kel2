#include "../ADT/mesinkata.h"
#include "../ADT/arrayGame.h"
#include "../ADT/arrayMap.h"
#include "../Commands/load.h"
#include "../Commands/save.h"
#include <time.h>
#include <stdlib.h>

boolean IsMemberRegArr (char *guesses, char guess);
/* Mengembalikan true apabila guess terdapat dalam array guesses */
/* Prekondisi: sembarang */

boolean IsInKata(Game el, Game guess);
/* Mengembalikan true apabila karakter pertama dari Word guess terdapat dalam Word el */
/* Prekondisi: sembarang */

int countAppearance(Game el, char x);
/* Mengembalikan jumlah kemunculan x dalam suatu Word el */
/* Prekondisi: sembarang */

void printRegArr(char *guesses, int guess);
/* I.S. Sembarang */
/* F.S. Prosedur mencetak huruf yang sudah ditebak user (dari array guesses) ke layar */

boolean cekNonKapital (Game el);
/* I.S. Sembarang */
/* F.S. Jika ada huruf nonkapital dalam el mengembalikan false*/

void tambahDiksi (arrGame *arrKata);
/* I.S. arrKata terdefinisi */
/* F.S. Prosedur meminta masukan kepada pengguna hingga pengguna memberi masukan 'STOP', kemudian prosedur menyimpan masukan ke berkas kamus.txt */

void freeGuesses(char *guesses);
/* I.S. Array of char guesses terdefinisi */
/* F.S. Array of char guesses diisi dengan '\0' */

void hangman(arrScore *Scores, int gamebrp);
/* I.S. Sembarang */
/* F.S. Prosedur menjalankan gim hangman */
