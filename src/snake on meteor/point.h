#ifndef _POINT_H_
#define _POINT_H_

#define Xp(P) (P).x
#define Yp(P) (P).y
#include "../boolean.h"
typedef struct
{
   int x;
   int y;
} point;

boolean SamePoint(point a, point b);

#endif