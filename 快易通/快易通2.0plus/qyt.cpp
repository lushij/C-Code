#include"qyt.h"


//文件接口
FILE* open_file()
{
	FILE* fp = NULL;
	fp= fopen(FileName, "r");
	if (!fp)
	{
		perror("");
		exit(1);
	}
	return fp;
}

//获取单词个数
int get_line()
{
	FILE* fp = open_file();
	int i = 0;
	char *p = 0;//判断fgets返回值
	char buf[256] = {0};
	while (1)
	{
		//一行英文
		p = fgets(buf, sizeof(buf), fp);
		if (p == NULL)
		{
			break;
		}
		//一行中文
		p = fgets(buf, sizeof(buf), fp);
		if (p == NULL)
		{
			break;
		}

		i++;
	}
	return i;
}


//过滤单词
void filtration_file(char* buf)
{
	//buf的最后一位下标
	int n = strlen(buf) - 1;
	while (buf[n] == ' ' || buf[n] == '\n' || buf[n] == '\r' || buf[n] == '\t')
	{
		n--;
	}
	buf[n + 1] = 0;//自动补0
}


//初始化单词
void init_file(Qyt**qyt,int n)
{
	Qyt*q = NULL;//进行转换地址时用
	q = (QYT)malloc(sizeof(Qyt)*n);//开辟空间
	FILE* fp = open_file();
	int i = 0;
	char* p = 0;//判断fgets返回值
	char buf[256] ="";
	while (1)
	{
		
		//一行英文
		p = fgets(buf, sizeof(buf), fp);
		if (p == NULL)
		{
			break;
		}
		filtration_file(buf);
		q[i].eng = (char*)malloc(strlen(buf) + 1);
		strcpy(q[i].eng, buf + 1);
		//一行中文
		p = fgets(buf, sizeof(buf), fp);
		if (p == NULL)
		{
			break;
		}
		q[i].zh = (char*)malloc(strlen(buf) + 1);
		strcpy(q[i].zh, buf+6);
		i++;
	}
	fclose(fp);
	*qyt = q;
}


//查找翻译
int search_zh(char* eng, char* zh, int n, Qyt* qyt)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(eng, qyt[i].eng) == 0)
		{
			strcpy(zh, qyt[i].zh);
			return 1;
		}
	}
	return 0;//代表没有找到
}