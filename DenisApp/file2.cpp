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
	printf("Использовать текущий файл(1) или создать новый(2): ");
	fflush(stdin); 
	scanf("%s", &opt);
	if (opt == 2) {
		//Сделать защиту от дурака
		printf("Введите имя файла: ");
		scanf("%s", filename);
	}
	FILE* inp =fopen(filename, "wb");
	fwrite(&count, sizeof(unsigned), 1, inp);
	Cipher(data, count);
	fwrite(data, sizeof(BookStore), count, inp);
	fclose(inp);
}

void CReadHidden(BookStore* data, unsigned count, char* filename)
{

	FILE* inp = fopen(filename, "rb");
	if (inp == NULL) {
		printf("Файл не найден,создан пустой файл");
		inp = fopen(filename, "wb");
		count = 0;
	}
	else {
		fseek(inp, 0, 0);
		unsigned new_count=0;
		fread(&new_count, sizeof(unsigned), 1, inp);
		fread(data, sizeof(BookStore), new_count, inp);
		DeCipher(data, new_count);
		fclose(inp);
		count = new_count;
	}
}

void CRead(BookStore* data, unsigned& count, char* filename)
{
	int opt;
	printf("Использовать текущий файл(1) или создать новый(2): ");
	fflush(stdin);
	scanf("%s", &opt);
	if (opt == 2) {
		//Сделать защиту от дурака
		printf("Введите имя файла: ");
		scanf("%s", filename);
	}
	FILE* inp = fopen(filename, "rb");
	if (inp == NULL) {
		printf("Файл не найден,создан пустой файл");
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
	//Сделать защиту от дурака
	char filename[20];
	printf("Введите имя файла: ");
	fflush(stdin);
	scanf("%s", &filename);
	FILE* inp = fopen(filename, "w");
	fprintf(inp, "%d\n", count);
	for (unsigned i = 0; i < count; i++) {
		fprintf(inp,"%s,%s,%s,%f,%d\n",
			data[i].author,
			data[i].bookName,
			data[i].code,
			data[i].price,
			data[i].count);
	}
	fclose(inp);
}

void CSVRead(BookStore* data, unsigned &count) {
	char filename[20];
	printf("Введите имя файла: ");
	//Сделать защиту от дурака
	fflush(stdin);
	scanf("%s", &filename);
	FILE* inp = fopen(filename, "r");
	fscanf(inp, "%d", &count);
	int temp = count;
	char buffer[1000];
	int c1 = 0;
	int c2 = 1;
	int point = 0;
	char subbuff[16] = "";

	for (int i = -1; i <= temp; i++) {
		std::cout << i<<"\n";
		fgets(buffer, 1000, inp);
		puts(buffer);
		c1 = 0;
		c2 = 1;
		point = 0;
		for (c2 = 1; c2 < 1000; c2++) {
			if (buffer[c2] == ',' || buffer[c2] == '\n') {
				memset(subbuff, 0, sizeof(subbuff));
				memcpy(subbuff, &buffer[c1], c2 - c1);			
				switch (point) {
				case 0:
					memcpy(data[i].author, subbuff, sizeof(subbuff));
					//*data[i].author = (char)subbuff;
					printf("%s = %s\n", data[i].author,subbuff);
					point++;
					break;
				case 1:
					memcpy(data[i].bookName, subbuff, sizeof(subbuff));
					printf("%s = %s\n", data[i].bookName, subbuff);
					point++;
					break;
				case 2:
					memcpy(data[i].code, subbuff, sizeof(subbuff));
					printf("%s = %s\n", data[i].code, subbuff);
					point++;
					break;
				case 3:
					data[i].price = (float)atof(subbuff);
					point++;
					break;
				case 4:
					data[i].count = atoi(subbuff);
					point++;
					break;
				}
				c1 = c2 + 1;
				
			}
			
		}
		
	}

	fclose(inp);
	system("pause");

}

