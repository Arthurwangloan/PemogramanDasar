#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Tambahkan header ini

using namespace std;

// Fungsi untuk menampilkan daftar pasien
void tampilkanDaftar(const vector<string>& daftarPasien) {
    if (daftarPasien.empty()) {
        cout << "Daftar pasien kosong." << endl;
    } else {
        cout << "Daftar Pasien yang Telah Meninggal:" << endl;
        for (size_t i = 0; i < daftarPasien.size(); ++i) {
            cout << i + 1 << ". " << daftarPasien[i] << endl;
        }
    }
}

// Fungsi untuk menambahkan pasien
void tambahPasien(vector<string>& daftarPasien, const string& nama) {
    daftarPasien.push_back(nama);
    cout << "Pasien '" << nama << "' telah ditambahkan ke daftar." << endl;
}

// Fungsi untuk menghapus pasien
void hapusPasien(vector<string>& daftarPasien, const string& nama) {
    auto it = find(daftarPasien.begin(), daftarPasien.end(), nama);
    if (it != daftarPasien.end()) {
        daftarPasien.erase(it);
        cout << "Pasien '" << nama << "' telah dihapus dari daftar." << endl;
    } else {
        cout << "Pasien '" << nama << "' tidak ditemukan dalam daftar." << endl;
    }
}

// Fungsi untuk menampilkan menu
void menu() {
    vector<string> daftarPasien;
    int pilihan;
    string nama;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Pasien" << endl;
        cout << "2. Tampilkan Daftar Pasien" << endl;
        cout << "3. Hapus Pasien" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi (1-4): ";
        cin >> pilihan;
        cin.ignore(); // Mengabaikan newline setelah input integer

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama pasien: ";
                getline(cin, nama);
                tambahPasien(daftarPasien, nama);
                break;
            case 2:
                tampilkanDaftar(daftarPasien);
                break;
            case 3:
                cout << "Masukkan nama pasien yang ingin dihapus: ";
                getline(cin, nama);
                hapusPasien(daftarPasien, nama);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);
}

// Fungsi utama
int main() {
    menu();
    return 0;
}
