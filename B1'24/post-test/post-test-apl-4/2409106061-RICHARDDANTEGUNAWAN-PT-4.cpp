#include <iostream>
using namespace std;

struct pengunjung {
    string nama;
    int umur;
    string tujuan;
};
struct regis {
    string nimlogin, nimsignup;
    string userlogin, usersignup;
};

int isi = 0;
#define Max 50
#define maxregis 10
pengunjung pgj[Max];

void Tambah()
{
     cout << "Silahkan masukkan nama pengunjung: ";
        getline(cin, pgj[isi].nama);

        cout << "Masukkan umur pengunjung: ";
        cin >> pgj[isi].umur;
        cin.ignore();

        cout << "Masukkan tujuan kunjungan: ";
        getline(cin, pgj[isi].tujuan);

        isi++;
        cout << "Data pengunjung berhasil ditambahkan!\n" << endl;
}

void Tampil()
{
      cout << "Daftar Pengunjung" << endl;
        for (int i = 0; i < isi; i++) 
        {
            cout << "Pengunjung ke-" << i + 1 << ": " << pgj[i].nama
                << " | Umur: " << pgj[i].umur 
                << " | Tujuan: " << pgj[i].tujuan << endl;
        }
}

void Ubah()
{
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
                    getline(cin, pgj[index - 1].nama);
                    cout << "Nama berhasil diperbarui!\n";
                    break;
                case 2:
                    cout << "Masukkan umur baru: ";
                    cin >> pgj[index - 1].umur;
                    cin.ignore();
                    cout << "Umur berhasil diperbarui!\n";
                    break;
                case 3:
                    cout << "Masukkan tujuan kunjungan baru: ";
                    getline(cin, pgj[index - 1].tujuan);
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

bool Hapus (pengunjung data [], int &jumlah, int idx){
    if (idx > 0 && idx <= jumlah) {
        for (int i = idx - 1; i < jumlah - 1; i++) {
            data[i] = data[i + 1];
        }
        jumlah--;
        return true;
    } else {
        return false;
    }
}

int main() {
    regis rgs[maxregis];
    
    cout << "=== Signup Akun ===" << endl;
    cout << "Silahkan masukkan NIM anda: ";
    cin >> rgs[0].nimsignup;
    cin.ignore();
    
    cout << "Silahkan masukkan nama anda: ";
    getline(cin, rgs[0].usersignup);
    
    cout << "\nAkun berhasil terdaftar!\n" << endl;
    
    int counter = 0;
    while (counter < 3) {
        cout << "=== Login Akun ===" << endl;
        cout << "Silahkan masukkan NIM anda: ";
        cin >> rgs[0].nimlogin;
        cin.ignore();
        
        cout << "Silahkan masukkan nama Anda: ";
        getline(cin, rgs[0].userlogin);
        
        if (rgs[0].nimsignup == rgs[0].nimlogin && rgs[0].usersignup == rgs[0].userlogin) {
            cout << "\nLogin berhasil! Selamat datang, " << rgs[0].usersignup << "!\n" << endl;
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
    do{
        cout << "\n==== Silahkan pilih aksi yang ingin dilakukan! ==== " << endl;
        cout << "1. Tambah Data Pengunjung" << endl;
        cout << "2. Lihat Data Pengunjung" << endl;
        cout << "3. Perbarui Data Pengunjung" << endl;
        cout << "4. Hapus Data Pengunjung" << endl;
        cout << "5. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
    
        switch (pilihan){
           case 1:
                if (isi < Max) {
                   Tambah();
                } else {
                    cout << "Daftar pengunjung sudah penuh!\n" << endl;
                }
                break;
            case 2:
                if (isi == 0) {
                    cout << "Daftar pengunjung masih kosong!\n" << endl;
                } else {
                    Tampil();
                }
                break;
            case 3:
                if (isi == 0) {
                    cout << "Belum ada pengunjung untuk diperbarui!\n" << endl;
                } else {
                    Tampil();
                    Ubah();
                }
                break;
             case 4:
                if (isi == 0) {
                    cout << "Tidak ada data pengunjung untuk dihapus!\n" << endl;
                } else {
                   Tampil();
                   int idx;
                   cout<< "Masukkan index pengunjung yang ingin dihapus: \n";
                   cin>> idx;
                   
                   if (Hapus (pgj, isi, idx)) {
                       cout<< "Data pengunjung berhasil dihapus!\n"<< endl;
                   } else {
                       cout<< "Index tidak valid!\n" << endl;
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