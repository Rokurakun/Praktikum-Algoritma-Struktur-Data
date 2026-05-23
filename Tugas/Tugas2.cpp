#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
} TNode;

TNode *head, *tail;

int pil, menu;
char pilihan[10];

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main()
{
menu:
    cout<<"Double Linked List Non Circular (DLLNC)"<<endl;
    cout<<"=============================="<<endl;
    cout<<"Silahkan pilih program DLLNC yang ingin dijalankan!"<<endl;
    cout<<"1. DLLNC dengan Head"<<endl;
    cout<<"2. DLLNC dengan Head dan Tail"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Pilihan : ";
    cin>>menu;
    system("cls");
    if(menu==1){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head)"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Berdasarkan Target"<<endl;
            cout<<"7. Clear"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil) {
                case 1: tambahDepanH(); break;
                case 2: tambahBelakangH(); break;
                case 3: tampilkanH(); break;
                case 4: hapusDepanH(); break;
                case 5: hapusBelakangH(); break;
                case 6: hapusTargetH(); break;
                case 7: clearH(); break;
                case 8: system("cls"); goto menu;
                default: cout<<"Pilihan tidak tersedia."<<endl; break;
            }
            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");

        } while (pil!=8);
    } else if(menu==2){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head dan Tail)"<<endl;
            cout<<"------------------------------------------------------"<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Berdasarkan Target"<<endl;
            cout<<"7. Clear"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil) {
                case 1: tambahDepanHT(); break;
                case 2: tambahBelakangHT(); break;
                case 3: tampilkanHT(); break;
                case 4: hapusDepanHT(); break;
                case 5: hapusBelakangHT(); break;
                case 6: hapusTargetHT(); break;
                case 7: clearHT(); break;
                case 8: system("cls"); goto menu;
                default: cout<<"Pilihan tidak tersedia."<<endl; break;
            }
            cout<<"\nPress any key to continue"<<endl;
            getch();
            system("cls");
        } while (pil!=8);
    }
    cout<<"\nTERIMA KASIH"<<endl;
    cout<<"Program was made by Dillon Riffa Harits (2510817210009)."<<endl;
}

void initH()  { head = NULL; }
void initHT() { head = NULL; tail = NULL; }
int isEmptyH()  { return head == NULL ? 1 : 0; }
int isEmptyHT() { return tail == NULL ? 1 : 0; }

void tambahDepanH() {
    string input, arr[100];
    int count = 0;
    cout<<"Masukkan data: ";
    getline(cin >> ws, input);
    stringstream ss(input);
    while(ss >> arr[count]) { count++; }

    for(int i = count - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyH() == 1) {
            head = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout<<"Semua data berhasil dimasukkan di bagian depan.";
}

void tambahDepanHT() {
    string input, arr[100];
    int count = 0;
    cout<<"Masukkan data: ";
    getline(cin >> ws, input);
    stringstream ss(input);
    while(ss >> arr[count]) { count++; }

    for(int i = count - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout<<"Semua data berhasil dimasukkan di bagian depan.";
}

void tambahBelakangH() {
    string input, arr[100];
    int count = 0;
    cout<<"Masukkan data: ";
    getline(cin >> ws, input);
    stringstream ss(input);
    while(ss >> arr[count]) { count++; }

    for(int i = 0; i < count; i++) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyH() == 1) {
            head = baru;
        } else {
            TNode *bantu = head;
            while(bantu->next != NULL) { bantu = bantu->next; }
            bantu->next = baru;
            baru->prev = bantu;
        }
    }
    cout<<"Semua data berhasil dimasukkan di bagian belakang.";
}

void tambahBelakangHT() {
    string input, arr[100];
    int count = 0;
    cout<<"Masukkan data: ";
    getline(cin >> ws, input);
    stringstream ss(input);
    while(ss >> arr[count]) { count++; }

    for(int i = 0; i < count; i++) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }
    cout<<"Semua data berhasil dimasukkan di bagian belakang.";
}

