/* rnggame.c*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include "boolean.h"
#include "random_number_generator.h"
#include "rnggame.h"

int rnggame(){
    printf("\n>======>     >==>    >=>    >===>    \n");
    printf(">=>    >=>   >> >=>  >=>  >>    >=>    \n");
    printf(">=>    >=>   >=> >=> >=> >=>           \n");
    printf(">> >==>      >=>  >=>>=> >=>           \n");
    printf(">=>  >=>     >=>   > >=> >=>   >===>   \n");
    printf(">=>    >=>   >=>    >>=>  >=>    >>    \n");
    printf(">=>      >=> >=>     >=>   >====>      \n");
    int try = 0;
    boolean success = false;
    int ans;
    int x = rng(MIN_RNG_X, MAX_RNG_X);
    int score;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    while ((try < MAX_RNG_TRY) && (!success)){
        STARTWORD_INPUT();
        ans = wordToInt(currentWord);
        if (ans < x){
            printf("Lebih Besar\n");
        } else if (ans > x){
            printf("Lebih Kecil\n");
        } else /* ans == x */{
            printf("\n \nYa, X adalah %d.\n",x);
            success = true;
        }
        try++;
    }
    if (!success){
        printf("\n \nX adalah %d.\n",x);
        score = 0;
    } else { 
        score = (4-try);
    }
    return 0;
}
