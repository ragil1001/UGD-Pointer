#include "header.h"

int main(int argc, char *argv[]) {
	int menu, subMenu;
	int search;
	string merk, status, tanggal_pembelian;
	float harga_sewa;
	char conf;
	Komputer k[row][col];
	Komputer *ptr;
	Komputer temp;
	Komputer *DPtr = &k[0][0];

	initData(k);

	do{
		system("cls");
		printData(DPtr);
		printf("\n\n\t\t=== NetBersama ===");
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
					printf("\n\t4. Geser Bawah");
					printf("\n\t0. Kembali");
					printf("\n\t>>> "); scanf("%d", &subMenu);

					switch(subMenu){
						case 1:
							printf("\n\tMasukan Id (1-20) : "); scanf("%d", &search);
							if(search < 1 || search > 20){
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
						    DPtr += col;
						    if (DPtr > &k[row-1][col-1]) {
						        DPtr -= 20;
						    }
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
				if(strcmpi((*DPtr).merk, "-")!=0){
					printf("\n\t\tData Sudah Di Isi [!]");
					getch();
					break;
				}
				system("cls");
				printf("\n\tMasukkan Data: ");
				do{
					printf("\n\tMerk				: "); fflush(stdin); gets(merk);
					if(strlen(merk)==0 || strcmp(merk, "-")==0){
						printf("\n\t\tInput Tidak boleh Kosong atau '-'\n");
					}
				}while(strlen(merk)==0);
				do{
					printf("\n\tHarga Sewa			: "); scanf("%f", &harga_sewa);
					if(harga_sewa <= 0){
						printf("\n\t\tHarga Sewa Tidak Boleh <= 0\n");
					}
				}while(harga_sewa <= 0);
				do{
					printf("\n\tStatus				: "); fflush(stdin); gets(status);
					if(strcmpi(status, "Baik")!=0 && strcmpi(status, "Rusak")!=0){
						printf("\n\t\tInput Hanya antara 'Baik' atau 'Rusak'\n");
					}
				}while(strcmpi(status, "Baik")!=0 && strcmpi(status, "Rusak")!=0);
				do{
					printf("\n\tTanggal Pembelian		: "); fflush(stdin); gets(tanggal_pembelian);
					if(strlen(tanggal_pembelian)==0 || strcmp(tanggal_pembelian, "-")==0){
						printf("\n\t\tInput Tidak boleh Kosong atau '-'\n");
					}
				}while(strlen(tanggal_pembelian)==0 || strcmp(tanggal_pembelian, "-")==0);
				*DPtr = editData((*DPtr).id, merk, harga_sewa, status, tanggal_pembelian);
				printf("\n\t\t[*] Data Berhasil Diisi");
				getch();
				break;

			case 3:
				if(strcmpi((*DPtr).merk, "-")==0){
					printf("\n\t\tData Masih Kosong [!]");
					getch();
					break;
				}
				system("cls");
				printf("\n\tUbah Data: ");
				do{
					printf("\n\tMerk				: "); fflush(stdin); gets(merk);
					if(strlen(merk)==0 || strcmp(merk, "-")==0){
						printf("\n\t\tInput Tidak boleh Kosong atau '-'\n");
					}
				}while(strlen(merk)==0);
				do{
					printf("\n\tHarga Sewa			: "); scanf("%f", &harga_sewa);
					if(harga_sewa <= 0){
						printf("\n\t\tHarga Sewa Tidak Boleh <= 0\n");
					}
				}while(harga_sewa <= 0);
				do{
					printf("\n\tStatus				: "); fflush(stdin); gets(status);
					if(strcmpi(status, "Baik")!=0 && strcmpi(status, "Rusak")!=0){
						printf("\n\t\tInput Hanya antara 'Baik' atau 'Rusak'\n");
					}
				}while(strcmpi(status, "Baik")!=0 && strcmpi(status, "Rusak")!=0);
				do{
					printf("\n\tTanggal Pembelian		: "); fflush(stdin); gets(tanggal_pembelian);
					if(strlen(tanggal_pembelian)==0 || strcmp(tanggal_pembelian, "-")==0){
						printf("\n\t\tInput Tidak boleh Kosong atau '-'\n");
					}
				}while(strlen(tanggal_pembelian)==0 || strcmp(tanggal_pembelian, "-")==0);
				*DPtr = editData((*DPtr).id, merk, harga_sewa, status, tanggal_pembelian);
				printf("\n\t\t[*] Data Berhasil Diisi");
				getch();
				break;
			
			case 4:
				if(strcmpi((*DPtr).merk, "-")==0){
					printf("\n\t\tData Masih Kosong [!]");
					getch();
					break;
				}
				system("cls");
				printf("\n\tAnda Yakin ingin menghapus data? (Y/N) : "); conf = getche();
				if(conf == 'Y' || conf == 'y'){
					*DPtr = editData((*DPtr).id, "-", 0, "-", "-");
					printf("\n\t\t[*] Data Berhasil Dihapus");
				}else{
					printf("\n\t\t[*] Data Batal Dihapus");
				}
				getch();
				break;
				
			case 5:
				printf("\n\tMasukan Id (1-20) : "); scanf("%d", &search);
				if(search < 1 || search > 20){
					printf("\n\t\t[*] Id tidak ditemukan");
					getch();
					break;
				}
				ptr = cariData(k, search);
				if((*ptr).harga_sewa!=0){
					printf("\n\t\tData yang dituju sudah terisi !!\n\n");
				}else{
					temp = editData((*DPtr).id, (*ptr).merk, (*ptr).harga_sewa, (*ptr).status, (*ptr).tanggal_pembelian);
					*ptr = editData((*ptr).id, (*DPtr).merk, (*DPtr).harga_sewa, (*DPtr).status, (*DPtr).tanggal_pembelian);
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
