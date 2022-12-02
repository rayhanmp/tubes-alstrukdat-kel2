#include <stdio.h>
#include "point.h"

int main () {
    point a, b;

    /* TEST CASE 1*/
    /* EXPECTED OUTPUT: Same */
    a.x = 1;
    a.y = 2;

    b.x = 1;
    b.y = 2;

    if (SamePoint(a, b)) {
        printf("Same\n");
    } else {
        printf("Not same\n");
    }

    /* TEST CASE 2*/
    /* EXPECTED OUTPUT: Not same */
    a.x = 1;
    a.y = 3;

    b.x = 1;
    b.y = 2;

    if (SamePoint(a, b)) {
        printf("Same\n");
    } else {
        printf("Not same\n");
    }
}