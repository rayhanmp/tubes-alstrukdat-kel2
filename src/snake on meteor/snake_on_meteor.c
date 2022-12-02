#include "snake_on_meteor.h"


int snake_on_meteor(){
    /* TITLE */
    printf("  _|_|_|  _|      _|    _|_|    _|    _|  _|_|_|_|        _|_|    _|      _|      _|      _|  _|_|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|    _|_|_|    \n");
    printf("_|        _|_|    _|  _|    _|  _|  _|    _|            _|    _|  _|_|    _|      _|_|  _|_|  _|            _|      _|        _|    _|  _|    _|  \n");
    printf("  _|_|    _|  _|  _|  _|_|_|_|  _|_|      _|_|_|        _|    _|  _|  _|  _|      _|  _|  _|  _|_|_|        _|      _|_|_|    _|    _|  _|_|_|    \n");
    printf("      _|  _|    _|_|  _|    _|  _|  _|    _|            _|    _|  _|    _|_|      _|      _|  _|            _|      _|        _|    _|  _|    _|  \n");
    printf("_|_|_|    _|      _|  _|    _|  _|    _|  _|_|_|_|        _|_|    _|      _|      _|      _|  _|_|_|_|      _|      _|_|_|_|    _|_|    _|    _|  \n");
    /*__________DECLARE/INISIALISASI__________*/
    matrixchar display;
    int input;
    boolean valid;
    long long seed;
    Listdp snake,obstacle;
    Word w,w2;
    point h,f,m;
    point o;
    int n;
    int skor = 0;
    addressldp p;
    boolean run = true;
    seedrngver2(&seed);
    /*_____INISIALISASI SNAKE_____*/
    Xp(h) = (int) rngver2(&seed,0,4);
    Yp(h) = (int) rngver2(&seed,0,4);
    CreateEmptyLDP(&snake);
    CreateEmptyLDP(&obstacle);
    InsVFirstLDP (&snake, h);
    for(int i = 0; i < 2; i++){
    if (Xp(h) != 0){
        Xp(h) --;
    } else {
        Xp(h) = 4;
    }
    InsVLastLDP (&snake, h);
    }
    /*END__INISIALISASI SNAKE__END*/
    /*_____INISIALISASI METEOR_____*/
    Xp(m) = 100;
    Yp(m) = 100;
    /*_____INISIALISASI OBSTACLE_____*/
    for(int i = 0; i < 3; i++){
        valid = false;
        while (!valid)
        {
            Xp(o) = (int) rngver2(&seed,0,4);
            Yp(o) = (int) rngver2(&seed,0,4);
            if ((SearchLDP(snake,o) == NULL)&&(SearchLDP(obstacle,o) == NULL)){
                valid = true;
            }
        }
        InsVLastLDP(&obstacle,o);
    }
    /*END__INISIALISASI OBSTACLE__END*/
    /*_____INISIALISASI FOOD_____*/
    valid = false;
    while (!valid)
    {
        Xp(f) = (int) rngver2(&seed,0,4);
        Yp(f) = (int) rngver2(&seed,0,4);
        if ((SearchLDP(snake,f) == NULL)&&(SearchLDP(obstacle,f) == NULL)){
            valid = true;
        }
    }
    /*END__INISIALISASI FOOD__END*/
    /*_____DISPLAY PERTAMA KALI_____*/
    CreateEmptyMatrixChar(&display,5,5);
    p = First(snake);
    CloneWord(&w,w2);
    InsertLastW(&w,"H ");
    InsertMatrixChar(&display, w, p->info);
    p = Next(p);
    n = 1;
    while (p != NULL){
        CloneWord(&w,intToWord(n));
        if (n < 10) {
            InsertLastW(&w," ");
        }
        InsertMatrixChar(&display,w, p->info);
        n++;
        p = Next(p);
    }
    p = First(obstacle);
    CloneWord(&w,w2);
    InsertLastW(&w," X");
    while (p != NULL){
        InsertMatrixChar(&display,w, p->info);
        p = Next(p);
    }
    CloneWord(&w,w2);
    InsertLastW(&w," o");
    InsertMatrixChar(&display,w,f);
    CloneWord(&w,w2);
    InsertLastW(&w," m");
    InsertMatrixChar(&display,w,m);
    
    PrintMatrixChar(display);
    
    /*END__DISPLAY PERTAMA KALI__END*/
    while (run)
    {
        
        /*_____GERAKAN_____*/
        valid = false;
        while (!valid)
        {
            printf("Silahkan masukkan command anda: ");
            STARTWORD_INPUT();
            if ((isKataEqual(currentWord, "A"))||(isKataEqual(currentWord, "S"))||(isKataEqual(currentWord, "W"))||(isKataEqual(currentWord, "D"))||(isKataEqual(currentWord, "a"))||(isKataEqual(currentWord, "s"))||(isKataEqual(currentWord, "w"))||(isKataEqual(currentWord, "d")) ){
                    if ((isKataEqual(currentWord, "A")) || (isKataEqual(currentWord, "a"))) { /* KIRI*/
                        if (X(First(snake)) == 0){
                            Xp(h) = 4;
                        }
                        else {
                            Xp(h) = X(First(snake))-1;
                        }
                        Yp(h) = Y(First(snake));
                        if ((SearchLDP(snake,h) == NULL)&&(SearchLDP(obstacle,h) == NULL)&&(!SamePoint(h,m))){
                            valid = true;
                        } else {
                            if (SearchLDP(snake,h) != NULL){
                                printf("\nAnda tidak dapat bergerak ke tubuh anda sendiri\n");
                            }
                            else if (SearchLDP(obstacle,h) != NULL){
                                printf("\nAnda tidak dapat bergerak ke obstacle\n");
                            } else if (SamePoint(h,m)){
                                printf("\nMeteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                            }
                        }
                } else if ((isKataEqual(currentWord, "D"))||(isKataEqual(currentWord, "d"))) { /* KANAN */
                        if (X(First(snake)) == 4){
                            Xp(h) = 0;
                        }
                        else {
                            Xp(h) = X(First(snake))+1;
                        }
                        Yp(h) = Y(First(snake));
                        if ((SearchLDP(snake,h) == NULL) && (SearchLDP(obstacle,h) == NULL) &&(!SamePoint(h,m))){
                            valid = true;
                        } else {
                            if (SearchLDP(snake,h) != NULL){
                                printf("\nAnda tidak dapat bergerak ke tubuh anda sendiri\n");
                            }
                            else if (SearchLDP(obstacle,h) != NULL){
                                printf("\nAnda tidak dapat bergerak ke obstacle\n");
                            } else if (SamePoint(h,m)){
                                printf("\nMeteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                            }
                        }
                } else if ((isKataEqual(currentWord, "W"))|| (isKataEqual(currentWord, "w"))) { /* ATAS */
                        if (Y(First(snake)) == 0){
                            Yp(h) = 4;
                        }
                        else {
                            Yp(h) = Y(First(snake))-1;
                        }
                        Xp(h) = X(First(snake));
                        if ((SearchLDP(snake,h) == NULL)&&(SearchLDP(obstacle,h) == NULL) &&(!SamePoint(h,m))){
                            valid = true;
                        } else {
                            if (SearchLDP(snake,h) != NULL){
                                printf("\nAnda tidak dapat bergerak ke tubuh anda sendiri\n");
                            }
                            else if (SearchLDP(obstacle,h) != NULL){
                                printf("\nAnda tidak dapat bergerak ke obstacle\n");
                            } else if (SamePoint(h,m)){
                                printf("\nMeteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                            }
                        }  
                } else if ((isKataEqual(currentWord, "S"))||(isKataEqual(currentWord, "s"))) { /* BAWAH */
                        if (Y(First(snake)) == 4){
                            Yp(h) = 0;
                        }
                        else {
                            Yp(h) = Y(First(snake))+1;
                        }
                        Xp(h) = X(First(snake));
                        if ((SearchLDP(snake,h) == NULL)&&(SearchLDP(obstacle,h) == NULL) &&(!SamePoint(h,m))){
                            valid = true;
                        } else {
                            if (SearchLDP(snake,h) != NULL){
                                printf("\nAnda tidak dapat bergerak ke tubuh anda sendiri\n");
                            }
                            else if (SearchLDP(obstacle,h) != NULL){
                                printf("\nAnda tidak dapat bergerak ke obstacle\n");
                            } else if (SamePoint(h,m)){
                                printf("\nMeteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                            }
                        }  
                }
            } else {
                printf("\nCommand tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
            }
        }
        printf("\nBerhasil bergerak!\n");
        InsVFirstLDP (&snake, h);
        DelVLastLDP (&snake, &h);
        /*END__GERAKAN__END*/
        /*_____MAKAN_____*/
        if (SearchLDP(snake,f) != NULL){
            /* MAKANAN BARU*/
            valid = false;
            while (!valid)
            {
                Xp(f) = (int) rngver2(&seed,0,4);
                Yp(f) = (int) rngver2(&seed,0,4);
                if ((SearchLDP(snake,f) == NULL)&&(SearchLDP(obstacle,f) == NULL)&&(!SamePoint(m,f))){
                    valid = true;
                }
            }
            valid = false;
            /* PENAMBAHAN EKOR*/
            /*KE KIRI*/
            if (X(Last(snake)) == 0){
                Xp(h) = 4;    
            } else {
                Xp(h) = X(Last(snake)) - 1;
            }
            Yp(h) = Y(Last(snake));
            if ((SearchLDP(snake,h) != NULL) || (SearchLDP(obstacle,h) != NULL) || (SamePoint(h,m))){
                /*KE ATAS*/
                Xp(h) = X(Last(snake));
                if (Y(Last(snake)) == 0){
                    Yp(h) = 4;    
                } else {
                    Yp(h) = Y(Last(snake)) - 1;
                }
            } else {
                valid = true; 
            }
            if ((SearchLDP(snake,h) != NULL)||(SearchLDP(obstacle,h)!= NULL) || (SamePoint(h,m))){
                /*KE BAWAH*/
                Xp(h) = X(Last(snake));
                if (Y(Last(snake)) == 4){
                    Yp(h) = 0;    
                } else {
                    Yp(h) = Y(Last(snake)) + 1;
                }
            } else {
                valid = true; 
            }
            if ((SearchLDP(snake,h) != NULL)||(SearchLDP(obstacle,h) != NULL) || (SamePoint(h,m))){
                /*KE KANAN*/
                if (X(Last(snake)) == 4){
                    Xp(h) = 0;    
                } else {
                    Xp(h) = X(Last(snake)) + 1;
                }
                Yp(h) = Y(Last(snake));
            } else {
                valid = true; 
            }
            if ((SearchLDP(snake,h) != NULL)||(SearchLDP(obstacle,h) != NULL) || (SamePoint(h,m))){
                run = false; /*GAME OVER EKOR*/
            }
            if (run){
                InsVLastLDP (&snake, h);
            }
        }
        /*END__MAKAN__END*/
        /*_____METEOR_____ */
        valid = false;
        while (!valid)
        {
            Xp(m) = (int) rngver2(&seed,0,4);
            Yp(m) = (int) rngver2(&seed,0,4);
            if ((SearchLDP(obstacle,m) == NULL)&&(!SamePoint(m,f))){
                valid = true;
            }
        }
        if (SearchLDP(snake,m) != NULL){
            if (SearchLDP(snake,m) == First(snake)){
                DelPLDP(&snake,m);
                run = false; /* GAME OVER METEOR*/
            } else {
                DelPLDP(&snake,m);
                printf("Anda Terkena Meteor\n");

            }
        }
        /*END__METEOR__END*/
        /*_____PRINT_____ */
        CreateEmptyMatrixChar(&display,5,5);
        p = First(snake);
        CloneWord(&w,w2);
        InsertLastW(&w,"H ");
        InsertMatrixChar(&display, w, p->info);
        p = Next(p);
        n = 1;
        while (p != NULL){
            CloneWord(&w,intToWord(n));
            if (n < 10) {
                InsertLastW(&w," ");
            }
            InsertMatrixChar(&display,w, p->info);
            n++;
            p = Next(p);
        }
        p = First(obstacle);
        CloneWord(&w,w2);
        InsertLastW(&w," X");
        while (p != NULL){
            InsertMatrixChar(&display,w, p->info);
            p = Next(p);
        }
        CloneWord(&w,w2);
        InsertLastW(&w," o");
        InsertMatrixChar(&display,w,f);
        CloneWord(&w,w2);
        InsertLastW(&w," m");
        InsertMatrixChar(&display,w,m);

        PrintMatrixChar(display);

        /*_____CEK GAME OVER_____*/
        if (X(Last(snake)) == 4){ /* CEK KANAN*/
            Xp(h) = 0;    
        } else {
            Xp(h) = X(Last(snake)) + 1;
        }
        Yp(h) = Y(Last(snake));
        if ((SearchLDP(snake,h) != NULL) || (SearchLDP(obstacle,h) != NULL) || (SamePoint(h,m))){
            if (X(Last(snake)) == 0){ /* CEK KIRI */
                Xp(h) = 4;    
            } else {
                Xp(h) = X(Last(snake)) - 1;
            }
            Yp(h) = Y(Last(snake));
            if ((SearchLDP(snake,h) != NULL) || (SearchLDP(obstacle,h) != NULL) || (SamePoint(h,m))){
                Xp(h) = X(Last(snake)); /* CEK ATAS */
                if (Y(Last(snake)) == 0){ 
                Yp(h) = 4;    
                } else {
                Yp(h) = Y(Last(snake)) - 1;
                }
                if ((SearchLDP(snake,h) != NULL) || (SearchLDP(obstacle,h) != NULL) || (SamePoint(h,m))){
                    Xp(h) = X(Last(snake)); /* CEK BAWAH */
                    if (Y(Last(snake)) == 4){ 
                    Yp(h) = 0;    
                    } else {
                    Yp(h) = Y(Last(snake)) + 1;
                    }
                    if ((SearchLDP(snake,h) != NULL) || (SearchLDP(obstacle,h) != NULL) || (SamePoint(h,m))){
                        run = false;
                    }
                }
            }
        }
        
    }
    printf("\nGAME OVER\n");
    p = First(snake);
    while (p != NULL)
    {
        skor = skor + 2;
        p = Next(p);
    }
    printf("SKOR : %d",skor);
    return 0;
}
