#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>
#include <time.h>
#include <stdlib.h>
#define Max 51
void init()
{
	printf("��ѡ������\n");
	printf("�س���-->����Ϸ\n");
	printf("ESC��  -->�˳�\n");
}

void random_game(char *s)
{
	srand((unsigned)time(NULL));
	rand() % 26 + 1;
	int i = 0;
	for (i = 0; i < Max; i++)
	{
		s[i] = rand() % 26 + 1 + 'a';
	}
	s[i] = 0;
}

void start_game(char*s)
{
	char ch;
	int i = 0;
	int count = 0;
	time_t t_start, t_end;

	system("cls");	//������
	printf("\n%s\n", s);
	for (i = 0; i < Max - 1; i++)
	{
		char ch = _getch();//�ȴ��û��������ⰴ��   
		if (i == 0)
		{
			t_start = time(NULL);//ȡ��ʼʱ��
		}
		if (ch==s[i])
		{
			printf("%c", ch);
			count++;//�Ե���Ŀ
		}
		else
		{
			printf("_");
		}
	}
	printf("\n");
	t_end = time(NULL);//ȡ����ʱ��
	printf("һ������%d\n", count);
	printf("��ʱ%ld��\n", t_end - t_start);
}

int main()
{
	char s[Max] = { 0 };
	while (1)
	{
		init();
		//windows�Դ��������벻��Ҫ�س��Զ�ȷ��
		char ch = _getch();//�ȴ��û��������ⰴ��   
		if (ch == 27)//Esc��asciiΪ27
		{
			exit(1);
		}
		if (ch == 13)//enter��asciiΪ13
		{
			system("cls");//������
			random_game(s);
 			start_game(s);
		}
		else
		{
			printf("�������������ѡ��\n");
		}
	}
	
	return 0;
}