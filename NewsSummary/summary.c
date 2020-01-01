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
		puts("���� �б� ����!");
		puts("<<< NO FILE >>>");
		return -1;
	}

	sFile = acllocFile(file);	//�����Ҵ�� ���ڿ�(char[])
	ifileLine = PrintFile(file, sFile);	//���ڿ����, ���α��� ��ȯ,
	cutLine = ifileLine * (length / (double)100);

	puts("");
	puts("�ƹ�Ű�� ������ ��� ���� ��������");
	//while (getchar() != '\n') {}	//���� ����;
	if (_getch())
	{
		system("cls");
		writeFile(sFile, ifileLine, cutLine);	//��� ���� ����
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
		puts("���Ͼ��� ����!");
		puts("NO Creat File");
		return -1;
	}

	printf("���� ���� �� : %d X 2(���, �ϴ�)\n", length);
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
	puts("������� �۾��Ϸ� : \"summmary.txt\" ����");
	return 0;
}