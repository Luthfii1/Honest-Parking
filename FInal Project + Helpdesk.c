#include <stdio.h>  //lib untuk input output
#include <stdlib.h> //lib untuk menyimpan data di pointer
#include <string.h> //lib untuk menyimpan string with space dan penggunaan strcpy

//deklarasi struct dengan nama berupa Data
typedef struct {
  	char nama[50];
  	char namaTempat[50];
  	char namaKendaraan[50];
	int kendaraan;
	int tempat;
	int sisaParkir[16];
	int maxParkir[16];
	int jam1;
	int jam2;
	int lamaParkir;
	int biaya;
}Data;

//prototype func untuk menampilkan opening program
void Opening ();
//prototype func untuk memilih menu
void Menu();
//prototype func untuk memilih kendaraan yang digunakan
int Kendaraan(Data *pelanggan, int i);
//prototype func untuk menampilkan harga parkir sesuai kendaraan yang digunakan
void ListHarga(Data *pelanggan, int i);
//prototype func untuk memilih tempat parkir dan mengecek ketersediaan tempat
int TempatParkir(Data *pelanggan, int i);
//prototype func untuk memberikan bantuan kepada user jika mengalami kendala
void Helpdesk();
//prototype func untuk menginput data user seperti nama hingga jam parkir tsb
void InputData(Data *pelanggan, int i);
//prototype func untuk memberikan struk pembayaran serta data user yang diinput
void Struk(Data *pelanggan, int i);
//prototype func untuk menggunakan angka random untuk tempat parkir
int rand();

int main(Data *pelanggan, int i) {
	Opening();	//memanggil function opening
	Menu();		//memanggil funtion menu
	if (i>0){
		system("pause"); system("CLS"); 
	}
	printf("Terima kasih telah menggunakan Application Honesty Parking!\n\n");
  	return 0;
}

//func untuk menampilkan opening program
void Opening () {
	int loop;
	
  	printf ("\t\t\t\t=============================================\n"); Sleep(500);
  	printf ("\t\t\t\t||\t Proyek Akhir Pemrograman Dasar    || \n");Sleep(500);
  	printf ("\t\t\t\t||_________________________________________||\n");Sleep(500);
  	printf ("\t\t\t\t||           This app made by :            ||\n"); Sleep(500);
	printf ("\t\t\t\t||    1. Cecilia Inez Reva // 2106636994   ||\n"); Sleep(500);
	printf ("\t\t\t\t||  2. Luthfi Misbachul Munir // 2106631961||\n"); Sleep(500);
	printf ("\t\t\t\t|| 3. Raditya Ihsan Dhiaulhaq // 2106733912||\n"); Sleep(500);
	printf ("\t\t\t\t||_________________________________________||\n");Sleep(500);
	printf ("\t\t\t\t=============================================\n\n\n"); Sleep(500);
	printf("\tPlease wait"); Sleep(1000); //Sleep digunakan untuk memberikan delay
	for(loop=0; loop<3; loop++){
		printf("\a."); system("color 74"); Sleep(500); 
		system("color 07"); Sleep(500);  //Sleep(500) berarti terdapat delay selama 500ms atau 0.5s
	} printf("\n\n"); system("pause"); system("CLS"); //digunakan untuk membersihkan tampilan saat melanjutkan program
}
  
