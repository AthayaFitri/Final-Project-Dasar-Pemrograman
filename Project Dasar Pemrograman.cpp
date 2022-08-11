/* Project Akhir
	APLIKASI "AT THE TICKET"
	Oleh:
	Dhea Intan Charisma [124210061]
	Athaya Rizqia Fitriani [124210071] */
	
#include <iostream>  // header standar untuk input output dalam bahasa C++
#include <conio.h>   // header berfungsi untuk menampilkan hasil antarmuka kepada user -> untuk fungsi getch()
#include <unistd.h>  // header untuk fungsi sleep(x sekon) untuk mem-pause program dalam x sekon
using namespace std;

struct keberangkatan{
	string tanggal;
	string bulan;
	string kodebulan;
	int	tahun;
};

struct data_penumpang{
	string nama;
	char nik[16];
	keberangkatan waktu;
	char kode;
};

struct pesawat{
	string maskapai;
	string rute;
	string kelas;
	string kodekelas;
	string berangkat;
	string tiba;
	int harga;
	data_penumpang penumpang;
};

struct kereta_api{
	string kereta;
	string rute;
	string kelas;
	string kodekelas;
	string berangkat;
	string tiba;
	int harga;
	data_penumpang penumpang;
};

struct akun{
	string username;
	string password;
	pesawat P[1000];
	kereta_api K[1000];
	int jml;	  // jumlah pesanan (jumlah pesanan tiket pesawat + kereta)
	int jumlahps; // jumlah pesanan tiket pesawat		
	int jumlahka; // jumlah pesanan tiket kereta
}pemesan[1000];

int i,n; // n untuk jumlah daftar akun pemesan
int p,tambahps,hargaP; 
int k,tambahka,hargaK;

void exit(){
	cout << "============================================="<<endl;
	cout << "|                                           |"<<endl;
	cout << "|         Aplikasi Pemesanan Tiket          |"<<endl;
	cout << "|             'AT THE TICKET'               |"<<endl;
	cout << "|                                           |"<<endl;
	cout << "============================================="<<endl;
	cout << "Terima Kasih Telah Menggunakan Aplikasi Ini!"<<endl;
	cout << "\nSemoga Perjalananmu Aman dan Menyenangkan!"<<endl;
	exit(0);
}

void optionMenu(){
	cout << "========================================"<<endl;
	cout << "|                                      |"<<endl;
	cout << "|       Aplikasi Pemesanan Tiket       |"<<endl;
	cout << "|           'AT THE TICKET'            |"<<endl;
	cout << "|                                      |"<<endl;
	cout << "========================================"<<endl;
	cout << "1. Daftar Akun"<<endl;
	cout << "2. Login"<<endl;
	cout << "3. Exit"<<endl;
	cout << "\nPilih Menu : "; 
}

void daftarAkun(){
	char p; // untuk deklarasi input karakter password daftar akun
	i=n;    // i nilainya sama dengan n, nilainya sama-sama dari 0
	n++;    // setiap memilih menu daftar Akun n-nya akan bertambah 1
		cout << "======================="<<endl;
		cout << ">>>   Daftar Akun   <<<"<<endl;
		cout << "======================="<<endl;
		cin.ignore(); // berfungsi untuk mengabaikan atau menghapus satu atau lebih karakter dari buffer input
		cout << "Username : "; getline(cin,pemesan[i].username); 
		// membaca seluruh baris, dan menggunakan karakter baris baru yang dikirimkan oleh tombol Enter untuk menandai akhir input
		cout << "Password : "; 
	while(i<n){ // ketika i kurang dari jumlah 
		while(p!='\r') // ketika input password belum memencet enter
		{
			p = getch(); // menahan (pause) output suatu program 
			if(p=='0') // jika menginput karakter 0 
			{
				switch(getch()){ // membaca getch() 
					default: // ketika input selain 0
						break; // fungsi berhenti dan kembali ke pengulangan
				};
			}
			else if(p=='\b') // jika getch() adalah backspace, atau jika user menghapus
			{
				if(pemesan[i].password.size()!=0) // jika ukuran password tidak kosong
				{
					cout << "\b \b"; // menghapus satu karakter yang berada di depan kursor
					pemesan[i].password.erase(pemesan[i].password.size()-1,1); 
					// karakter yang terhapus berjumlah 1 dan pada posisi terakhir
				}
			continue; 
			}
			else if(p<='9' && p>='0'||p>='a' && p<='z'||p>='A' && p<='Z')
			// jika getch() merupakan angka ataupun huruf
			{
				pemesan[i].password += p; // password akan membaca p 
				cout << "*"; // bentuk outputnya [*]
			}
			// selain inputan diatas, input tidak akan muncul, dan kembali ke perulangan
			else{
				continue;
			}
		}
		cout <<endl<<endl;
		cout << "Loading..."<<endl;
		sleep(1);
		cout << "\nSelamat! Anda Telah Terdaftar"<<endl;
		cout << "Login Untuk Memesan Tiket"<<endl;
		i++; // i bertambah 1 menandakan telah ada 1 akun yang terdaftar	
	}
}

