//main.c : .txt ���� �Է�, ���� .txt���� ���(MKnews.txt)

#include "main.h"

int main(void)
{
	int ifileLength;
	int isummaryLine = 20;
	char sfileName[100] = "MKnews.txt";
	//printf("�����̸��� �Է��ϼ���(Ȯ���ڱ���) : ");
	//scanf("%s",sfileName);

	printf("����� �ۼ�Ʈ(%%)�� �Է��ϼ��� : ");
	scanf("%d", &ifileLength);

	SummaryNews(sfileName, isummaryLine);
	return 0;
}