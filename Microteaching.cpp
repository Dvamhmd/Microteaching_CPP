#include <iostream>
#include <conio.h>

using namespace std;

bool program_start = true;
bool terdeteksi_admin = false;
bool lanjut_admin = false;
bool lanjut_user = false;
bool terdeteksi_user = false;
bool bisa_daftar = true;

string nama_kk[2][5] = {
							{"Jaka","Wiwid","Zinan"},
							{"Ferdian","Galih","Ahmad"}
						};
						
string opsi_awal[3] = {"Masuk","Daftar","Keluar"};
string opsi_admin[6] = {"Tampilkan","Tambah","Edit","Hapus","Pengajuan","Log Out"};
string opsi_user[3] = {"Tampilkan","Ajukan","Log_Out"};

string id_admin[4] = {"ateng","komeng","samsul","1"};
string id_user[10] = { "2"};
string pw_admin[4] = {"1234","1234","1234","1"};
string pw_user[10] = {"2"};

string pengajuan_nama_kk[10];
string pengajuan_nomor_rt[10];


string pilihan_awal, pilihan_admin, pilihan_user;
string id, nomor_rt, nama_baru, edit, hapus;
string password;						

int rt;
int total_warga[2] = {3,3};
int total_pengajuan;
int batas_akun, total_akun;
char karakter;


void garis1(){
	cout<<"\t\t\t======================================================";
}

void garis2(){
	cout<<"\t\t\t------------------------------------------------------";
}

void header(){
	garis1();cout<<endl;
	cout<<"\t\t\t||\t\tPROGRAM DATA PENDUDUK\t\t    ||"<<endl;
	garis1();cout<<endl;	
}

void tampilkan(){
	system("cls");
	header();
	for(int rt=0; rt<2; rt++){
		cout<<"\t\t\t\t\t\t"<<"RT 00"<<rt+1<<endl;
		garis2();cout<<endl;
		for(int nama=0; nama<total_warga[rt]; nama++){
			cout<<"\t\t\t"<<nama+1<<". "<<nama_kk[rt][nama];
			cout<<endl;
		}
		garis2();cout<<endl;
	}
	cout<<endl<<"\t\t\t";
	system("pause");system("cls");
}

int tambah(){
	system("cls");	
	header();
	for(int rt=0; rt<2; rt++){
		cout<<"\t\t\t\t\t\t"<<"RT 00"<<rt+1<<endl;
		garis2();cout<<endl;
		for(int nama=0; nama<total_warga[rt]; nama++){
			cout<<"\t\t\t"<<nama+1<<". "<<nama_kk[rt][nama];
			cout<<endl;
		}
		garis2();cout<<endl;
	}	
	cout<<"\t\t\tMasukkan RT yang ingin ditambah : ";cin>>nomor_rt;
	if (nomor_rt == "1" || nomor_rt == "001"){
		rt = 0;
	}else if (nomor_rt == "2" || nomor_rt == "002"){
		rt = 1;
	}else{
		cout<<"\t\t\tNomor RT tidak Valid!!!";
		system("cls");
	}
	cout<<"\t\t\tMasukkan Nama KK baru : ";cin>>nama_baru;
	nama_kk[rt][total_warga[rt]] = nama_baru;
	total_warga[rt]++;
	system("cls");
	
	return total_warga[rt];
}

void mengedit(){
	system("cls");	
	header();
	for(int rt=0; rt<2; rt++){
		cout<<"\t\t\t\t\t\t"<<"RT 00"<<rt+1<<endl;
		garis2();cout<<endl;
		for(int nama=0; nama<total_warga[rt]; nama++){
			cout<<"\t\t\t"<<nama+1<<". "<<nama_kk[rt][nama];
			cout<<endl;
		}
		garis2();cout<<endl;
	}	
	cout<<"\t\t\tMasukkan Nama yang ingin diedit : ";cin>>edit;
	for (int rt=0; rt<2; rt++){
		for (int nama = 0; nama <total_warga[rt]; nama++){
			if (edit == nama_kk[rt][nama]){
				cout<<"\t\t\tMasukkan Nama pengganti : ";cin>>nama_baru;
				nama_kk[rt][nama] = nama_baru;
			}
		}
	}
	
	system("cls");	
}

