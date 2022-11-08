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

void START(file filename)
{
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* Algoritma */
    char directory[50] = "../../data/";
    int i=0,j=0;
    while(directory[i]!='\0'){
        i++;  
    }
    while(filename[j]!='\0')
    {
        directory[i]=filename[j];
        j++;
        i++;
    }
  directory[i]='\0';
    pita = fopen(directory, "r");
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