//func untuk memilih menu  
void Menu(){
	int pilih, i=0, j=0, loop;
	Data *pelanggan;
	
	//untuk mengalokasikan ruang sesuai dengan jumlah pemesanan
	pelanggan = (Data*) calloc (15, sizeof(Data));
	//untuk memberikan informasi jika memory untuk pointer tidak tercukupi
	if(pelanggan == NULL){
		printf("Error! Memory Not Allocated");
		exit(0);
		}
	
	//Untuk deklarasi sisa parkir dan max parkir pada tempat yang tersedia
	for(loop=1; loop<=15; loop++){
		(pelanggan)->sisaParkir[loop] = rand() % 25; 		//menggunakan func random
		(pelanggan)->maxParkir[loop] = rand() % 100 + 25;	//supaya nilai max parkir > sisa parkir
	}	
	
	do {
		printf("\t\t||============================================================================||\n");
		printf("\t\t||                         Welcome to Honesty Parking                         ||\n");
		printf("\t\t||                                                                            ||\n");
		printf("\t\t||____________________________________________________________________________||\n");
		printf("\t\t||_______________________________Menu Transaksi_______________________________||\n"); Sleep(500);
		printf("\t\t||                                                                            ||\n");

		for(loop=0; loop<6; loop++){
			printf("\t\t||");
			for(j=0; j<28; j++){
				printf(" ");
			} 
			switch(loop){
				case 0:	printf("1. Pemesanan tiket  ");	break;
				case 1: printf("2. Update pemesanan "); break;
				case 2: printf("3. Data parkiran    "); break;
				case 3: printf("4. Data pembelian   "); break;
				case 4: printf("5. Help desk        "); break;
				case 5: printf("6. Exit app         "); break;
				default: printf("ERROR"); break;
			}
			for(j=0; j<28; j++){
				printf(" ");
			} printf("||\n"); 
		}
		
		printf("\t\t||============================================================================||\n");
		printf("\t\t    Silahkan pilih menu yang ingin anda gunakan : ");
 		scanf("%d", &pilih);
		Sleep(500); system("CLS");
 		
 		switch(pilih) {
 			case 1 : //case saat user memilih pemesanan tiket
 				ListHarga(pelanggan, i);
 				Kendaraan(pelanggan, i);	
 				TempatParkir(pelanggan, i);
 				//jika sisa parkir 0 maka program langsung di break sebelum menginput data pelanggan
 				if ((pelanggan)->sisaParkir[(pelanggan+i)->tempat]<1){
 					break;
				}
 				InputData(pelanggan, i);
 				i++;	//untuk deklarasi user selanjutnya
 				break;
 			
 			case 2 : //case saat user memilih update data
 				do{
					Struk(pelanggan, i);
	 				if(i>0){
		 				printf("Silahkan pilih pesanan yang ingin anda update : "); 
						scanf("%d", &j); 
		 				j -= 1; 				//menyesuaikan dengan variabel orang pemesan atau i
		 				if(j<0 || j>=i){		//user hanya bisa memilih update data sesuai nomer pesanan yang tersedia
		 					system("color 74");	//mengganti warna background dan font di terminal
		 					printf("\aPilihan yang anda pilih tidak tersedia!\n");
		 					Sleep(2000); system("CLS"); system("color 07");
						}
					 } else if(i<1){ //ketika user belum memesan tiket sama sekali maka tidak dapat mengupdate data
					 	break;
					 }
				 }while(j<0 || j>=i); //user hanya bisa memilih update data sesuai nomer pesanan yang tersedia
				 
				//jika user belum memesan parkir sama sekali, program akan di break
				if(i<1){
	 				break;
					} 
				system("CLS");
 				ListHarga(pelanggan, j);
 				Kendaraan(pelanggan, j);
 				TempatParkir(pelanggan, j);
 				//jika sisa parkir di suatu tempat habis maka program akan di break
 				if((pelanggan)->sisaParkir[(pelanggan+j)->tempat]<1){
	 				break;
					} 
 				InputData(pelanggan, j);
				break;
				
 			case 3 : //case jika user ingin melihat sisa parkir yang tersedia
 				TempatParkir(pelanggan, i);
 				(pelanggan)->sisaParkir[(pelanggan+i)->tempat]++; 
 				 system("CLS");
 				break;
 				
 			case 4 : //case jika user ingin melihat data pesanan yang telah dipesan
 				Struk(pelanggan, i);	
 				if(i>0){
 				system("pause"); system("CLS");
				}
				break;
				
 			case 5 : //case jika user membutuhkan bantuan untuk penggunaan program ini
 				Helpdesk();
 				break;
 				
 			case 6 : //case jika user ingin exit dari program
 				break;
 				
 			default : //error handling ketika user memberikan input yang tidak tersedia
 				system("color 74");
	            printf("\aPilihan yang anda pilih tidak tersedia!\n");
	            Sleep(2000); system("CLS");
	           	system("color 07");
 				break;
			}
		} while(pilih != 6); //program akan selalu ter-loop kecuali user ingin mengakhiri program dengan menginput pilihan 6
		
		printf("Berikut data pesanan yang anda pesan");
		for(loop=0; loop<5; loop++){
			printf("."); Sleep(1000);
		} printf("\n\n");
		//memberikan struk pesanan
		Struk(pelanggan, i); 
		//membebaskan memory pada pointer pelanggan
		free(pelanggan);
}