void tiketPesawat(){
	char yakin;
	char kodeps; // deklarasi kode pesawat
	cout << "============================================================================================================="<<endl;
    cout << "-----------------------------------------   Jadwal Penerbangan   --------------------------------------------"<<endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>       YOGYAKARTA       <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    cout << "-----------------------------------------     Daftar Pilihan     --------------------------------------------"<<endl;
    cout << "============================================================================================================="<<endl;
    cout << "|- Kode -|--- Nama Maskapai ---|--- Rute ---|------ Kelas ------|----- Harga-----|- Berangkat -|--- Tiba ---|"<<endl;
    cout << "============================================================================================================="<<endl;
    cout << "|    A   |       Air Asia      |  BJR - YK  |      Ekonomi      |  Rp1.026.100   |    08:45    |    11:35   |"<<endl;
    cout << "|    B   |       Citilink      |  YK - DPS  |      Ekonomi      |  Rp1.329.000   |    13:35    |    16:35   |"<<endl;
    cout << "|    C   |       Lion Air      |  MTR - YK  |      Ekonomi      |  Rp869.400     |    14:20    |    15:50   |"<<endl;
    cout << "|    D   |       Citilink      |  PKB - YK  |  Ekonomi Premium  |  Rp1.165.300   |    05:00    |    06:30   |"<<endl;
    cout << "|    E   |        NAM Air      |  JKT - YK  |  Ekonomi Premium  |  Rp2.709.200   |    06:00    |    17:40   |"<<endl;
    cout << "|    F   |       Batik Air     |  BTM - YK  |  Ekonomi Premium  |  Rp4.593.200   |    08:00    |    12:20   |"<<endl;
    cout << "|    G   |   Garuda Indonesia  |  YK - BLP  |       Bisnis      |  Rp3.689.500   |    16:45    |    18:05   |"<<endl;
    cout << "|    H   |       Wings Air     |  PLB - YK  |       Bisnis      |  Rp4.644.800   |    07:50    |    12:50   |"<<endl;
    cout << "|    I   |       Batik Air     |  MKS - YK  |       Bisnis      |  Rp5.852.200   |    05:00    |    06:30   |"<<endl;
    cout << "|    J   |       Lion Air      |  MDN - YK  |       Bisnis      |  Rp4.829.700   |    06:00    |    08:40   |"<<endl;
    cout << "|    K   |       Lion Air      |  YK - PTK  |     First Class   |  Rp8.245.800   |    13:15    |    17:10   |"<<endl;
    cout << "|    L   |   Garuda Indonesia  |  YK - BTM  |     First Class   |  Rp10.035.200  |    15:40    |    17:40   |"<<endl;
    cout << "|    M   |       Citilink      |  YK - BL   |     First Class   |  Rp9.946.300   |    14:15    |    17:20   |"<<endl;
    cout << "|    N   |       Air Asia      |  SRD - YK  |     First Class   |  Rp9.428.400   |    11:00    |    11:45   |"<<endl;
    cout << "|    O   |       Batik Air     |  PDG - YK  |     First Class   |  Rp10.240.500  |    16:00    |    17:55   |"<<endl;
    cout << "============================================================================================================="<<endl;
    cout << "Pilih Kode\t: "; cin >> kodeps;
    if(kodeps >= 97 && kodeps <= 122) // jika kode pesawat yang diinput menurut ASCII (97-122) adalah huruf kecil
	{
		// kode huruf besar dari (65-90)
    	kodeps -= 32; // kode dikurangi 32 agar berubah menjadi huruf besar
	}
    if(!(kodeps >= 'A' && kodeps <= 'O' || kodeps >= 'a' && kodeps <= 'o'))
    // jika kode pesawat yang diinput selain huruf a-o
	{
        cout << "\nKode Pesawat Tidak Tersedia"<<endl;
        cout << "Silahkan Pilih Jadwal yang Tersedia!"<<endl;
	}
    if(kodeps >= 'A' && kodeps <= 'O' || kodeps >= 'a' && kodeps <= 'o')
    // jika kode pesawat sesuai yang disediakan 
	{
		p = pemesan[i].jumlahps; // p = jumlah pesanan tiket pesawat
	    cout << "Jumlah Tiket\t: "; cin >> tambahps;
	    pemesan[i].jumlahps += tambahps; // jumlah pesanan akan bertambah sesuai tambahan tiket yang diinput
	    
	    cout << "\nYakin dengan Pesanan Anda? Pesanan Tidak Dapat di-Cancel (Y/T) : "; cin >> yakin;
		if(yakin == 'Y' || yakin == 'y')
		{
			cout << "\nFormat Pengisian Data Keberangkatan : yyyy mm dd" <<endl;
		    while(p<pemesan[i].jumlahps) // ketika p kurang dari jumlah pesanan
		    {
		    	pemesan[i].P[p].penumpang.kode = kodeps; // kode pesawat yang dipesan penumpang sesuai dengan kode pesawat
		    	cout << "\nPenumpang " << p+1<<endl; 
		    	cin.ignore(); 
		    	cout << "\nNama\t\t: "; getline(cin,pemesan[i].P[p].penumpang.nama);
		    	cout << "No.Identitas\t: "; cin >> pemesan[i].P[p].penumpang.nik;
		    	cout << "Keberangkatan\t: "; cin >> pemesan[i].P[p].penumpang.waktu.tahun >> pemesan[i].P[p].penumpang.waktu.bulan >> pemesan[i].P[p].penumpang.waktu.tanggal;
		    	pemesan[i].jml++; // jumlah pesanan tiket bertambah 1
				if(kodeps == 'A' || kodeps == 'a'){
		            pemesan[i].P[p].maskapai = "Air Asia";
		            pemesan[i].P[p].rute = "Banjarmasin - Yogyakarta";
		            pemesan[i].P[p].kelas = "Ekonomi";
		            pemesan[i].P[p].harga = 1026100;
		            pemesan[i].P[p].berangkat = "08:45";
		            pemesan[i].P[p].tiba = "11:35";
		        }
		        if(kodeps == 'B' || kodeps == 'b'){
		            pemesan[i].P[p].maskapai = "Citilink";
		            pemesan[i].P[p].rute = "Yogyakarta - Denpasar";
		            pemesan[i].P[p].kelas = "Ekonomi";
		            pemesan[i].P[p].harga = 1329000;
		            pemesan[i].P[p].berangkat = "13:35";
		            pemesan[i].P[p].tiba = "16:35";
		        }
		        if(kodeps == 'C' || kodeps == 'c'){
		            pemesan[i].P[p].maskapai = "Lion Air";
		            pemesan[i].P[p].rute = "Mataram - Yogyakarta";
		            pemesan[i].P[p].kelas = "Ekonomi Premium";
		            pemesan[i].P[p].harga = 869400;
		            pemesan[i].P[p].berangkat = "14:20";
		            pemesan[i].P[p].tiba = "15:50";
		        }
		        if(kodeps == 'D' || kodeps == 'd'){
		            pemesan[i].P[p].maskapai = "Citilink";
		            pemesan[i].P[p].rute = "Pekanbaru - Yogyakarta";
		            pemesan[i].P[p].kelas = "Ekonomi";
		            pemesan[i].P[p].harga = 1165300;
		            pemesan[i].P[p].berangkat = "05:00";
		            pemesan[i].P[p].tiba = "06:30";
		        }
		        if(kodeps == 'E' || kodeps == 'e'){
		            pemesan[i].P[p].maskapai = "NAM Air";
		            pemesan[i].P[p].rute = "Jakarta - Yogyakarta";
		            pemesan[i].P[p].kelas = "Ekonomi Premium";
		            pemesan[i].P[p].harga = 2709200;
		            pemesan[i].P[p].berangkat = "06:00";
		            pemesan[i].P[p].tiba = "17:40";
		        }
		        if(kodeps == 'F' || kodeps == 'f'){
		            pemesan[i].P[p].maskapai = "Batik Air";
		            pemesan[i].P[p].rute = "Batam - Yogyakarta";
		            pemesan[i].P[p].kelas = "Ekonomi Premium";
		            pemesan[i].P[p].harga = 4593200;
		            pemesan[i].P[p].berangkat = "08:00";
		            pemesan[i].P[p].tiba = "12:20";
		        }
		        if(kodeps == 'G' || kodeps == 'g'){
		            pemesan[i].P[p].maskapai = "Garuda Indonesia";
		            pemesan[i].P[p].rute = "Yogyakarta - Balikpapan";
		            pemesan[i].P[p].kelas = "Bisnis";
		            pemesan[i].P[p].harga = 3689500;
		            pemesan[i].P[p].berangkat = "16:45";
		            pemesan[i].P[p].tiba = "18:05";
		        }
		        if(kodeps == 'H' || kodeps == 'h'){
		            pemesan[i].P[p].maskapai = "Wings Air";
		            pemesan[i].P[p].rute = "Palembang - Yogyakarta";
		            pemesan[i].P[p].kelas = "Bisnis";
		            pemesan[i].P[p].harga = 4644800;
		            pemesan[i].P[p].berangkat = "07:50 ";
		            pemesan[i].P[p].tiba = "12:50";
		        }
		        if(kodeps == 'I' || kodeps == 'i'){
		            pemesan[i].P[p].maskapai = "Batik Air";
		            pemesan[i].P[p].rute = "Makassar - Yogyakarta";
		            pemesan[i].P[p].kelas = "Bisnis";
		            pemesan[i].P[p].harga = 5852200;
		            pemesan[i].P[p].berangkat = "05:00";
		            pemesan[i].P[p].tiba = "06:30";
		        }
		        if(kodeps == 'J' || kodeps == 'j'){
		            pemesan[i].P[p].maskapai = "Lion Air";
		            pemesan[i].P[p].rute = "Medan - Yogyakarta";
		            pemesan[i].P[p].kelas = "Bisnis";
		            pemesan[i].P[p].harga = 4829700;
		            pemesan[i].P[p].berangkat = "06:00";
		            pemesan[i].P[p].tiba = "08:40";
		        }
		        if(kodeps == 'K' || kodeps == 'k'){
		            pemesan[i].P[p].maskapai = "Lion Air";
		            pemesan[i].P[p].rute = "Yogyakarta - Pontianak";
		            pemesan[i].P[p].kelas = "First Class";
		            pemesan[i].P[p].harga = 8245800;
		            pemesan[i].P[p].berangkat = "13:15";
		            pemesan[i].P[p].tiba = "17:10";
		        }
		        if(kodeps == 'L' || kodeps == 'l'){
		            pemesan[i].P[p].maskapai = "Garuda Indonesia";
		            pemesan[i].P[p].rute = "Yogyakarta - Batam";
		            pemesan[i].P[p].kelas = "First Class";
		            pemesan[i].P[p].harga = 10035200;
		            pemesan[i].P[p].berangkat = "15:40";
		            pemesan[i].P[p].tiba = "17:40";
		        }
		        if(kodeps == 'M' || kodeps == 'm'){
		            pemesan[i].P[p].maskapai = "Citilink";
		            pemesan[i].P[p].rute = "Yogyakarta - Bali";
		            pemesan[i].P[p].kelas = "First Class";
		            pemesan[i].P[p].harga = 9946300;
		            pemesan[i].P[p].berangkat = "14:15";
		            pemesan[i].P[p].tiba = "17:20";
		        }
		        if(kodeps == 'N' || kodeps == 'n'){
		            pemesan[i].P[p].maskapai = "Air Asia";
		            pemesan[i].P[p].rute = "Samarinda - Yogyakarta";
		            pemesan[i].P[p].kelas = "First Class";
		            pemesan[i].P[p].harga = 9428400;
		            pemesan[i].P[p].berangkat = "11:00";
		            pemesan[i].P[p].tiba = "11:45";
		        }
		        if(kodeps == 'O' || kodeps == 'o'){
		            pemesan[i].P[p].maskapai = "Batik Air";
		            pemesan[i].P[p].rute = "Padang - Yogyakarta";
		            pemesan[i].P[p].kelas = "First Class";
		            pemesan[i].P[p].harga = 10240500;
		            pemesan[i].P[p].berangkat = "16:00";
		            pemesan[i].P[p].tiba = "17:55";
		        }
		    	p++;
			}	
		}	
	}
}

