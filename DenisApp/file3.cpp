#include "file1.h" //�������� ���������� � TRec*
#include <iostream> // header in standard library
#include <stdio.h>
eCMD MenuShow()
{
	while (true)
	{
		puts("\n�������� �������� : ");
		puts(" 1 - �������������"); //����������� ����
		unsigned opt;
		fflush(stdin); //��������� �������� ������
		scanf_s("%u" , &opt);
		switch (opt) { //������� �� ������� �������
			case 1: return CMD_EDIT;
			case 6: return CMD_EXIT;
			default: puts("�� ����� ������������ ������� ");
				system("pause");
		}
	}
}
void EditRecord(BookStore* data, unsigned count)
{

}
void AddRecord(BookStore* data, unsigned& count)
{

}
void ShowData(BookStore *data, unsigned &count) 
{
	eCMD cmd = CMD_NONE;
	while (cmd != CMD_EXIT)
	{
		system("cls");
		printf("______________________________________________________________________\n");
		printf("|%16s|%16s|%16s|     ���.|     ��.|\n",
			"�����",
			"�����",
			"�����");
		for (int i = 0; i < count; i++) {
			printf("______________________________________________________________________\n");
			printf("|%16s|%16s|%16s|%4i ���.|%3i ��.|\n",
					data[i].author,
					data[i].bookName,
					data[i].code,
					data[i].price,
					data[i].count);
		}
		cmd = MenuShow(); //����������� ���� � ���� ������
		switch (cmd) //����� ������� ��� ��������������� �������
		{
		case CMD_EDIT: 
			EditRecord(data, count);
			break;
		}
	}
}