void tampilkanH() {
    TNode *bantu = head;
    if(isEmptyH() == 0) {
        while(bantu != NULL) {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List.";
}

void tampilkanHT() {
    TNode *bantu = head;
    if(isEmptyHT() == 0) {
        while(bantu != NULL) {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List.";
}

void hapusDepanH() {
    if(isEmptyH() == 0) {
        TNode *hapus = head;
        string data = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List.";
}

void hapusDepanHT() {
    if(isEmptyHT() == 0) {
        TNode *hapus = head;
        string data = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List.";
}

void hapusBelakangH() {
    if(isEmptyH() == 0) {
        int n, count = 0;
        TNode *bantu = head;
        while(bantu != NULL) { count++; bantu = bantu->next; }

        cout<<"Masukkan N (hapus node ke-N dari belakang): ";
        cin>>n;

        if(n > count) {
            n = ((n - 1) % count) + 1;
            cout<<"(N disesuaikan menjadi "<<n<<")"<<endl;
        }

        int posisi = count - n + 1;
        TNode *hapus = head;
        for(int i = 1; i < posisi; i++) { hapus = hapus->next; }

        string data = hapus->data;
        if(hapus == head) {
            if(head->next != NULL) { head = head->next; head->prev = NULL; }
            else { initH(); }
        } else if(hapus->next == NULL) {
            hapus->prev->next = NULL;
        } else {
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
        }
        delete hapus;
        cout<<"Node ke-"<<n<<" dari belakang (data: \""<<data<<"\") berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List.";
}

void hapusBelakangHT() {
    if(isEmptyHT() == 0) {
        int n, count = 0;
        TNode *bantu = head;
        while(bantu != NULL) { count++; bantu = bantu->next; }

        cout<<"Masukkan N (hapus node ke-N dari belakang): ";
        cin>>n;

        if(n > count) {
            n = ((n - 1) % count) + 1;
            cout<<"(N disesuaikan menjadi "<<n<<")"<<endl;
        }

        int posisi = count - n + 1;
        TNode *hapus = head;
        for(int i = 1; i < posisi; i++) { hapus = hapus->next; }

        string data = hapus->data;
        if(hapus == head) {
            if(head->next != NULL) { head = head->next; head->prev = NULL; }
            else { initHT(); }
        } else if(hapus == tail) {
            if(tail->prev != NULL) { tail = tail->prev; tail->next = NULL; }
            else { initHT(); }
        } else {
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
        }
        delete hapus;
        cout<<"Node ke-"<<n<<" dari belakang (data: \""<<data<<"\") berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List.";
}

void hapusTargetH() {
    if(isEmptyH() == 1) { cout<<"Tidak terdapat data pada Linked List."; return; }
    string target;
    cout<<"Masukkan data target yang ingin dihapus: ";
    cin>>target;

    TNode *bantu = head;
    bool ketemu = false;
    while(bantu != NULL) {
        TNode *nextBantu = bantu->next;
        if(bantu->data == target) {
            ketemu = true;
            if(bantu == head) {
                if(head->next != NULL) { head = head->next; head->prev = NULL; }
                else { initH(); }
            } else if(bantu->next == NULL) {
                bantu->prev->next = NULL;
            } else {
                bantu->prev->next = bantu->next;
                bantu->next->prev = bantu->prev;
            }
            delete bantu;
        }
        bantu = nextBantu;
    }
    if(!ketemu) cout<<"Data \""<<target<<"\" tidak ditemukan dalam Linked List.";
    else cout<<"Semua data \""<<target<<"\" berhasil dihapus.";
}

void hapusTargetHT() {
    if(isEmptyHT() == 1) { cout<<"Tidak terdapat data pada Linked List."; return; }
    string target;
    cout<<"Masukkan data target yang ingin dihapus: ";
    cin>>target;

    TNode *bantu = head;
    bool ketemu = false;
    while(bantu != NULL) {
        TNode *nextBantu = bantu->next;
        if(bantu->data == target) {
            ketemu = true;
            if(bantu == head) {
                if(head->next != NULL) { head = head->next; head->prev = NULL; }
                else { initHT(); }
            } else if(bantu == tail) {
                if(tail->prev != NULL) { tail = tail->prev; tail->next = NULL; }
                else { initHT(); }
            } else {
                bantu->prev->next = bantu->next;
                bantu->next->prev = bantu->prev;
            }
            delete bantu;
        }
        bantu = nextBantu;
    }
    if(!ketemu) cout<<"Data \""<<target<<"\" tidak ditemukan dalam Linked List.";
    else cout<<"Semua data \""<<target<<"\" berhasil dihapus.";
}

void clearH() {
    if(isEmptyH() == 1) { cout<<"Tidak terdapat data pada Linked List."; return; }
    int urut = 1;
    bool dariDepan = true;
    while(head != NULL) {
        TNode *hapus;
        if(dariDepan) {
            hapus = head;
            cout<<urut<<". Hapus depan    : \""<<hapus->data<<"\""<<endl;
            if(head->next != NULL) { head = head->next; head->prev = NULL; }
            else { initH(); }
            delete hapus;
        } else {
            hapus = head;
            while(hapus->next != NULL) { hapus = hapus->next; }
            cout<<urut<<". Hapus belakang : \""<<hapus->data<<"\""<<endl;
            if(hapus->prev != NULL) { hapus->prev->next = NULL; }
            else { initH(); }
            delete hapus;
        }
        urut++;
        dariDepan = !dariDepan;
    }
    cout<<"Seluruh data pada Linked List telah dibersihkan.";
}

void clearHT() {
    if(isEmptyHT() == 1) { cout<<"Tidak terdapat data pada Linked List."; return; }
    int urut = 1;
    bool dariDepan = true;
    while(head != NULL) {
        TNode *hapus;
        if(dariDepan) {
            hapus = head;
            cout<<urut<<". Hapus depan    : \""<<hapus->data<<"\""<<endl;
            if(head != tail) { head = head->next; head->prev = NULL; }
            else { initHT(); }
            delete hapus;
        } else {
            hapus = tail;
            cout<<urut<<". Hapus belakang : \""<<hapus->data<<"\""<<endl;
            if(tail != head) { tail = tail->prev; tail->next = NULL; }
            else { initHT(); }
            delete hapus;
        }
        urut++;
        dariDepan = !dariDepan;
    }
    cout<<"Seluruh data pada Linked List telah dibersihkan.";
}