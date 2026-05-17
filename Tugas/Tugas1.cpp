#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

typedef struct TNode{
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[2];
string dataBaru, dataHapus;

void init();
int isEmpty();
int hitungNode();

void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main()
{
    do {
        cout<<"Single Linked List Circular (SLLC)"<<endl;
        cout<<"=================================="<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan Data"<<endl;
        cout<<"6. Hapus Semua Elemen (Reset)"<<endl;
        cout<<"7. Cari Data"<<endl;
        cout<<"8. Hapus Setiap Data Tertentu"<<endl;
        cout<<"9. Sisipkan Node/Data Baru Sebelum Data Tertentu"<<endl;
        cout<<"10. Sisipkan Node/Data Baru Setelah Data Tertentu"<<endl;
        cout<<"11. Quit"<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        pil=atoi(pilihan);

        switch(pil) {
        case 1:
            tambahDepan();
            break;
        case 2:
            tambahBelakang();
            break;
        case 3:
            hapusDepan();
            break;
        case 4:
            hapusBelakang();
            break;
        case 5:
            tampilkan();
            break;
        case 6:
            reset();
            break;
        case 7:
            cariData();
            break;
        case 8:
            hapusData();
            break;
        case 9:
            sisipkanSebelum();
            break;
        case 10:
            sisipkanSetelah();
            break;
        default:
            cout<<"\nTERIMA KASIH"<<endl;
            cout<<"Program was made by Dillon Riffa Harits (2510817210009)."<<endl;
        }

        if(pil < 11) {
            cout<<"\nPress any key to continue!"<<endl;
            getch();
            system("cls");
        }

    } while (pil < 11);
    return 0;
}

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if(head == NULL) return 1;
    else return 0;
}

int hitungNode() {
    if (isEmpty() == 1) return 0;
    int count = 0;
    TNode* bantu = head;
    do {
        count++;
        bantu = bantu->next;
    } while (bantu != head);
    return count;
}

void tambahDepan() {
    cout << "Masukkan data : ";
    string inputBaris;
    cin.ignore();
    getline(cin, inputBaris);

    stringstream ss(inputBaris);
    string kata;
    vector<string> kumpulanData;

    while(ss >> kata) {
        kumpulanData.push_back(kata);
    }

    for (int i = kumpulanData.size() - 1; i >= 0; i--) {
        string dataMasuk = kumpulanData[i];
        TNode *baru = new TNode;
        baru->data = dataMasuk;
        baru->next = baru;

        if(isEmpty() == 1) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }
    cout << "Data berhasil dimasukkan di bagian depan dengan urutan sesuai input." << endl;
}

void tambahBelakang() {
    cout<<"Masukkan data : ";
    TNode *baru;
    baru = new TNode;
    cin>>dataBaru;
    baru->data =  dataBaru;
    baru->next = baru;

    if(isEmpty() == 1) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data \""<<dataBaru<<"\" berhasil dimasukkan dibagian belakang."<<endl;
}

