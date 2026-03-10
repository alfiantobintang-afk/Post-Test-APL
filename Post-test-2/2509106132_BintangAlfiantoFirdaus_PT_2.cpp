#include <iostream>
#include <string>
using namespace std;

struct Akun {
    string username;
    string password;
};

struct Hewan {
    int id;
    string nama;
    int umur;
    double berat;
};

int main() {

    Akun user;
    Hewan ternak[100];
    int jumlah = 0;

    string username, password;
    int kesempatan = 3;
    int pilihan;

    cout << "=== REGISTRASI AKUN ===" << endl;
    cout << "Buat Username            : ";
    cin >> user.username;
    cout << "Buat Password (3 digit NIM): ";
    cin >> user.password;

    cout << "\nAkun berhasil dibuat!\n\n";

    while (kesempatan > 0) {

        cout << "=== LOGIN ===" << endl;
        cout << "Username : ";
        cin >> username;
        cout << "Password : ";
        cin >> password;

        if (username == user.username && password == user.password) {
            
            cout << "\nLogin berhasil!\n";
            cout << "" << endl;
            cout << "" << endl;
            cout << "====Selamat Datang di Ternak Binn====" << endl;
            cout << "\nhai, " << username << endl;
            break;
        }
        else {
            kesempatan--;
            cout << "\nLogin gagal! Sisa percobaan: " << kesempatan << endl;
        }

        if (kesempatan == 0) {
            cout << "\nAnda salah login 3 kali.\n";
            cout << "Program berhenti.\n";
            return 0;
        }
    }

    do {

        cout << "\n=== MENU DATA HEWAN TERNAK ===" << endl;
        cout << "1. Tambah Data Hewan (Create)" << endl;
        cout << "2. Tampilkan Data Hewan (Read)" << endl;
        cout << "3. Update Data Hewan (Update)" << endl;
        cout << "4. Hapus Data Hewan (Delete)" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        //Membuat
        if (pilihan == 1) {

            cout << "\n=== Tambah Data Hewan ===" << endl;
            cout << "ID Hewan   : ";
            cin >> ternak[jumlah].id;
            cout << "Nama Hewan : ";
            cin.ignore();
            getline(cin, ternak[jumlah].nama);
            cout << "Umur (tahun): ";
            cin >> ternak[jumlah].umur;
            cout << "Berat (kg) : ";
            cin >> ternak[jumlah].berat;

            jumlah++;

            cout << "Data berhasil ditambahkan!\n";
        }

        //Membaca
        else if (pilihan == 2) {

            cout << "\n=== Data Hewan Ternak ===\n";

            if (jumlah == 0) {
                cout << "Belum ada data.\n";
            }
            else {
                for (int i = 0; i < jumlah; i++) {
                    cout << "\nData ke-" << i + 1 << endl;
                    cout << "ID Hewan   : " << ternak[i].id << endl;
                    cout << "Nama Hewan : " << ternak[i].nama << endl;
                    cout << "Umur       : " << ternak[i].umur << " tahun" << endl;
                    cout << "Berat      : " << ternak[i].berat << " kg" << endl;
                }
            }
        }

        //Mengupdate
        else if (pilihan == 3) {

            int idCari;
            cout << "\nMasukkan ID hewan yang ingin diupdate: ";
            cin >> idCari;

            bool ditemukan = false;

            for (int i = 0; i < jumlah; i++) {

                if (ternak[i].id == idCari) {

                    cout << "Nama baru : ";
                    cin.ignore();
                    getline(cin, ternak[i].nama);
                    cout << "Umur baru : ";
                    cin >> ternak[i].umur;
                    cout << "Berat baru: ";
                    cin >> ternak[i].berat;

                    cout << "Data berhasil diupdate!\n";
                    ditemukan = true;
                }
            }

            if (!ditemukan) {
                cout << "Data tidak ditemukan!\n";
            }
        }

        //Menghapus
        else if (pilihan == 4) {

            int idHapus;
            cout << "\nMasukkan ID hewan yang mati atau terjual: ";
            cin >> idHapus;

            bool ditemukan = false;

            for (int i = 0; i < jumlah; i++) {

                if (ternak[i].id == idHapus) {

                    for (int j = i; j < jumlah - 1; j++) {
                        ternak[j] = ternak[j + 1];
                    }

                    jumlah--;
                    ditemukan = true;
                    cout << "Data berhasil dihapus!\n";
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Data tidak ditemukan!\n";
            }
        }

        else if (pilihan == 5) {
            cout << "\nTerima kasih telah menggunakan program.\n";
        }

        else {
            cout << "\nPilihan tidak tersedia!\n";
        }

    } while (pilihan != 5);

    return 0;
}