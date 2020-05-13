#include "file1.h" //содержит информацию о TRec*
#include <iostream> // header in standard library
#include <stdio.h>
eCMD MenuShow()
{
	while (true)
	{
		puts("\nВыберите действие : ");
		puts(" 1 - Редактировать"); //отображение меню
		unsigned opt;
		fflush(stdin); //обнуление входного потока
		scanf_s("%u" , &opt);
		switch (opt) { //возврат из функции команды
			case 1: return CMD_EDIT;
			case 6: return CMD_EXIT;
			default: puts("Вы ввели неправильную команду ");
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
		printf("|%16s|%16s|%16s|     руб.|     шт.|\n",
			"автор",
			"автор",
			"автор");
		for (int i = 0; i < count; i++) {
			printf("______________________________________________________________________\n");
			printf("|%16s|%16s|%16s|%4i руб.|%3i шт.|\n",
					data[i].author,
					data[i].bookName,
					data[i].code,
					data[i].price,
					data[i].count);
		}
		cmd = MenuShow(); //отображение меню и ввод команд
		switch (cmd) //вызов функции для соответствующей команды
		{
		case CMD_EDIT: 
			EditRecord(data, count);
			break;
		}
	}
}

