#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define row 5
#define col 5

typedef char string[128];

typedef struct{
	int id;
	string nama;
	int kapasitas;
	string status;
	int pop;
}Komputer;

void initData(Komputer k[row][col]);
Komputer editData(int id, string nama, int kapasitas, string status, int pop);
void printData(Komputer *DPtr);
Komputer *cariData(Komputer k[row][col], int search);
