#include "header.h"

void initData(Komputer k[row][col]){
	Komputer *ptrData;
	int i=1;

	for(ptrData = &k[0][0]; ptrData <= &k[row-1][col-1]; ptrData++){
		(*ptrData).id = i++;
		(*ptrData).kapasitas = 0;
		strcpy((*ptrData).status, "-");
		strcpy((*ptrData).nama, "-");
		strcpy((*ptrData).waktu, "-");
	}
}

Komputer editData(int id, int kapasitas, string status, string nama, string waktu){
	Komputer k;
	
	k.id = id;
	k.kapasitas = kapasitas;
	strcpy(k.status, status);
	strcpy(k.nama, nama);
	strcpy(k.waktu, waktu);

	return k;
}

void printData(Komputer *DPtr){
	printf("\n\tID - %d", (*DPtr).id);
	printf("\n\tKapasitas	: %d Orang", (*DPtr).kapasitas);
	printf("\n\tStatus		: %s", (*DPtr).status);
	printf("\n\tNama Pemesan	: %s", (*DPtr).nama);
	printf("\n\tWaktu Reservasi	: %s\n", (*DPtr).waktu);
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

