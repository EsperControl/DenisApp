#include "file1.h" //содержит информацию о TRec*
#include <iostream> // header in standard library
#include <stdio.h>
#include <fstream>
using namespace std;
void MonitorFiles() {

}
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
