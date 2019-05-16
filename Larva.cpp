#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#define D 256  //nilai maksimal

using namespace std;
void gotoxy(int x, int y)  //untuk matriks
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void pushc(string stack[], int *top, string value)
{
    stack[*top] = value;
}

void pushi(int stack[], int *top, int *value)
{
    stack[*top]=*value;
}

int jumlah;  //untuk kondisi
struct pembelian
{
    string kode[D],nama[D];
    int stok[D],harga[D];
    long int total[D],bayar[D],kembali[D],sisa[D];
    int top=0;
    int jumlah[D],jual;
}beli;

struct jualan
{
    string kode[D]={"SE01","SE02","SE03","SE04","SE05"};
    string nama[D]={"Vans Old Skool BW","Vans Authentic BW","Vans Sk8 Hi BW","Vans Slip on BW","Vans Slip on Checkerboard"};
    int harga[D]={750000,650000,750000,650000,750000};
    int stok[D]={200,200,150,150,100};
    int top=5;
}jual;

void pesan();
void welcome();

void menu_sepatu()
{
    system("cls");
    cout<<setw(53)<<"Selamat Datang di Streetbae Store "<<endl;
    cout<<"==================================================================="<<endl;
    gotoxy(3,2); cout<<"Kode";
    gotoxy(20,2);cout<<"Nama Sepatu";
    gotoxy(58,2);cout<<"Harga"<<endl;
     cout<<"==================================================================="<<endl;
    for (int i=0;i<jual.top;i++)
    {
        gotoxy(3,4+i);cout<<jual.kode[i];
        gotoxy(20,4+i);cout<<jual.nama[i];
        gotoxy(58,4+i);cout<<jual.harga[i];
    }
    cout<<endl;
     cout<<"==================================================================="<<endl;
}

int pengecekan(char cek[])
{
    int temp,c=-1;

    for(int i=0;i<jual.top;i++)
        {
            for (int j=0;j<strlen(cek);j++)
            {
                if(jual.kode[i][j]==cek[j])
                {
                    temp=1;
                }
                else
                {
                    temp=0;
                    break;
                }
            }
            if(temp==1)
            {
                c=i;
                return c;
            }
        }
        if(temp==0)
        {
            return c;
        }
}

void pemesanan()
{
    int c,total;
    char kode[D];
    cout<<"Masukkan Kode Sepatu     : ";cin>>kode;
    for(int i=0;i<kode[i];i++)
    {
        kode[i]=toupper(kode[i]);  //auto kapital
    }

    if (strlen(kode)==4)
{
    c=pengecekan(kode);
    if(c>=0)
    {
        jumlah:
            cout<<"Jumlah Pesanan           : ";cin>>jumlah;
        if(jumlah<=0)
        {
            cout<<"Jumlah Pesanan Yang Anda Masukan Salah";
            getch();
            goto jumlah;
        }
        else
        {
            pushc(beli.kode, &beli.top, kode);
            pushc(beli.nama, &beli.top, jual.nama[c]);
            pushi(beli.stok, &beli.top, &jual.stok[c]);
            pushi(beli.harga, &beli.top, &jual.harga[c]);
            pushi(beli.jumlah, &beli.top, &jumlah);
            beli.top++;
            beli.jual++;

            cout<<"Sepatu Sukses di Masukan ke Daftar Pesanan";
            getch();
        }
    }
}
    else
        {
        cout<<"Kode Yang Anda Masukan Salah";
        getch();
        }
}

void mengurangi_pesanan()
{
    int n;
        cout<<endl;
        cout<<"Tekan 1 untuk menghapus pesanan terakhir     : ";cin>>n;
        if(beli.top>0)
        {
            cout<<"Sukses Menghapus Pesanan Terakhir."<<endl;
            getch();
            beli.top--;
        }
        else
        {
            cout<<"Maaf, Anda tidak mempunyai pesanan"<<endl;
            return;
        }

    if(n!=1)
    {
        return;
    }
}

