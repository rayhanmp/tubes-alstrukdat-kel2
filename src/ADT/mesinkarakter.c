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
    ADV_INPUT();
}

void START(char* filename)
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
    pita = fopen("data/config1.txt", "r");
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

void ADV_INPUT()
{
    /* Pita dimajukan satu karakter. ... */
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK_INPUT);
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