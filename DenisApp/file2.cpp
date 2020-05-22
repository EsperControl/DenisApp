#include "file1.h" //содержит информацию о TRec*
#include <iostream> // header in standard library
#include <stdio.h>
#include <fstream>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
void Cezar(char* mystring, int size, int step);
void Cipher(BookStore* data, unsigned count);
void DeCipher(BookStore* data, unsigned count);


void CSave(BookStore *data, unsigned count, char* filename)
{
	int opt;
	printf("»спользовать текущий файл(1) или создать новый(2): ");
	fflush(stdin); 
	scanf("%s", &opt);
	if (opt == 2) {
		printf("¬ведите им€ файла: ");
		scanf("%s", filename);
	}
	FILE* inp =fopen(filename, "wb");
	fwrite(&count, sizeof(unsigned), 1, inp);
	Cipher(data, count);
	fwrite(data, sizeof(BookStore), count, inp);
	fclose(inp);
	system("pause");
}

void CReadHidden(BookStore* data, unsigned count, char* filename)
{

	FILE* inp = fopen(filename, "rb");
	if (inp == NULL) {
		printf("‘айл не найден,создан пустой файл");
		inp = fopen(filename, "wb");
		count = 0;
	}
	else {
		fseek(inp, 0, 0);
		unsigned new_count;
		fread(&new_count, sizeof(unsigned), 1, inp);
		fread(data, sizeof(BookStore), new_count, inp);
		DeCipher(data, new_count);
		fclose(inp);
		count = new_count;
		system("pause");
	}
}

void CRead(BookStore* data, unsigned& count, char* filename)
{
	int opt;
	printf("»спользовать текущий файл(1) или создать новый(2): ");
	fflush(stdin);
	scanf("%s", &opt);
	if (opt == 2) {
		printf("¬ведите им€ файла: ");
		scanf("%s", filename);
	}
	FILE* inp = fopen(filename, "rb");
	if (inp == NULL) {
		printf("‘айл не найден,создан пустой файл");
		inp = fopen(filename, "wb");
		count = 0;
	}
	else {
		fseek(inp, 0, 0);
		unsigned new_count;
		fread(&new_count, sizeof(unsigned), 1, inp);
		fread(data, sizeof(BookStore), new_count, inp);
		DeCipher(data, new_count);
		fclose(inp);
		count = new_count;
		system("pause");
	}
}

void Cipher(BookStore* data, unsigned count) {
		for (unsigned i = 0; i < count; i++) {
			Cezar(data[i].author, strlen(data[i].author), 1);
			Cezar(data[i].bookName, strlen(data[i].bookName), 1);
			Cezar(data[i].code, strlen(data[i].code), 1);
			data[i].price = pow(data[i].price,2);
			data[i].count = pow(data[i].count, 2);
		}
	}

void DeCipher(BookStore* data, unsigned count){
		for (unsigned i = 0; i < count; i++) {
			Cezar(data[i].author, strlen(data[i].author), -1);
			Cezar(data[i].bookName, strlen(data[i].bookName), -1);
			Cezar(data[i].code, strlen(data[i].code), -1);
			data[i].price = pow(data[i].price,0.5);
			data[i].count = pow(data[i].count, 0.5);
		}

	}

void Cezar(char* mystring, int size, int step) {
		if (step > 0) {
			for (int i=0; i < size; i++) {
				mystring[i] += step;
			}
		}
		else {
			for (int i=0; i < size; i++) {
				mystring[i] += step;
			}
		}

	}

void CSVSave(BookStore* data, unsigned count) {
	char filename[20];
	printf("¬ведите им€ файла: ");
	fflush(stdin);
	scanf("%s", &filename);
	FILE* inp = fopen(filename, "w");
	for (unsigned i = 0; i < count; i++) {
		fprintf(inp,"%s,%s,%s,%f,%d\n",
			data[i].author,
			data[i].bookName,
			data[i].code,
			data[i].price,
			data[i].count);
	}
	fclose(file);
}

void CSVRead(BookStore* data, unsigned count) {
	char filename[20];
	printf("¬ведите им€ файла: ");
	fflush(stdin);
	scanf("%s", &filename);
	FILE* inp = fopen(filename, "w");

}

