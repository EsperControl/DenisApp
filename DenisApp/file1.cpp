#include "file1.h" // header in local directory
#include "file2.h"
#include "file3.h"
#include <iostream> // header in standard library
#include <stdio.h>
#include <fstream>
#include <filesystem>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
BookStore Data[MAX_SIZE] =
{
{ "asd","sdfsdfsdf","10A",100,10 },
{ "asd1","sdfsdfg","11A",101,11 },
{ "asd22","sdfsdfsdff","12A",102,12 },
};
char FileName[20] = "SuperDataBin.bin";
unsigned Count = 3;

eCMD Menu()
{
	//���� ��� ������ ����, ���� ����� ����������� �������
	while (true)
	{
		system("cls"); //������� ������
		std::cout << "Global data address" << &Data << "\n";
		std::cout << "Global count address" << &Count << "\n";
		std::cout << "Global count value" << Count << "\n";
		puts("�������� �������� : "); //����������� ����
		puts("1 - ������� ���� ");
		puts("2 - �������� ������");
		puts("3 - ��������� ����");
		puts("4 - ��������� ���� CSV");
		puts("5 - ����� �� ���������");
		unsigned opt;
		fflush(stdin); //��������� �������� ������
		scanf_s("%u" , &opt);
		switch (opt) 
		{ //������� �� ������� �������
		case 1: return CMD_READ; break;
			case 2: return CMD_SHOW; break;
			case 3: return CMD_SAVE; break;
			case 4: return CMD_SAVECSV; break;
			case 5: return CMD_EXIT; break;
			default: puts("�� ����� ������������ �������");
				system("pause");


		}
	}
}


int main(int argc, char* argv[])
{
	std::cout << argc << "\n";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << "\n";
	}
	if (argc == 2) {
		strcpy(FileName,argv[1]);
	}
	else if (argc > 2) {
		puts("��������� ������� �� �����, ������ �� ���������");
	}
	system("chcp 1251");
	eCMD cmd = CMD_NONE;
	while (true) //���� ��� ��������� ������ ��������� ����
	{
		if (cmd == CMD_EXIT) break; //����� �� �����
		cmd = Menu(); //����������� ���� � ���� ������
		switch (cmd) //����� ������� ��� ��������������� �������
		{
			case CMD_SHOW: ShowData(Data, Count); break;
			case CMD_READ: CRead(Data, Count,FileName); break;
			case CMD_SAVE: 
				CSave(Data, Count, FileName); 
				CReadHidden(Data, Count, FileName);
				break;
			case CMD_SAVECSV:
				CSVSave(Data, Count);
				break;
		}
	}
	puts("������ ���������");
	system("pause");
	return 0;
}