#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	FILE* src = NULL;
	//打开待拷贝的文件
	src = fopen("3.png", "rb");
	if (!src)
	{
		perror("");
		exit(1);
	}

	FILE* dst = NULL;
	//打开拷贝的地址文件
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