#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <malloc.h>
#include<string.h>

typedef struct stu {
	char eng[256];
	char zh[256];
}stu,*Tra;


void stu_init(Tra &stu)//c++����
{
	Tra p = NULL;
	p = (Tra)malloc(sizeof(stu) * 2);
	strcpy(p[0].eng, "hello");
	strcpy(p[0].zh, "���");
	strcpy(p[1].eng, "world");
	strcpy(p[1].zh, "����");
	stu = p;//��pָ��ĵ�ַ��stu
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
	char search[1024] = " ";//����ҵ��ĵ��ʵķ���
	char eng = 0, zh = 0;
	while (1)
	{
		printf("������Ҫ��ѯ�ĵ��ʣ�");
		fgets(cmd, sizeof(cmd), stdin);
		cmd[strlen(cmd) - 1] = 0;//��cmd�����������һ����ֵΪ0
		int ret = search_stu(cmd ,stu,search);
		if (ret == 1)
		{
			printf("�õ��ʷ���Ϊ��%s\n", search);
		}
		else
		{
			printf("not fouund\n");

		}
	}

	return 0;
}