int menghapus(){
	system("cls");	
	header();
	for(int rt=0; rt<2; rt++){
		cout<<"\t\t\t\t\t\t"<<"RT 00"<<rt+1<<endl;
		garis2();cout<<endl;
		for(int nama=0; nama<total_warga[rt]; nama++){
			cout<<"\t\t\t"<<nama+1<<". "<<nama_kk[rt][nama];
			cout<<endl;
		}
		garis2();cout<<endl;
	}	
	cout<<"\t\t\tMasukkan RT yang dituju : ";cin>>nomor_rt;
	if (nomor_rt == "1" || nomor_rt == "001"){
		rt = 0;
	}else if (nomor_rt == "2" || nomor_rt == "002"){
		rt = 1;
	}else{
		cout<<"\t\t\tNomor RT tidak Valid!!!";
		system("cls");
	}
	cout<<"\t\t\tMasukkan Nama yang ingin dihapus : ";cin>>hapus;	
	for (int nama = 0; nama <total_warga[rt]; nama++){
		if (hapus == nama_kk [rt][nama]){
			for (int target = nama; target<total_warga[rt]-1; target++){
				nama_kk[rt][target] = nama_kk[rt][target+1];
			}
			total_warga[rt]--;
			break;
		}
	}
	system("cls");
	return total_warga[rt];	
}

int log_out(){
	garis2();cout<<endl;
	cout<<"\t\t\tLog Out Berhasil"<<endl<<endl;
	cout<<"\t\t\t";
	system("pause");cout<<endl<<endl;
	system("cls");
	
	lanjut_admin = false;
	lanjut_user = false;
	
	return lanjut_admin, lanjut_user;	
}

int keluar(){
	garis2();cout<<endl;
	cout<<"\t\t\tTerima Kasih"<<endl<<endl;
	cout<<"\t\t\t";
	system("pause");cout<<endl<<endl;
	system("cls");
	
	program_start = false;
	
	return program_start;	
}

int pengajuan(){
	total_pengajuan = 0;
	system("cls");
	header();cout<<endl;
	cout<<"\t\t\tMasukkan Nama Panggilan Anda\t: ";cin>>pengajuan_nama_kk[total_pengajuan];
	cout<<"\t\t\tMasukkan Nomor RT Rumah Anda\t: ";cin>>pengajuan_nomor_rt[total_pengajuan];
	garis2();cout<<endl;
	cout<<"\t\t\tPengajuan Berhasil"<<endl<<endl;
	cout<<"\t\t\t";
	system("pause");cout<<endl<<endl;
	system("cls");	
	
	total_pengajuan++;	
	return total_pengajuan;
}

void hasil_pengajuan(){
	system("cls");
	header();cout<<endl;
	cout<<"\t\t\tBerikut Pengajuan Baru : "<<endl;
	garis2();cout<<endl;
	if (total_pengajuan == 0){
		cout<<"\t\t\tBelum Ada Pengajuan";cout<<endl;
		garis2();cout<<endl;
		cout<<"\t\t\t";
		system("pause");cout<<endl<<endl;
		system("cls");		
	}else{
		for (int i=0; i<total_pengajuan; i++){
			cout<<"\t\t\t"<<"Pengajuan Ke-"<<i+1<<" : "<<pengajuan_nama_kk[i]<<"\tRT "<<pengajuan_nomor_rt[i];
			cout<<endl;
		}
		cout<<"\t\t\t";
		system("pause");cout<<endl<<endl;
		system("cls");	
	}
}

void menu_admin(){
	header();
	for(int i=0;i<6;i++){
		cout<<"\t\t\t"<<i+1<<". "<<opsi_admin[i]<<endl;		
	}
	garis1();cout<<endl;	
	cout<<"\t\t\tMasukkan Pilihan Anda : ";cin>>pilihan_admin;
	if (pilihan_admin == "1"){
		tampilkan();
	}else if (pilihan_admin == "2"){
		tambah();
	}else if (pilihan_admin == "3"){
		mengedit();
	}else if(pilihan_admin == "4"){
		menghapus();
	}else if(pilihan_admin == "5"){
		hasil_pengajuan();
	}else if(pilihan_admin == "6"){
		log_out();	
}
	
}