//func untuk memilih kendaraan yang digunakan
int Kendaraan(Data *pelanggan, int i){
	char nama_kendaraan[4][50] = {"","Mobil","Motor","Sepeda"};
	do{
		printf("Tempat parkir hanya tersedia untuk moda transportasi :\n1. Mobil\n2. Motor\n3. Sepeda\n\n");
		printf("Moda transportasi apa yang anda gunakan : ");
		scanf("%d", &(pelanggan+i)->kendaraan);	
		
		//error handling
		if (((pelanggan+i)->kendaraan)<1 || ((pelanggan+i)->kendaraan)>3) {
			system("color 74");
			printf("\n\aInput yang anda berikan tidak sesuai\nHarap masukan angka yang sesuai\n");
	        Sleep(2000); system("CLS"); system("color 07");
		};
	} while(((pelanggan+i)->kendaraan)<1 || ((pelanggan+i)->kendaraan)>3);
	strcpy((pelanggan+i)->namaKendaraan,nama_kendaraan[(pelanggan+i)->kendaraan]);
	
	switch ((pelanggan+i)->kendaraan) {
		case 1 : //case saat user menggunakan mobil
			printf("\n=========================================\n");
			printf("|| List biaya parkir kendaraan mobil : ||\n");
			printf("|| 1 jam pertama   = Rp 8.000          ||\n");
			printf("|| jam selanjutnya = Rp 5.000          ||\n");
			printf("=========================================\n");
			system("pause"); system("CLS"); break;
			
		case 2 : //case saat user menggunakan motor
			printf("\n=========================================\n");
			printf("|| List biaya parkir kendaraan motor : ||\n");
			printf("|| 1 jam pertama   = Rp 5.000          ||\n");
			printf("|| jam selanjutnya = Rp 3.000          ||\n");
			printf("=========================================\n"); 
			system("pause"); system("CLS"); break;
			
		case 3 : //case saat user menggunakan sepeda
			printf("\n==========================================\n");
			printf("|| List biaya parkir kendaraan sepeda : ||\n");
			printf("|| 1 jam pertama   = Rp 2.000           ||\n");
			printf("|| jam selanjutnya = Rp 1.000           ||\n");
			printf("==========================================\n"); 
			system("pause"); system("CLS"); break;
		default :
			break;
	}
	
	//me-return input user mengenaik kendaraan
	return (pelanggan+i)->kendaraan;
}

//func untuk menampilkan harga parkir sesuai kendaraan yang digunakan
void ListHarga(Data *pelanggan, int i){
	
			printf("\n\t||=====================================||\n");
			printf("\t|| List biaya parkir kendaraan mobil : ||\n");
			printf("\t|| 1 jam pertama   = Rp 8.000          ||\n");
			printf("\t|| jam selanjutnya = Rp 5.000          ||\n");
			printf("\t||=====================================||\n");
			printf("\t||                                     ||\n");
			printf("\t||=====================================||\n");
			printf("\t|| List biaya parkir kendaraan motor : ||\n");
			printf("\t|| 1 jam pertama   = Rp 5.000          ||\n");
			printf("\t|| jam selanjutnya = Rp 3.000          ||\n");
			printf("\t||=====================================||\n"); 
			printf("\t||                                     ||\n");
			printf("\t||=====================================||\n");
			printf("\t|| List biaya parkir kendaraan sepeda :||\n");
			printf("\t|| 1 jam pertama   = Rp 2.000          ||\n");
			printf("\t|| jam selanjutnya = Rp 1.000          ||\n");
			printf("\t||=====================================||\n"); 
			system("pause"); system("CLS"); 

}

