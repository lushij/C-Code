#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	FILE* src = NULL;
	//�򿪴��������ļ�
	src = fopen("3.png", "rb");
	if (!src)
	{
		perror("");
		exit(1);
	}

	FILE* dst = NULL;
	//�򿪿����ĵ�ַ�ļ�
	dst = fopen("1.png", "wb");
	if (!dst)
	{
		perror("");
		exit(1);
	}
	char c = 0;
	while (1)
	{
		c = fgetc(src);
		if (feof(src))
		{
			break;
		}
		fputc(c, dst);
	}
	return 0;
}