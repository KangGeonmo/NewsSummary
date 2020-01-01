#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "locale.h"

char *acllocFile(FILE *file);	//동적할당된 문자열(char[])
int PrintFile(FILE *file, char *sFile);	//문자열출력, 라인길이 반환,
int writeFile(char *sFile, int iFileLine, int length);	//요약 파일 생성