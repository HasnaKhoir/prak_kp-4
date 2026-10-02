#include <stdio.h>
#include <string.h>

#define MAKS_MAHASISWA 5
#define JUMLAH_MK 3

void inputData(char nama[][30], int nilai[][JUMLAH_MK], int jumlah);
float hitungRataRata(int nilai[][JUMLAH_MK], int index);
char tentukanGrade(float rata);
void tampilkanRapor(
    char nama[][30],
    int nilai[][JUMLAH_MK],
    float rataRata[],
    int jumlah);

int nilaiTertinggi(int nilai[][JUMLAH_MK], int jumlah);
int nilaiTerendah(int nilai[][JUMLAH_MK], int jumlah);
int mahasiswaTerbaik(float rataRata[], int jumlah);
int cariMahasiswa(char nama[][30], int jumlah, char cari[]);

int main()
{
    char nama[MAKS_MAHASISWA][30];
    int nilai[MAKS_MAHASISWA][JUMLAH_MK];
    float rataRata[MAKS_MAHASISWA];
    int jumlah, i;
    char cari[30];
    int index;

    printf("=============================================\n");
    printf("            SISTEM RAPOR DIGITAL\n");
    printf("=============================================\n");

    printf("Jumlah mahasiswa (1-%d): ", MAKS_MAHASISWA);
    scanf("%d", &jumlah);

    if (jumlah < 1 || jumlah > MAKS_MAHASISWA)
    {
        printf("Jumlah mahasiswa tidak valid!\n");
        return 0;
    }

    inputData(nama, nilai, jumlah);

    for (i = 0; i < jumlah; i++)
    {
        rataRata[i] = hitungRataRata(nilai, i);
    }

    tampilkanRapor(nama, nilai, rataRata, jumlah);

    printf("\nNilai Tertinggi : %d\n", nilaiTertinggi(nilai, jumlah));
    printf("Nilai Terendah : %d\n", nilaiTerendah(nilai, jumlah));

    i = mahasiswaTerbaik(rataRata, jumlah);
    printf("Mahasiswa Terbaik : %s\n", nama[i]);

    printf("\nMasukkan nama mahasiswa yang dicari : ");
    scanf("%29s", cari);

    index = cariMahasiswa(nama, jumlah, cari);

    if (index != -1) {
        printf("Nama : %s\n", nama[index]);
        printf("Rata-rata : %.2f\n", rataRata[index]);
        printf("Grade : %c\n", tentukanGrade(rataRata[index]));

        if (rataRata[index] >=70) {
            printf("Status : LULUS\n");
        } else {
            printf("Status : TIDAK LULUS\n");
        }
    } else {
        printf("Mahasiswa tidak ditemukan.\n");
    }

    return 0;
}

void inputData(char nama[][30], int nilai[][JUMLAH_MK], int jumlah)
{
    int i, j;

    for (i = 0; i < jumlah; i++)
    {
        printf("\nMahasiswa ke-%d\n", i + 1);

        printf("Nama      : ");
        scanf("%s", nama[i]);

        for (j = 0; j < JUMLAH_MK; j++)
        {
            if (j == 0)
            {
                printf("Nilai Algoritma     : ");
            }
            else if (j == 1)
            {
                printf("Nilai Pemograman    : ");
            }
            else
            {
                printf("Nilai Basis Data    : ");
            }
            scanf("%d", &nilai[i][j]);
        }
    }
}

float hitungRataRata(int nilai[][JUMLAH_MK], int index)
{
    int j, total = 0;

    for (j = 0; j < JUMLAH_MK; j++)
    {
        total += nilai[index][j];
    }

    return (float)total / JUMLAH_MK;
}

char tentukanGrade(float rata)
{
    if (rata >= 90)
    {
        return 'A';
    }
    else if (rata >= 80)
    {
        return 'B';
    }
    else if (rata >= 70)
    {
        return 'C';
    }
    else if (rata >= 60)
    {
        return 'D';
    }
    else
    {
        return 'E';
    }
}

void tampilkanRapor(char nama[][30], int nilai[][JUMLAH_MK], float rataRata[], int jumlah)
{
    int i, j;

    printf("=============================================\n");
    printf("             RAPOR DIGITAL\n");
    printf("=============================================\n");

    printf("%-15s %-8s %-8s %-8s %-12s %-8s %-12s\n",
           "Nama", "Alg", "Prog", "BD", "Rata-rata", "Grade", "Status");

    printf("------------------------------------------\n");

    for (i = 0; i < jumlah; i++)
    {
        printf("%-15s", nama[i]);

        for (j = 0; j < JUMLAH_MK; j++)
        {
            printf("%-8d", nilai   [i][j]);
        }

        printf("%-12.2f%-8c", rataRata[i], tentukanGrade(rataRata[i]));

        if (rataRata[i] >= 70)
        {
            printf("%s", "LULUS");
        }
        else
        {
            printf("%s", "TIDAK LULUS");
        }

        printf("\n");
    }

    printf("==========================================================================================\n");
}

int nilaiTertinggi(int nilai[][JUMLAH_MK], int jumlah)
{
    int tertinggi = nilai[0][0];
    for (int i = 0; i < jumlah; i++)
    {
        for (int j = 0; j < JUMLAH_MK; j++)
        {
            if (tertinggi < nilai[i][j])
            {
                tertinggi = nilai[i][j];
            }
        }
    }
    return tertinggi;
}

int nilaiTerendah(int nilai[][JUMLAH_MK], int jumlah)
{
    int i, j;
    int terendah = nilai[0][0];
    for (i = 0; i < jumlah; i++)
    {
        for (j = 0; j < JUMLAH_MK; j++)
        {
            if (nilai[i][j] < terendah) 
            {
                terendah = nilai[i][j];
            }
        }
    }
    return terendah;
}

int mahasiswaTerbaik(float rataRata[], int jumlah)
{
    int i;
    int terbaik = 0;
    for (i = 1; i < jumlah; i++)
    {
        if (rataRata[i] > rataRata[terbaik])
        {
            terbaik = i;
        }
    }
    return terbaik;
}

int cariMahasiswa(char nama[][30], int jumlah, char cari[])
{
    int i;
    for (i = 0; i < jumlah; i++)
    {
        if (strcmp(nama[i], cari) == 0)
        {
            return i; 
        }
    }
    return -1;
}