//func untuk memilih tempat parkir dan mengecek ketersediaan tempat
int TempatParkir(Data *pelanggan, int i){
	//deklarasi nama tempat yang tersedia
	char nama_tempat[16][50] = {" ","Gedung Rektorat","Fakultas Teknik","Pusat Kegiatan Mahasiswa","Stasiun UI","Masjid UI","Fakultas Kesehatan Masyarakat ","Fakultas Hukum","Fakultas Ilmu Administrasi","Fakultas Ilmu Komputer","Fakultas Ilmu Pengetahuan Budaya","Fakultas Ekonomi dan Bisnis","Fakultas Farmasi","Fakultas Ilmu Keperawatan","Fakultas Kedokteran","Fakultas Ilmu Sosial dan Politik"};
	
	do{	
	
		printf("  __________________________________________________________________________________________________________________    \n");
		printf("  ||                                          HONESTY PARKING                                                      ||   \n");
		printf("  ||_______________________________________________________________________________________________________________||   \n");
		printf("  ||                                   Tempat parkir yang tersedia di UI :                                         ||   \n");
		printf("  ||_______________________________________________________________________________________________________________||   \n");
		printf("  || 1. Gedung Rektorat           || 6.Fakultas Kesehatan Masyarakat     || 11.Fakultas Ekonomi dan Bisnis         ||   \n");
		printf("  || 2. Fakultas Teknik           || 7.Fakultas Hukum                    || 12.Fakultas Farmasi                    ||   \n");
		printf("  || 3. Pusat Kegiatan Mahasiswa  || 8.Fakultas Ilmu Administrasi        || 13.Fakultas Ilmu Keperawatan           ||   \n");
		printf("  || 4. Stasiun UI                || 9.Fakultas Ilmu Komputer            || 14.Fakultas Kedokteran                 ||   \n");
		printf("  || 5. Masjid UI                 || 10.Fakultas Ilmu Pengetahuan Budaya || 15.Fakultas Ilmu Sosial dan Politik    ||   \n");
		printf("  ===================================================================================================================   \n");
		printf("\n  Tempat parkir tujuan anda : ");
		scanf("%d", &(pelanggan+i)->tempat);
		
		//error handling
		if ((pelanggan+i)->tempat<1 || (pelanggan+i)->tempat>15){
			system("color 74");
			printf("\n\aInput yang anda berikan tidak sesuai dengan pilihan yang tersedia\n");
	        Sleep(2000); system("CLS"); system("color 07");
		} else //mengurangin kuota tempat parkir yang tersedia
			(pelanggan)->sisaParkir[(pelanggan+i)->tempat]--;
			
		//menggunakan strcpy untuk memberikan bentruk string terhadap pilihan tempat user
		strcpy((pelanggan+i)->namaTempat,nama_tempat[(pelanggan+i)->tempat]);
	} while ((pelanggan+i)->tempat<1 || (pelanggan+i)->tempat>15);

 	printf("\n\n  Tempat Parkir yang tersedia di %s ",(pelanggan+i)->namaTempat);

	//kondisi ketika tempat parkir sudah penuh
	if ((pelanggan)->sisaParkir[(pelanggan+i)->tempat]<1){
		system("color 74");
		printf("\a\a\aTelah penuh\n  Anda dapat mencari tempat parkir lain disekitar UI!\n");
	    system("pause"); system("CLS"); system("color 07");
	} else
	printf("\n  tersisa %d dari total sebanyak %d\n\n\n", (pelanggan)->sisaParkir[(pelanggan+i)->tempat], (pelanggan)->maxParkir[(pelanggan+i)->tempat]);
	system("pause"); system("CLS");
	//mereturn tempat parkir yang dipilih user ke-i
	return (pelanggan+i)->tempat;
}

