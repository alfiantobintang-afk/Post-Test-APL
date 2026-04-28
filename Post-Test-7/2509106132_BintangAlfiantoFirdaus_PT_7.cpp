#include <iostream>
#include <string>
#include <limits>
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

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int inputInt(string pesan) {
    int x;
    while (true) {
        cout << pesan;
        cin >> x;
        if (cin.fail()) {
            cout << "Input harus angka!\n";
            clearInput();
        } else return x;
    }
}

double inputDouble(string pesan) {
    double x;
    while (true) {
        cout << pesan;
        cin >> x;
        if (cin.fail()) {
            cout << "Input harus angka!\n";
            clearInput();
        } else return x;
    }
}

void tambahData(Hewan ternak[], int *jumlah) {
    if (*jumlah >= 100) {
        cout << "Data penuh!\n";
        return;
    }

    cout << "\n=== Tambah Data Hewan ===\n";

    ternak[*jumlah].id = inputInt("ID Hewan   : ");

    cout << "Nama Hewan : ";
    clearInput();
    getline(cin, ternak[*jumlah].nama);

    ternak[*jumlah].umur = inputInt("Umur (tahun): ");
    ternak[*jumlah].berat = inputDouble("Berat (kg) : ");

    (*jumlah)++;
    cout << "Data berhasil ditambahkan!\n";
}

void tampilData(Hewan ternak[], int index, int *jumlah) {
    if (index == *jumlah) return;

    cout << "\nData ke-" << index + 1 << endl;
    cout << "ID Hewan   : " << ternak[index].id << endl;
    cout << "Nama Hewan : " << ternak[index].nama << endl;
    cout << "Umur       : " << ternak[index].umur << " tahun\n";
    cout << "Berat      : " << ternak[index].berat << " kg\n";

    tampilData(ternak, index + 1, jumlah);
}

void updateData(Hewan ternak[], int *jumlah) {
    if (*jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    int idCari = inputInt("\nMasukkan ID hewan: ");
    bool ditemukan = false;

    for (int i = 0; i < *jumlah; i++) {
        if (ternak[i].id == idCari) {
            cout << "Nama baru : ";
            clearInput();
            getline(cin, ternak[i].nama);

            ternak[i].umur = inputInt("Umur baru : ");
            ternak[i].berat = inputDouble("Berat baru: ");

            cout << "Data berhasil diupdate!\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) cout << "Data tidak ditemukan!\n";
}

void hapusData(Hewan ternak[], int *jumlah) {
    if (*jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    int idHapus = inputInt("\nMasukkan ID hewan: ");
    bool ditemukan = false;

    for (int i = 0; i < *jumlah; i++) {
        if (ternak[i].id == idHapus) {
            for (int j = i; j < *jumlah - 1; j++) {
                ternak[j] = ternak[j + 1];
            }
            (*jumlah)--;

            cout << "Data berhasil dihapus!\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) cout << "Data tidak ditemukan!\n";
}

void cariID(Hewan ternak[], int *jumlah) {
    if (*jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    int idCari = inputInt("\nMasukkan ID: ");
    bool ditemukan = false;

    for (int i = 0; i < *jumlah; i++) {
        if (ternak[i].id == idCari) {
            cout << "\nData ditemukan!\n";
            cout << "ID    : " << ternak[i].id << endl;
            cout << "Nama  : " << ternak[i].nama << endl;
            cout << "Umur  : " << ternak[i].umur << endl;
            cout << "Berat : " << ternak[i].berat << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) cout << "Data tidak ditemukan!\n";
}

void sortNamaAscending(Hewan ternak[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (ternak[j].nama > ternak[j + 1].nama) {
                swap(ternak[j], ternak[j + 1]);
            }
        }
    }
}

void sortNamaDescending(Hewan ternak[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (ternak[j].nama < ternak[j + 1].nama) {
                swap(ternak[j], ternak[j + 1]);
            }
        }
    }
    cout << "Sorting nama (Z-A) selesai!\n";
}

void sortUmurAscending(Hewan ternak[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < jumlah; j++) {
            if (ternak[j].umur < ternak[minIndex].umur)
                minIndex = j;
        }
        swap(ternak[i], ternak[minIndex]);
    }
    cout << "Sorting umur selesai!\n";
}

void sortBeratDescending(Hewan ternak[], int jumlah) {
    for (int i = 1; i < jumlah; i++) {
        Hewan key = ternak[i];
        int j = i - 1;

        while (j >= 0 && ternak[j].berat < key.berat) {
            ternak[j + 1] = ternak[j];
            j--;
        }
        ternak[j + 1] = key;
    }
    cout << "Sorting berat selesai!\n";
}

void cariNama(Hewan ternak[], int jumlah) {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    string namaCari;
    cout << "\nMasukkan nama: ";
    clearInput();
    getline(cin, namaCari);

    int kiri = 0, kanan = jumlah - 1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (ternak[tengah].nama == namaCari) {
            cout << "\nData ditemukan!\n";
            cout << "ID    : " << ternak[tengah].id << endl;
            cout << "Nama  : " << ternak[tengah].nama << endl;
            cout << "Umur  : " << ternak[tengah].umur << endl;
            cout << "Berat : " << ternak[tengah].berat << endl;
            return;
        }
        else if (ternak[tengah].nama < namaCari)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    cout << "Data tidak ditemukan!\n";
}

int main() {
    Akun user;
    Hewan ternak[100];
    int jumlah = 0;
    int kesempatan = 3, pilihan;

    cout << "=== REGISTRASI ===\n";
    cout << "Username: ";
    cin >> user.username;
    cout << "Password: ";
    cin >> user.password;

    while (kesempatan > 0) {
        string u, p;
        cout << "\n=== LOGIN ===\n";
        cout << "Username: "; cin >> u;
        cout << "Password: "; cin >> p;

        if (u == user.username && p == user.password) break;

        kesempatan--;
        cout << "Login gagal! Sisa: " << kesempatan << endl;

        if (kesempatan == 0) return 0;
    }

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah\n2. Tampil\n3. Update\n4. Hapus\n";
        cout << "5. Sort Nama\n6. Sort Umur\n7. Sort Berat\n";
        cout << "8. Cari ID\n9. Cari Nama\n10. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahData(ternak, &jumlah); break;
            case 2: tampilData(ternak, 0, &jumlah); break;
            case 3: updateData(ternak, &jumlah); break;
            case 4: hapusData(ternak, &jumlah); break;
            case 5: sortNamaDescending(ternak, jumlah); break;
            case 6: sortUmurAscending(ternak, jumlah); break;
            case 7: sortBeratDescending(ternak, jumlah); break;
            case 8: cariID(ternak, &jumlah); break;
            case 9: sortNamaAscending(ternak, jumlah); cariNama(ternak, jumlah); break;
            case 10: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 10);

    return 0;
}