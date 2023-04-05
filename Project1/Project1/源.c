#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	FILE* fp = fopen("1.png", "rb");
	FILE* fp1 = fopen("2.png", "wb");
	/*FILE* fp = fopen("a.txt", "r");
	FILE* fp1 = fopen("b.txt", "w");*/
	if (!fp || !fp1)
	{
		perror("");
		return -1;
	}
	char ch = 0;
	while (1)
	{
		if (feof(fp))
			break;
		ch = fgetc(fp);
		fputc(ch, fp1);
	}
	
	fclose(fp);
	fclose(fp1);

	return 0;
}