#pragma once
#include <string>
#include "file1.h" //�������� ���������� � TRec*
void MonitorFiles();
void ReadDatabase(BookStore *data, unsigned &count);
void SaveDatabase(BookStore *data, unsigned count);
