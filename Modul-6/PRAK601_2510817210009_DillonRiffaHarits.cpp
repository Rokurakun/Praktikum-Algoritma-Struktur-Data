#include <iostream>
#include <stdlib.h>
#include <time.h>
 
using namespace std;

int random(int bil)
{
    return rand() % bil;
}
 
void randomize()
{
    srand(time(NULL));
}
 
void clrscr()
{
    system("cls");
}
 
void pauseScreen()
{
    cout << "\nTekan Enter untuk kembali ke menu.";
    cin.ignore();
    cin.get();
}

void sequentialSearching()
{
    clrscr();
    cout << "========================================\n";
    cout << "         SEQUENTIAL SEARCHING           \n";
    cout << "========================================\n";
 
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    cout << "Generating 100 number . . .\n";
    for (int i = 0; i < 100; i++)
    {
        data[i] = random(100) + 1;
        cout << data[i] << " ";
    }
    cout << "\nMencari angka: " << cari << "\n\n";

    for (int i = 0; i < 100; i++)
    {
        if (data[i] == cari)
        {
            counter++;
            flag = 1;
            save = i;
        }
    }
 
    if (flag == 1)
    {
        cout << "Data ada sebanyak " << counter << "!\n";
        cout << "pada index ke-" << save << "\n";
    }
    else
    {
        cout << "Data tidak ada!\n";
    }
 
    pauseScreen();
}
 
void binarySearching()
{
    clrscr();
    cout << "========================================\n";
    cout << "          BINARY SEARCHING              \n";
    cout << "========================================\n";
 
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;
 
    cout << "Masukkan jumlah data: ";
    cin >> n;
    int angka[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Angka ke-[" << i << "]: ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
    cout << "--------------------------------------------------------------\n";
    cout << "Data setelah diurutkan:\n";
    for (int i = 0; i < n; i++)
    {
        cout << angka[i] << " ";
    }
    cout << "\n--------------------------------------------------------------\n";
    cout << "Masukkan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if (key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        }
    }
    if (ketemu)
        cout << "Angka " << key << " ditemukan!\n";
    else
        cout << "Angka " << key << " tidak ditemukan!\n";

    pauseScreen();
}
 
void Perbedaan()
{
    clrscr();
    cout << "==========================================\n";
    cout << "   PERBEDAAN SEQUENTIAL & BINARY SEARCH   \n";
    cout << "==========================================\n\n";
 
    cout << "1. SEQUENTIAL SEARCHING\n";
    cout << "   Cara kerja sequential search adalah dengan mencari data secara\n";
    cout << "   berurutan dari depan ke belakang atau dari awal sampai akhir array.\n\n";
 
    cout << "   Kelebihan algoritma ini adalah yang paling mudah diterapkan.\n";
    cout << "   Jika data yang dicari kebetulan terletak di awal susunan,\n";
    cout << "   maka data tersebut akan ditemukan dengan cepat.\n\n";
 
    cout << "   Kekurangannya adalah proses pencarian akan membutuhkan waktu\n";
    cout << "   yang lama jika data yang dicari terletak di urutan paling belakang.\n";
    cout << "   Selain itu, jika jumlah data di dalam array sangat banyak, beban\n";
    cout << "   kerja komputer akan semakin bertambah.\n\n";
 
    cout << "----------------------------------------------------------\n\n";
 
    cout << "2. BINARY SEARCHING\n";
    cout << "   Cara kerja binary search adalah dengan membagi ruang pencarian\n";
    cout << "   menjadi dua secara berulang-ulang. Algoritma akan mencari nilai\n";
    cout << "   di posisi tengah, lalu membandingkannya dengan data yang sedang\n";
    cout << "   dicari. Jika data yang dicari lebih kecil, batas akhir pencarian\n";
    cout << "   digeser menjadi sebelum titik tengah (tengah-1), dan jika lebih\n";
    cout << "   besar, batas awal pencarian digeser menjadi setelah titik tengah.\n";
    cout << "   Proses ini terus berulang sampai data ditemukan atau ruang\n";
    cout << "   pencarian habis.\n\n";
 
    cout << "   Kelebihan dari algoritma ini adalah memiliki kompleksitas\n";
    cout << "   algoritma yang lebih kecil daripada Sequential Search,\n";
    cout << "   sehingga waktu yang dibutuhkan untuk mencari suatu data\n";
    cout << "   jauh lebih cepat dan singkat.\n\n";
 
    cout << "   Kekurangannya adalah data harus sudah terurut terlebih dahulu.\n";
    cout << "   Apabila data mentah belum terurut, maka kita harus melakukan\n";
    cout << "   proses sorting terlebih dahulu sebelum bisa menggunakan metode ini\n";

    pauseScreen();
}
 
int main()
{
    int pilihan;
    do
    {
        clrscr();
        cout << "  Pilih menu:\n";
        cout << "  1. Sequential Searching\n";
        cout << "  2. Binary Searching\n";
        cout << "  3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "  4. Exit\n";
        cout << "  Pilih : ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                sequentialSearching();
                break;
            case 2:
                binarySearching();
                break;
            case 3:
                Perbedaan();
                break;
            case 4:
                clrscr();
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
                cin.ignore();
                cin.get();
                break;
        }
    } while (pilihan != 4);
    return 0;
}