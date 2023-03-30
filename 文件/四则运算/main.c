#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE* get_file(char*src)
{
	FILE* fp = NULL;
	fp = fopen("clsc.txt", src);
	if (!fp)
	{
		perror("");
		exit(1);
	}
	return fp;
}

void get_data()
{
	int a = 0, b = 0,c = 0;
	char sym[4] = {'+','-','*','/'};
	char d = 0;
	FILE* fp = get_file("w");
	srand((unsigned)time(NULL));
	char ch[1024] = " ";
	for (int i = 0; i < 10; i++)
	{
		a = rand() % 100 + 1;
		b = rand() % 100 + 1;
		c = rand() % 100 + 1;
		d = rand() % 4;
		sprintf(ch, "%d%c%d=\n", a, sym[d], c);
		fputs(ch, fp);
	}
	fclose(fp);
}

void out_data()
{
	int a = 0, b = 0, c = 0;
	char d = 0;
	int ret = 0;
	char buf[128] = " ";
	char buff[10][1024] = {0};//��ȡ��ý�������ݣ�ʹ�ö�ά�����ÿһ�пռ��
	char* p = NULL;
	FILE* fp = get_file("r");
	int i = 0;
	while (1)
	{
		p= fgets(buf, sizeof(buf), fp);//���ļ�����ȡ��buf
		if (p == NULL)
		{
			break;
		}
		sscanf(buf, "%d%c%d=\n", &a, &d, &c);
		switch (d)
		{
		case '+':
			ret = a + c;
			break;
		case '-':
			ret = a - c;
			break;
		case '*':
			ret = a * c;
			break;
		case '/':
			ret = a / c;
			break;
		}
		sprintf(buff[i], "%d%c%d=%d\n", a, d, c, ret);//ÿһ�ж���1024�ֽڵĿռ�
		i++;
	}
	fclose(fp);
	fp = get_file("w");
	for (int j = 0; j < i; j++)
	{
		fputs(buff[j], fp);
	}
	fclose(fp);
	
}
int main()
{
	
	//�����ļ�
	get_data();
	//�����ļ������м���
	out_data();

	return 0;
}