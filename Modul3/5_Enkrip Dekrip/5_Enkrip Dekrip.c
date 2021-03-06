#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void enkripsi(char input_enkripsi[], int jumlah_pergeseran);
void dekripsi(char input_dekripsi[], int jumlah_pergeseran);
int validation(int pilihan);
int validasi(int jumlah_pergeseran);
void mengulang(char ulang[]);
void validasimengulang(char ulang[]);
void selesai();

int main(){

    char input_enkripsi[100], ulang[10], input_dekripsi[100];
    int jumlah_pergeseran;
    int pilihan;
    int n, j;

    printf("+------------------------------+\n");
    printf("| LIST PILIHAN MENU            |\n");
    printf("+------------------------------+\n");
    printf("| 1. ENKRIPSI                  |\n");
    printf("| 2. DEKRIPSI                  |\n");
    printf("+------------------------------+\n");
    printf("| MASUKAN PILIHAN MENU : ");
    pilihan = validation(pilihan);
    system("cls || clear");

    if (pilihan == 1 || pilihan == 2){
        printf("+---------------------------+\n");
        printf("| MASUKAN JUMLAH PERGESERAN |\n");
        printf("+---------------------------+\n");
        printf("| : ");

        n = validasi(jumlah_pergeseran);

        if (pilihan == 1){
            printf("+------------------------------+\n");
            printf("| MASUKAN PLAINTEXT            |\n");
            printf("+------------------------------+\n");
            printf("| : ");
            scanf(" %[^\n]s", input_enkripsi);

            enkripsi(input_enkripsi, n);

            printf("+------------------------------+\n");
            printf("| HASIL ENKRIPSI               |\n");
            printf("+------------------------------+\n");
            printf("| : %s\n", input_enkripsi);
            printf("+------------------------------+\n");
        } else if (pilihan == 2){
            printf("+------------------------------+\n");
            printf("| MASUKAN CHYPERTEXT           |\n");
            printf("+------------------------------+\n");
            printf("| : ");
            scanf(" %[^\n]s", input_dekripsi);

            dekripsi(input_dekripsi, n);
            printf("+------------------------------+\n");
            printf("| HASIL DEKRIPSI               |\n");
            printf("+------------------------------+\n");
            printf("| : %s\n", input_dekripsi);
            printf("+------------------------------+\n");
        }
    }

    mengulang(ulang);
    system("cls || clear");
    validasimengulang(ulang);
    return 0;
}

void enkripsi(char input_enkripsi[], int jumlah_pergeseran){
    char karakter;

    for (int i = 0; input_enkripsi[i] != '\0'; i++){
        karakter = input_enkripsi[i];
        if (karakter >= 'a' && karakter <= 'z'){
            karakter = karakter + (jumlah_pergeseran % 26);
            if (karakter > 'z'){
                karakter = karakter - 'z' + 'a' - 1;
            }
            input_enkripsi[i] = toupper(karakter);
        } else if (karakter >= 'A' && karakter <= 'Z'){
                karakter = karakter + (jumlah_pergeseran % 26);
                if (karakter > 'Z'){
                    karakter = karakter - 'Z' + 'A' - 1;
                }
                input_enkripsi[i] = tolower(karakter);
            }
        }
    }

void dekripsi(char input_dekripsi[], int jumlah_pergeseran){
    char karakter;

    for (int i = 0; input_dekripsi[i] != '\0'; i++){
        karakter = input_dekripsi[i];
        if (karakter >= 'a' && karakter <= 'z'){
            karakter = karakter - (jumlah_pergeseran % 26);
            if (karakter < 'a'){
                karakter = karakter + 'z' - 'a' + 1;
            }
            input_dekripsi[i] = toupper(karakter);
        } else if (karakter >= 'A' && karakter <= 'Z'){
            karakter = karakter - (jumlah_pergeseran % 26);
            if (karakter < 'A'){
                karakter = karakter + 'Z' - 'A' + 1;
            }
            input_dekripsi[i] = tolower(karakter);
        }
    }
}

int validation(int pilihan){
    char check;

    if (scanf("%i%c", &pilihan, &check) != 2 || check != '\n'){
        while ((check = getchar()) != '\n' && check != EOF){
        }; // input buffer

        printf("+------------------------------+\n");
        printf("|  TIDAK SESUAI PILIHAN !\n");
        printf("+------------------------------+\n");
        printf("| MASUKAN ULANG : ");
        return validation(pilihan);
    } else if (pilihan < 1 || pilihan > 2){
        printf("+------------------------------+\n");
        printf("| TIDAK SESUAI PILIHAN !\n");
        printf("+------------------------------+\n");
        printf("| MASUKAN ULANG : ");
        return validation(pilihan);
        printf("\n===============================================\n");
    } else{
        return pilihan;
    }
    return 0;
}

int validasi(int jumlah_pergeseran){
    char check;

    if (scanf("%i%c", &jumlah_pergeseran, &check) != 2 || check != '\n'){
        while ((check = getchar()) != '\n' && check != EOF){
        }; // input buffer

        printf("+------------------------------+\n");
        printf("| NILAI INPUT TIDAK VALID !\n");
        printf("+------------------------------+\n");
        printf("| MASUKAN ULANG : ");
        return validasi(jumlah_pergeseran);
        printf("+------------------------------+\n");
    } else{
        return jumlah_pergeseran;
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

void selesai(){
    system("cls || clear");
    printf("+---------------------------------------------+\n");
    printf("| TERIMA KASIH TELAH MENGGUNAKAN PROGRAM KAMI |\n");
    printf("+---------------------------------------------+\n");
}