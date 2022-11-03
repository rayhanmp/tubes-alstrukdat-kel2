#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
FILE *pita;
static int retval;

void START_INPUT()
{
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* Algoritma */
    pita = stdin;
    ADV();
}

void START()
{
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* Algoritma */
    pita = fopen("../ADT/data1.txt", "r");
    ADV();
}

void ADV()
{
    /* Pita dimajukan satu karakter. ... */
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC()
{
    /* Mengirimkan currentChar */
    /* Algoritma */
    return currentChar;
}

boolean IsEOP()
{
    /* Mengirimkan true jika currentChar = MARK */
    /* Algoritma */
    return EOP;
}