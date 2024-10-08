#include "header.h"

int main(int argc, char *argv[]) {
	int menu, subMenu;
	int search;
	string nama, status, jenis;
	char conf;
	int durasi;
	Komputer k[row][col];
	Komputer *ptr;
	Komputer temp;
	Komputer *DPtr = &k[0][0];

	initData(k);

	do{
		system("cls");
		printData(DPtr);
		printf("\n\n\t\t=== Klinik Gigi Berseri ===");
		printf("\n\t1. Point Data");
		printf("\n\t2. Isi Data");
		printf("\n\t3. Ubah Data");
		printf("\n\t4. Hapus Data");
		printf("\n\n\t\t=== Tugas ===");
		printf("\n\t5. Pindah Posisi");
		printf("\n\t0. Exit");
		printf("\n\t>>> "); scanf("%d", &menu);

		switch(menu){
			case 1:
				do{
					system("cls");
					printf("\t\t=== Posisi Sekarang ===\n");
					printData(DPtr);
					printf("\n\t\t=== Point Data ===");
					printf("\n\t1. Pilih dengan Id");
					printf("\n\t2. Geser Kiri");
					printf("\n\t3. Geser Kanan");
					printf("\n\t4. Geser Diagonal Bawah");
					printf("\n\t0. Kembali");
					printf("\n\t>>> "); scanf("%d", &subMenu);

					switch(subMenu){
						case 1:
							printf("\n\tMasukan Id (1-25) : "); scanf("%d", &search);
							if(search < 1 || search > 25){
								printf("\n\t\t[*] Id tidak ditemukan");
								break;
							}
							DPtr = cariData(k, search);
							printf("\n\t\t[*] Berhasil Geser");
							break;

						case 2:
							if(DPtr == &k[0][0]){
								printf("\n\t\tIndex sudah di ujung [!]");
								break;
							}
							DPtr--;
							printf("\n\t\t[*] bergeser ke Id - %d", (*DPtr).id);
							break;

						case 3:
							if(DPtr == &k[row-1][col-1]){
								printf("\n\t\tIndex sudah di ujung [!]");
								break;
							}
							DPtr++;
							printf("\n\t\t[*] bergeser ke Id - %d", (*DPtr).id);
							break;
							
	  					case 4:
	  						if(DPtr->id > 20 || (DPtr->id - 1) % 5 == 0){
								printf("\n\t\tMentok Gan [!]");
								break;
							}
							DPtr += 4;
							printf("\n\t\t[*] bergeser ke Id - %d", (*DPtr).id);
							break;

						case 0:
							printf("\n\t\t");
							system("pause");
					}
					getch();
				}while(subMenu!=0);
				break;

			case 2:
				if(strcmpi((*DPtr).nama, "-")!=0){
					printf("\n\t\tData Sudah Di Isi [!]");
					getch();
					break;
				}
				system("cls");
				printf("\n\tMasukkan Data: ");
				do{
					printf("\n\tNama Dokter			: "); fflush(stdin); gets(nama);
					if(strlen(nama)==0 || strcmp(nama, "-")==0){
						printf("\n\t\tInput Tidak boleh Kosong atau '-'\n");
					}
				}while(strlen(nama)==0);
				do{
					printf("\n\tJenis Perawatan			: "); fflush(stdin); gets(jenis);
					if(strlen(jenis)==0 || strcmp(jenis, "-")==0){
						printf("\n\t\tInput Tidak boleh Kosong atau '-'\n");
					}
				}while(strlen(jenis)==0 || strcmp(jenis, "-")==0);
				do{
					printf("\n\tStatus Ruang			: "); fflush(stdin); gets(status);
					if(strcmpi(status, "Tersedia")!=0 && strcmpi(status, "Sedang Digunakan")!=0){
						printf("\n\t\tInput Harus 'Tersedia' atau 'Sedang Digunakan'\n'");
					}
				}while(strcmpi(status, "Tersedia")!=0 && strcmpi(status, "Sedang Digunakan")!=0);
				do{
					printf("\n\tDurasi Perawatan		: "); scanf("%d", &durasi);
					if(durasi <= 0){
						printf("\n\t\tDurasi Perawatan Tidak Boleh <= 0\n");
					}
				}while(durasi <= 0);
				*DPtr = editData((*DPtr).id, nama, jenis, status, durasi);
				printf("\n\t\t[*] Data Berhasil Diisi");
				getch();
				break;
				
			case 3:
				if(strcmpi((*DPtr).nama, "-")==0){
					printf("\n\t\tData Masih Kosong [!]");
					getch();
					break;
				}
				system("cls");
				printf("\n\tUbah Data: ");
				do{
					printf("\n\tNama Dokter			: "); fflush(stdin); gets(nama);
					if(strlen(nama)==0 || strcmp(nama, "-")==0){
						printf("\n\t\tInput Tidak boleh Kosong atau '-'\n");
					}
				}while(strlen(nama)==0);
				do{
					printf("\n\tJenis Perawatan			: "); fflush(stdin); gets(jenis);
					if(strlen(jenis)==0 || strcmp(jenis, "-")==0){
						printf("\n\t\tInput Tidak boleh Kosong atau '-'\n");
					}
				}while(strlen(jenis)==0 || strcmp(jenis, "-")==0);
				do{
					printf("\n\tStatus Ruang			: "); fflush(stdin); gets(status);
					if(strcmpi(status, "Tersedia")!=0 && strcmpi(status, "Sedang Digunakan")!=0){
						printf("\n\t\tInput Harus 'Tersedia' atau 'Sedang Digunakan'\n'");
					}
				}while(strcmpi(status, "Tersedia")!=0 && strcmpi(status, "Sedang Digunakan")!=0);
				do{
					printf("\n\tDurasi Perawatan		: "); scanf("%d", &durasi);
					if(durasi <= 0){
						printf("\n\t\tDurasi Perawatan Tidak Boleh <= 0\n");
					}
				}while(durasi <= 0);
				*DPtr = editData((*DPtr).id, nama, jenis, status, durasi);
				printf("\n\t\t[*] Data Berhasil Diubah");
				getch();
				break;
				
			case 4:
				if(strcmpi((*DPtr).nama, "-")==0){
					printf("\n\t\tData Masih Kosong [!]");
					getch();
					break;
				}
				system("cls");
				printf("\n\tAnda Yakin ingin menghapus data? (Y/N) : "); conf = getche();
				if(conf == 'Y' || conf == 'y'){
					*DPtr = editData((*DPtr).id, "-", "-", "-", 0);
					printf("\n\t\t[*] Data Berhasil Dihapus");
				}else{
					printf("\n\t\t[*] Data Batal Dihapus");
				}
				getch();
				break;
					
			case 5:
				printf("\n\tMasukan Id (1-25) : "); scanf("%d", &search);
				if(search < 1 || search > 25){
					printf("\n\t\t[*] Id tidak ditemukan");
					getch();
					break;
				}
				ptr = cariData(k, search);
				if((*ptr).durasi!=0){
					printf("\n\t\tData yang dituju sudah terisi !!\n\n");
				}else{
					temp = editData((*DPtr).id, (*ptr).nama, (*ptr).jenis, (*ptr).status, (*ptr).durasi);
					*ptr = editData((*ptr).id, (*DPtr).nama, (*DPtr).jenis, (*DPtr).status, (*DPtr).durasi);
					*DPtr = temp;
					DPtr = ptr;
					printf("\n\t\t[*] Berhasil Pindah Data");
				}
				getch();
				break;
				
			case 0:
			printf("\n\t\tNama Lengkap - NPM - Kelas");
			getch();
			break;
		}
	}while(menu!=0);
	return 0;
}
