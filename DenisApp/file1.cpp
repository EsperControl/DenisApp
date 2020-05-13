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
{ "Донцова","Проходняк","10А",100,10 },
{ "Донцова2","Проходняк3","11А",101,11 },
{ "Донцова3","Проходняк3","12А",102,12 },
};

unsigned Count = 3;
//BookStore *dataPointer;
//dataPointer = &Data;
eCMD Menu()
{
	//цикл для вывода меню, если ввели неправильно команду
	while (true)
	{
		system("cls"); //очистка экрана
		puts("Выберите действие : "); //отображение меню
		puts("0 - Просмотр файлов ");
		puts("1 - Открыть файл ");
		puts("2 - Просмотр данных");
		puts("4 - Выход из программы");
		unsigned opt;
		fflush(stdin); //обнуление входного потока
		scanf_s("%u" , &opt);
		switch (opt) 
		{ //возврат из функции команды
			case 0: return CMD_MONITOR;
			case 1: return CMD_READ;
			case 2: return CMD_SHOW;
			case 4: return CMD_EXIT;
			default: puts("Вы ввели неправильную команду");
				system("pause");

		}
	}
}
int main(int argc, char* argv[])
{
	system("chcp 1251");
	eCMD cmd = CMD_NONE;
	while (true) //цикл для обработки команд основного меню
	{
		if (cmd == CMD_EXIT) break; //выход из цикла
		cmd = Menu(); //отображение меню и ввод команд
		switch (cmd) //вызов функции для соответствующей команды
		{
			case CMD_MONITOR:MonitorFiles();
			case CMD_SHOW: ShowData(Data, Count); break;
			case CMD_READ: ReadDatabase(Data, Count); break;
		}
	}
	puts("Работа закончена");
	system("pause");
	return 0;
}