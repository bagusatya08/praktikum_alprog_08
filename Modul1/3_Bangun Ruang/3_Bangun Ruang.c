#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX 80   /* maximum data buffer     */
#define DIGIT 1  /* data akan dibaca sebagai digit   */
#define ALPHA 2  /* data akan dibaca sebagai alphabet */
#define STRING 3 /* data akan dibaca sebagai ascii */

void ending();
void invalidinputs();
void Tabung();
void Bola();
void Limas_segiempat();
void Prisma_segitiga();
void Kerucut();
int validasiInt(int choice);

int main()
{
    int choice;
    printf("pilihlah salah satu bangun ruang berikut, hanya bisa menggunakan angka\n");
    printf("1.  Tabung\n");
    printf("2.  Bola\n");
    printf("3.  Limas_segiempat\n");
    printf("4.  Prisma_segitiga\n");
    printf("5.  Kerucut\n");
    printf("Masukan Pilihan Anda: ");
    choice = validasiInt(choice);
    if (choice == 1)
    {
        Tabung();
    }
    else if (choice == 2)
    {
        Bola();
    }
    else if (choice == 3)
    {
        Limas_segiempat();
    }
    else if (choice == 4)
    {
        Prisma_segitiga();
    }
    else if (choice == 5)
    {
        Kerucut();
    }
    else
    {
        invalidinputs();
    }
    printf("__________________________________________\n\n");
    ending();
    return 0;
}
int readinput(char buff[], int mode, int limit)
{
    int ch, index = 0;
    ch = getchar();
    while ((ch != '\n') && (index < limit))
    {
        switch (mode)
        {
        case DIGIT: // untuk memvalidasi jika input adalah digit
            if (isdigit(ch))
            {
                buff[index] = ch;
                index++;
            }
            break;
        case ALPHA: // untuk memvalidasi jika input adalah karakter
            if (isalpha(ch))
            {
                buff[index] = ch;
                index++;
            }
            break;
        case STRING: // untuk memvalidasi jika input adalah string
            if (isascii(ch))
            {
                buff[index] = ch;
                index++;
            }
            break;
        default:
            /*  */
            break;
        }
        ch = getchar();
    }
    buff[index] = 0x00; /* null terminate input */
    return index;
}

void ending()
{
    int choice2;
    
    printf("Program Selesai\n");
    printf("\n+-----------------------------------------------------------------------------+");
    printf("\n               TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI!               ");
    printf("\n+-----------------------------------------------------------------------------+\n");
    printf("Ketik 1 Untuk Melanjutkan\n");
    printf("Ketik 2 Untuk Keluar\n");
    scanf("%d", &choice2);
    choice2 = validasiInt(choice2);
    
    if (choice2 == 1)
    {
    	system("cls || clear");
        main();
    }
    else if (choice2 == 2)
    {
        printf("Terima kasih telah menggunakan program ini\n");
    }
    else
    {
        printf("\nInvalid Input\n");
    }
}

void invalidinputs()
{
    system("cls || clear");
    printf("__________________________________________\n");
    printf("input yang anda masukan salah\n");
    printf("__________________________________________\n");
    main();
}

void Tabung()
{
    float volume, luas, jari = 0, tinggi = 0;
    float number;
    char buffer[MAX];
    system("cls || clear");
    printf("Anda telah memilih Tabung \n");

    while (jari == 0)
    {
        printf("Masukan ukuran jari - jari tabung : ");
        scanf("%f", &jari);
        number = readinput(buffer, DIGIT, MAX);
        if (number != 0)
        {
            number = atoi(buffer);
        }
    }
    while (tinggi == 0)
    {
        printf("Masukan ukuran tinggi tabung : ");
        scanf("%f", &tinggi);
        number = readinput(buffer, DIGIT, MAX);
        if (number != 0)
        {
            number = atoi(buffer);
        }
    }
    volume = jari * jari * tinggi * 3.14;
    luas = 2 * jari * (jari * tinggi) * 3.14;
    printf("__________________________________________\n");
    printf("Volume tabung adalah %.0f m3\n", volume);
    printf("luas tabung adalah %.0f cm\n", luas);
}
void Bola()
{
    float volume, luas, jari = 0;
    float number;
    char buffer[MAX];
    system("cls || clear");
    printf("Anda telah memilih bola\n");

    while (jari == 0)
    {
        printf("Masukan ukuran jari - jari bola : ");
        scanf("%f", &jari);
        number = readinput(buffer, DIGIT, MAX);
        if (number != 0)
        {
            number = atoi(buffer);
        }
    }
    volume = 4 / 3 * 3.14 * (jari * jari * jari);
    luas = 4 * 3.14 * (jari * jari);
    printf("__________________________________________\n");
    printf("Volume bola adalah %.0f m3\n", volume);
    printf("luas bola adalah %.3f cm\n", luas);
}
void Limas_segiempat()
{
    float volume, luas, sisi = 0, tinggi = 0;
    float number;
    system("cls || clear");
    char buffer[MAX];
    printf("Anda telah memilih Limas segiempat\n");

    while (sisi == 0)
    {
        printf("Masukan Panjang sisi alas: : ");
        scanf("%f", &sisi);
        number = readinput(buffer, DIGIT, MAX);
        if (number != 0)
        {
            number = atoi(buffer);
        }
    }
    while (tinggi == 0)
    {
        printf("Masukan tinggi : ");
        scanf("%f", &tinggi);
        number = readinput(buffer, DIGIT, MAX);
        if (number != 0)
        {
            number = atoi(buffer);
        }
    }
    volume = (sisi * sisi * tinggi) * 1 / 3;
    luas = 4 * 1 / 2 * sisi * tinggi + (sisi * sisi);
    printf("__________________________________________\n");
    printf("Volume limas segiempat adalah %.0f m3\n", volume);
    printf("luas limas segiempat adalah %.0f cm\n", luas);
}

