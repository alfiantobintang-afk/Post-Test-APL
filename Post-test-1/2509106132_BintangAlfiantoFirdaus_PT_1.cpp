#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    string username, password, registUser, registPass;
    int kesempatan = 3;
    int pilihan;
    double nilai;

    cout << "===REGISTRASI AKUN===" << endl;
    cout << "Buat Username           : ";
    cin >> registUser;
    cout << "Buat Password (3 digit NIM): ";
    cin >> registPass;

    cout << "\nAkun berhasil dibuat!\n\n";

    while (kesempatan > 0) {
        cout << "Username : ";
        cin >> username;
        cout << "Password : ";
        cin >> password;
        

        if (username ==registUser && password == registPass) {
            cout << "\nLogin berhasil!\n";
            system("pause");
            break;
        } else {
            kesempatan--;
            cout << "\nLogin gagal! Sisa percobaan: "
                 << kesempatan << endl;
        }

            if (kesempatan == 0) {
        cout << "Anda salah login 3 kali.\n";
        cout << "Program berhenti.\n";
        return 0;
        }
    }
    cout << "" << endl;
    cout << "=============Pilihan Fitur=============" << endl;
    cout << "" << endl;
    cout << "1. Konversi Meter ke Kilometer dan Centimeter" << endl;
    cout << "" << endl;
    cout << "2. Konversi Kilometer ke Meter dan Centimeter" << endl;
    cout << "" << endl;
    cout << "3. Konversi Centimeter ke Meter dan Kilometer" << endl;
    cout << "" << endl;
    cout << "4. Keluar" << endl;
    cout << "" << endl;
    cout << "Pilihlah menu dari (1-4) diatas" << endl;
    cin >> pilihan;
    cout << "\n" << endl;

    switch (pilihan)
    {
    case 1:
        cout << "" << endl;
        cout << "== Masukkan Nilai Meter ==" << endl;
        cout << "" << endl;
        cout << "Nilai: " << endl;
        cin >> nilai;
        cout << "" << endl;
        cout << "Hasil Konversi: \n" << endl;
        cout << "" << endl;
        cout << nilai << "m = " << nilai / 1000 << "Km\n" << endl;
        cout << nilai << "m = " << nilai * 100 << "Cm\n" << endl;
        break;
    

    case 2:
        cout << "" << endl;
        cout << "== Masukkan Nilai Kilometer ==" << endl;
        cout << "" << endl;
        cout << "Nilai: " << endl;
        cin >> nilai;
        cout << "" << endl;
        cout << "Hasil Konversi: \n" << endl;
        cout << "" << endl;
        cout << nilai << "Km = " << nilai * 1000 << "M\n" << endl;
        cout << nilai << "Km = " << nilai * 100000 << "Cm\n" << endl;
        break;

    case 3:
        cout << "" << endl;
        cout << "== Masukkan Nilai Centimeter ==" << endl;
        cout << "" << endl;
        cout << "Nilai: " << endl;
        cin >> nilai;
        cout << "" << endl;
        cout << "Hasil Konversi: \n" << endl;
        cout << "" << endl;
        cout << nilai << "Cm = " << nilai / 100 << "M\n" << endl;
        cout << nilai << "Cm = " << nilai / 100000 << "Km\n" << endl;
        break;

    case 4:
        cout << "Terimakasih sudah mencoba program ini \n" << endl;
        break;
    
    default:
    cout << "Pilihan tidak valid!\n\n";
        break;
    } 
    
    while (pilihan != 4);

    return 0;
}