void tabel_belanjaan()
{
    system("cls");
    cout<<"======================================================================";
    gotoxy(3,1); cout<<"Kode";
    gotoxy(15,1);cout<<"Nama Sepatu";
    gotoxy(34,1);cout<<"Jumlah";
    gotoxy(48,1);cout<<"Harga";
    gotoxy(62,1);cout<<"Total"<<endl;
    cout<<"======================================================================"<<endl;
    for (int i=0;i<beli.top;i++)
    {
        gotoxy(3,3+i);cout<<beli.kode[i];
        gotoxy(15,3+i);cout<<beli.nama[i];
        gotoxy(36,3+i);cout<<beli.jumlah[i];
        gotoxy(48,3+i);cout<<beli.harga[i];
        gotoxy(62,3+i);cout<<beli.jumlah[i]*beli.harga[i];
    }
    cout<<endl;
    cout<<"======================================================================"<<endl;
}

void pembayaran()
{
    int total=0, kembalian, bayar, tambahan, tmbh, z;
    tabel_belanjaan();
    for(int i=0;i<beli.top;i++)
    {
        total=total+(beli.harga[i]*beli.jumlah[i]);
    }
    if(beli.top>0){
        gotoxy(38,beli.top+4);cout<<"Total Pembelian"<<"         "<<total<<endl;
        gotoxy(38,beli.top+5);cout<<"Bayar"<<"                   ";cin>>bayar;
    kembalian=bayar-total;
        if (kembalian>0)
     {
        gotoxy(38,beli.top+6);cout<<"Kembalian"<<"               "<<kembalian<<endl;
        getch();
        cout<<"======================================================================"<<endl;
        cout<<"            Terima Kasih Telah Berkunjung ke Streetbae Store"<<endl;
        cout<<"                              Have A Good Day ;) "<<endl;
        getch();
        beli.top=0;
        welcome();
     }
     else if(kembalian==0)
     {
        gotoxy(38,beli.top+6);cout<<"-------------------------------- "<<endl;
        gotoxy(47,beli.top+7);cout<<"Uang Anda Pas "<<endl;
        gotoxy(38,beli.top+8);cout<<"-------------------------------- "<<endl;
        getch();
        cout<<"======================================================================"<<endl;
        cout<<"            Terima Kasih Telah Berkunjung ke Streetbae Store"<<endl;
        cout<<"                              Have A Good Day ;) "<<endl;
        getch();
        beli.top=0;
        welcome();
     }
     else if (kembalian<0)
     {
         gotoxy(38,beli.top+6);cout<<"-------------------------------- "<<endl;
         gotoxy(47,beli.top+7);cout<<"Uang Anda Kurang "<<endl;
         gotoxy(38,beli.top+8);cout<<"-------------------------------- "<<endl;

         getch();
         gotoxy(38,beli.top+9);cout<<"Tambahan"<<"                ";cin>>tambahan;
         tmbh=bayar+tambahan;
         z=tmbh-total;
         beli.top=0;
         if(tmbh>total)
         {
             gotoxy(38,beli.top+11);cout<<"Kembalian"<<"               "<<z;
             getch();
             cout<<endl;
            cout<<"======================================================================"<<endl;
            cout<<"            Terima Kasih Telah Berkunjung ke Streetbae Store"<<endl;
            cout<<"                              Have A Good Day ;) "<<endl;
            getch();
            welcome();
         }
         else if(tmbh==total)
         {
             gotoxy(38,beli.top+11);cout<<"-------------------------------- "<<endl;
             gotoxy(47,beli.top+12);cout<<"Uang Anda Pas "<<endl;
             gotoxy(38,beli.top+13);cout<<"-------------------------------- "<<endl;
             getch();
            cout<<"======================================================================"<<endl;
            cout<<"            Terima Kasih Telah Berkunjung ke Streetbae Store"<<endl;
            cout<<"                              Have A Good Day ;) "<<endl;
            getch();
            welcome();
         }
     }
     getch();
     pesan();}
    else
    {
        cout<<"Pesanan Masih Kosong "<<endl;
        getch();
        welcome();
    }

}

