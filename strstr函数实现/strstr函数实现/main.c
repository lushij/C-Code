#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int myStrtr(char* str, char* subStr)
{
	int count = 0;//��¼�±�
	while (*str)
	{
		if (*str != *subStr)
		{
			str++;
			count++;
			continue;
		}

		//ƥ��ɹ�������ʱ����
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
		printf("�ҵ��ˣ��±�Ϊ%d\n", ret);
	}
	else
	{
		printf("not found\n");
	}

	return 0;
}