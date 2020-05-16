#include "file1.h" //�������� ���������� � TRec*
#include <iostream> // header in standard library
#include <stdio.h>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


void CSave(BookStore *data, unsigned count, char* fileName)
{

	printf("������� ��� �����: ");
	char filename[20];
	scanf("%s",filename);
	FILE* inp =fopen(filename, "wb");

	cout << "New count is:" << count << "\n";
	fwrite(&count, sizeof(unsigned), 1, inp);

	fwrite(data, sizeof(BookStore), count, inp);
	fclose(inp);
	system("pause");
}


void CRead(BookStore *data, unsigned &count, char* fileName)
{

	printf("������� ������� ����(1) ��� ����� ����(2): ");
	unsigned opt;
	scanf("%u",opt);
	FILE* inp = fopen(fileName, "rb");
	switch (opt)
	{
	case 1:
		break;
	case 2:
		puts("������� ��� �����: ");
		scanf("%s", fileName);
		inp = fopen(fileName, "rb");
		break;
	}
	if (inp == NULL) {
		printf("���� �� ������,������ ������ ����");
		inp = fopen(fileName, "wb");
		count = 0;
	}
	else {
		fseek(inp, 0, 0);
		unsigned new_count;
		fread(&new_count, sizeof(unsigned), 1, inp);

		fread(data, sizeof(BookStore), new_count, inp);
		fclose(inp);
		count = new_count;
		system("pause");
	}

	
	

}
