#include <iostream>
#include <string>

using namespace std;

struct Kendaraan {
    string platnomor;
    string jenis;
    string namapemilik;
    string alamat;
    string kota;
};

int main() {
    Kendaraan datamobil;

    datamobil.platnomor = "DA1234MK";
    datamobil.jenis = "RUSH";
    datamobil.namapemilik = "Andika Hartanto";
    datamobil.alamat = "Jl. Kayu Tangi 1";
    datamobil.kota = "Banjarmasin";

    cout << "a. Plat Nomor Kendaraan : " << datamobil.platnomor << endl;
    cout << "b. Jenis Kendaraan      : " << datamobil.jenis << endl;
    cout << "c. Nama Pemilik         : " << datamobil.namapemilik << endl;
    cout << "d. Alamat               : " << datamobil.alamat << endl;
    cout << "e. Kota                 : " << datamobil.kota << endl;

    return 0;
}