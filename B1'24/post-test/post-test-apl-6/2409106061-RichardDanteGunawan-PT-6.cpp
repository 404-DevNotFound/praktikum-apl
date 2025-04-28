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

const int Max = 50;
const int maxregis = 10;
pengunjung pgj[Max];
int isi = 0;

void Tambah(pengunjung pgj[], int &isi) {
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

void Tampil(pengunjung pgj[], int &isi) {
    cout << "Daftar Pengunjung:\n";
    for (int i = 0; i < isi; i++) {
        cout << "Pengunjung ke-" << i + 1 << ": "
             << pgj[i].nama
             << " | Umur: " << pgj[i].umur
             << " | Tujuan: " << pgj[i].tujuan << endl;
    }
}

void Ubah(pengunjung pgj[], int &isi) {
    int index;
    cout << "Masukkan index pengunjung yang ingin diperbarui: ";
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= isi) {
        int pilihanEdit;
        cout << "Pilih data yang ingin diperbarui:\n";
        cout << "1. Nama\n2. Umur\n3. Tujuan Kunjungan\n";
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
        }
    } else {
        cout << "Index tidak valid!\n";
    }
}

bool Hapus(pengunjung data[], int &jumlah, int idx) {
    if (idx > 0 && idx <= jumlah) {
        for (int i = idx - 1; i < jumlah - 1; i++) {
            data[i] = data[i + 1];
        }
        jumlah--;
        return true;
    }
    return false;
}

void signup(regis rgs[], int index) {
    cout << "=== Signup Akun ===\n";
    cout << "Silahkan masukkan NIM anda: ";
    cin >> rgs[index].nimsignup;
    cin.ignore();
    cout << "Silahkan masukkan nama anda: ";
    getline(cin, rgs[index].usersignup);
    cout << "\nAkun berhasil terdaftar!\n";
}

bool login(regis rgs[], int index) {
    cout << "=== Login Akun ===\n";
    cout << "Silahkan masukkan NIM anda: ";
    cin >> rgs[index].nimlogin;
    cin.ignore();
    cout << "Silahkan masukkan nama Anda: ";
    getline(cin, rgs[index].userlogin);

    if (rgs[index].nimsignup == rgs[index].nimlogin &&
        rgs[index].usersignup == rgs[index].userlogin) {
        cout << "\nLogin berhasil! Selamat datang, " << rgs[index].usersignup << "!\n";
        return true;
    } else {
        cout << "\nLogin gagal! NIM atau Nama tidak sesuai.\n";
        return false;
    }
}

void bubbleSort(pengunjung data[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j].umur < data[j + 1].umur) {
                pengunjung temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
        cout << "\nProses [" << i + 1 << "] : ";
        for (int k = 0; k < n; k++) {
            cout << data[k].umur << " ";
        }
    }
    cout << endl;
}

void insertionSort(pengunjung* data, int panjang)
{
    for (int i = 1; i < panjang; i++)
    {
        pengunjung key = *(data + i);
        int j = i - 1;

        while (j >= 0 && (data + j)->nama > key.nama)
        {
            *(data + j + 1) = *(data + j);
            j = j - 1;
        }
        *(data + j + 1) = key;

        cout << "Tahap ke-" << i << ": ";
        for (int k = 0; k < panjang; k++)
        {
            cout << (data + k)->nama << " ";
        }
        cout << endl;
    }
}


void selectionSort(pengunjung* data, int panjang)
{
    for (int i = 0; i < panjang - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < panjang; j++)
        {
            if ((data + j)->umur < (data + min)->umur)
            {
                min = j;
            }
        }

        pengunjung temp = *(data + i);
        *(data + i) = *(data + min);
        *(data + min) = temp;

        cout << "Tahap ke-" << i + 1 << ": ";
        for (int k = 0; k < panjang; k++)
        {
            cout << (data + k)->umur << " ";
        }
        cout << endl;
    }
}

int main() {
    regis rgs[maxregis];

    signup(rgs, 0);

    int counter = 0;
    while (counter < 3) {
        if (login(rgs, 0)) {
            break;
        }
        counter++;
    }

    if (counter == 3) {
        cout << "Anda telah mencoba login sebanyak 3 kali. Program berhenti.\n";
        return 0;
    }

    int pilihan;
    do {
        cout << "\n==== Silahkan pilih aksi yang ingin dilakukan! ====\n";
        cout << "1. Tambah Data Pengunjung\n";
        cout << "2. Lihat Data Pengunjung\n";
        cout << "3. Perbarui Data Pengunjung\n";
        cout << "4. Hapus Data Pengunjung\n";
        cout << "5. Urutkan Data Pengunjung berdasarkan Umur (Descending/bubblesort)\n";
        cout << "6. Urutkan Data Pengunjung berdasarkan Nama (Ascending/insertionsort)\n";
        cout << "7. Urutkan Data Pengunjung berdasarkan Umur (Aescending/selectionsort)\n";
        cout << "8. Exit\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                if (isi < Max) {
                    Tambah(pgj, isi);
                } else {
                    cout << "Daftar pengunjung sudah penuh!\n";
                }
                break;
            case 2:
                if (isi == 0) {
                    cout << "Daftar pengunjung masih kosong!\n";
                } else {
                    Tampil(pgj, isi);
                }
                break;
            case 3:
                if (isi == 0) {
                    cout << "Belum ada pengunjung untuk diperbarui!\n";
                } else {
                    Tampil(pgj, isi);
                    Ubah(pgj, isi);
                }
                break;
            case 4:
                if (isi == 0) {
                    cout << "Tidak ada data pengunjung untuk dihapus!\n";
                } else {
                    Tampil(pgj, isi);
                    int idx;
                    cout << "Masukkan index pengunjung yang ingin dihapus: ";
                    cin >> idx;
                    cin.ignore();
                    if (Hapus(pgj, isi, idx)) {
                        cout << "Data pengunjung berhasil dihapus!\n";
                    } else {
                        cout << "Index tidak valid!\n";
                    }
                }
                break;
            case 5:
                if (isi == 0) {
                    cout << "Tidak ada data pengunjung untuk diurutkan!\n";
                } else {
                    bubbleSort(pgj, isi);
                    cout << "\nData pengunjung setelah diurutkan (Descending):\n";
                    Tampil(pgj, isi);
                }
                break;
            case 6:
                if (isi == 0) {
                    cout << "Tidak ada data pengunjung untuk diurutkan!\n";
                } else {
                    insertionSort(pgj, isi);
                    cout << "\nData pengunjung setelah diurutkan (Ascending):\n";
                    Tampil(pgj, isi);
                }
                break;
            case 7:
                if (isi == 0) {
                    cout << "Tidak ada data pengunjung untuk diurutkan!\n";
                } else {
                    selectionSort(pgj, isi);
                    cout << "\nData pengunjung setelah diurutkan (Ascending):\n";
                    Tampil(pgj, isi);
                }
                break;
            case 8:
                cout << "Terima kasih telah menggunakan program ini!\n";
                return 0;
            default:
                cout << "Pilihan tidak valid, silahkan coba lagi!\n";
                break;
        }
    } while (true);

    return 0;
}
