#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
    
    Node(int val) {
        data = val;
        kiri = NULL;
        kanan = NULL;
    }
};

Node* insertBST(Node* root, int val) {
    if (root == NULL) return new Node(val);
    
    if (val < root->data) {
        root->kiri = insertBST(root->kiri, val);
    } else if (val > root->data) {
        root->kanan = insertBST(root->kanan, val);
    }
    
    return root;
}

int hitungDiameter(Node* node, int& rekor_jarak) {
    if (node == NULL) return 0;

    int tinggi_kiri = hitungDiameter(node->kiri, rekor_jarak);
    int tinggi_kanan = hitungDiameter(node->kanan, rekor_jarak);

    if (tinggi_kiri + tinggi_kanan > rekor_jarak) {
        rekor_jarak = tinggi_kiri + tinggi_kanan;
    }

    return max(tinggi_kiri, tinggi_kanan) + 1;
}

int main() {
    int n;
    cout << "--------------------------------------------------\n";
    cout << "Masukkan N (Jumlah Elemen): ";
    if (!(cin >> n)) return 0;

    Node* root = NULL;

    cout << "Masukkan " << n << " angka dipisah spasi:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insertBST(root, val);
    }

    int jarak_terjauh = 0;
    
    hitungDiameter(root, jarak_terjauh);

    cout << "\n--------------------------------------------------\n";
    cout << "TOTAL SISI MAKSIMAL (JARAK) = " << jarak_terjauh << "\n";
    cout << "--------------------------------------------------\n";

    return 0;
}