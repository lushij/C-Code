#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	FILE* fp = fopen("1.png", "rb");
	FILE* fp1 = fopen("2.png", "wb");
	if (!fp)
	{
		perror("");
		return -1;
	}
	char ch = 0;
	while (ch = fgetc(fp) != NULL)
	{
		fputc(ch, fp1);
	}
	fclose(fp);
	fclose(fp1);

	return 0;
}