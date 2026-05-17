#include <iostream>
#include <string>
using namespace std;

void insertionSort(string s) {
    int n = s.length();
    for (int i = 1; i < n; i++) {
        char key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j] > key) {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
    cout << "Hasil Insertion Sort: " << s << "\n";
}

void merge(string &s, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    string L = s.substr(left, n1);
    string R = s.substr(mid + 1, n2);
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            s[k] = L[i];
            i++;
        } else {
            s[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        s[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        s[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(string &s, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortHelper(s, left, mid);
    mergeSortHelper(s, mid + 1, right);
    merge(s, left, mid, right);
}

void mergeSort(string s) {
    mergeSortHelper(s, 0, s.length() - 1);
    cout << "Hasil Merge Sort: " << s << "\n";
}

void shellSort(string s) {
    int n = s.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            char temp = s[i];
            int j;
            for (j = i; j >= gap && s[j - gap] > temp; j -= gap) {
                s[j] = s[j - gap];
            }
            s[j] = temp;
        }
    }
    cout << "Hasil Shell Sort: " << s << "\n";
}

int partition(string &s, int low, int high) {
    char pivot = s[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (s[j] < pivot) {
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return (i + 1);
}

void quickSortHelper(string &s, int low, int high) {
    if (low < high) {
        int pi = partition(s, low, high);
        quickSortHelper(s, low, pi - 1);
        quickSortHelper(s, pi + 1, high);
    }
}

void quickSort(string s) {
    quickSortHelper(s, 0, s.length() - 1);
    cout << "Hasil Quick Sort: " << s << "\n";
}

void bubbleSort(string s) {
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                swap(s[j], s[j + 1]);
            }
        }
    }
    cout << "Hasil Bubble Sort: " << s << "\n";
}

void selectionSort(string s) {
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[min_idx]) {
                min_idx = j;
            }
        }
        swap(s[min_idx], s[i]);
    }
    cout << "Hasil Selection Sort: " << s << "\n";
}

void tampilkanMenu() {
    cout << "\n==============================\n";
    cout << "           SORTING\n";
    cout << "==============================\n";
    cout << "1. Insertion Sort (Nama)\n";
    cout << "2. Merge Sort (Nama)\n";
    cout << "3. Shell Sort (Nama)\n";
    cout << "4. Quick Sort (NIM)\n";
    cout << "5. Bubble Sort (NIM)\n";
    cout << "6. Selection Sort (NIM)\n";
    cout << "7. Exit\n";
    cout << "==============================\n";
    cout << "Masukkan Pilihan : ";
}

int main() {
    int pilihan;
    string inputData;

    do {
        tampilkanMenu();
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 3) {
            cout << "Masukkan Nama: ";
            cin >> ws;
            getline(cin, inputData);
            
            if (pilihan == 1) insertionSort(inputData);
            else if (pilihan == 2) mergeSort(inputData);
            else shellSort(inputData);
            
        } else if (pilihan >= 4 && pilihan <= 6) {
            cout << "Masukkan NIM: ";
            cin >> inputData;
            
            if (pilihan == 4) quickSort(inputData);
            else if (pilihan == 5) bubbleSort(inputData);
            else selectionSort(inputData);
            
        } else if (pilihan == 7) {
            cout << "Terima kasih\n";
        } else {
            cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 7);

    return 0;
}