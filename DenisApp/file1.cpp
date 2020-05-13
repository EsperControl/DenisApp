#include "file1.h" // header in local directory
#include "file2.h"
#include "file3.h"
#include <iostream> // header in standard library
#include <stdio.h>
#include <fstream>
#include <filesystem>
#include <string>

BookStore Data[MAX_SIZE] =
{
{ "�������","���������","10�",100,10 },
{ "�������2","���������3","11�",101,11 },
{ "�������3","���������3","12�",102,12 },
};

unsigned Count = 3;
//BookStore *dataPointer;
//dataPointer = &Data;
eCMD Menu()
{
	//���� ��� ������ ����, ���� ����� ����������� �������
	while (true)
	{
		system("cls"); //������� ������
		puts("�������� �������� : "); //����������� ����
		puts("0 - �������� ������ ");
		puts("1 - ������� ���� ");
		puts("2 - �������� ������");
		puts("4 - ����� �� ���������");
		unsigned opt;
		fflush(stdin); //��������� �������� ������
		scanf_s("%u" , &opt);
		switch (opt) 
		{ //������� �� ������� �������
			case 0: return CMD_MONITOR;
			case 1: return CMD_READ;
			case 2: return CMD_SHOW;
			case 4: return CMD_EXIT;
			default: puts("�� ����� ������������ �������");
				system("pause");

		}
	}
}
int main(int argc, char* argv[])
{
	system("chcp 1251");
	eCMD cmd = CMD_NONE;
	while (true) //���� ��� ��������� ������ ��������� ����
	{
		if (cmd == CMD_EXIT) break; //����� �� �����
		cmd = Menu(); //����������� ���� � ���� ������
		switch (cmd) //����� ������� ��� ��������������� �������
		{
			case CMD_MONITOR:MonitorFiles();
			case CMD_SHOW: ShowData(Data, Count); break;
			case CMD_READ: ReadDatabase(Data, Count); break;
		}
	}
	puts("������ ���������");
	system("pause");
	return 0;
}