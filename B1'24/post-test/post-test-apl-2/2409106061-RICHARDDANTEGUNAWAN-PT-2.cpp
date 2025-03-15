#include <iostream>
using namespace std;

#define Max 50
string nama[Max];
int umur[Max];
string tujuan[Max];
int isi = 0;

int main() {
    int nimsignup, nimlogin;
    string usersignup, userlogin;
    
    cout << "=== Signup Akun ===" << endl;
    cout << "Silahkan masukkan NIM anda: ";
    cin >> nimsignup;
    cin.ignore();
    
    cout << "Silahkan masukkan nama anda: ";
    getline(cin, usersignup);
    
    cout << "\nAkun berhasil terdaftar!\n" << endl;
    
    int counter = 0;
    while (counter < 3) {
        cout << "=== Login Akun ===" << endl;
        cout << "Silahkan masukkan NIM anda: ";
        cin >> nimlogin;
        cin.ignore();
        
        cout << "Silahkan masukkan nama Anda: ";
        getline(cin, userlogin);
        
        if (nimsignup == nimlogin && usersignup == userlogin) {
            cout << "\nLogin berhasil! Selamat datang, " << usersignup << "!\n" << endl;
            break;
        } else {
            cout << "\nLogin gagal! NIM atau Nama tidak sesuai.\n" << endl;
            counter++;
        }
    }
    
    if (counter == 3) {
        cout << "Anda telah mencoba login sebanyak 3 kali. Program berhenti." << endl;
        return 0;
    }
    
    int pilihan;
    do {
        cout << "\n==== Silahkan pilih aksi yang ingin dilakukan! ==== " << endl;
        cout << "1. Tambah Data Pengunjung" << endl;
        cout << "2. Lihat Data Pengunjung" << endl;
        cout << "3. Perbarui Data Pengunjung" << endl;
        cout << "4. Hapus Data Pengunjung" << endl;
        cout << "5. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1:
                if (isi < Max) {
                    cout << "Silahkan masukkan nama pengunjung: ";
                    getline(cin, nama[isi]);

                    cout << "Masukkan umur pengunjung: ";
                    cin >> umur[isi];
                    cin.ignore();

                    cout << "Masukkan tujuan kunjungan: ";
                    getline(cin, tujuan[isi]);

                    isi++;
                    cout << "Data pengunjung berhasil ditambahkan!\n" << endl;
                } else {
                    cout << "Daftar pengunjung sudah penuh!\n" << endl;
                }
                break;
            
            case 2:
                if (isi == 0) {
                    cout << "Daftar pengunjung masih kosong!\n" << endl;
                } else {
                    cout << "Daftar Pengunjung" << endl;
                    for (int i = 0; i < isi; i++) {
                        cout << "Pengunjung ke-" << i + 1 << ": " << nama[i] 
                             << " | Umur: " << umur[i] 
                             << " | Tujuan: " << tujuan[i] << endl;
                    }
                }
                break;
            
            case 3:
                if (isi == 0) {
                    cout << "Belum ada pengunjung untuk diperbarui!\n" << endl;
                } else {
                    int index;
                    cout << "Masukkan index pengunjung yang ingin diperbarui: ";
                    cin >> index;
                    cin.ignore();
                    if (index > 0 && index <= isi) {
                        int pilihanEdit;
                        cout << "Pilih data yang ingin diperbarui:" << endl;
                        cout << "1. Nama" << endl;
                        cout << "2. Umur" << endl;
                        cout << "3. Tujuan Kunjungan" << endl;
                        cout << "Pilih: ";
                        cin >> pilihanEdit;
                        cin.ignore();

                        switch (pilihanEdit) {
                            case 1:
                                cout << "Masukkan nama baru: ";
                                getline(cin, nama[index - 1]);
                                cout << "Nama berhasil diperbarui!\n";
                                break;
                            case 2:
                                cout << "Masukkan umur baru: ";
                                cin >> umur[index - 1];
                                cin.ignore();
                                cout << "Umur berhasil diperbarui!\n";
                                break;
                            case 3:
                                cout << "Masukkan tujuan kunjungan baru: ";
                                getline(cin, tujuan[index - 1]);
                                cout << "Tujuan kunjungan berhasil diperbarui!\n";
                                break;
                            default:
                                cout << "Pilihan tidak valid!\n";
                                break;
                        }
                    } else {
                        cout << "Index tidak valid!\n" << endl;
                    }
                }
                break;
            
            case 4:
                if (isi == 0) {
                    cout << "Tidak ada data pengunjung untuk dihapus!\n" << endl;
                } else {
                    int index;
                    cout << "Masukkan index pengunjung yang ingin dihapus: ";
                    cin >> index;
                    if (index > 0 && index <= isi) {
                        for (int i = index - 1; i < isi - 1; i++) {
                            nama[i] = nama[i + 1];
                            umur[i] = umur[i + 1];
                            tujuan[i] = tujuan[i + 1];
                        }
                        isi--;
                        cout << "Data pengunjung berhasil dihapus!\n" << endl;
                    } else {
                        cout << "Index tidak valid!\n" << endl;
                    }
                }
                break;
            
            case 5:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                return 0;
            
            default:
                cout << "Pilihan tidak valid, silahkan coba lagi!\n" << endl;
                break;
        }
    } while (true);
    
    return 0;
}
