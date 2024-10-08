#include "header.h"

void initData(Komputer k[row][col]){
	Komputer *ptrData;
	int i=1;

	for(ptrData = &k[0][0]; ptrData <= &k[row-1][col-1]; ptrData++){
		(*ptrData).id = i++;
		strcpy((*ptrData).nama, "-");
		(*ptrData).kapasitas = 0;
		strcpy((*ptrData).status, "-");
		(*ptrData).pop = 0;
	}
}

Komputer editData(int id, string nama, int kapasitas, string status, int pop){
	Komputer k;
	
	k.id = id;
	strcpy(k.nama, nama);
	k.kapasitas = kapasitas;
	strcpy(k.status, status);
	k.pop = pop;

	return k;
}

void printData(Komputer *DPtr){
	printf("\n\tID - %d", (*DPtr).id);
	printf("\n\tNama Wahana		: %s", (*DPtr).nama);
	printf("\n\tKapasitas		: %d Orang", (*DPtr).kapasitas);
	printf("\n\tStatus			: %s", (*DPtr).status);
	printf("\n\tTingkat Popularitas	: %d / 10\n", (*DPtr).pop);
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

