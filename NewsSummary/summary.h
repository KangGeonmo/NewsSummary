#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "locale.h"

char *acllocFile(FILE *file);	//�����Ҵ�� ���ڿ�(char[])
int PrintFile(FILE *file, char *sFile);	//���ڿ����, ���α��� ��ȯ,
int writeFile(char *sFile, int iFileLine, int length);	//��� ���� ����