//func untuk menginput data user seperti nama hingga jam parkir tsb
void InputData(Data *pelanggan, int i){
	int hargaAwal, harga;
	
	do{
		printf("___________________________________________________\n");
		printf("                 HONESTY PARKING\n             UNIVERSITY OF INDONESIA\n");
		printf("   ============================================\n   ============================================\n\n");
		//meminta data nama pemesan
		printf("     Nama                     : ");
		scanf(" %49[^\n]s", &(pelanggan+i)->nama);
		//mengeprint kendaraan
		printf("     Kendaraan yang digunakan : ");
		switch ((pelanggan+i)->kendaraan) {
		case 1 : //case saat user menggunakan mobil
			printf("Mobil\n");
			break;
			
		case 2 : //case saat user menggunakan motor
			printf("Motor \n");
			break;
			
		case 3 : //case saat user menggunakan sepeda
			printf("Sepeda\n");
			break;
			
		default :
			printf("ERROR");
			break;
	}
		//meminta jam awal parkir
		printf("     Jam Masuk Parkir (1-24)  : ");
		scanf("%d",&(pelanggan+i)->jam1);
		//meminta jam selesai parkir
		printf("     Jam Keluar Parkir (1-24) : ");
		scanf("%d",&(pelanggan+i)->jam2);
		//error handling 
		if((pelanggan+i)->jam1 > 24 || (pelanggan+i)->jam1 < 1 || (pelanggan+i)->jam2 > 24 || (pelanggan+i)->jam2 < 1 ){
			system("color 74");
			printf("\aHarap masukan jam antara pukul 1 hingga 24\n\n");
	        Sleep(2000); system("color 07");
		}
	}while((pelanggan+i)->jam1 > 24 || (pelanggan+i)->jam1 < 1 || (pelanggan+i)->jam2 > 24 || (pelanggan+i)->jam2 < 1 );
	
	//penyesuaian biaya parkir sesuai dengan kendaraan yang digunakan user
	switch((pelanggan+i)->kendaraan){
		case 1 : //ketika user menggunakan mobil
			harga = 5000;
			hargaAwal = 8000;
			break;
			
		case 2: //ketika user menggunakan motor
			harga = 3000;
			hargaAwal = 5000;
			break;
			
		case 3 : //ketika user menggunakan sepeda
			harga = 1000;
			hargaAwal = 2000;
			break;
	}
	
	//rumus perhitungan serta error handling
	if((pelanggan+i)->jam1 > (pelanggan+i)->jam2){
		(pelanggan+i)->lamaParkir = ((24 - (pelanggan+i)->jam1)+ (pelanggan+i)->jam2);
		(pelanggan+i)->biaya = (((pelanggan+i)->lamaParkir - 1)* harga)+hargaAwal;
	}
	else if((pelanggan+i)->jam1 < (pelanggan+i)->jam2 ){
		(pelanggan+i)->lamaParkir = ((pelanggan+i)->jam2 - (pelanggan+i)->jam1);
		(pelanggan+i)->biaya = (((pelanggan+i)->lamaParkir - 1)* harga)+hargaAwal;
	}
	else{
		(pelanggan+i)->lamaParkir = 24;
		(pelanggan+i)->biaya = (((pelanggan+i)->lamaParkir - 1)* harga)+hargaAwal;   
	}
	
	//mengeprint lama parkir
	printf("     Durasi parkir            : %d jam\n", (pelanggan+i)->lamaParkir);
	printf("     Harga Total menjadi      : Rp %d \n",(pelanggan+i)->biaya);
	printf("   ============================================\n   ============================================\n\n");
	system("pause"); system("CLS"); 
}

