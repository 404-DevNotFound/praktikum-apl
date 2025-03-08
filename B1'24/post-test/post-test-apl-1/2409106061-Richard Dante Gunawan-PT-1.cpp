#include <iostream>

using namespace std;

int main (){
    int nim = 6061;
    int coba = 0;
    while (coba <= 2){
        cout<<"Program Atm Sederhana \n";
        cout<<"Silahkan login terlebih dahulu menggunakan 4 digit nim anda! \n";
        cin>>nim;
        if (nim == 6061){
           do{
                int aksi;
                double saldo;
                cout<<"Selamat anda berhasil login!\n";
                cout<<"Silahkan pilih transaksi apa yang anda ingin lakukan!\n";
                cout<<" (1) Setor Tunai\n (2) Cek Saldo\n (3) Tarik Tunai\n (4) Keluar\n";
                cin>> aksi;
                if (aksi ==1){
                int setor;
                cout<<"Silahkan input nominal yang ingin disetor: ";
                cin>> setor;
                saldo += setor;
                } 
                else if (aksi == 2){
                    cout<<"Sisa saldo anda kini: "<< saldo<< endl;
                }
                else if (aksi == 3){
                    int tarik;
                    cout<<"Silahkan input nominal yang ingin ditarik: ";
                    cin>> tarik;
                    if (tarik < saldo){
                        saldo -= tarik;
                    }
                    else {
                        cout<<"Maaf saldo anda tidak mencukupi\n";
                    }
                }
                else if (aksi ==4){
                    return 0;
                }
           } while (true);
        }
        else{
            cout<<"Maaf password anda salah! Silahkan coba kembali! \n";
        }
        coba +=1;
    }
}