void hapusDepan() {
    if(isEmpty() == 0) {
        int n;
        cout << "Masukkan N (hapus node ke-N dari depan): ";
        cin >> n;
        int total = hitungNode();

        if (n > total) {
            TNode *hapus = tail;
            dataHapus = hapus->data;
            if (head != tail) {
                TNode *bantu = head;
                while (bantu->next != tail) bantu = bantu->next;
                tail = bantu;
                tail->next = head;
            } else {
                init();
            }
            delete hapus;
            cout << "Input N melebihi jumlah node. Node Tail (\"" << dataHapus << "\") telah dihapus." << endl;
        } else {
            TNode *hapus = head;
            TNode *sebelum = tail;
            for (int i = 1; i < n; i++) {
                sebelum = hapus;
                hapus = hapus->next;
            }
            dataHapus = hapus->data;
            sebelum->next = hapus->next;
            
            if (hapus == head) head = hapus->next;
            if (hapus == tail) tail = sebelum;
            if (total == 1) init();
            
            delete hapus;
            cout << "Node ke-" << n << " dari depan (\"" << dataHapus << "\") telah dihapus." << endl;
        }
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void hapusBelakang() {
    if(isEmpty() == 0) {
        int n;
        cout << "Masukkan N (hapus node ke-N dari belakang): ";
        cin >> n;
        int total = hitungNode();

        if (n > total) {
            TNode *hapus = head;
            dataHapus = hapus->data;
            if (head != tail) {
                head = head->next;
                tail->next = head;
            } else {
                init();
            }
            delete hapus;
            cout << "Input N melebihi jumlah node. Node Head (\"" << dataHapus << "\") telah dihapus." << endl;
        } else {
            int targetPos = total - n + 1;
            TNode *hapus = head;
            TNode *sebelum = tail;
            for (int i = 1; i < targetPos; i++) {
                sebelum = hapus;
                hapus = hapus->next;
            }
            dataHapus = hapus->data;
            sebelum->next = hapus->next;
            
            if (hapus == head) head = hapus->next;
            if (hapus == tail) tail = sebelum;
            if (total == 1) init();
            
            delete hapus;
            cout << "Node ke-" << n << " dari belakang (\"" << dataHapus << "\") telah dihapus." << endl;
        }
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void tampilkan() {
    if(isEmpty() == 0) {
        TNode *bantu;
        bantu = head;

        do {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        } while(bantu != head);
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void reset() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        TNode *hapus;
        int counter = 1;

        tail->next = NULL;

        while(bantu != NULL) {
            hapus = bantu;
            cout << "Menghapus node ke-" << counter << " dengan isi: " << hapus->data << endl;
            bantu = bantu->next;
            delete hapus;
            counter++;
        }

        init();
        cout << "Seluruh elemen pada Linked List telah tuntas dibersihkan." << endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void cariData(){
    if(isEmpty() == 0) {
        string cari;
        cout<<"Masukan data yang ingin dicari : ";
        cin>>cari;

        TNode *bantu, *bantuTampilkan;
        bool apaDitemukan = false;

        bantu = head;

        do {
            if(cari == bantu->data){
                cout<<"Setiap data yang berada di dalam tanda kurung siku ([...]) "
                    <<"merupakan data yang anda cari."<<endl;
                cout<<"Linked List : ";
                bantuTampilkan = head;

                do {
                    if(cari == bantuTampilkan->data)
                        cout<<"["<<bantuTampilkan->data<<"] ";
                    else
                        cout<<bantuTampilkan->data<<' ';
                    bantuTampilkan = bantuTampilkan->next;
                } while(bantuTampilkan != head);

                apaDitemukan = true;
                cout<<endl;
                break;
            }
            bantu = bantu->next;
        } while(bantu != head);

        if(apaDitemukan == false)
            cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void hapusData(){
    if(isEmpty() == 0) {
        string cari;
        cout<<"Masukkan data yang ingin dihapus : ";
        cin>>cari;

        TNode *bantu = head, *sebelum = tail, *hapus[225], *bantu2;
        int hitung = 0;
        bool apaDitemukan = false;

        do {
            bantu2 = bantu;
            if(cari == bantu->data){
                hapus[hitung++] = bantu;
                apaDitemukan = true;
                if(bantu != head && bantu != tail) {
                    sebelum->next = bantu->next;
                    bantu2 = sebelum;
                }
            }
            sebelum = bantu2;
            bantu = bantu->next;
        } while(bantu != head);

        if(apaDitemukan == true) {
            for(int i = 0; i < hitung; i++) {
                if(hapus[i] == head){
                    TNode* hapusDepanBantu = head;
                    if (head != tail) {
                        head = head->next;
                        tail->next = head;
                    } else init();
                    delete hapusDepanBantu;
                } else if(hapus[i] == tail) {
                    TNode* hapusBelakangBantu = tail;
                    if (head != tail) {
                        TNode* temp = head;
                        while(temp->next != tail) temp = temp->next;
                        tail = temp;
                        tail->next = head;
                    } else init();
                    delete hapusBelakangBantu;
                } else {
                    delete hapus[i];
                }
            }
            cout<<"Setiap data \""<<cari<<"\" yang terdapat pada Linked List telah dihapus."<<endl;
        } else cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;

    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void sisipkanSebelum() {
    if(isEmpty() == 0) {
        TNode *bantu, *sebelum;
        string nextData;
        bool apaAda = false;

        bantu = head;
        sebelum = tail;

        cout<<"Sisipkan data baru sebelum data : ";
        cin>>nextData;

        do {
            if(nextData == bantu->data){
                apaAda = true;
                break;
            } else {
                sebelum = bantu;
                bantu = bantu->next;
            }
        } while(bantu != head);

        if(apaAda==true) {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>dataBaru;

            TNode *baru;
            baru = new TNode;

            baru->data = dataBaru;
            baru->next = bantu;

            sebelum->next = baru;

            if(bantu == head){
                head = baru;
            }

            cout << "Data \""<<dataBaru<<"\" berhasil disisipkan sebelum data \""<<nextData<<"\"."<<endl;
        } else {
            cout<<"Tidak terdapat data \""<<nextData<<"\" pada Linked List."<<endl;
        }
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void sisipkanSetelah() {
    if(isEmpty() == 0) {
        TNode *bantu;
        string prevData;
        bool apaAda = false;

        bantu = head;

        cout<<"Sisipkan data baru setelah data : ";
        cin>>prevData;

        do {
            if(prevData == bantu->data){
                apaAda = true;
                break;
            } else {
                bantu = bantu->next;
            }
        } while(bantu != head);

        if(apaAda==true) {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>dataBaru;

            TNode *baru;
            baru = new TNode;

            baru->data = dataBaru;
            baru->next = bantu->next;
            
            bantu->next = baru;

            if(bantu == tail){
                tail = baru;
            }

            cout << "Data \""<<dataBaru<<"\" berhasil disisipkan setelah data \""<<prevData<<"\"."<<endl;
        } else {
            cout<<"Tidak terdapat data \""<<prevData<<"\" pada Linked List."<<endl;
        }
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}