/* rnggame.c*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include "boolean.h"
#include "random_number_generator.h"
#include "rnggame.h"

int rnggame(){
    int try = 0;
    boolean success = false;
    int ans;
    x = rng() % (MAX_RNG_X - MIN_RNG_X + 1) + MIN_RNG_X;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    while ((try < MAX_RNG_TRY) && (!success)){
        scanf("%d",&ans);
        if (ans < x){
            printf("Lebih Besar\n");
        } else if (ans > x){
            printf("Lebih Kecil\n");
        } else /* ans == x */{
            printf("\n \n Ya, X adalah %d.\n",x);
            success = true;
        }
        try++;
    }
    if (!success){
        printf("\n \n X adalah %d.\n",x);
    }
    return 0;
}