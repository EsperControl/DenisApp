#include "file1.h" //содержит информацию о TRec*
#include <iostream> // header in standard library
#include <stdio.h>
#include <string>
#include <filesystem>
#include <wtypes.h>

namespace fs = std::filesystem;
void MonitorFiles() {

}
void ReadDatabase(BookStore *data, unsigned &count)
{
	//Читаем базу данных...
}
void SaveDatabase(BookStore *data, unsigned count)
{
	for (int i = 0; i < count; i++) {

	}
	//Сохраняем базу данных...
}
