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
{ "Донцова","Проходняк","10А",100,10 },
{ "Донцова2","Проходняк2","11А",101,11 },
{ "Донцова3","Проходняк3","12А",102,12 },
};
char FileName[20] = "SuperDataBin.bin";
unsigned Count = 3;

eCMD Menu()
{
	//цикл для вывода меню, если ввели неправильно команду
	while (true)
	{
		system("cls"); //очистка экрана
		std::cout << "Global data address" << &Data << "\n";
		std::cout << "Global count address" << &Count << "\n";
		std::cout << "Global count value" << Count << "\n";
		puts("Выберите действие : "); //отображение меню
		puts("1 - Открыть файл ");
		puts("2 - Просмотр данных");
		puts("3 - Сохранить файл");
		puts("4 - Выход из программы");
		unsigned opt;
		fflush(stdin); //обнуление входного потока
		scanf_s("%u" , &opt);
		switch (opt) 
		{ //возврат из функции команды
		case 1: return CMD_READ; break;
			case 2: return CMD_SHOW; break;
			case 3: return CMD_SAVE; break;
			case 4: return CMD_EXIT; break;
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
			case CMD_SHOW: ShowData(Data, Count); break;
			case CMD_READ: CRead(Data, Count,FileName); break;
			case CMD_SAVE: CSave(Data, Count, FileName); break;
		}
	}
	puts("Работа закончена");
	system("pause");
	return 0;
}