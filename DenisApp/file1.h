//��� enum ��� ���������� ������ ��������� ������
#pragma once
#define _CRT_SECURE_NO_WARNINGS
enum eCMD {
	CMD_EXIT = -1, CMD_NONE, CMD_READ, CMD_SHOW, CMD_EDIT,
	CMD_ADD, CMD_DELETE, CMD_SORT, CMD_FIND, CMD_SAVE,CMD_MONITOR
};

//��������� ������ ������ ������������ �������
const int MAX_SIZE = 10;
//�������� ��������� ������
struct BookStore {
    char  author[16];
	char  bookName[16];
	char  code[16];
	float price;
	int count;
};
