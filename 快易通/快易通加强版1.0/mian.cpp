#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FileName "./qyt.txt" //文件名

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
	char* p = 0;//获取fgets函数的返回值
	FILE* fp = open_file();
	while (1)
	{
		//获取英文
		p = fgets(cmd, sizeof(cmd), fp);
		if (p == NULL)
		{
			break;
		}
		//获取中文
		p = fgets(cmd, sizeof(cmd), fp);
		if (p == NULL)
		{
			break;
		}

		//获取一行中文一行英文，才算一个单词
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
		buf[n + 1] = 0;//把单词后面添加一个\0
}


void init_txt(Qyt* &qyt,int n)//c++引用
{
	Qyt* p = NULL;
	p = (Qyt*)malloc(sizeof(Qyt) * n);//开辟空间
	char buf[256] = "";
	char* q = 0;
	int i = 0;
	FILE* fp = open_file();
	while (1)
	{
		//获取英文
		q = fgets(buf, sizeof(buf), fp);
		if (q == NULL)
		{
			break;
		}
		filter_buf(buf);//过滤掉单词后面的显示不了的字符
		p[i].key = (Qyt*)malloc(strlen(buf) + 1);//给存储单词开辟空间
		strcpy(p[i].key, buf + 1);//进行拷贝

		//获取中文
		q = fgets(buf, sizeof(buf), fp);
		if (q == NULL)
		{
			break;
		}
		p[i].content = malloc(strlen(buf) + 1);//给存储单词开辟空间
		strcpy(p[i].content, buf + 6);//进行拷贝
		i++;
	}
	fclose(fp);
	qyt = p;//交换地址

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
//	int n=get_txt_line();//记录单词个数
//	/*printf("%d\n", n);*/
//	init_txt(qyt,n);
//	char key[256] = "";//存储输入的单词
//	char count[256] = "";//存储找到的翻译
//	while (1)
//	{
//		printf("请输入你要查找的单词：");
//		fgets(key, sizeof(key), stdin);
//		int ret=search_fp(qyt,n,key,count);
//		if (ret == 1)
//		{
//			printf("翻译为：%s\n", count);
//		}
//		else
//		{
//			printf("not found\n");
//		}
//	}
//
//	return 0;
//}