void pesan()
{
    int kode, pil;
    awal:
    system("cls");
    menu_sepatu();
    cout<<"1. Buat Pesanan "<<endl;
    cout<<"2. Mengurangi Pesanan "<<endl;
    cout<<"3. Pesanan Ku"<<endl;
    cout<<"4. Kembali ke Menu Utama"<<endl;
    cout<<"==================================================================="<<endl;
    cout<<"Pilihan      : "; cin>>pil;
    if(pil==1)
    {
        system("cls");
        menu_sepatu();
        pemesanan();
        goto awal;
    }
    else if(pil==2)
    {
        mengurangi_pesanan();
        goto awal;
    }
    else if(pil==3)
    {
        tiga :
        system("cls");
        tabel_belanjaan();
        cout<<"1. Tambah/Kurangi Pesanan "<<endl;
        cout<<"2. Bayar Pesanan "<<endl;
        cout<<"======================================================================"<<endl;
        cout<<"Masukan Pilihan : ";cin>>kode;
        if(kode==1)
        {
            goto awal;
        }
        else if(kode==2)
        {
            pembayaran();
        }
        else
        {
            goto tiga;
        }
    }
    else if(pil==4)
    {
        welcome();
    }
    else
    {
        getch();
        goto awal;
    }
}

int cek(char cek[])
{
    int sama=0,beda=0;
    int temp;
    for(int i=0;i<jual.top;i++)
        {
            for (int j=0;j<strlen(cek);j++)
            {
                if(jual.kode[i][j]==cek[j])
                {
                    temp=1;
                }
                else
                {
                    temp=0;
                    break;
                }
            }
            if(temp==1)
            {
                sama++;
            }
            else
            {
                beda++;
            }
        }
        if(sama==0)
        {
            return sama;
        }
}

void tambah_menu()
{
    int c,harga,stok,i;
    char pil,kode[D], nama[D],in;
    p :
    system("cls");
for (i=1; i<=3; i++)
{
string pass ;
        cout<<"==================================================================="<<endl;
        cout<<"       Silakan Masukan Password Untuk Mengakses Menu Tersebut "<<endl;
        cout<<"==================================================================="<<endl;
        cout << "Password : ";
        in = _getch();
        while(in != 13) //13 pada ASCII = ENTER
        {
            pass.push_back(in);
            cout << '*';
            in = _getch();
            i++;
        }

    if (pass == "ikbal123")
    {
    awal:
    system("cls");
    cout<<"==================================================================="<<endl;
    cout<<setw(42)<<"MENAMBAH MENU "<<endl;
    cout<<"==================================================================="<<endl;
    cout<<"Masukkan Kode            : ";cin>>kode;
    for(int i=0;i<kode[i];i++)
    {
    kode[i]=toupper(kode[i]);  //auto kapital
    }
    if (strlen(kode)==4)
    {
    fflush(stdin);
    c=cek(kode);

    if(c==0)
    {
        cout<<"Masukkan Nama Sepatu     : ";cin.getline(nama,256);
        stok:
        cout<<"Stok                     : ";cin>>stok;
         if(stok<=0)
                {
                    cout<<"Stok harus lebih dari 0 !!"<<endl;
                    getch();
                    goto stok;
                }
            harga:
                cout<<"Masukkan Harga Sepatu    : ";cin>>harga;
                if(harga<=0)
                {
                    cout<<"Harga yang anda masukan salah !!"<<endl;
                    getch();
                    goto harga;
                }
            pushc(jual.kode,&jual.top,kode);
            pushc(jual.nama,&jual.top,nama);
            pushi(jual.harga,&jual.top,&harga);
            pushi(jual.stok,&jual.top,&stok);
            jual.top++;
            cout<<endl;
            cout<<"Sukses Menambah Menu"<<endl;
        }
        else
        {
            cout<<"Kode Telah Digunakan, Gunakan Kode Lain"<<endl;
            getch();
            system("cls");
            goto awal;
        }
    }
    else
    {
        cout<<"Kode Harus Berjumlah 4 digit !!!"<<endl;
        getch();
        goto awal;
    }
}
    else
    {
         cout << "\n\nMaaf Password yang Anda Masukan Salah !!!\n\n";
         getch();
         goto p;
    }
}
}