//func untuk menginput data user seperti nama hingga jam parkir tsb
void Helpdesk(){
	int bantuan;
	
	do {
		printf("==== Ada Masalah dan Memerlukan Bantuan? ====");
		printf("\n1. Bagaimana cara memesan tiket\n2. Bagaimana saya bisa mengganti pemesanan"
				"\n3. Bagaimana melihat data parkiran \n4. Bagaimana melihat data pembelian"
				"\n5. Cara exit dari app \n6. Kembali ke Menu\n\nSilahkan pilih menu : ");
 		scanf("%d", &bantuan);
 		
		switch(bantuan){
 			case 1 : 
 				printf("\n======== Panduan Pemesanan Tiket ========\n");
 				printf("\n1. Pada halaman Menu, masukkan pilihan 1 untuk Pemesanan Tiket."
			 			"\n2. Anda akan diarahkan ke halaman selanjutnya. Anda dapat mengisi data pembelian tiket"
						"\n   seperti moda transportasi, lokasi tempat parkir, nama pengguna, dan jam parkir."
						"\n3. Di akhir pemesanan, tampilan harga tiket parkir akan diperlihatkan."
						"\n\nNB : Struk parkir dapat dilihat pada halaman Menu pilihan 4"
						"\n     Pilih 6 untuk kembali ke Menu.\n\n\n");
			 	system("pause"); system("CLS");
				break;
				
 			case 2 :
 				printf("\n======== Panduan Update Pemesanan ========\n");
 				printf("\n1. Pada halaman Menu, masukkan pilihan 2 untuk Update Pemesanan."
 						"\n2. Masukkan pilihan tiket yang Anda ingin ubah."
 						"\n3. Anda dapat mengisi data pembelian tiket kembali."
			 			"\n4. Data pemesanan Anda sudah otomatis diubah."
						"\n\nNB : Jika Anda belum memesan tiket, data pembelian tidak akan terlihat."
						"\n     Pesan tiket terlebih dahulu pada halaman Menu pilihan 1."
						"\n     Pilih 6 untuk kembali ke Menu.\n\n\n");
				system("pause"); system("CLS");
				break;
				
			case 3 :
				printf("\n======== Panduan Ketersediaan Tempat Parkir ========\n");
 				printf("\n1. Pada halaman Menu, masukkan pilihan 3 untuk melihat Data Tempat Parkir."
 						"\n2. Anda dapat mengisi pilihan informasi tempat parkir yang diminta."
			 			"\n3. Akhir pemesanan, tampilan ketersediaan tempat parkir akan diperlihatkan."
						"\n\nNB : Tampilan akan menunjukkan informasi mengenai ketersediaan tempat"
						"\n     parkir pada setiap lokasi tempat masing-masing."
						"\n     Pilih 6 untuk kembali ke Menu.\n\n\n");
				system("pause"); system("CLS");
				break;
				
			case 4 :
				printf("\n======== Panduan Melihat Struk Parkir ========\n");
 				printf("\n1. Pada halaman Menu, masukkan pilihan 4 untuk melihat Struk Parkir."
			 			"\n2. Tampilan ketersediaan tempat parkir akan diperlihatkan."
						"\n\nNB : Struk parkir akan ditampilkan pada pilihan ini."
						"\n     Pesan tiket terlebih dahulu pada halaman Menu pilihan 1."
						"\n     Pilih 6 untuk kembali ke Menu.\n\n\n");
				system("pause"); system("CLS");
				break;
				
			case 5 :
				printf("\n======== Panduan Exit dari App ========\n");
 				printf("\n1. Pada halaman Menu, masukkan pilihan 6 untuk Exit dari App."
			 			"\n2. Tampilan struk parkir akan diperlihatkan."
						"\n\nNB : Pilih 6 untuk kembali ke Menu.\n\n\n");
				system("pause"); system("CLS");
				break;
				
			case 6 :
				break;
				
			default :
				system("color 74");
				printf("\n\aPilihan menu tidak tersedia.\n\n\n");
				Sleep(2000); system("CLS"); 
	           	system("color 07");
				break;
		} 
	} while(bantuan!=6);
	
	system("pause"); system("CLS"); 
}

//func untuk memberikan struk pembayaran serta data user yang diinput
void Struk(Data *pelanggan, int i){
	int loop;
	
	//mengeprint struk sesuai pesanan yang tersedia
	for (loop=0; loop<i; loop++){
		printf("_______________________________________________(%d)\n", loop+1);
		printf("                 HONESTY PARKING\n             UNIVERSITY OF INDONESIA\n");
		printf("   ============================================\n   ============================================\n\n");
		printf("     Nama                     : %s \n", (pelanggan+loop)->nama);
		printf("     Kendaraan yang Digunakan : %s \n", (pelanggan+loop)->namaKendaraan);
		printf("     Tempat Parkir            : %s \n", (pelanggan+loop)->namaTempat);
		printf("     Jam Masuk Parkir         : %d.00 \n", (pelanggan+loop)->jam1);
		printf("     Jam Keluar Parkir        : %d.00 \n", (pelanggan+loop)->jam2);
		printf("     Lama Durasi Parkir       : %d jam\n", (pelanggan+loop)->lamaParkir);
		printf("     Total Biaya Parkir       : Rp %d \n\n", (pelanggan+loop)->biaya);
		printf("   ============================================\n   ============================================\n\n");
	}
	
	//kondisi ketika user belum memesan tempat parkir sama sekali
	if (i<1){
		printf("Anda belum parkir ditempat mana pun\nSilahkan pilih tempat parkir dahulu untuk mendapat data parkiran\n\n");
		system("pause"); system("CLS"); 
	}
}


