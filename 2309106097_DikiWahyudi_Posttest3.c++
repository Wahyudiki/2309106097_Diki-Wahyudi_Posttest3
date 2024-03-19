#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk menyimpan informasi beras
struct BerasInfo {
    string jenisNama;
    double hargaBeras;
    int stokBeras;
};

// Fungsi untuk login
bool prosesLogin() {
    string user, pw;
    int percobaan = 0;
    const string userBenar = "diki";
    const string pwBenar = "097";

    while (percobaan < 3) {
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pw;

        if (user == userBenar && pw == pwBenar) {
            return true;
        } else {
            percobaan++;
            cout << "Username atau password salah. Sisa percobaan: " << 3 - percobaan << endl;
        }
    }

    cout << "Login gagal. Program akan keluar." << endl;
    return false;
}

// Fungsi untuk menampilkan menu
void tampilMenu() {
    cout << "=== Toko Beras Diki Walla ===" << endl;
    cout << "1. Lihat Daftar Beras" << endl;
    cout << "2. Tambah Jenis Beras" << endl;
    cout << "3. Jual Beras" << endl;
    cout << "4. Hapus Jenis Beras" << endl;
    cout << "5. Ubah Jenis Beras" << endl;
    cout << "6. Cari Jenis Beras" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilihan: ";
}

// Fungsi menambah jenis beras baru
void tambahBerasData(BerasInfo daftarBeras[], int& jumlahBeras) {
    if (jumlahBeras < 10) {
        BerasInfo berasInput;
        cout << "Jenis Beras: ";
        cin.ignore();
        getline(cin, berasInput.jenisNama);
        cout << "Harga per Kg: ";
        cin >> berasInput.hargaBeras;
        cout << "Stok (Kg): ";
        cin >> berasInput.stokBeras;
        daftarBeras[jumlahBeras] = berasInput;
        jumlahBeras++;
        cout << "Jenis beras berhasil ditambahkan!" << endl;
    } else {
        cout << "Toko sudah penuh!" << endl;
    }
}

// Fungsi menjual beras
void jualBerasData(BerasInfo daftarBeras[], int jumlahBeras) {
    string jenisNama;
    int jumlahJual;
    cout << "Jenis Beras: ";
    cin.ignore();
    getline(cin, jenisNama);
    cout << "Jumlah Jual (Kg): ";
    cin >> jumlahJual;

    for (int i = 0; i < jumlahBeras; i++) {
        if (daftarBeras[i].jenisNama == jenisNama) {
            if (daftarBeras[i].stokBeras >= jumlahJual) {
                daftarBeras[i].stokBeras -= jumlahJual;
                double totalHarga = daftarBeras[i].hargaBeras * jumlahJual;
                cout << "Total Harga: " << totalHarga << endl;
                cout << "Transaksi berhasil!" << endl;
            } else {
                cout << "Stok tidak mencukupi!" << endl;
            }
            return;
        }
    }

    cout << "Jenis beras tidak ditemukan!" << endl;
}

// Fungsi  menghapus jenis beras
void hapusBerasData(BerasInfo daftarBeras[], int& jumlahBeras) {
    string jenisNama;
    cout << "Jenis Beras yang Akan Dihapus: ";
    cin.ignore();
    getline(cin, jenisNama);

    for (int i = 0; i < jumlahBeras; i++) {
        if (daftarBeras[i].jenisNama == jenisNama) {
    // Menggeser data setelah jenis beras yang dihapus ke kiri
            for (int j = i; j < jumlahBeras - 1; j++) {
                daftarBeras[j] = daftarBeras[j + 1];
            }
            jumlahBeras--;
            cout << "Jenis beras berhasil dihapus!" << endl;
            return;
        }
    }

    cout << "Jenis beras tidak ditemukan!" << endl;
}

// Fungsi mengubah jenis beras
void ubahBerasData(BerasInfo daftarBeras[], int jumlahBeras) {
    string jenisNama;
    cout << "Jenis Beras yang Akan Diubah: ";
    cin.ignore();
    getline(cin, jenisNama);

    for (int i = 0; i < jumlahBeras; i++) {
        if (daftarBeras[i].jenisNama == jenisNama) {
            BerasInfo berasUbah;
            cout << "Jenis Beras Baru: ";
            getline(cin, berasUbah.jenisNama);
            cout << "Harga per Kg: ";
            cin >> berasUbah.hargaBeras;
            cout << "Stok (Kg): ";
            cin >> berasUbah.stokBeras;
            daftarBeras[i] = berasUbah;
            cout << "Jenis beras berhasil diubah!" << endl;
            return;
        }
    }

    cout << "Jenis beras tidak ditemukan!" << endl;
}

// Fungsi mencari jenis beras
void cariBerasData(BerasInfo daftarBeras[], int jumlahBeras) {
    string jenisNama;
    cout << "Jenis Beras yang Akan Dicari: ";
    cin.ignore();
    getline(cin, jenisNama);

    for (int i = 0; i < jumlahBeras; i++) {
        if (daftarBeras[i].jenisNama == jenisNama) {
            cout << "Jenis Beras: " << daftarBeras[i].jenisNama << endl;
            cout << "Harga per Kg: " << daftarBeras[i].hargaBeras << endl;
            cout << "Stok: " << daftarBeras[i].stokBeras << " Kg" << endl;
            return;
        }
    }

    cout << "Jenis beras tidak ditemukan!" << endl;
}

// Fungsi menampilkan menu utama secara rekursif
void tampilMenuUtama(BerasInfo daftarBeras[], int jumlahBeras) {
    tampilMenu();
    int pilihan;
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
        case 1:
            cout << "=== Daftar Beras ===" << endl;
            if (jumlahBeras == 0) {
                cout << "Tidak ada jenis beras!" << endl;
            } else {
                for (int i = 0; i < jumlahBeras; i++) {
                    cout << "Jenis Beras: " << daftarBeras[i].jenisNama << endl;
                    cout << "Harga per Kg: " << daftarBeras[i].hargaBeras << endl;
                    cout << "Stok: " << daftarBeras[i].stokBeras << " Kg" << endl;
                    cout << "-------------------" << endl;
                }
            }
            tampilMenuUtama(daftarBeras, jumlahBeras);
            break;
        case 2:
            tambahBerasData(daftarBeras, jumlahBeras);
            tampilMenuUtama(daftarBeras, jumlahBeras);
            break;
        case 3:
            jualBerasData(daftarBeras, jumlahBeras);
            tampilMenuUtama(daftarBeras, jumlahBeras);
            break;
        case 4:
            hapusBerasData(daftarBeras, jumlahBeras);
            tampilMenuUtama(daftarBeras, jumlahBeras);
            break;
        case 5:
            ubahBerasData(daftarBeras, jumlahBeras);
            tampilMenuUtama(daftarBeras, jumlahBeras);
            break;
        case 6:
            cariBerasData(daftarBeras, jumlahBeras);
            tampilMenuUtama(daftarBeras, jumlahBeras);
            break;
        case 7:
            cout << "Terima kasih telah belanja di toko kami!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            tampilMenuUtama(daftarBeras, jumlahBeras);
    }
}

int main() {
    BerasInfo daftarBeras[10];
    int jumlahBeras = 0;

    // Login
    if (!prosesLogin()) {
        return 0; // Keluar dari program jika login gagal
    }

    tampilMenuUtama(daftarBeras, jumlahBeras);

    return 0;
}