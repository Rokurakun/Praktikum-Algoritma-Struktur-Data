#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define max 5 
using namespace std;

struct Stack {
    int atas;
    int data[max];
} Tumpuk;

void inisialisasi() {
    Tumpuk.atas = -1;
}

int kosong() {
    if (Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

int penuh() {
    if(Tumpuk.atas == max-1)
        return 1;
    else
        return 0;
}

void input() {
    if (penuh() == 0) {
        int data_baru;
        cout << "Masukkan angka untuk ditumpuk: ";
        cin >> data_baru;
        
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data_baru;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " berhasil masuk ke Stack.\n";
    } else {
        cout << "Tumpukan Penuh!\n";
    }
}

void hapus() {
    if(kosong() == 0) {
        cout << "Data Teratas " << Tumpuk.data[Tumpuk.atas] << " Sudah Terambil.\n";
        Tumpuk.atas--;
    } else {
        cout << "Data masih kosong.\n";
    }
}

void tampil() {
    if (kosong() == 0) {
        cout << "Isi tumpukan dari atas ke bawah:\n";
        for(int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = " << Tumpuk.data[i] << "\n";
        }
    } else {
        cout << "Tumpukan Kosong.\n";
    }
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan berhasil dibersihkan\n";
}

int main() {
    int PIL;
    char PILIHAN[10];
    
    inisialisasi(); 
    do {
        cout << "\nSTACK" << endl;
        cout << "=====================" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. CETAK STACK" << endl;
        cout << "4. BERSIHKAN STACK" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : "; 
        cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL) {
            case 1:
                input();
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
            case 5:
                cout << "TERIMA KASIH" << endl;
                break;
            default:
                cout << "Pilihan tidak valid, masukkan angka 1-5 aja." << endl;
                break;
        }
        
        if (PIL != 5) {
            cout << "press any key to continue" << endl;
            getch();
            system("cls");
        }
    } while (PIL != 5);
    return 0;
}