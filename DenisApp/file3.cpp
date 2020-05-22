#include "file1.h" 
#include <iostream> // header in standard library
#include <stdio.h>
#include <string> 
#define _CRT_SECURE_NO_WARNINGS
void AveragePrice(BookStore* data, unsigned count);
void SortCount(BookStore* data, unsigned count);
void SortAuthor(BookStore* data, unsigned count);
void Find(BookStore* data, unsigned count);


eCMD MenuShow()
{
	while (true)
	{
		puts("\nВыберите  : ");
		puts(" 1 - Редактировать запись"); 
		puts(" 2 - Добавить запись"); 
		puts(" 3 - Удалить запись");
		puts(" 4 - Подсчитать среднее значение цены");
		puts(" 5 - Отсортировать по количеству книг");
		puts(" 6 - Отсортировать по имени автора");
		puts(" 7 - Поиск записей"); 
		puts(" 8 - Выход"); 
		unsigned opt;
		fflush(stdin); 
		scanf_s("%u" , &opt);
		switch (opt) { 
			case 1: return CMD_EDIT;
			case 2: return CMD_ADD;
			case 3: return CMD_DELETE;
			case 4: return CMD_AVG;
			case 5: return CMD_SORT;
			case 6: return CMD_SORTA;
			case 7: return CMD_FIND;
			case 8: return CMD_EXIT;
			default: puts("?? ????? ???????????? ??????? ");
				system("pause");
		}
	}
}


void EditRecord(BookStore* data, unsigned count)
{
	std::cout << "Global data address" << data << "\n";
	puts("\n???????? ??????,??????? ?????? ????????: ");
	unsigned opt;
	while (true) {
		fflush(stdin);
		scanf_s("%u", &opt);
		if (opt < count) {
			break;
		}
		else {
			puts("?????? ???????? ????? ??????,?????????? ??? ???: ");
		}
	}

	printf("Старое значние поля 'Автор' - %s, введите нове значение:", data[opt].author);
	fflush(stdin);
	scanf("%s", &data[opt].author);

	printf("Старое значние поля 'Название книги' - %s, введите нове значение:", data[opt].bookName);
	fflush(stdin);
	scanf("%s", &data[opt].bookName);

	printf("Старое значние поля 'Код'- %s, введите нове значение:", data[opt].code);
	fflush(stdin);
	scanf("%s", &data[opt].code);

	printf("???????? ???? ???? - %f, ????а?? ????? ????????:", data[opt].price);
	fflush(stdin); //????
	scanf("%f", &data[opt].price);

	printf("Старое значние поля 'Количесвто'- %d, введите нове значение:", data[opt].count);
	fflush(stdin); //????
scanf("%d", &data[opt].count);
	printf("______________________________________________________________________\n");
	printf("|%d|%16s|%16s|%16s|%4f ???.|%руб??.|\nшт",
		opt,
		data[opt].author,
		data[opt].bookName,
		data[opt].code,
		data[opt].price,
		data[opt].count);
	system("pause");
	//Show
}

void AddRecord(BookStore *data, unsigned *count)
{
	std::cout << "Global data address" << data << "\n";
	std::cout << "Global count address" << count << "\n";
	std::cout << "Global count value" << *count << "\n";
	if (*count < MAX_SIZE) {
		unsigned opt = *count;
		std::cout << "opt value" << opt << "\n";
		*count += 1;
		puts("Введите значение 1");
		fflush(stdin); //????
		scanf("%s", &data[opt].author);

		puts("Введите значение 2");
		fflush(stdin); //????
		scanf("%s", &data[opt].bookName);

		puts("Введите значение 3");
		fflush(stdin); //????
		scanf("%s", &data[opt].code);

		// ???ts("Введите значение 4");
		fflush(stdin); //????
		scanf("%f", &data[opt].price);

		puts("Введите значение 5");
		fflush(stdin); //????
		scanf("%d", &data[opt].count);
		printf("______________________________________________________________________\n");
		printf("|%d|%16s|%16s|%16s|%4f ???.|%руб??.|\nшт",
			opt,
			data[opt].author,
			data[opt].bookName,
			data[opt].code,
			data[opt].price,
			data[opt].count);
		std::cout << "Global data address" << data << "\n";
		std::cout << "Global count address" << &count << "\n";
		std::cout << "Global count value" << count << "\n";
		system("pause");
	}
	else {
		puts("Достигнут максимум записей");
		
	}
}


