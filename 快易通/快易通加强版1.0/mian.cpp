#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FileName "./qyt.txt" //�ļ���

typedef struct _qyt
{
	char* key;
	char* content;

}Qyt;

FILE* open_file()
{
	FILE* fp = fopen(FileName, "r");
	if (fp == NULL)
	{
		perror("");
		return NULL;
	}
	return fp;
}

int get_txt_line()
{
	char cmd[256] = "";
	int i = 0;
	char* p = 0;//��ȡfgets�����ķ���ֵ
	FILE* fp = open_file();
	while (1)
	{
		//��ȡӢ��
		p = fgets(cmd, sizeof(cmd), fp);
		if (p == NULL)
		{
			break;
		}
		//��ȡ����
		p = fgets(cmd, sizeof(cmd), fp);
		if (p == NULL)
		{
			break;
		}

		//��ȡһ������һ��Ӣ�ģ�����һ������
		i++;
	}
	fclose(fp);
	return i;
	
}



void filter_buf(char*buf)
{
	int n = strlen(buf) - 1;
		while((buf[n] == ' ' || buf[n] == '\r' || buf[n] == '\n' || buf[n] == '\t'))
		{
			n--;
		}
		buf[n + 1] = 0;//�ѵ��ʺ������һ��\0
}


void init_txt(Qyt* &qyt,int n)//c++����
{
	Qyt* p = NULL;
	p = (Qyt*)malloc(sizeof(Qyt) * n);//���ٿռ�
	char buf[256] = "";
	char* q = 0;
	int i = 0;
	FILE* fp = open_file();
	while (1)
	{
		//��ȡӢ��
		q = fgets(buf, sizeof(buf), fp);
		if (q == NULL)
		{
			break;
		}
		filter_buf(buf);//���˵����ʺ������ʾ���˵��ַ�
		p[i].key = (Qyt*)malloc(strlen(buf) + 1);//���洢���ʿ��ٿռ�
		strcpy(p[i].key, buf + 1);//���п���

		//��ȡ����
		q = fgets(buf, sizeof(buf), fp);
		if (q == NULL)
		{
			break;
		}
		p[i].content = malloc(strlen(buf) + 1);//���洢���ʿ��ٿռ�
		strcpy(p[i].content, buf + 6);//���п���
		i++;
	}
	fclose(fp);
	qyt = p;//������ַ

}



int search_fp(Qyt* qyt,int n,char *key,char*count)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(key, qyt[i].key) == 0)
		{
			strcpy(count, qyt[i].content);
			return  1;
		}
		
	}
	return 0;
}

//int main()
//{
//	Qyt* qyt = NULL;
//	int n=get_txt_line();//��¼���ʸ���
//	/*printf("%d\n", n);*/
//	init_txt(qyt,n);
//	char key[256] = "";//�洢����ĵ���
//	char count[256] = "";//�洢�ҵ��ķ���
//	while (1)
//	{
//		printf("��������Ҫ���ҵĵ��ʣ�");
//		fgets(key, sizeof(key), stdin);
//		int ret=search_fp(qyt,n,key,count);
//		if (ret == 1)
//		{
//			printf("����Ϊ��%s\n", count);
//		}
//		else
//		{
//			printf("not found\n");
//		}
//	}
//
//	return 0;
//}