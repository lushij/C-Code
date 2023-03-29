#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>
#include <time.h>
#include <stdlib.h>
#define Max 51
void init()
{
	printf("请选择数字\n");
	printf("回车键-->玩游戏\n");
	printf("ESC键  -->退出\n");
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

	system("cls");	//先清屏
	printf("\n%s\n", s);
	for (i = 0; i < Max - 1; i++)
	{
		char ch = _getch();//等待用户输入任意按键   
		if (i == 0)
		{
			t_start = time(NULL);//取开始时间
		}
		if (ch==s[i])
		{
			printf("%c", ch);
			count++;//对的数目
		}
		else
		{
			printf("_");
		}
	}
	printf("\n");
	t_end = time(NULL);//取结束时间
	printf("一共对了%d\n", count);
	printf("用时%ld秒\n", t_end - t_start);
}

int main()
{
	char s[Max] = { 0 };
	while (1)
	{
		init();
		//windows自带键盘输入不需要回车自动确认
		char ch = _getch();//等待用户输入任意按键   
		if (ch == 27)//Esc的ascii为27
		{
			exit(1);
		}
		if (ch == 13)//enter的ascii为13
		{
			system("cls");//先清屏
			random_game(s);
 			start_game(s);
		}
		else
		{
			printf("输入错误，请重新选择\n");
		}
	}
	
	return 0;
}