#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void merge(int arr[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[kiri + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int kiri, int kanan) {
    if (kiri >= kanan) return;
    int tengah = kiri + (kanan - kiri) / 2;
    mergeSort(arr, kiri, tengah);
    mergeSort(arr, tengah + 1, kanan);
    merge(arr, kiri, tengah, kanan);
}

bool binarySearch(int arr[], int kiri, int kanan, int target) {
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (arr[tengah] == target) return true;
        if (arr[tengah] < target) kiri = tengah + 1;
        else kanan = tengah - 1;
    }
    return false;
}

int hitungPasangan(int angka[], int n, int x) {
    int total_pasangan = 0;
    
    cout << "Pasangan yang Ditemukan:\n";
    for (int i = 0; i < n - 1; i++) {
        if (i > 0 && angka[i] == angka[i - 1]) continue;

        int target = x - angka[i];
        
        if (binarySearch(angka, i + 1, n - 1, target)) {
            cout << angka[i] << " + " << target << " = " << x << "\n";
            total_pasangan++;
        }
    }
    
    if (total_pasangan == 0) {
        cout << "Tidak ada pasangan yang cocok.\n";
    }
    
    return total_pasangan;
}

int main() {
    int n, x;
    cout << "Masukkan N (Jumlah Elemen) dan X (Target Jumlah): ";
    cin >> n >> x;

    int angka[n];
    srand(time(0));

    cout << "\n--------------------------------------------------\n";
    cout << "Barisan data acak berhasil digenerate (1-25):\n";
    for (int i = 0; i < n; i++) {
        angka[i] = (rand() % 25) + 1;
        cout << angka[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n--------------------------------------------------\n";

    mergeSort(angka, 0, n - 1);

    cout << "Data setelah diurutkan menggunakan Merge Sort:\n";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << "\n--------------------------------------------------\n";

    int total_pasangan = hitungPasangan(angka, n, x);

    cout << "\nTOTAL PASANGAN YANG COCOK (JUMLAH = " << x << "): " << total_pasangan << "\n";
    cout << "--------------------------------------------------\n";
    
    return 0;
}