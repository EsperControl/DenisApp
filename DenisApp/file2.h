#pragma once
#include "file1.h" 
void CSave(BookStore* data, unsigned count,char *fileName);
void CRead(BookStore* data, unsigned& count, char* fileName);
void CReadHidden(BookStore* data, unsigned count, char* filename);
void CSVSave(BookStore* data, unsigned count);
void CSVRead(BookStore* data, unsigned &count);