void kelasP(){
    if(pemesan[i].P[p].kelas == "Ekonomi"){
        pemesan[i].P[p].kodekelas = "EK";
    }
    if(pemesan[i].P[p].kelas == "Ekonomi Premium"){
        pemesan[i].P[p].kodekelas = "EP";
    }
    if(pemesan[i].P[p].kelas == "Bisnis"){
        pemesan[i].P[p].kodekelas = "BN";
    }
    if(pemesan[i].P[p].kelas == "First Class"){
        pemesan[i].P[p].kodekelas = "FC";
    }
}

int totalHargaP(int hargaP){
	// total harga tiket pesawat yang dipesan 
	for(p=0;p<pemesan[i].jumlahps;p++){
		// harga pesawat bertambah sesuai jumlah pesanan
		hargaP += pemesan[i].P[p].harga;
	}
	return hargaP; // mengembalikan nilai hargaP yang tersimpan
}

void tiketKereta(){
	char yakin;
	char kodeka; 
	cout << "========================================================================================================="<<endl;
    cout << "-----------------------------------------   Jadwal Kereta Api   -----------------------------------------"<<endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>      YOGYAKARTA       <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    cout << "-----------------------------------------    Daftar Pilihan     -----------------------------------------"<<endl;
    cout << "========================================================================================================="<<endl;
    cout << "|- Kode -|---- Nama Kereta ----|--- Rute ---|---- Kelas ----|----- Harga-----|- Berangkat -|--- Tiba ---|"<<endl;
    cout << "========================================================================================================="<<endl;
    cout << "|    A   |        Progo        |  LPY - PSE |    Ekonomi    |    Rp125.000   |    14:45    |    23:42   |"<<endl;
    cout << "|    B   |      Bogowonto      |  LPY - PSE |    Ekonomi    |    Rp170.000   |    09:00    |    17:29   |"<<endl;
    cout << "|    C   |      Gajahwong      |  LPY - PSE |    Ekonomi    |    Rp170.000   |    18:00    |    02:43   |"<<endl;
    cout << "|    D   |      Bengawan       |  PWS - PSE |    Ekonomi    |    Rp74.000    |    15:26    |    00:28   |"<<endl;
    cout << "|    E   |    Fajar Utama Yk   |   YK - PSE |    Bisnis     |    Rp215.000   |    07:00    |    15:02   |"<<endl;
    cout << "|    F   |       Tatsaka       |   YK - GMR |   Eksekutif   |    Rp260.000   |    08:00    |    15:42   |"<<endl;
    cout << "|    G   |    Argo Dwipangga   |  SLO - GMR |   Eksekutif   |    Rp285.000   |    20:57    |    04:37   |"<<endl;
    cout << "|    H   |       Sancaka       |   YK - SGU |   Eksekutif   |    Rp105.000   |    06:45    |    11:37   |"<<endl;
    cout << "|    I   |       Sancaka       |   YK - SGU |    Ekonomi    |    Rp105.000   |    16:40    |    21:55   |"<<endl;
    cout << "|    J   |  Malioboro Ekspress |   YK - ML  |    Ekonomi    |    Rp140.000   |    07:45    |    15:43   |"<<endl;
    cout << "|    K   |  Malioboro Ekspress |   YK - ML  |   Eksekutif   |    Rp140.000   |    20:45    |    03:49   |"<<endl;
    cout << "|    L   |       Lodaya        |  SLO - BD  |    Bisnis     |    Rp140.000   |    08:08    |    15:48   |"<<endl;
    cout << "|    M   |       Lodaya        |  SLO - BD  |    Bisnis     |    Rp140.000   |    20:08    |    04:15   |"<<endl;
    cout << "========================================================================================================="<<endl;
    cout << "Pilih Kode\t: "; cin >> kodeka;
    if(kodeka >= 97 && kodeka <= 122){
    	kodeka -= 32;
    }
    if(!(kodeka >= 'A' && kodeka <= 'O' || kodeka >= 'a' && kodeka <= 'o')){
        cout << "\nKode Kereta Tidak Tersedia"<<endl;
        cout << "Silahkan Pilih Jadwal yang Tersedia!"<<endl;
	}
	else
	{
		k = pemesan[i].jumlahka;
	    cout << "Jumlah Tiket\t: "; cin >> tambahka;
	    pemesan[i].jumlahka += tambahka;
	    
	    cout << "\nYakin dengan Pesanan Anda? Pesanan Tidak Dapat di-Cancel (Y/T) : "; cin >> yakin;
		if(yakin == 'Y' || yakin == 'y')
		{
			cout << "\nFormat Pengisian Data Keberangkatan : yyyy mm dd" <<endl;
		    while(k<pemesan[i].jumlahka)
		    {
		    	pemesan[i].K[k].penumpang.kode = kodeka;
		    	cout << "\nPenumpang " << k+1<<endl;
		    	cin.ignore();
		    	cout << "\nNama\t\t: "; getline(cin,pemesan[i].K[k].penumpang.nama);
		    	cout << "No.Identitas\t: "; cin >> pemesan[i].K[k].penumpang.nik;
		    	cout << "Keberangkatan\t: "; cin >> pemesan[i].K[k].penumpang.waktu.tahun >> pemesan[i].K[k].penumpang.waktu.bulan >> pemesan[i].K[k].penumpang.waktu.tanggal;
		    	pemesan[i].jml++;
		    	if(kodeka == 'A' || kodeka == 'a'){
		            pemesan[i].K[k].kereta = "Progo";
		            pemesan[i].K[k].rute = "Lempuyangan - Pasar Senen";
		            pemesan[i].K[k].kelas = "Ekonomi";
		            pemesan[i].K[k].harga = 125000;
		            pemesan[i].K[k].berangkat = "14:45";
		            pemesan[i].K[k].tiba = "23:42";
		        }
		        if(kodeka == 'B' || kodeka == 'b'){
		            pemesan[i].K[k].kereta = "Bogowonto";
		            pemesan[i].K[k].rute = "Lempuyangan - Pasar Senen";
		            pemesan[i].K[k].kelas = "Ekonomi";
		            pemesan[i].K[k].harga = 170000;
		            pemesan[i].K[k].berangkat = "09:00";
		            pemesan[i].K[k].tiba = "17:29";
		        }
		        if(kodeka == 'C' || kodeka == 'c'){
		            pemesan[i].K[k].kereta = "Gajahwong";
		            pemesan[i].K[k].rute = "Lempuyangan - Pasar Senen";
		            pemesan[i].K[k].kelas = "Ekonomi";
		            pemesan[i].K[k].harga = 170000;
		            pemesan[i].K[k].berangkat = "18:00";
		            pemesan[i].K[k].tiba = "02:43";
		        }
		        if(kodeka == 'D' || kodeka == 'd'){
		            pemesan[i].K[k].kereta = "Bengawan";
		            pemesan[i].K[k].rute = "Purwosari - Pasar Senen";
		            pemesan[i].K[k].kelas = "Ekonomi";
		            pemesan[i].K[k].harga = 74000;
		            pemesan[i].K[k].berangkat = "15:26";
		            pemesan[i].K[k].tiba = "00:28";
		        }
		        if(kodeka == 'E' || kodeka == 'e'){
		            pemesan[i].K[k].kereta = "Fajar Utama Yk";
		            pemesan[i].K[k].rute = "Yogyakarta - Pasar Senen";
		            pemesan[i].K[k].kelas = "Bisnis";
		            pemesan[i].K[k].harga = 215000;
		            pemesan[i].K[k].berangkat = "07:00";
		            pemesan[i].K[k].tiba = "15:02";
		        }
		        if(kodeka == 'F' || kodeka == 'f'){
		            pemesan[i].K[k].kereta = "Tatsaka";
		            pemesan[i].K[k].rute = "Yogyakarta - Gambir";
		            pemesan[i].K[k].kelas = "Eksekutif";
		            pemesan[i].K[k].harga = 260000;
		            pemesan[i].K[k].berangkat = "08:00";
		            pemesan[i].K[k].tiba = "15:42";
		        }
		        if(kodeka == 'G' || kodeka == 'g'){
		            pemesan[i].K[k].kereta = "Argo Dwipangga";
		            pemesan[i].K[k].rute = "Solo - Gambir";
		            pemesan[i].K[k].kelas = "Eksekutif";
		            pemesan[i].K[k].harga = 285000;
		            pemesan[i].K[k].berangkat = "20:57";
		            pemesan[i].K[k].tiba = "04:37";
		        }
		        if(kodeka == 'H' || kodeka == 'h'){
		            pemesan[i].K[k].kereta = "Sancaka";
		            pemesan[i].K[k].rute = "Yogyakarta - Surabaya Gubeng";
		            pemesan[i].K[k].kelas = "Eksekutif";
		            pemesan[i].K[k].harga = 105000;
		            pemesan[i].K[k].berangkat = "06:45";
		            pemesan[i].K[k].tiba = "11:37";
		        }
		        if(kodeka == 'I' || kodeka == 'i'){
		            pemesan[i].K[k].kereta = "Sancaka";
		            pemesan[i].K[k].rute = "Yogyakarta - Surabaya Gubeng";
		            pemesan[i].K[k].kelas = "Ekonomi";
		            pemesan[i].K[k].harga = 105000;
		            pemesan[i].K[k].berangkat = "16:40";
		            pemesan[i].K[k].tiba = "21:55";
		        }
		        if(kodeka == 'J' || kodeka == 'j'){
		            pemesan[i].K[k].kereta = "Malioboro Ekspress";
		            pemesan[i].K[k].rute = "Yogyakarta - Malang";
		            pemesan[i].K[k].kelas = "Ekonomi";
		            pemesan[i].K[k].harga = 140000;
		            pemesan[i].K[k].berangkat = "07:45";
		            pemesan[i].K[k].tiba = "15:43";
		        }
		        if(kodeka == 'K' || kodeka == 'k'){
		            pemesan[i].K[k].kereta = "Malioboro Ekspress";
		            pemesan[i].K[k].rute = "Yogyakarta - Malang";
		            pemesan[i].K[k].kelas = "Eksekutif";
		            pemesan[i].K[k].harga = 140000;
		            pemesan[i].K[k].berangkat = "20:45";
		            pemesan[i].K[k].tiba = "03:49";
		        }
		        if(kodeka == 'L' || kodeka == 'l'){
		            pemesan[i].K[k].kereta = "Lodaya";
		            pemesan[i].K[k].rute = "Solo - Bandung";
		            pemesan[i].K[k].kelas = "Bisnis";
		            pemesan[i].K[k].harga = 140000;
		            pemesan[i].K[k].berangkat = "08:08";
		            pemesan[i].K[k].tiba = "15:48";
		        }
		        if(kodeka == 'M' || kodeka == 'm'){
		            pemesan[i].K[k].kereta = "Lodaya";
		            pemesan[i].K[k].rute = "Solo - Bandung";
		            pemesan[i].K[k].kelas = "Bisnis";
		            pemesan[i].K[k].harga = 140000;
		            pemesan[i].K[k].berangkat = "20:08";
		            pemesan[i].K[k].tiba = "04:15";
		        }
				k++;
			}
		}
	}
}

