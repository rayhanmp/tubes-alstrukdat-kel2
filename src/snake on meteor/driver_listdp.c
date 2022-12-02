#include "listdp.h"

int main() {
    Listdp L;
    point a, b, c, d, e, f, g, h, i, temppoint;
    addressldp p, q, r, s, tempaddress;

    a.x = 1;
    a.y = 2;
    b.x = 3;
    b.y = 4;
    c.x = 5;
    c.y = 6;
    d.x = 7;
    d.y = 8;
    e.x = 9;
    e.y = 10;
    f.x = 11;
    f.y = 12;
    g.x = 13;
    g.y = 14;
    h.x = 15;
    h.y = 16;

    /* TEST CASE 1: KONSTRUKTOR & ISEMPTYLDP */
    /* EXPECTED OUTPUT: Listdp kosong*/
    CreateEmptyLDP(&L);

    if (IsEmptyLDP(L)) {
        printf("Listdp kosong\n");
    } else {
        printf("Listdp tidak kosong\n");
    }

    /* TEST CASE 2: PRIMITIF PENAMBAHAN BERDASARKAN NILAI */
    /* EXPECTED OUTPUT: [(3,4),(1,2)]
                        [(3,4),(1,2),(7,8),(5,6)] 
                        [(5,6),(7,8),(1,2),(3,4)] */
    InsVFirstLDP(&L, a);
    InsVFirstLDP(&L, b);
    PrintForwardLDP(L);

    printf("\n");

    InsVLastLDP(&L, d);
    InsVLastLDP(&L, c);
    PrintForwardLDP(L);
    printf("\n");
    PrintBackwardLDP(L);
    printf("\n");

    /* TEST CASE 3: PRIMITIF PENAMBAHAN BERDASARKAN ALAMAT DAN ALOKASI */
    /* EXPECTED OUTPUT: [(9,10),(3,4),(1,2),(7,8),(5,6),(15,16)] */
    p = AlokasiLDP(e);
    q = AlokasiLDP(f);
    r = AlokasiLDP(g);
    s = AlokasiLDP(h);

    InsertFirstLDP(&L, p);
    InsertLastLDP(&L, s);
    PrintForwardLDP(L);
    printf("\n");

    /* TEST CASE 4: PRIMITIF PENGHAPUSAN DAN DEALOKASI */
    /* EXPECTED OUTPUT: [(3,4),(1,2),(7,8),(5,6)]
                        [(1,2),(7,8),(5,6)]
                        [(7,8),(5,6)] 
                        [(7,8)] 
                        [] */
    DelVFirstLDP(&L, &temppoint);
    DelVLastLDP(&L, &temppoint);
    PrintForwardLDP(L);
    printf("\n");

    DelPLDP(&L, b);
    PrintForwardLDP(L);
    printf("\n");

    DelBeforeLDP(&L, &tempaddress, SearchLDP(L, d));
    PrintForwardLDP(L);
    printf("\n");

    DelAfterLDP(&L, &tempaddress, SearchLDP(L, d));
    PrintForwardLDP(L);
    printf("\n");

    DelVLastLDP(&L, &temppoint);
    PrintForwardLDP(L);
    printf("\n");

    /* TEST CASE 5: PRIMITIF PENCARIAN BERDASARKAN NILAI */
    /* EXPECTED OUTPUT: [(3,4),(1,2)]
                        [(5,6),(3,4),(5,6),(1,2)] */

    InsVFirstLDP(&L, a);
    InsVFirstLDP(&L, b);
    PrintForwardLDP(L);
    printf("\n");

    InsertAfterLDP(&L, AlokasiLDP(c), SearchLDP(L, b));
    InsertBeforeLDP(&L, AlokasiLDP(c), SearchLDP(L, b));
    PrintForwardLDP(L);

}