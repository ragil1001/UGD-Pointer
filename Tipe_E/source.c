#include "header.h"

void initData(Komputer k[row][col]){
	Komputer *ptrData;
	int i=1;

	for(ptrData = &k[0][0]; ptrData <= &k[row-1][col-1]; ptrData++){
		(*ptrData).id = i++;
		strcpy((*ptrData).nama, "-");
		(*ptrData).durasi = 0;
		strcpy((*ptrData).status, "-");
		strcpy((*ptrData).jenis, "-");
	}
}

Komputer editData(int id, string nama, string jenis, string status, int durasi){
	Komputer k;
	
	k.id = id;
	strcpy(k.nama, nama);
	k.durasi = durasi;
	strcpy(k.status, status);
	strcpy(k.jenis, jenis);

	return k;
}

void printData(Komputer *DPtr){
	printf("\n\tID - %d", (*DPtr).id);
	printf("\n\tNama Dokter		: %s", (*DPtr).nama);
	printf("\n\tJenis Perawatan		: %s", (*DPtr).jenis);
	printf("\n\tStatus Ruang		: %s", (*DPtr).status);
	printf("\n\tDurasi Perawatan	: %d Menit\n", (*DPtr).durasi);
}

Komputer *cariData(Komputer k[row][col], int search){
	int i, j;
	
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(k[i][j].id == search){
				return &k[i][j];
			}
		}
	}
}



