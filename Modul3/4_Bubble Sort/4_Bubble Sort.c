#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int validation(int banyak_data);
int validation2(int pilih_jenis);
int bubble_sort_pointer(int kumpulan[], int banyak_data);
int bubble_sort_biasa(int kumpulan[], int banyak_data);
void random_number(int kumpulan[], int banyak_data);
void mengulang(char ulang[]);
void selesai();
void validasimengulang(char ulang[]);

int main(){

    int kumpulan[70000];
    char ulang[10];
    int banyak_data, pilih_jenis, jumlah_data;

    printf("\n+------------------------------+\n");
    printf("| PILIHAN BANYAK DATA          |\n");
    printf("+------------------------------+\n");
    printf("| 1. 1000 DATA                 |\n");
    printf("| 2. 16000 DATA                |\n");
    printf("| 3. 64000 DATA                |\n");
    printf("+------------------------------+\n");
    printf("| MASUKAN PILIHAN BANYAK DATA   : ");
    banyak_data = validation(banyak_data);
    printf("+------------------------------+\n");

    if (banyak_data > 0 && banyak_data < 4){
        if (banyak_data == 1){
            jumlah_data = 1000;
        } else if (banyak_data == 2){
            jumlah_data = 16000;
        } else{
            jumlah_data = 64000;
        }
        system("cls || clear");

        printf("\n+------------------------------+\n");
        printf("| LIST PILIHAN SORTING         |\n");
        printf("+------------------------------+\n");
        printf("| 1. BUBBLE SORT NORMAL        |\n");
        printf("| 2. BUBBLE SORT POINTER       |\n");
        printf("+------------------------------+\n");
        printf("| MASUKAN PILIHAN SORTING   : ");
        pilih_jenis = validation2(pilih_jenis);
        printf("+------------------------------+\n");

        if (pilih_jenis == 1 || pilih_jenis == 2){

            printf("\n+------------------------------+\n");
            printf("| DATA AWAL                    |");
            printf("\n+------------------------------+\n");
            random_number(kumpulan, jumlah_data);
            printf("\n+------------------------------+\n");
            printf("| HASIL SORTING                |");
            printf("\n+------------------------------+\n");

            if (pilih_jenis == 1){
                bubble_sort_biasa(kumpulan, jumlah_data);
            } else{
                bubble_sort_pointer(kumpulan, jumlah_data);
            }

            int z;

            for (z = 0; z < jumlah_data; z++){
                printf("%d ", kumpulan[z]);
            }

            int waktu_ticks = clock(); // system process count time
            printf("\n\nWAKTU PROSES = %f DETIK\n", (float)waktu_ticks / CLOCKS_PER_SEC);
        }
    }

    mengulang(ulang);
    system("cls || clear");
    validasimengulang(ulang);
    return 0;
}

int validation(int banyak_data){
    char check;

    if (scanf("%i%c", &banyak_data, &check) != 2 || check != '\n'){
        while ((check = getchar()) != '\n' && check != EOF){
        }; // input buffer

        printf("+------------------------------+\n");
        printf("|  TIDAK SESUAI PILIHAN !\n");
        printf("+------------------------------+\n");
        printf("| MASUKAN ULANG : ");
        return validation(banyak_data);
    } else if (banyak_data < 1 || banyak_data > 3){
        printf("+------------------------------+\n");
        printf("| TIDAK SESUAI PILIHAN !\n");
        printf("+------------------------------+\n");
        printf("| MASUKAN ULANG : ");
        return validation(banyak_data);
        printf("\n===============================================\n");
    } else{
        return banyak_data;
    }
    return 0;
}

int validation2(int pilih_jenis){
    char check;

    if (scanf("%i%c", &pilih_jenis, &check) != 2 || check != '\n'){
        while ((check = getchar()) != '\n' && check != EOF){
        }; // input buffer

        printf("+------------------------------+\n");
        printf("|  TIDAK SESUAI PILIHAN !\n");
        printf("+------------------------------+\n");
        printf("| MASUKAN ULANG : ");
        return validation2(pilih_jenis);
    } else if (pilih_jenis < 1 || pilih_jenis > 2){
        printf("+------------------------------+\n");
        printf("| TIDAK SESUAI PILIHAN !\n");
        printf("+------------------------------+\n");
        printf("| MASUKAN ULANG : ");
        return validation2(pilih_jenis);
        printf("\n===============================================\n");
    } else{
        return pilih_jenis;
    }
    return 0;
}

int bubble_sort_biasa(int kumpulan[], int banyak_data){

    int tukar, j, i;

    for (i = 0; i < banyak_data; i++){
        for (j = 0; j < banyak_data - i - 1; j++){
            if (kumpulan[j] > kumpulan[j + 1]){
                tukar = kumpulan[j];
                kumpulan[j] = kumpulan[j + 1];
                kumpulan[j + 1] = tukar;
            }
        }
    }
    return kumpulan[j];
}

int bubble_sort_pointer(int kumpulan[], int banyak_data){

    int tukar, j, i;
    int *p = kumpulan;

    for (i = 0; i < banyak_data; i++){
        for (j = 0; j < banyak_data - i - 1; j++){
            if (*(p + j) > *(p + (j + 1))){
                tukar = *(p + j);
                *(p + j) = *(p + (j + 1));
                *(p + (j + 1)) = tukar;
            }
        }
    }
    return kumpulan[j];
}

void random_number(int kumpulan[], int banyak_data){

    int angka, i;
    int low = 0, high = 180000;
    srand(time(NULL)); // using time seed to randomize number

    for (i = 0; i < banyak_data; i++){
        angka = (rand() % (high - low + 1)) + low; // using high dan low parameter to limit random number between 0 and 180000
        kumpulan[i] = angka;
        printf("%d ", kumpulan[i]);
    }
}

void mengulang(char ulang[]){

    char check;

    printf("\n\n+------------------------------+\n");
    printf("| MENGULANG PROGRAM ?          |\n");
    printf("+------------------------------+\n");
    printf("| (y/t): ");
    scanf("%s", ulang);
    while ((check = getchar()) != '\n' && check != EOF){
    }; // input buffer

    if (strcmp(ulang, "y") == 0 || strcmp(ulang, "Y") == 0){
        system("cls || clear");
        main();
    } else if (strcmp(ulang, "t") == 0 || strcmp(ulang, "T") == 0){
        selesai();
    } else{
        system("cls || clear");
        mengulang(ulang);
    }
}

void selesai(){
    system("cls || clear");
    printf("+---------------------------------------------+\n");
    printf("| TERIMA KASIH TELAH MENGGUNAKAN PROGRAM KAMI |\n");
    printf("+---------------------------------------------+\n");
}

void validasimengulang(char ulang[]){

    char check;

    printf("\n+---------------------------------------------+\n");
    printf("|       YAKIN INGIN MENGAKHIRI PROGRAM ?      |\n");
    printf("+---------------------------------------------+\n");
    printf("| (y/t): ");
    scanf("%s", ulang);
    while ((check = getchar()) != '\n' && check != EOF){
    }; // input buffer

    if (strcmp(ulang, "y") == 0 || strcmp(ulang, "Y") == 0){
        selesai();
    } else if (strcmp(ulang, "t") == 0 || strcmp(ulang, "T") == 0){
        system("cls || clear");
        main();
    } else{
        system("cls || clear");
        validasimengulang(ulang);
    }
}