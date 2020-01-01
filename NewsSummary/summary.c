#include "summary.h"

int SummaryNews(char fileName[], int length)
{
	system("cls");
	_wsetlocale(LC_ALL, L"korean");
	int ifileLine = 0;
	FILE *file = fopen(fileName, "rt");
	char *sFile;
	int cutLine;

	if (file == NULL)
	{
		puts("파일 읽기 실패!");
		puts("<<< NO FILE >>>");
		return -1;
	}

	sFile = acllocFile(file);	//동적할당된 문자열(char[])
	ifileLine = PrintFile(file, sFile);	//문자열출력, 라인길이 반환,
	cutLine = ifileLine * (length / (double)100);

	puts("");
	puts("아무키나 누를시 요약 파일 생성시작");
	//while (getchar() != '\n') {}	//버퍼 지움;
	if (_getch())
	{
		system("cls");
		writeFile(sFile, ifileLine, cutLine);	//요약 파일 생성
	}


	free(sFile);
	fclose(file);
	return 0;
}

char *acllocFile(FILE *file)
{
	char *sFile = NULL;
	int bufferSize;

	fseek(file, 0, SEEK_END);
	bufferSize = ftell(file);
	fseek(file, 0, SEEK_SET);
	sFile = malloc(bufferSize + 1);

	return sFile;
}

int PrintFile(FILE *file, char *sFile)
{
	int count = 0;
	int i = 0;
	while (!feof(file))
	{
		sFile[i] = fgetc(file);
		if (sFile[i] == '\n')	count++;
		i++;
	}

	printf("%s", sFile);

	return count;
}

int writeFile(char *sFile, int iFileLine, int length)
{
	int temp = 0;
	int n = -1;
	FILE *fp = fopen("summmary.txt", "wt");
	if (fp == NULL)
	{
		puts("파일쓰기 실패!");
		puts("NO Creat File");
		return -1;
	}

	printf("요약될 라인 수 : %d X 2(상단, 하단)\n", length);
	for (int i = 0; i < length; i++)
	{
		while (1)
		{
			n++;
			fputc(sFile[n], fp);
			if (sFile[n] == '\n') break;
		}
	}

	n = -1;
	for (int i = 0; i < length; i++)
	{
		while (1)
		{
			n++;
			if (sFile[n] == '\n')temp++;
			if (temp == (iFileLine - length))	break;
		}
	}

	for (int i = 0; i < length; i++)
	{
		while (1)
		{
			fputc(sFile[n], fp);
			if (sFile[n] == '\n')break;
			n++;
		}
		n++;
	}


	fclose(fp);
	puts("요약파일 작업완료 : \"summmary.txt\" 생성");
	return 0;
}