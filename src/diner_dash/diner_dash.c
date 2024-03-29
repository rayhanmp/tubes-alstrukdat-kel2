/*diner_dash.c*/
#include "diner_dash.h"

void displayCook(Map m){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("-------------------------------\n");
    for(int i = 0; i < m.Count; i++){
        if (m.Elements[i].Key < 10){
            printf("M%d      | %d\n",m.Elements[i].Key, m.Elements[i].Value);
            }
        else {
            printf("M%d     | %d\n",m.Elements[i].Key, m.Elements[i].Value);
        }
    }
}

void displayServe(Map m){
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("-------------------------------\n");
    for(int i = 0; i < m.Count; i++){
        if (m.Elements[i].Key < 10){
            printf("M%d      | %d\n",m.Elements[i].Key, m.Elements[i].Value);
            }
        else {
            printf("M%d     | %d\n",m.Elements[i].Key, m.Elements[i].Value);
        }
    }
}

void displayErrand(QueueDD q){
    int key,duration,spoliage,price;
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    while(!(isEmptydd(q))){
        dequeuedd(&q, &key, &duration, &spoliage, &price);
        if (key < 10){
            printf("M%d      | %d              | %d         | %d\n",key,duration,spoliage,price);
            }
        else {
            printf("M%d     | %d              | %d         | %d\n",key,duration,spoliage,price);
        }
    }    
}

void displaySeparator(){
    printf("==========================================================\n");
}

int diner_dash(){
    /*DECLARE/INISIALISASI*/
    Map mCook;
    Map mServe;
    QueueDD qErrand;
    boolean run = true;
    boolean input_valid;
    int customer = 0;
    int saldo = 0;
    long long seed;
    seedrngver2(&seed);
    Word input1;
    int input2;
    int key,duration,spoliage,price;
    CreateQueuedd(&qErrand);
    CreateEmpty(&mCook);
    CreateEmpty(&mServe);
    enqueuedd(&qErrand,1,rngver2(&seed,1,5),rngver2(&seed,1,5),rngver2(&seed,10,50)*1000);
    enqueuedd(&qErrand,2,rngver2(&seed,1,5),rngver2(&seed,1,5),rngver2(&seed,10,50)*1000);
    enqueuedd(&qErrand,3,rngver2(&seed,1,5),rngver2(&seed,1,5),rngver2(&seed,10,50)*1000);
    printf("Selamat Datang di Diner Dash!\n");
    while (run){
        /* CETAK */
        printf("\nSALDO: %d\n",saldo);
        displayErrand(qErrand);
        printf("\n");
        displayCook(mCook);
        printf("\n");
        displayServe(mServe);
        printf("\n");
        input_valid = false;
        printf("MASUKKAN COMMAND: ");
        /* PROSES INPUT*/
        while(!(input_valid)){
            STARTWORD_INPUT();
            input1 = currentWord;
            if (isKataEqual(input1,"COOK")){ 
                ADVWORD_INPUT();
                input2 = wordToIntDD (currentWord);
                if ((input2 >= HEAD_ID(qErrand)) && (input2 <= TAIL_ID(qErrand))  && (!IsMember(mCook,input2)) && (mCook.Count < 5) && (!IsMember(mServe,input2))){ 
                    input_valid = true;
                    printf("\nBerhasil memasak M%d\n",input2); /* COOK, berhasil*/
                } 
                else if (IsMember(mCook,input2)){
                    printf("\nM%d sedang dimasak\n",input2); /* COOK, gagal karena input2 ada pada mCook */
                }
                 else if (IsMember(mServe, input2)){
                    printf("\nM%d sudah siap disajikan\n",input2); /*COOK, gagal karena input2 ada pada mServe */
                }
                 else if (mCook.Count >= 5) {
                     printf("\nHanya bisa memasak 5 makanan sekaligus\n"); /* COOK, mCook penuh */
                 }
                 else {
                    printf("\nM%d tidak ada pada pemesanan\n",input2); /* COOK, input2 tidak ada pada qErrand*/
                }
            } else if(isKataEqual(input1,"SERVE")) { 
                ADVWORD_INPUT();
                input2 = wordToIntDD (currentWord);
                if ((IsMember(mServe,input2)) && (HEAD_ID(qErrand) == input2)){
                    input_valid = true;
                    printf("\nBerhasil mengantar M%d\n",input2); /* SERVE, berhasil*/
                } else if (!IsMember(mServe,input2)){
                    printf("\nM%d belum selesai dimasak\n",input2); /* SERVE, gagal karena tidak ada di mServe*/
                } else {
                    printf("\nM%d belum dapat disajikan karena M%d belum selesai\n",input2,HEAD_ID(qErrand)); /* SERVE, gagal karena id bukanlah HEAD_ID*/
                }
            } else if ((isKataEqual(input1,"SKIP"))){ /*GANTI DENGAN KATA*/
                input_valid = true;
                printf("\nPutaran ini dilewati\n");
            } else {
                printf("\nCommand yang tersedia adalah COOK, SERVE, SKIP\n"); /* INPUT PERTAMA GAGAL*/
            }
            if (!(input_valid)){
                printf("\nMASUKKAN COMMAND: ");
            }
        }
        /* UPDATE GAME*/
        /* laksanakan input serve*/
        if (isKataEqual(input1,"SERVE")){
            dequeuedd(&qErrand, &key, &duration, &spoliage, &price);
            Delete(&mServe,key);
            saldo = saldo + price;
            customer++;
            if (customer >= 15 ){
                run = false;
            }
        }
        /* update serve*/
        for(int i = 0; i < mServe.Count; i++){
            if (mServe.Elements[i].Value == 1){
                key = mServe.Elements[i].Key;
                Delete(&mServe,key);
                printf("Makanan M%d telah basi\n", key);
            } else {
                mServe.Elements[i].Value = mServe.Elements[i].Value - 1;
            }
        }
        /* update cook*/
        for(int i = 0; i < mCook.Count; i++){
            if (mCook.Elements[i].Value == 1){
                key = mCook.Elements[i].Key;
                takeValue(qErrand, key , &duration, &spoliage, &price);
                Insert(&mServe, key, spoliage);
                Delete(&mCook, key);
                printf("Makanan M%d telah selesai dimasak\n", key);
            } else {
                mCook.Elements[i].Value = mCook.Elements[i].Value - 1;
            }
        }        
        /* laksanakan input cook*/
        if (isKataEqual(input1,"COOK")){
            takeValue(qErrand, input2, &duration, &spoliage, &price);
            Insert(&mCook, input2, duration);
        }
        /* MENAMBAH CUSTOMER*/
        if (lengthdd(qErrand) <= 7){
            key = TAIL_ID(qErrand) + 1;
            enqueuedd(&qErrand,key,rngver2(&seed,1,5),rngver2(&seed,1,5),rngver2(&seed,10,50)*1000);
        } else {
            run = false;
        }
        displaySeparator();
    }
    printf("Jumlah pelanggan yang dilayani : %d\n Saldo total : %d\n",customer,saldo);
    return 0;
}