void DeleteRecord(BookStore *data, unsigned *count) {
	std::cout << "Global data address" << data << "\n";
	std::cout << "Global count address" << count << "\n";
	std::cout << "Global count value" << *count << "\n";
	printf("Какую запись Вы хотите удалить? ");
	unsigned opt;
	fflush(stdin); 
	scanf("%u", &opt);
	if (*count > opt) {
		for (unsigned i = opt; i < *count; i++)
		{
			data[i] = data[i + 1];
		}
		*count -= 1;
	}
	else {
		puts("Неверно введен номер записи для удаления!");
	}
}


void ShowData(BookStore *data, unsigned &count) 
{

	eCMD cmd = CMD_NONE;
	while (cmd != CMD_EXIT)
	{
		system("cls");
		std::cout << "Global data address" << data << "\n";
		std::cout << "Global count address" << &count << "\n";
		std::cout << "Global count value" << count << "\n";
		printf("___________________________________________________________________\n");
		printf("|id|%16s|%16s|%16s|     руб.|     шт.|\n",
			"?????",
			"?????",
			"???");
		for (unsigned i = 0; i < count; i++) {
			printf("______________________________________________________________________\n");
			printf("|%d|%16s|%16s|%16s|%4f руб.|%3i шт.|\n", 
					i,
					data[i].author,
					data[i].bookName,
					data[i].code,
					data[i].price,
					data[i].count);
		}
		cmd = MenuShow(); //??????????? ???? ? ???? ??????
		switch (cmd) //????? ??????? ??? ??????????????? ???????
		{
		case CMD_EDIT: 
			EditRecord(data, count);
			break;
		case CMD_ADD:
			AddRecord(data, &count);
			break;
		case CMD_DELETE:
			DeleteRecord(data, &count);
			break;
		case CMD_AVG:
			AveragePrice(data, count); 
			break;
		case CMD_SORT:
			SortCount(data, count);
			break;
		case CMD_SORTA:
			SortAuthor(data, count);
			break;
		case CMD_FIND:
			Find(data, count);
			break;
		}
	}
	puts("done");
	system("pause");
}


void AveragePrice(BookStore* data, unsigned count) {
	float average=0;
	for (int i = 0; i <= count; i++) {
		average += data[i].price;
	}
	average /=count;
	printf("Среднее значение цены:%f",average);
	system("pause");
}


void SortCount(BookStore* data, unsigned count) {
	BookStore buffer;
	bool b = true;
	while (b) {
		b = false;
		for (unsigned i = 0; i <= count - 1; i++) {
			if (data[i].count > data[i + 1].count) {
				buffer = data[i + 1];
				data[i + 1] = data[i];
				data[i] = buffer;
				b = true;
			}
		}
	}
}


void SortAuthor(BookStore *data, unsigned count) {
	BookStore buffer;
	bool b = true;
	while (b) {
		b = false;
		for (unsigned i = 0; i <= count - 1; i++) {
			if (strcoll(data[i].author,data[i + 1].author)>0) {
				buffer = data[i + 1];
				data[i + 1] = data[i];
				data[i] = buffer;
				b = true;
			}
		}
	}
}


void Find(BookStore *data, unsigned count){

	puts("Введите запрос: ");
	char request[16];
	scanf("%s", &request);
	std::string target;
	std::string req = request;
	bool A = false;
	system("cls");
	puts("Найдены следующие записи:\n");
	for(int i=0;i<=count;i++){
		target = data[i].author;
		if (target.find(req) != std::string::npos) {
			A = true;
			printf("|%d|%16s|%16s|%16s|%4f ???.|%3i ??.|\n", 
					i,
					data[i].author,
					data[i].bookName,
					data[i].code,
					data[i].price,
					data[i].count);
			continue;
		}
		target = data[i].bookName;
		if (target.find(req) != std::string::npos) {
			A = true;
			printf("|%d|%16s|%16s|%16s|%4f ???.|%3i ??.|\n",
				i,
				data[i].author,
				data[i].bookName,
				data[i].code,
				data[i].price,
				data[i].count);
			continue;
		}
		target = data[i].code;
		if (target.find(req) != std::string::npos) {
			A = true;
			printf("|%d|%16s|%16s|%16s|%4f ???.|%3i ??.|\n",
				i,
				data[i].author,
				data[i].bookName,
				data[i].code,
				data[i].price,
				data[i].count);
			continue;
		}

		}
	if (!A) {
		system("cls");
		puts("Ничего не найдено");
	}
	system("pause");
}