void kelasK(){
    if(pemesan[i].K[k].kelas == "Ekonomi"){
        pemesan[i].K[k].kodekelas = "EK";
    }
    if(pemesan[i].K[k].kelas == "Bisnis"){
        pemesan[i].K[k].kodekelas = "BN";
    }
    if(pemesan[i].K[k].kelas == "Eksekutif"){
        pemesan[i].K[k].kodekelas = "XF";
    }
}

int totalHargaK(int hargaK){
	for(k=0;k<pemesan[i].jumlahka;k++){
		hargaK += pemesan[i].K[k].harga;
	}
	return hargaK;
}

void kodeBulan(){
	if(pemesan[i].P[p].penumpang.waktu.bulan == "01" || pemesan[i].K[k].penumpang.waktu.bulan == "01"){
		pemesan[i].P[p].penumpang.waktu.kodebulan = "Januari";
		pemesan[i].K[k].penumpang.waktu.kodebulan = "Januari";
	}
	if(pemesan[i].P[p].penumpang.waktu.bulan == "02" || pemesan[i].K[k].penumpang.waktu.bulan == "02"){
		pemesan[i].P[p].penumpang.waktu.kodebulan = "Februari";
		pemesan[i].K[k].penumpang.waktu.kodebulan = "Februari";
	}
	if(pemesan[i].P[p].penumpang.waktu.bulan == "03" || pemesan[i].K[k].penumpang.waktu.bulan == "03"){
		pemesan[i].P[p].penumpang.waktu.kodebulan = "Maret";
		pemesan[i].K[k].penumpang.waktu.kodebulan = "Maret";
	}
	if(pemesan[i].P[p].penumpang.waktu.bulan == "04" || pemesan[i].K[k].penumpang.waktu.bulan == "04"){
		pemesan[i].P[p].penumpang.waktu.kodebulan = "April";
		pemesan[i].K[k].penumpang.waktu.kodebulan = "April";
	}
	if(pemesan[i].P[p].penumpang.waktu.bulan == "05" || pemesan[i].K[k].penumpang.waktu.bulan == "05"){
		pemesan[i].P[p].penumpang.waktu.kodebulan = "Mei";
		pemesan[i].K[k].penumpang.waktu.kodebulan = "Mei";
	}
	if(pemesan[i].P[p].penumpang.waktu.bulan == "06" || pemesan[i].K[k].penumpang.waktu.bulan == "06"){
		pemesan[i].P[p].penumpang.waktu.kodebulan = "Juni";
		pemesan[i].K[k].penumpang.waktu.kodebulan = "Juni";
	}
	if(pemesan[i].P[p].penumpang.waktu.bulan == "07" || pemesan[i].K[k].penumpang.waktu.bulan == "07"){
		pemesan[i].P[p].penumpang.waktu.kodebulan = "Juli";
		pemesan[i].K[k].penumpang.waktu.kodebulan = "Juli";
	}
	if(pemesan[i].P[p].penumpang.waktu.bulan == "08" || pemesan[i].K[k].penumpang.waktu.bulan == "08"){
		pemesan[i].P[p].penumpang.waktu.kodebulan = "Agustus";
		pemesan[i].K[k].penumpang.waktu.kodebulan = "Agustus";
	}
	if(pemesan[i].P[p].penumpang.waktu.bulan == "09" || pemesan[i].K[k].penumpang.waktu.bulan == "09"){
		pemesan[i].P[p].penumpang.waktu.kodebulan = "September";
		pemesan[i].K[k].penumpang.waktu.kodebulan = "September";
	}
	if(pemesan[i].P[p].penumpang.waktu.bulan == "10" || pemesan[i].K[k].penumpang.waktu.bulan == "10"){
		pemesan[i].P[p].penumpang.waktu.kodebulan = "Oktober";
		pemesan[i].K[k].penumpang.waktu.kodebulan = "Oktober";
	}
	if(pemesan[i].P[p].penumpang.waktu.bulan == "11" || pemesan[i].K[k].penumpang.waktu.bulan == "11"){
		pemesan[i].P[p].penumpang.waktu.kodebulan = "November";
		pemesan[i].K[k].penumpang.waktu.kodebulan = "November";
	}
	if(pemesan[i].P[p].penumpang.waktu.bulan == "12" || pemesan[i].K[k].penumpang.waktu.bulan == "12"){
		pemesan[i].P[p].penumpang.waktu.kodebulan = "Desember";
		pemesan[i].K[k].penumpang.waktu.kodebulan = "Desember";
	}
}

