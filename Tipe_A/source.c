#include "header.h"

void initData(Komputer k[row][col]){
	Komputer *ptrData;
	int i=1;

	for(ptrData = k[0][0]; ptrData != &k[row][0]; ptrData++){
		(*ptrData).id = i++;
		strcpy((*ptrData).merk, "-");
		(*ptrData).harga_sewa = 0;
		strcpy((*ptrData).status, "-");
		strcpy((*ptrData).tanggal_pembelian, "-");
	}
}

Komputer editData(int id, string merk, float harga_sewa, string status, string tanggal_pembelian){
	Komputer k;
	
	k.id = id;
	strcpy(k.merk, merk);
	k.harga_sewa = harga_sewa;
	strcpy(k.status, status);
	strcpy(k.tanggal_pembelian, tanggal_pembelian);

	return k;
}

void printData(Komputer *DPtr){
	printf("\n\tID - %d", (*DPtr).id);
	printf("\n\tMerk			: %s", (*DPtr).merk);
	printf("\n\tHarga Sewa / Jam	: Rp.%.2f", (*DPtr).harga_sewa);
	printf("\n\tStatus			: %s", (*DPtr).status);
	printf("\n\tTanggal Pembelian	: %s\n", (*DPtr).tanggal_pembelian);
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

