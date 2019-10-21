#include <iostream>
using namespace std;
int status_login = 0;
int saldo = 10000000;

string ket[6] = {"tersedia","tersedia","tersedia","tersedia","tersedia","tersedia"};
string ket2[5] = {"tersedia","tersedia","tersedia","tersedia","tersedia"};

//Prototype fungsi.
void kendaraan_pilih(char a);
void login();
void main_menu();

//Fungsi login(2).
void login_process(string a) {
    string passw;
    if(a=="admin") {
        do{
            cout << "Password = ";
            cin >> passw;
            if(passw=="admin123") {
                status_login = 1;}
            else{
                cout << "Password salah\n";
            }
        }while(status_login==0);
    } else{
        cout << "Username tidak terdaftar\n";
        login();
    }
}

//Fungsi login.
void login() {
    string usern;    
    cout << "Username = ";
    cin >> usern;
    login_process(usern);
}

//Fungsi seleksi jenis kendaraan. dan menampilkan sesuai dengan jenis yang dipilih.
void submenu(int a) {
    int kosong;
    char pilih_lagi;
    if(a==1) {
        system("clear");
        cout << "-----------------------------------------------------\n";
        cout << "|                      Mobil                        |\n";
        cout << "-----------------------------------------------------\n";
        cout << "|NO.|            Merk          |       Harga        | Ket.\n";
        cout << "-----------------------------------------------------\n";
        cout << "| 1.| Daihatsu Ayla            | Rp. 300000/hari    | " <<  ket[0] << endl;
        cout << "| 2.| Daihatsu Sirion          | Rp. 320000/hari    | " <<  ket[1] << endl;
        cout << "| 3.| Daihatsu Grand New Xenia | Rp. 450000/hari    | " <<  ket[2] << endl;
        cout << "| 4.| Toyota All New Avanza    | Rp. 300000/hari    | " <<  ket[3] << endl;
        cout << "| 5.| Toyota New Rush          | Rp. 500000/hari    | " <<  ket[4] << endl;
        cout << "| 6.| Toyota Alphard           | Rp. 2000000/hari   | " <<  ket[5] << endl;
        cout << "-----------------------------------------------------\n";
        kendaraan_pilih('a');
    } else if(a==2) {
        system("clear");
        cout << "-----------------------------------------------------\n";
        cout << "|                      Motor                        |\n";
        cout << "-----------------------------------------------------\n";
        cout << "|NO.|            Merk          |       Harga        | Ket.\n";
        cout << "-----------------------------------------------------\n";
        cout << "| 1.| Honda Beat               | Rp. 75000/hari     | " <<  ket2[0]  << endl;
        cout << "| 2.| Honda Genio              | Rp. 80000/hari     | " <<  ket2[1]  << endl; ;
        cout << "| 3.| Honda Vario              | Rp. 70000/hari     | " <<  ket2[2]  << endl;;
        cout << "| 4.| Yamaha NMAX              | Rp. 110000/hari    | " <<  ket2[3]  << endl;;
        cout << "| 5.| Yamaha Lexi              | Rp. 100000/hari    | " <<  ket2[4]  << endl;;
        cout << "-----------------------------------------------------\n";
        kendaraan_pilih('b');
    } else if(a==3){
        int tambah_saldo;
        int pilihan_back;
        char acc;
        saldo:
        system("clear");
        cout << "-----------------------------------------------------\n";
        cout << "|                     Isi Saldo                      |\n";
        cout << "-----------------------------------------------------\n\n";
        cout << " Saldo anda                         = " << saldo << endl;
        cout << " Nominal saldo yang ditambahkan     = ";
        cin >> tambah_saldo;
        cout << " Nominal sudah tepat (y/t)          = ";
        cin >>acc;
        if(acc=='y'){
            saldo += tambah_saldo;
            cout << " Saldo anda kini                    = " << saldo << endl << endl;
            pilihan:
            cout << " [1] Isi saldo lagi \n";
            cout << " [2] Kembali ke menu utama\n";
            cout << " Pilih => ";
            cin >> pilihan_back;
            if(pilihan_back==1){
                goto saldo;
            } else if(pilihan_back==2){
                system("clear");
                main_menu();
            } else {
                cout << "Pilihan salah, coba masukan nomor pilihan lagi\n";
                goto pilihan;
            }
        }else if(acc=='t'){
            cout << "Tekan enter untuk mengulangi proses... ";
            cin.get();
            cin.ignore();
            goto saldo;
        }
        
        
    } else if(a>4){
        cout << "Menu nomor. " << a << " tidak ditemukan!\n\n";
        cout << "===> Pilih Lagi ?? (y/t) : ";
        cin >> pilih_lagi;
        if(pilih_lagi=='Y'||pilih_lagi=='y'){
            system("clear");
            main_menu();
        }
    }
}