void menuTiket();

int allPesanan(int jml_pesanan);
void admin();

void login(){
	string username2,password2;
	bool checkAkun = false; // check Akun masih bernilai false
	char p2; // untuk deklarasi input karakter password login
	i=0; // i mulai dari 0 lagi 
	cout << "======================="<<endl;
	cout << ">>>>     Login    <<<<"<<endl;
	cout << "======================="<<endl;
	cin.ignore();
	cout << "Username : "; getline(cin,username2);
	cout << "Password : "; 
	while(p2!='\r')
	{
		p2 = getch();
		if(p2=='0')
		{
			switch(getch()){
				default:
					break;
			};
		}
		else if(p2=='\b')
		{
			if(password2.size()!=0)
			{
				cout << "\b \b";
				password2.erase(password2.size()-1,1);
			}
		continue;
		}
		else if(p2<='9' && p2>='0'||p2>='a' && p2<='z'||p2>='A' && p2<='Z')
		{
			password2 += p2;
			cout << "*";
		}
		else{
			continue;
		}
	}
	cout <<endl<<endl;
	cout << "Loading..."<<endl<<endl;
	sleep(1);
	while(i<n){
		if(username2 == pemesan[i].username && password2 == pemesan[i].password) 
		// jika username dan password login sama dengan username dan password pada daftar akun
		{
			cout << "Selamat Datang " << pemesan[i].username <<"!"<<endl;
			cout << "Pilih Menu yang Anda Inginkan!"<<endl;
			menuTiket(); 
			checkAkun = true; // check Akun berubah menjadi true
		}
		i++;
	}
	if(username2 == "admin" && password2 == "ad123")
	// jika username dan password login sesuai dengan akun admin
	{		
		admin();
	}
	if(!checkAkun && username2 != "admin" && password2 != "ad123")
	// jika check Akun nilainya false dan bukan akun admin
	{
		cout << "Maaf, Akun Anda Belum Terdaftar"<<endl;
		cout << "Silahkan Kembali ke Menu Untuk Daftar Akun"<<endl;
	}
}

