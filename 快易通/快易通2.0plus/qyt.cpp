#include"qyt.h"


//�ļ��ӿ�
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

//��ȡ���ʸ���
int get_line()
{
	FILE* fp = open_file();
	int i = 0;
	char *p = 0;//�ж�fgets����ֵ
	char buf[256] = {0};
	while (1)
	{
		//һ��Ӣ��
		p = fgets(buf, sizeof(buf), fp);
		if (p == NULL)
		{
			break;
		}
		//һ������
		p = fgets(buf, sizeof(buf), fp);
		if (p == NULL)
		{
			break;
		}

		i++;
	}
	return i;
}


//���˵���
void filtration_file(char* buf)
{
	//buf�����һλ�±�
	int n = strlen(buf) - 1;
	while (buf[n] == ' ' || buf[n] == '\n' || buf[n] == '\r' || buf[n] == '\t')
	{
		n--;
	}
	buf[n + 1] = 0;//�Զ���0
}


//��ʼ������
void init_file(Qyt**qyt,int n)
{
	Qyt*q = NULL;//����ת����ַʱ��
	q = (QYT)malloc(sizeof(Qyt)*n);//���ٿռ�
	FILE* fp = open_file();
	int i = 0;
	char* p = 0;//�ж�fgets����ֵ
	char buf[256] ="";
	while (1)
	{
		
		//һ��Ӣ��
		p = fgets(buf, sizeof(buf), fp);
		if (p == NULL)
		{
			break;
		}
		filtration_file(buf);
		q[i].eng = (char*)malloc(strlen(buf) + 1);
		strcpy(q[i].eng, buf + 1);
		//һ������
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


//���ҷ���
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
	return 0;//����û���ҵ�
}