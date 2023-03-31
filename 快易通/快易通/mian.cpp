#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <malloc.h>
#include<string.h>

typedef struct stu {
	char eng[256];
	char zh[256];
}stu,*Tra;


void stu_init(Tra &stu)//c++引用
{
	Tra p = NULL;
	p = (Tra)malloc(sizeof(stu) * 2);
	strcpy(p[0].eng, "hello");
	strcpy(p[0].zh, "你好");
	strcpy(p[1].eng, "world");
	strcpy(p[1].zh, "世界");
	stu = p;//把p指向的地址给stu
}

int search_stu(char *cmd, Tra stu,char*search)
{
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		if (strcmp(stu[i].eng, cmd) == 0)
		{
			strcpy(search, stu[i].zh);
			return 1;
		}
		else if(strcmp(stu[i].zh,cmd)==0)
		{
			strcpy(search, stu[i].eng);
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	stu* stu = NULL;
	stu_init(stu);
	char cmd[1024] = " ";
	char search[1024] = " ";//存放找到的单词的翻译
	char eng = 0, zh = 0;
	while (1)
	{
		printf("请输入要查询的单词：");
		fgets(cmd, sizeof(cmd), stdin);
		cmd[strlen(cmd) - 1] = 0;//把cmd的数组的最后的一个赋值为0
		int ret = search_stu(cmd ,stu,search);
		if (ret == 1)
		{
			printf("该单词翻译为：%s\n", search);
		}
		else
		{
			printf("not fouund\n");

		}
	}

	return 0;
}