//Fungsi menampilkan menu.
void main_menu(){
    int pilih;
    cout << "-----------------------------------------------------\n";
    cout << "--     Selamat Datang di Program Rental Mobil      --\n";
    cout << "-----------------------------------------------------\n";
    cout << "|                        MENU                       |\n";
    cout << "-----------------------------------------------------\n";
    cout << "| 1. |                  Mobil                       |\n"; 
    cout << "| 2. |                  Motor                       |\n";
    cout << "| 3. |                  Saldo                       |\n";
    cout << "| 4. |                  Keluar                      |\n";
    cout << "-----------------------------------------------------\n";
    cout << "Pilih => ";
    cin >> pilih;
    submenu(pilih);
}

//Fungsi pilihan setelah transaksi.
void memilih(int a){
    int pilih;
    cout << "[1] Pilih lagi\n";
    cout << "[2] Kembali ke menu utama\n";
    cout << "Pilih => ";
    cin >> pilih; 
    if(pilih==1){
        if(a==1){
            submenu(1);
        } else if(a==2){
            submenu(2);
        }
    }else if(pilih==2){
        system("clear");
        main_menu();
    }else{
        cout << "------Input salah------\n\n";
        if(a==1){
            memilih(1);
        }else {
            memilih(2);
        }
    }
}

void pengurangan_saldo(int a, int b,int c){
    if(saldo>a*b){
        saldo -= a * b;
        if(c==1){
            ket[c] = "tidak tersedia";
        } else if(c==2){
            
            ket2[c] = "tidak tersedia";
        }
    } else {
        cout << "\n---------------Saldo Tidak Mencukupi-----------------\n\n";
    }
}

// Fungsi Transaksi setelah memilih no.kendaraan yang diinginkan.
void transaksi(int a, int b, int c,int d){
    string bayar;
    cout << "-----------------------------------------------------\n";
    cout << "Total biaya rental                       = Rp." << a * b << endl;
    cout << "Bayar ? (y/t)                            = ";
    cin >> bayar;
    if(bayar=="Y"||bayar=="y"){
        pengurangan_saldo(a,b,d);    
        
        cout << "-----------------------------------------------------\n";
        cout << "Sisa saldo Anda kini                     = Rp." << saldo << endl;
        cout << "-----------------------------------------------------\n\n";
        if(d==1){
            memilih(1);
        } else if(d==2){
            memilih(2);
        }
    } else{
        if(d==1){
            memilih(1);
        }else if(d==2){
            memilih(2);
        }
    }
}

// Fungsi Memilih no.kendaraan
void kendaraan_pilih(char a){
    int b, lama_rental;
    cout << "Masukan no. kendaraan yang Anda inginkan => ";
    cin >> b;
    if(a=='a'){
        if(ket[b-1]=="tidak tersedia"||b>6){
            cout << "Kendaraan yang anda pilih sedang tidak tersedia\n";
            memilih(1);
        }else {
            cout << "Untuk berapa hari ?                      => ";
            cin >> lama_rental;        
                if(b==1){        
                    transaksi(300000, lama_rental,0,1);
                }else if(b==2){
                    transaksi(320000, lama_rental,1,1);
                }else if(b==3){
                    transaksi(450000, lama_rental,2,1);
                }else if(b==4){
                    transaksi(300000, lama_rental,3,1);
                }else if(b==5){
                    transaksi(500000, lama_rental,4,1);
                }else if(b==6){
                    transaksi(2000000, lama_rental,5,1);
                }
        }
    }

    if(a=='b'){
        if(ket2[b-1]=="tidak tersedia"||b>5){
            cout << "Kendaraan yang anda pilih sedang tidak tersedia\n";
            memilih(2);
        }else {
            cout << "Untuk berapa hari ?                      => ";
            cin >> lama_rental;        
                if(b==1){        
                    transaksi(75000, lama_rental,0,2);
                }else if(b==2){
                    transaksi(80000, lama_rental,1,2);
                }else if(b==3){
                    transaksi(70000, lama_rental,2,2);
                }else if(b==4){
                    transaksi(110000, lama_rental,3,2);
                }else if(b==5){
                    transaksi(100000, lama_rental,4,2);
                }
        }
    }
}

//Fungsi utama
int main(){
    int pilih;
    system("clear");
    cout << "-Login\n";
    login();
    if(status_login==1){
        system("clear");
        main_menu();
    }
    cout << endl;
    cout << "-----------------------------------------------------\n";
    cout << "---      TERIMA KASIH ATAS KUNJUNGAN ANDA         ---\n";
    cout << "-----------------------------------------------------\n";
    cout << "Tekan enter untuk melanjutkan...\n";
    cin.get();
    cin.ignore();
    return 0;
}
