#pragma once
#include "file1.h" //содержит информацию о TRec*
void CSave(BookStore* data, unsigned count,char *fileName);
void CRead(BookStore* data, unsigned& count, char* fileName);
