#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Penderita{
	int JumlahPenderita;
	char kecamatan[20];
	char status[20];
};

int TotalPenderita (struct Penderita x[], int n){			//function ini untuk menghitung total penderita di setiap kecamatan yang telah diinput
	int i=0, total=0;
	for (i=0; i<n; i++){
	total = total + x[i].JumlahPenderita;
	}
	return total;
}

void Zona (struct Penderita x[], int n){					//function ini untuk mencetak hasil data yang telah diinput
	printf ("Nama Kecamatan : %s \n", x[n].kecamatan);
	printf ("Jumlah Penderita : %d \n", x[n].JumlahPenderita);
	printf ("Status : %s \n", x[n].status);	
}

void Help (){				//function ini untuk mencetak panduan dari keseluruhan program jika user bingung dalam pengoperasian
	printf ("\nPanduan\n");
	printf ("1. Pilihan menu 1 merupakan menu untuk menginput data nama kecamatan dan jumlah penderita di kecamatan tersebut.\n");
	printf ("2. Anda akan diinstruksikan untuk mengisi berapa jumlah kecamatan yang akan didata.\n");
	printf ("3. Nama kecamatan yang diinput tidak diperbolehkan memakai spasi! Contoh: PasarMinggu.\n");
	printf ("4. Anda dapat menginput data kecamatan kurang dari jumlah kecamatan yang diinginkan diawal.\n");
	printf ("5. Pilihan menu 2 merupakan menu untuk melihat hasil pendataan.\n");
	printf ("6. Pilihan menu 4 merupakan menu untuk mengetahui klasifikasi zona berdasarkan jumlah penderita.\n");
	printf ("7. Pilihan menu 5 merupakan menu untuk menyelesaikan program.\n");
}

struct Penderita status(struct Penderita x[], int n){				//function ini untuk mengklasifikasikan zona dengan acuan jumlah penderita yang diinput user
		if (x[n].JumlahPenderita == 0){
	   	strcpy(x[n].status, "ZONA HIJAU");
	   	return x[n];
		}
	 	else if (x[n].JumlahPenderita > 0 && x[n].JumlahPenderita <= 30) {
		strcpy(x[n].status, "ZONA KUNING");
		return x[n];
		}
	  	else if (x[n].JumlahPenderita > 30 && x[n].JumlahPenderita <= 100) {
	    strcpy(x[n].status, "ZONA MERAH");
	    return x[n];
		}
	  	else if (x[n].JumlahPenderita > 100) {
	    strcpy(x[n].status, "ZONA HITAM");
	    return x[n];
		}
}

int main(){
	system("COLOR 70");				//mengubah warna background program
	int pilihan, HasilData, JumlahKecamatan, Total, acc;
	int i, j;
	int totalhijau;
	struct Penderita *JakartaSelatan;			//menyimpan data struct penderita menjadi struct JakartaSelatan menggunakan pointer
	char x[4][10] = {
						"Hijau",
						"Kuning",
						"Merah",
						"Hitam"
					};
	
	printf("\n");
	printf ("				Program Pendataan Penderita COVID-19 di Jakarta Selatan				\n\n");
    JakartaSelatan = (struct Penderita*) calloc(JumlahKecamatan, sizeof(struct Penderita));	
	    
	do {				//menu program akan tercetak selagi user tidak memilih pilihan menu 4
	 printf ("\n\t\t\t\t\t\t  Silahkan Pilih Menu : \n");
	 printf ("\t\t\t\t\t\t     1. Isi Data \n\t\t\t\t\t\t     2. Hasil Data \n\t\t\t\t\t\t     3. Panduan \n\t\t\t\t\t\t     4. Klasifikasi Zona \n\t\t\t\t\t\t     5. Keluar Program \n");
	 printf ("\t\t\t\t\t\t     Pilihan : "); 
	 scanf ("%d", &pilihan);
		switch(pilihan){
		 	case(1): 
		 	printf ("\nMasukkan jumlah kecamatan yang ingin didata: ");
			scanf ("%d", &JumlahKecamatan);
		 		for (i=0; i<JumlahKecamatan; i++){
			   	printf ("\nMasukkan nama kecamatan : ");
			   	scanf ("%s", &JakartaSelatan[i].kecamatan);
			   	printf ("Masukkan jumlah penderita : ");
			   	scanf ("%d", &JakartaSelatan[i].JumlahPenderita);
			   	JakartaSelatan[i] =  status(JakartaSelatan, i);				//memanggil function status untuk mengolah klasifikasi zona
			   	if(i<JumlahKecamatan-1){
			   		printf ("Apakah ingin memasukkan data lagi? 1(YES)/0(NO)\n");
			   		scanf ("%d", &acc);
				   	if (acc == 1){
				   		continue;
				   		}
				   	else if (acc == 0){
				   		break;
					   }
				   }
				}	
				break;
				
			case(3):
			   	Help ();				//memanggil function help untuk mencetak menu panduan
			  	break;
			   
			case(2):
				printf ("\n");
			  	printf ("\t---------------Hasil Pendataan Jumlah Penderita Covid-19 di Kotamadya Jakarta Selatan---------------\n\n");
			  	printf ("Jumlah total penderita COVID-19 di kecamatan yang didata: "); 
			  	Total = TotalPenderita (JakartaSelatan, i);			//memanggil function total penderita untuk menghitung total penderita dari semua kecamatan
			  	printf ("%d\n", Total);
			  	for (j = 0;  j < i; j++){
			  		printf ("%d.", j+1);
  					Zona (JakartaSelatan, j);				//memanggil function zona untuk mencetak klasifikasi zona setiap kecamatan beserta nama dan jumlah penderitanya
  					printf("\n");
					}
				break;
				
			case(5):
				break;
			
			case(4) :				//untuk memberi informasi user bagaimana pengklasifikasian zona berdasarkan jumlah penderitanya
				printf ("\nZona %s  = 0 penderita", x[0]);
				printf ("\nZona %s = 0 < penderita <= 30", x[1]);
				printf ("\nZona %s  = 30 < penderita <= 100", x[2]);
				printf ("\nZona %s  = penderita > 100", x[3]);
				break;
					
				
			default: printf ("\t\t\t\t\t\tMaaf, pilihanmu tidak tersedia.\n\t\t\t\t\t\tPilih angka 1 sampai 4.\n");
			break;
			
			}
	}while (pilihan != 5);

	if (pilihan == 5) {
  		printf ("\n");
  		printf ("\t\t\t\t\t\tTerima kasih! Sehat selalu, ya!");	
		}
	return 0;
}
