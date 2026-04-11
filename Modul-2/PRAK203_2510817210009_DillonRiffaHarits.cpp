#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 10
using namespace std;

void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();
void RESET();
int PIL, F, R;
char PILIHAN[10], HURUF;
char Q[n];

void Inisialisasi() {
    F = -1;
    R = -1;
}

void RESET() {
    F = -1;
    R = -1;
}

void INSERT() {
    if (R == n - 1) {
        cout << "Antrian Penuh!" << endl;
    } else {
        cout << "Masukin satu huruf: ";
        cin >> HURUF;
        if (F == -1) {
            F = 0;
        }
        R++;
        Q[R] = HURUF;
        cout << "Data '" << HURUF << "' berhasil masuk antrian." << endl;
    }
}

void DELETE() {
    if (F == -1 || F > R) {
        cout << "Antrian Kosong" << endl;
    } else {
        cout << "Data '" << Q[F] << "' keluar dari antrian." << endl;
        F++;
        if (F > R) {
            RESET();
        }
    }
}

void CETAKLAYAR() {
    if (F == -1 || F > R) {
        cout << "Belum ada antrian." << endl;
    } else {
        cout << "Isi antrian dari depan ke belakang: ";
        for (int i = F; i <= R; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

int main ()
{
    Inisialisasi();
    do
    {
        cout << "\nQUEUE" << endl;
        cout << "===========" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL)
        {
        case 1:
            INSERT ();
            break;
        case 2:
            DELETE();
            break;
        case 3:
            CETAKLAYAR ();
            break;
        case 4:
            cout << "TERIMA KASIH" << endl;
            break;
        default:
            cout << "Pilihan tidak valid, masukkan angka 1-4 aja." << endl;
            break;
        }
        
        if (PIL != 4) {
            cout << "press any key to continue" << endl;
            getch();
            system("cls");
        }
    } while (PIL != 4);
    return 0;
}