void menu_user(){
	header();
	for(int i=0;i<3;i++){
		cout<<"\t\t\t"<<i+1<<". "<<opsi_user[i]<<endl;		
	}
	garis1();cout<<endl;	
	cout<<"\t\t\tMasukkan Pilihan Anda : ";cin>>pilihan_user;
	if (pilihan_user == "1"){
		tampilkan();
	}else if (pilihan_user == "2"){
		pengajuan();
	}else if (pilihan_user == "3"){
		log_out();
	}
	
}

int masuk(){
	cout<<endl;
	garis2();
	cout<<endl;
	cout<<"\t\t\tMasukkan ID anda\t: ";cin>>id;
	cout<<"\t\t\tMasukkan Password\t: ";
	
	password = "";
	karakter = _getch();
	
	while (karakter != '\r'){
		if (karakter == '\b'){
			if (!password.empty()){
				password.pop_back();
				cout<<"\b \b";
			}
			
		}else{
			password.push_back(karakter);
			cout<< '*';
		}
		karakter = _getch();
	}
	
	cout<<endl;
	
	for (int i = 0; i<4; i++){
		if (id == id_admin[i] && password == pw_admin[i]){
			terdeteksi_admin = true;
			lanjut_admin = true;
			
			garis2();cout<<endl;
			cout<<"\t\t\tLog In Berhasil"<<endl<<endl;
			cout<<"\t\t\t";
			system("pause");cout<<endl<<endl;
			system("cls");
			
			while (terdeteksi_admin && lanjut_admin){
				menu_admin();	
			}

		}else if (id == id_user[i] && password == pw_user[i]){
			terdeteksi_user = true;
			lanjut_user = true;

			garis2();cout<<endl;
			cout<<"\t\t\tLog In Berhasil"<<endl<<endl;
			cout<<"\t\t\t";
			system("pause");cout<<endl<<endl;
			system("cls");

			while (terdeteksi_user && lanjut_user){
				menu_user();
			}
		}
	}
	
	if (terdeteksi_admin == false){
		garis2();cout<<endl;
		cout<<"\t\t\tID atau Password Salah!!!"<<endl<<endl;
		cout<<"\t\t\t";
		system("pause");cout<<endl<<endl;
		system("cls");
	}
	
	return terdeteksi_admin;
}

int daftar() {
    system("cls");
    total_akun = 1;
    batas_akun = 10;


    header(); cout << endl;
    cout << "\t\t\tBuat ID Akun anda\t: ";cin >> nama_baru;

    for (int i = 0; i < batas_akun; i++) {
        if (nama_baru == id_user[i] || nama_baru == id_admin[i]) {
            bisa_daftar = false;
            cout << "\t\t\tID Akun dengan nama ini sudah ada, gunakan nama lain" << endl << endl;
            cout << "\t\t\t";
            system("pause");
            system("cls");
            break;
        }
    }

    if (bisa_daftar) {
        id_user[total_akun] = nama_baru;
        cout<<"\t\t\tBuat Password anda\t: ";cin>>pw_user[total_akun];
        total_akun++;

        cout<<endl;
        garis2();
        cout<<endl;
        cout<<"\t\t\tPendaftaran Berhasil" << endl << endl;
        cout<<"\t\t\t";
        system("pause");
        cout<<endl<<endl;
        system("cls");
    }

    return bisa_daftar ? 0 : 1; // Kembalikan 0 jika pendaftaran berhasil, 1 jika tidak
}





void menu_awal(){
	for (int i=0; i<3; i++){
		cout<<"\t\t\t"<<i+1<<". "<<opsi_awal[i]<<endl;
	}
	garis1();cout<<endl;
	cout<<"\t\t\tMasukkan Pilihan Anda : ";cin>>pilihan_awal;
	if (pilihan_awal == "1"){
		masuk();
	}else if(pilihan_awal == "2"){
		daftar();
	}else if(pilihan_awal == "3"){
		keluar();
	}
}

int main(){
	while(program_start){
		header();
		menu_awal();		
	}

}