#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[256];
typedef struct
{
    string nama;
    string NIM;
} mahasiswa;

void input_data_mhs(mahasiswa mhs);
void tampilkan_data_mhs(mahasiswa mhs);
int validation2();
int validation3(mahasiswa mhs);
void mengulang(mahasiswa mhs);

int main()
{
    mahasiswa mhs;
    char update;
    int opsi;
    printf("\n+------------------------------+\n");
    printf("|         PILIHAN MENU         |\n");
    printf("+------------------------------+\n");
    printf("| 1. INPUT DATA");
    printf("\n| 2. MENCARI DATA");
    printf("\n| 3. KELUAR");
    printf("\n+------------------------------+");
    printf("\n| MASUKAN PILIHAN   : ");

    opsi = validation2();

    if (opsi == 1)
    {
        input_data_mhs(mhs);
    }
    else if (opsi == 2)
    {
        tampilkan_data_mhs(mhs);
    }
    else if (opsi == 3)
    {
        exit(0);
    }

    return 0;
}

void input_data_mhs(mahasiswa mhs)
{
    int pengulangan;
    char kode, y, n;
    pengulangan = 0;
    
        string induk, name;
        printf("\n+------------------------------+");
        printf("\n| MASUKKAN DATA MAHASISWA\n");
        printf("+------------------------------+");
        printf("\n| MASUKAN NIM    : ");
        scanf("%s", mhs.NIM);
        fflush(stdin);
        printf("\n| MASUKAN NAMA   : ");
        scanf("%[^\n]s", mhs.nama);
        fflush(stdin);
        FILE *out = fopen("database.txt", "r");
        if (!out)
        {
            printf("\n| DATABASE TIDAK TERSEDIA");
        }
        else
        {
            while (!feof(out))
            {
                fscanf(out, "%s # %[^\n]s #\n", induk, name);
            }
            fclose(out);
        }

        if (strcmp(mhs.NIM, induk) == 0)
        {
            printf("\n| DATA TELAH ADA");
        }
        else
        {
            FILE *in = fopen("database.txt", "a");
            fprintf(in, "%s # %s #\n", mhs.NIM, mhs.nama);
            fclose(in);
        }

        validation3(mhs);
}

void tampilkan_data_mhs(mahasiswa mhs)
{
    int pengulangan;
    char kode, y, n;

    string data;
    printf("\n| MASUKAN NIM MAHASISWA YANG DICARI : ");
    scanf("%s", data);
    fflush(stdin);
    FILE *in = fopen("database.txt", "r");
    if (!in)
    {
        printf("\n DATA TIDAK TERDAPAT\n");
    }
    else
    {
        while (!feof(in))
        {
            fflush(stdin);
            fscanf(in, "%s # %[^\n]s #\n", mhs.NIM, mhs.nama);
            if (strcmp(mhs.NIM, data) == 0)
            {
                printf("\n| DATA MAHASISWA\n");
                printf("| NIM       : %s\n", mhs.NIM);
                printf("| Nama      : %s\n", mhs.nama);
            }

        }
    }

    fclose(in);
    mengulang(mhs);
}

int validation2()
{
    int pilih_jenis;
    char check;

    if (scanf("%i%c", &pilih_jenis, &check) != 2 || check != '\n')
    {
        while ((check = getchar()) != '\n' && check != EOF)
        {
        }; // input buffer

        printf("+------------------------------+\n");
        printf("|  TIDAK SESUAI PILIHAN !\n");
        printf("+------------------------------+\n");
        printf("| MASUKAN ULANG : ");
        return validation2();
    }
    else if (pilih_jenis < 1 || pilih_jenis > 3)
    {
        printf("+------------------------------+\n");
        printf("| TIDAK SESUAI PILIHAN !\n");
        printf("+------------------------------+\n");
        printf("| MASUKAN ULANG : ");
        return validation2();
        printf("\n===============================================\n");
    }
    else
    {
        return pilih_jenis;
    }
    return 0;
}

int validation3(mahasiswa mhs){

    char ulang[10];
    char check;

    printf("+------------------------------+\n");
    printf("\n| KEMBALI MENGINPUT DATA (y/t):");
    scanf("%s", ulang);
    while ((check = getchar()) != '\n' && check != EOF)
    {
    }; // input buffer
    
    if (strcmp(ulang, "y") == 0 || strcmp(ulang, "Y") == 0)
    {
        input_data_mhs(mhs);
    }
    else if (strcmp(ulang, "t") == 0 || strcmp(ulang, "T") == 0)
    {
        system("cls || clear");
        main();
    }
    else
    {
        
        validation3(mhs);
    }
    return 0;
}

void mengulang(mahasiswa mhs)
{

    char ulang[10];
    char check;

    printf("\n| KEMBALI MENCARI DATA (y/t):");
    scanf("%s", ulang);
    while ((check = getchar()) != '\n' && check != EOF)
    {
    }; // input buffer

    if (strcmp(ulang, "y") == 0 || strcmp(ulang, "Y") == 0)
    {
        tampilkan_data_mhs(mhs);
    }
    else if (strcmp(ulang, "t") == 0 || strcmp(ulang, "T") == 0)
    {
        system("cls || clear");
        main();
    }
    else
    {
        system("cls || clear");
        mengulang(mhs);
    }
}