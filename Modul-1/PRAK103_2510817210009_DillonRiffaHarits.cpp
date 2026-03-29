#include <iostream>
#include <string>

using namespace std;

int main() {
    char huruf;
    string kata;
    int angka;

    cout << "a. Masukkan sebuah huruf = ";
    cin >> huruf;

    cout << "b. Masukan sebuah kata   = ";
    cin >> kata;

    cout << "c. Masukkan Angka        = ";
    cin >> angka;

    cout << "----------------------------------------\n";
    
    cout << "d. Huruf yang Anda masukkan adalah " << huruf << "\n";
    cout << "e. Kata yang Anda masukkan adalah " << kata << "\n";
    cout << "f. Angka yang Anda masukkan adalah " << angka << "\n";

    return 0;
}