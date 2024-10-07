#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define row 5
#define col 5

typedef char string[128];

typedef struct{
	int id;
	int kapasitas;
	string status;
	string nama;
	string waktu;
}Komputer;

void initData(Komputer k[row][col]);
Komputer editData(int id, int kapasitas, string status, string nama, string waktu);
void printData(Komputer *DPtr);
Komputer *cariData(Komputer k[row][col], int search);
