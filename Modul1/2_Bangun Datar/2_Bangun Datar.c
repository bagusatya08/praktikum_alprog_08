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
void Segitiga_sembarang();
void Belah_Ketupat();
void Jajar_genjang();
void Trapesium();
void Lingkaran();
int  validasiInt(int choice);

int main()
{
    int choice;
    printf("pilihlah salah satu bangun ruang berikut\n");
    printf("1.  Segitiga sembarang\n");
    printf("2.  Belah Ketupat\n");
    printf("3.  Jajar genjang\n");
    printf("4.  Trapesium\n");
    printf("5.  Lingkaran\n");
    printf("Masukan Pilihan Anda: ");
    choice = validasiInt(choice);

    if (choice == 1)
    {
        Segitiga_sembarang();
    }
    else if (choice == 2)
    {
        Belah_Ketupat();
    }
    else if (choice == 3)
    {
        Jajar_genjang();
    }
    else if (choice == 4)
    {
        Trapesium();
    }
    else if (choice == 5)
    {
        Lingkaran();
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

void Segitiga_sembarang()
{
    float a = 0, b = 0, c = 0, keliling, luas, invalidinputs;
    float jari, number;
    char buffer[MAX];
    system("cls || clear");
    printf("Anda telah memilih Segitiga sembarang \n");

    while (a == 0)
    {
        printf("Masukan ukuran sisi A Segitiga sembarang :  ");
        scanf("%f", &a);
        number = readinput(buffer, DIGIT, MAX);
        if (number != 0)
        {
            number = atoi(buffer);
        }
    }

    while (b == 0)
    {
        printf("Masukan ukuran sisi B Segitiga sembarang : ");
        scanf("%f", &b);
        number = readinput(buffer, DIGIT, MAX);
        if (b != 0)
        {
            number = atoi(buffer);
        }
    }
    
    while (c == 0)
    {
        printf("Masukan ukuran sisi C Segitiga sembarang : ");
        scanf("%f", &c);
        number = readinput(buffer, DIGIT, MAX);
        if (c != 0)
        {
            number = atoi(buffer);
        }
    }
    keliling = a + b + c;
    luas = (a + b + c) / 2;
    printf("__________________________________________\n");
    printf("keliling Segitiga sembarang adalah %.0f cm\n", keliling);
    printf("luas Segitiga sembarang adalah %.0f cm\n", luas);
}

void Belah_Ketupat()
{
    float keliling, luas, sisi = 0, d1 = 0, d2 = 0, number;
    char buffer[MAX];
    system("cls || clear");
    printf("Anda telah memilih Belah Ketupat\n");

    while (sisi == 0)
    {
    	system("cls || clear");
        printf("Masukan panjang sisi  untuk mencari keliling : ");
        scanf("%f", &sisi);
        number = readinput(buffer, DIGIT, MAX);
        if (sisi != 0)
        {
            number = atoi(buffer);
        }
    }

    while (d1 == 0)
    {
        printf("Masukan panjang sisi d1 untuk mencari luas : ");
        scanf("%f", &d1);
        number = readinput(buffer, DIGIT, MAX);
        if (d1 != 0)
        {
            number = atoi(buffer);
        }
    }

    while (d2 == 0)
    {
        printf("Masukan panjang sisi d2 untuk mencari luas : ");
        scanf("%f", &d2);
        number = readinput(buffer, DIGIT, MAX);
        if (d2 != 0)
        {
            number = atoi(buffer);
        }
    }

    keliling = 4 * sisi;
    luas = (d1 * d2) * 2;
    printf("__________________________________________\n");
    printf("keliling Belah Ketupat adalah %.0f cm\n", keliling);
    printf("luas Belah Ketupat adalah %.0f cm\n", luas);
    printf("__________________________________________\n");
    ending();
}

void Jajar_genjang()
{
    float keliling, luas, tinggi = 0, a = 0, b = 0, number;
    float jari;
    char buffer[MAX];
    system("cls || clear");
    printf("Anda telah memilih Jajar genjang\n");

    while (a == 0)
    {
        printf("Masukan panjang sisi A untuk mencari luas : ");
        scanf("%f", &a);
        number = readinput(buffer, DIGIT, MAX);
        if (a != 0)
        {
            number = atoi(buffer);
        }
    }

    while (b == 0)
    {
        printf("Masukan panjang sisi B untuk mencari luas : ");
        scanf("%f", &b);
        number = readinput(buffer, DIGIT, MAX);
        if (b != 0)
        {
            number = atoi(buffer);
        }
    }

    while (tinggi == 0)
    {
        printf("Masukan tinggi untuk mencari luas : ");
        scanf("%f", &tinggi);
        number = readinput(buffer, DIGIT, MAX);
        if (tinggi != 0)
        {
            number = atoi(buffer);
        }
    }

    keliling = (2 * a) + (2 * b);
    luas = a * tinggi;
    printf("__________________________________________\n");
    printf("Keliling Jajar genjang adalah %.0f cm\n", keliling);
    printf("luas Jajar genjang adalah %.0f cm \n", luas);
    printf("__________________________________________\n");
}

void Trapesium()
{
    float keliling, luas, a = 0, b = 0, c = 0, d = 0, number;
    float jari;
    char buffer[MAX];
    system("cls || clear");
    printf("Anda telah memilih Trapesium\n");

    while (a == 0)
    {
        printf("Masukan ukuran sisi A trapesium : ");
        scanf("%f", &a);
        number = readinput(buffer, DIGIT, MAX);
        if (a != 0)
        {
            number = atoi(buffer);
        }
    }

    while (b == 0)
    {
        printf("Masukan ukuran sisi B trapesium : ");
        scanf("%f", &b);
        number = readinput(buffer, DIGIT, MAX);
        if (b != 0)
        {
            number = atoi(buffer);
        }
    }

    while (c == 0)
    {
        printf("Masukan ukuran sisi C trapesium : ");
        scanf("%f", &c);
        number = readinput(buffer, DIGIT, MAX);
        if (c != 0)
        {
            number = atoi(buffer);
        }
    }

    while (d == 0)
    {
        printf("Masukan ukuran sisi D trapesium : ");
        scanf("%f", &d);
        number = readinput(buffer, DIGIT, MAX);
        if (d != 0)
        {
            number = atoi(buffer);
        }
    }
    keliling = a + b + c + d;
    luas = (a + c) * 1 / 2 * b;
    printf("__________________________________________\n");
    printf("keliling trapesium adalah %.0f cm\n", keliling);
    printf("Luas trapesium adalah %.0f cm\n", luas);
    printf("__________________________________________\n");
}

void Lingkaran()
{
    float keliling, luas, number;
    float jari = 0;
    char buffer[MAX];
    system("cls || clear");
    printf("Anda telah memilih Lingkaran\n");

    while (jari == 0)
    {
        printf("Masukan ukuran jari-jari trapesium : ");
        scanf("%f", &jari);
        number = readinput(buffer, DIGIT, MAX);
        if (jari != 0)
        {
            number = atoi(buffer);
        }
    }
    keliling = 2 * jari * 3.14;
    luas = jari * jari * 3.14;
    printf("__________________________________________\n");
    printf("keliling lingkaran adalah %.0f cm\n", keliling);
    printf("Luas lingkaran adalah %.0f cm\n", luas);
    printf("__________________________________________\n");
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
        printf("masukan ulang pilihanan anda : ");
        return validasiInt(choice);
        printf("__________________________________________\n");
    }
    else if (choice < 1 && choice > 5)
    {
        system("cls || clear");
        printf("__________________________________________\n");
        printf("input yang anda masukan salah\n");
        printf("__________________________________________\n");
        printf("masukan ulang  : ");
        return validasiInt(choice);
        printf("__________________________________________\n");
    }
    else
    {
        return choice;
    }
    return 0;
}
