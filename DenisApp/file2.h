#pragma once
#include "file1.h" //�������� ���������� � TRec*
void CSave(BookStore* data, unsigned count,char *fileName);
void CRead(BookStore* data, unsigned& count, char* fileName);
