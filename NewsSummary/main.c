//main.c : .txt 파일 입력, 요약된 .txt파일 출력(MKnews.txt)

#include "main.h"

int main(void)
{
	int ifileLength;
	int isummaryLine = 20;
	char sfileName[100] = "MKnews.txt";
	//printf("파일이름을 입력하세요(확장자까지) : ");
	//scanf("%s",sfileName);

	printf("요약할 퍼센트(%%)를 입력하세요 : ");
	scanf("%d", &ifileLength);

	SummaryNews(sfileName, isummaryLine);
	return 0;
}