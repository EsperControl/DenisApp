#pragma once
#include "file1.h" //�������� ���������� � TRec*
void MonitorFiles();
void ReadDatabase(BookStore *data, unsigned &count);
void SaveDatabase(BookStore *data, unsigned count);
void CSave(BookStore* data, unsigned count);
void CRead(BookStore* data, unsigned& count);