int main(){
	char ulang;
	do{	
		int menu;
		optionMenu(); cin >> menu;
		system("cls");
		switch(menu){
			case 1:
				daftarAkun();
				break;
			case 2:
				login();
				break;
			case 3:
				exit();
				break;
			default:
				cout << "Menu Tidak Tersedia. Silahkan Pilih Menu Lainnya!"<<endl;
				break;
		}
		cout << "\nIngin Kembali ke Halaman Awal? (Y/T) : "; cin >> ulang;
		system("cls");
	}
	while(ulang!='t'&&ulang!='T'); // perulangan akan berjalan ketika ulang yang diinput bukan t
	exit();
}

void menuTiket(){
	int tiket;
	char ulang2;
	do{
		system("cls");
		int pilih;
		cout << "========================================"<<endl;
        cout << "|                                      |"<<endl;
        cout << "|            Daftar Pilihan            |"<<endl;
        cout << "|                                      |"<<endl;
        cout << "========================================"<<endl;
        cout << "1. Pesan Tiket"<<endl;
        cout << "2. Cek Pesanan Tiket"<<endl;
        cout << "3. Log Out"<<endl;
        cout << "\nPilih Menu: "; cin >> pilih;
        system("cls");
        switch(pilih){
        	case 1:
        		cout << "====================="<<endl;
	            cout << ">>>  Pesan Tiket  <<<"<<endl;
	            cout << "====================="<<endl;
	            cout << "1. Tiket Pesawat"<<endl;
	            cout << "2. Tiket Kereta Api"<<endl;
	            cout << "\nPilih Tiket: "; cin >> tiket;
	            system("cls");
	            switch(tiket){
	            	case 1:
	            		tiketPesawat();
	            		break;
	            	case 2:
	            		tiketKereta();
	            		break;
	            	default:
	            		cout << "Menu Tidak Tersedia. Silahkan Pilih Menu Lainnya!"<<endl;
	            		break;
				}
        		break;
        	case 2:
        		if(pemesan[i].jml > 0)
        		// jika jumlah pesanan lebih dari 0
				{
	        		cout << "Jumlah Pesanan = " << pemesan[i].jml<<endl;
		            if(pemesan[i].jumlahps > 0){
		            	cout << "\nTiket Pesawat"<<endl;
		            	for(p=0;p<pemesan[i].jumlahps;p++){
		            		cout << "\nPenumpang " << p+1<<endl;
		            		cout << "\nNama\t\t: " << pemesan[i].P[p].penumpang.nama<<endl;
		            		cout << "No.Identitas\t: " << pemesan[i].P[p].penumpang.nik<<endl;
		            		cout << "Maskapai\t: " << pemesan[i].P[p].maskapai<<endl;
		            		cout << "Kelas\t\t: " << pemesan[i].P[p].kelas<<endl;
		            		cout << "Rute\t\t: " << pemesan[i].P[p].rute<<endl;
		            		cout << "Jadwal\t\t: " << pemesan[i].P[p].berangkat << " - " << pemesan[i].P[p].tiba<<endl;
		            		kelasP();
		            		cout << "\nKode Tiket\t: " << p+1 << pemesan[i].P[p].penumpang.kode << i+1 << pemesan[i].P[p].penumpang.waktu.tanggal << pemesan[i].P[p].penumpang.waktu.bulan << pemesan[i].P[p].kodekelas<<endl;
		            		kodeBulan();
		            		cout << "Keberangkatan\t: " << pemesan[i].P[p].penumpang.waktu.tanggal << " " << pemesan[i].P[p].penumpang.waktu.kodebulan << " " << pemesan[i].P[p].penumpang.waktu.tahun<<endl;
		            		cout << "Harga\t\t: " << "Rp" << pemesan[i].P[p].harga << ",00"<<endl;
						}
					}
					if(pemesan[i].jumlahka > 0){
		            	cout << "\nTiket Kereta"<<endl;
		            	for(k=0;k<pemesan[i].jumlahka;k++){
		            		cout << "\nPenumpang " << k+1<<endl;
		            		cout << "\nNama\t\t: " << pemesan[i].K[k].penumpang.nama<<endl;
		            		cout << "No.Identitas\t: " << pemesan[i].K[k].penumpang.nik<<endl;
		            		cout << "Kereta\t\t: " << pemesan[i].K[k].kereta<<endl;
		            		cout << "Kelas\t\t: " << pemesan[i].K[k].kelas<<endl;
		            		cout << "Rute\t\t: " << pemesan[i].K[k].rute<<endl;
		            		cout << "Jadwal\t\t: " << pemesan[i].K[k].berangkat << " - " << pemesan[i].K[k].tiba<<endl;
		            		kelasK();
		            		cout << "\nKode Tiket\t: " << k+1 << pemesan[i].K[k].penumpang.kode << i+1 << pemesan[i].K[k].penumpang.waktu.tanggal << pemesan[i].K[k].penumpang.waktu.bulan << pemesan[i].K[k].kodekelas<<endl;
		            		kodeBulan();
		            		cout << "Keberangkatan\t: " << pemesan[i].K[k].penumpang.waktu.tanggal << " " << pemesan[i].K[k].penumpang.waktu.kodebulan << " " << pemesan[i].K[k].penumpang.waktu.tahun<<endl;
		            		cout << "Harga\t\t: " << "Rp" << pemesan[i].K[k].harga << ",00"<<endl;
						}
					}
					cout << "\nTotal Harga\t: " << "Rp" << totalHargaP(hargaP)+totalHargaK(hargaK) << ",00"<<endl;
				}
				else{
					cout << "Anda Belum Memesan. Silahkan Pesan Tiket Terlebih Dahulu!"<<endl;
				}
        		break;
        	case 3:
        		main();
        		break;
        	default:
        		cout << "Menu Tidak Tersedia. Silahkan Pilih Menu Lainnya!"<<endl;
        		break;
		}
		cout << "\nIngin Kembali ke Menu Utama? (Y/T) : "; cin >> ulang2;
	}
	while(ulang2!='t'&&ulang2!='T');
}

