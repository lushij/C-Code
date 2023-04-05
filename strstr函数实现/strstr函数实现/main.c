#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int myStrtr(char* str, char* subStr)
{
	int count = 0;//记录下标
	while (*str)
	{
		if (*str != *subStr)
		{
			str++;
			count++;
			continue;
		}

		//匹配成功创建临时变量
		char* tmpStr = str;
		char* tmpSubstr = subStr;
		while (*tmpSubstr)
		{
			if (*tmpStr != *tmpSubstr)
			{
				str++;
				count++;
				break;
			}

			tmpStr++;
			tmpSubstr++;
		}
		if (*tmpSubstr == '\0')
		{
			return count;
		}
	

	}
	return -1;
}

int main()
{
	char* str = "abcdeffghijk";
	int ret=myStrtr(str, "fgh");
	if (ret != -1)
	{
		printf("找到了：下标为%d\n", ret);
	}
	else
	{
		printf("not found\n");
	}

	return 0;
}