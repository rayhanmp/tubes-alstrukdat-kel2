#include "boolean.h"
#include "point.h"


boolean SamePoint(point a, point b){
    return ((Xp(a) == Xp(b)) && (Yp(a) == Yp(b)));
}