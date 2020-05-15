#include "file1.h" //содержит информацию о TRec*
#include <iostream> // header in standard library
#include <stdio.h>
#include <fstream>
using namespace std;
void MonitorFiles() {

}/*
void ReadDatabase(BookStore *data, unsigned &count)
{
	std::cout << "Global data address" << data << "\n";
	std::cout << "Global count address" << &count << "\n";
	std::cout << "Global count value" << count << "\n";
	ifstream myFile;
	myFile.open("data.bin", ios::in | ios::binary);
	char s_buffer[16];
	char u_buffer[sizeof(unsigned)];
	char i_buffer[sizeof(int)];
	char f_buffer[sizeof(float)];
	myFile.read(u_buffer, sizeof(unsigned));
	count = (unsigned)u_buffer;
	for (unsigned i = 0; i < count; i++) {
		myFile.read(s_buffer, 16);
		*data[i].author = *s_buffer;
		myFile.read(s_buffer, 16);
		*data[i].bookName = *s_buffer;
		myFile.read(s_buffer, 16);
		*data[i].code = *s_buffer;
		myFile.read(f_buffer, sizeof(float));
		*data[i].price = f_buffer;
		myFile.read(i_buffer, sizeof(int));
		*data[i].count = i_buffer;
	}
	std::cout << "Global data address" << data << "\n";
	std::cout << "Global count address" << &count << "\n";
	std::cout << "Global count value" << count << "\n";
	system("pause");
}
void SaveDatabase(BookStore *data, unsigned count)
{
	std::cout << "Global data address" << data << "\n";
	std::cout << "Global count address" << &count << "\n";
	std::cout << "Global count value" << count << "\n";
	ofstream myFile;
	myFile.open("data.bin", ios::out | ios::binary);
	myFile.write((const char *) &count, sizeof(unsigned));
	for (unsigned i = 0; i < count; i++) {
		myFile.write(data[i].author, 16);
		myFile.write(data[i].bookName, 16);
		myFile.write(data[i].code, 16);
		myFile.write((const char *) &data[i].price, sizeof(float));
		myFile.write((const char *) &data[i].count, sizeof(int));
	}
	system("pause");
	//Сохраняем базу данных...
}
*/
void CSave(BookStore *data, unsigned count)
{
	FILE* inp =fopen("SuperDataBin.bin", "wb");
	cout << "New count is:" << count << "\n";
	fwrite(&count, sizeof(unsigned), 1, inp);

	fwrite(data, sizeof(BookStore), count, inp);
	fclose(inp);
	system("pause");
}


void CRead(BookStore *data, unsigned &count)
{
	int N;
	FILE* inp =fopen("SuperDataBin.bin", "rb");
	
	fseek(inp,0,0);
	unsigned new_count;
	fread(&new_count, sizeof(unsigned), 1, inp);

	
	fread(data, sizeof(BookStore),new_count,inp);
	fclose(inp);
	count = new_count;
	system("pause");
}