void hapus_menu()
{
    int i,n;
    char in;
    string pass;
    p:
    system("cls");
    cout<<"==================================================================="<<endl;
    cout<<"       Silakan Masukan Password Untuk Mengakses Menu Tersebut "<<endl;
    cout<<"==================================================================="<<endl;
    cout << "Password : ";
    in = _getch();
    while(in != 13) //13 pada ASCII = ENTER
    {
       pass.push_back(in);
       cout << '*';
       in = _getch();
       i++;
    }
    if (pass == "ikbal123")
    {
        do
        {
        system("cls");
        cout<<"Tekan 1 Untuk Menghapus Menu Paling Bawah : ";cin>>n;
        if(jual.top>0)
        {
            cout<<"Sukses Mengurangi Menu"<<endl;
            getch();
            jual.top--;
            welcome();
        }
        else
        {
            cout<<"Tidak ada Menu yang tersedia"<<endl;
            return;
        }
        } while(n==0);

        if(n!=1)
        {
            return;
        }
    }
    else
    {
         cout << "\n\nMaaf Password yang Anda Masukan Salah !!!\n\n";
         getch();
         goto p;
    }
}

void data_penjualan()
{
    int sisa,i;
    char in, kode[D];
    long int jualan,total_penj;
     p :
    system("cls");
for (i=1; i<=3; i++)
{
        string pass ;
        cout<<"==================================================================="<<endl;
        cout<<"       Silakan Masukan Password Untuk Mengakses Menu Tersebut "<<endl;
        cout<<"==================================================================="<<endl;
        cout << "Password : ";
        in = _getch();
        while(in != 13) //13 pada ASCII = ENTER
        {
            pass.push_back(in);
            cout << '*';
            in = _getch();
            i++;
        }

    if (pass == "ikbal123")
    {
    system("cls");
    cout<<"----------------------------------------------------------------------";
    gotoxy(1,1); cout<<"Kode";
    gotoxy(10,1);cout<<"Nama Sepatu";
    gotoxy(27,1);cout<<"Stok";
    gotoxy(33,1);cout<<"Terjual";
    gotoxy(43,1);cout<<"Sisa";
    gotoxy(50,1);cout<<"Harga";
    gotoxy(60,1);cout<<"Penjualan";
    cout<<endl;
    cout<<"----------------------------------------------------------------------";
    for (int i=0;i<beli.jual;i++)
    {
        gotoxy(1,3+i);cout<<beli.kode[i];
        gotoxy(10,3+i);cout<<beli.nama[i];
        gotoxy(27,3+i);cout<<beli.stok[i];
        gotoxy(36,3+i);cout<<beli.jumlah[i];
        beli.sisa[i]=beli.stok[i]-beli.jumlah[i];
        gotoxy(43,3+i);cout<<beli.sisa[i];
        gotoxy(50,3+i);cout<<beli.harga[i];
        jualan=jumlah*beli.harga[i];
        gotoxy(63,3+i);cout<<jualan;
    }
    cout<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    getch();
}
else
    {
         cout << "\n\nMaaf Password yang Anda Masukan Salah !!!\n\n";
         getch();
         goto p;
    }
}
}

void welcome()
{
     int pil;
    awal:
    system("cls");
    cout<<setw(53)<<"Selamat Datang di Streetbae Store "<<endl;
    cout<<"==================================================================="<<endl;
    cout<<"1. Pesan Menu Sepatu "<<endl;
    cout<<"2. Tambah Menu Sepatu "<<endl;
    cout<<"3. Hapus Menu Sepatu "<<endl;
    cout<<"4. Data Penjualan "<<endl;
    cout<<"==================================================================="<<endl;
    cout<<"Masukan Pilihan      : ";cin>>pil;
    if(pil==1)
    {
        pesan();
        goto awal;
    }
    else if(pil==2)
    {
        system("cls");
        tambah_menu();
        getch();
        goto awal;
    }
    else if(pil==3)
    {
        system("cls");
        hapus_menu();
        goto awal;
    }
    else if(pil==4)
    {
        system("cls");
        data_penjualan();
        goto awal;
    }
    else
    {
        goto awal;
    }
}

main()
{
  welcome();
}