int allPesanan(int jml_pesanan)
// untuk menghitung semua pesanan yang ada dalam program
{
	for(i=0;i<n;i++){
		jml_pesanan += pemesan[i].jml;
	}
	return jml_pesanan;
}

int jumlahbiaya(int pendapatan, int hargaP, int hargaK)
// untuk menghitung pendapatan dari jumlah harga pesanan yang ada
{
	for(i=0;i<n;i++){
		pendapatan += (totalHargaP(hargaP) + totalHargaK(hargaK));
	}
	return pendapatan;
}

void admin(){
	system("cls");
	int jml_pesanan,hargaP,hargaK,pendapatan,a=0,b=0;
	cout << "Selamat Datang Admin"<<endl<<endl;
	cout << "====================================="<<endl;
	cout << ">>> R I W A Y A T   P E S A N A N <<<"<<endl;
	cout << "====================================="<<endl;
	if(allPesanan(jml_pesanan) > 0){
	    cout << "\nJumlah Pesanan = " << allPesanan(jml_pesanan)<<endl;
		cout << "\nTiket Pesawat"<<endl;
		    for(i=0;i<n;i++)
			{
				for(p=0;p<pemesan[i].jumlahps;p++){
					a++;
					cout <<endl;
					cout << a << ". ";
		       		cout << "Nama\t\t: " << pemesan[i].P[p].penumpang.nama<<endl;
		            cout << "   No.Identitas\t: " << pemesan[i].P[p].penumpang.nik<<endl;
		            cout << "   Maskapai\t: " << pemesan[i].P[p].maskapai<<endl;
		            cout << "   Kelas\t: " << pemesan[i].P[p].kelas<<endl;
		            cout << "   Rute\t\t: " << pemesan[i].P[p].rute<<endl;
		            cout << "   Jadwal\t: " << pemesan[i].P[p].berangkat << " - " << pemesan[i].P[p].tiba<<endl;
		            kelasP();
		            cout << "\n   Kode Tiket\t: " << p+1 << pemesan[i].P[p].penumpang.kode << i+1 << pemesan[i].P[p].penumpang.waktu.tanggal << pemesan[i].P[p].penumpang.waktu.bulan << pemesan[i].P[p].kodekelas<<endl;
		            kodeBulan();
		            cout << "   Keberangkatan: " << pemesan[i].P[p].penumpang.waktu.tanggal << " " << pemesan[i].P[p].penumpang.waktu.kodebulan << " " << pemesan[i].P[p].penumpang.waktu.tahun<<endl;
		           	cout << "   Harga\t: " << "Rp" << pemesan[i].P[p].harga << ",00"<<endl;
				}
			}
		cout << "\nTiket Kereta"<<endl;
		    for(i=0;i<n;i++)
			{
				for(k=0;k<pemesan[i].jumlahka;k++){
					b++;
					cout <<endl;
					cout << b << ". ";
		            cout << "Nama\t\t: " << pemesan[i].K[k].penumpang.nama<<endl;
		           	cout << "   No.Identitas\t: " << pemesan[i].K[k].penumpang.nik<<endl;
		            cout << "   Kereta\t: " << pemesan[i].K[k].kereta<<endl;
		            cout << "   Kelas\t: " << pemesan[i].K[k].kelas<<endl;
		            cout << "   Rute\t\t: " << pemesan[i].K[k].rute<<endl;
		            cout << "   Jadwal\t: " << pemesan[i].K[k].berangkat << " - " << pemesan[i].K[k].tiba<<endl;
		            kelasK();
		            cout << "\n   Kode Tiket\t: " << k+1 << pemesan[i].K[k].penumpang.kode << i+1 << pemesan[i].K[k].penumpang.waktu.tanggal << pemesan[i].K[k].penumpang.waktu.bulan << pemesan[i].K[k].kodekelas<<endl;
		            kodeBulan();
		            cout << "   Keberangkatan: " << pemesan[i].K[k].penumpang.waktu.tanggal << " " << pemesan[i].K[k].penumpang.waktu.kodebulan << " " << pemesan[i].K[k].penumpang.waktu.tahun<<endl;
		            cout << "   Harga\t: " << "Rp" << pemesan[i].K[k].harga << ",00"<<endl;
				}
			}
		cout << "\nTotal Pendapatan : " << "Rp" << jumlahbiaya(pendapatan,hargaP,hargaK) << ",00"<<endl;
	}
	else{
		cout << "Belum Ada Pesanan"<<endl;
	}
}