void Prisma_segitiga()
{
    float volume, luas, sisi = 0, tinggi = 0, tinggi_prisma = 0;
    float number;
    char buffer[MAX];
    system("cls || clear");
    printf("Anda telah memilih prisma segitiga\n");

    while (sisi == 0)
    {
        printf("Masukan panjang sisi alas : ");
        scanf("%f", &sisi);
        number = readinput(buffer, DIGIT, MAX);
        if (number != 0)
        {
            number = atoi(buffer);
        }
    }
    while (tinggi == 0)
    {
        printf("Masukan tinggi : ");
        scanf("%f", &tinggi);
        number = readinput(buffer, DIGIT, MAX);
        if (number != 0)
        {
            number = atoi(buffer);
        }
    }
    while (tinggi_prisma == 0)
    {
        printf("Masukan tinggi prisma : ");
        scanf("%f", &tinggi_prisma);
        number = readinput(buffer, DIGIT, MAX);
        if (number != 0)
        {
            number = atoi(buffer);
        }
    }
    volume = (sisi * tinggi * 1 / 2) * tinggi_prisma;
    luas = 2 * (sisi * tinggi / 2) + 3 * (tinggi_prisma * sisi);
    printf("__________________________________________\n");
    printf("Volume prisma segitiga adalah %.0f m3\n", volume);
    printf("Luas prisma segitiga adalah %.0f cm\n", luas);
}
void Kerucut()
{
    float volume, luas, jari = 0, tinggi = 0;
    float number;
    char buffer[MAX];
    system("cls || clear");
    printf("Anda telah memilih Kerucut\n");

    while (jari == 0)
    {
        printf("Masukan ukuran jari-jari kerucut : ");
        scanf("%f", &jari);
        number = readinput(buffer, DIGIT, MAX);
        if (number != 0)
        {
            number = atoi(buffer);
        }
    }
    while (tinggi == 0)
    {
        printf("Masukan tinggi : ");
        scanf("%f", &tinggi);
        number = readinput(buffer, DIGIT, MAX);
        if (number != 0)
        {
            number = atoi(buffer);
        }
    }
    volume = jari * jari * tinggi * 1 / 3 * 3.14;
    luas = 3.14 * jari * (jari + sqrt(tinggi * tinggi + jari * jari));
    printf("__________________________________________\n");
    printf("Volume kerucut adalah %.0f m3\n", volume);
    printf("Luas kerucut adalah %.2f cm\n", luas);
}

int validasiInt(int choice)
{
    char check;
    if (scanf("%d%c", &choice, &check) != 2 || check != '\n')
    {
        while ((check = getchar()) != '\n' && check != EOF)
        {
        }; // input buffer
        printf("__________________________________________\n");
        printf("input yang anda masukan salah\n");
        printf("__________________________________________\n");
        printf("masukan ulang pilihan anda : ");
        return validasiInt(choice);
        printf("__________________________________________\n");
    }
    else if (choice < 1 && choice > 5)
    {
        system("cls || clear");
        printf("__________________________________________\n");
        printf("input yang anda masukan salah\n");
        printf("__________________________________________\n");
        printf("masukan ulang : ");
        return validasiInt(choice);
        printf("__________________________________________\n");
    }
    else
    {
        return choice;
    }
    return 0;
}
