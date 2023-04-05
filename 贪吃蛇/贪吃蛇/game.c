#include"game.h"

void init_ui()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

//初始化食物的坐标
void init_food(Snake* snake)
{
	srand((unsigned)time(NULL));//随机数种子
	snake->food.x = rand() % 60;
	snake->food.y = rand() % 20;
}

//初始化蛇和食物
void init_game(Snake* snake)
{
	//初始化蛇头坐标
	snake->list[0].x = Width / 2;
	snake->list[0].y = High / 2;
	//初始化蛇尾坐标
	snake->list[1].x = (Width / 2) - 1;
	snake->list[1].y = High / 2;
	//初始化蛇的身体的大小
	snake->size = 2;
	//初始化食物的坐标
	init_food(snake);
	//初始化蛇的移动方向
	snake->dx = 1;
	snake->dy = 0;
	//初始化分数
	snake->score = 0;
}


//初始化边界
void init_wall(Snake* snake)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= High; i++)
	{
		for (j = 0; j <=Width ; j++)
		{
			if (j == Width || i == High)
			{
				printf("+");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
}

//显示界面
void show_game(Snake* snake)
{
	//显示蛇 注意: 每次显示蛇或食物,都要设置显示的位置,(光标的位置)
	for (int i = 0; i < snake->size; i++)
	{
		snake->coord.X = snake->list[i].x;
		snake->coord.Y = snake->list[i].y;
		//window光标显示接口，直接引用即可
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
		if (i == 0)
		{
			printf("@");
		}
		else
		{
			printf("*");
		}
	}
	snake->coord.X = snake->food.x;
	snake->coord.Y = snake->food.y;
	//window光标显示接口，直接引用即可
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("#");
	//将原来尾巴的位置显示为空格
	snake->coord.X = snake->tail.x;
	snake->coord.Y = snake->tail.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf(" ");
	
}


//控制移动
void control_move(Snake* snake)
{
	char  key = 0;
	while (_kbhit()) //判断是否按下按键,按下不等于0 
	{
		key = _getch();
	}
	switch (key)
	{
	case 'a':
		snake->dx = -1;
		snake->dy = 0;
		break;
	case 'w':
		snake->dx = 0;
		snake->dy = -1;
		break;
	case 's':
		snake->dx = 0;
		snake->dy = 1;
		break;
	case 'd':
		snake->dx = 1;
		snake->dy = 0;
		break;
	}
}

void move_snake(Snake* snake)
{
	//记录尾巴的坐标
	snake->tail.x = snake->list[snake->size - 1].x;
	snake->tail.y = snake->list[snake->size - 1].y;
	//更新蛇的身体坐标,除蛇头
	for (int i = snake->size - 1; i > 0; i--)
	{
		snake->list[i] = snake->list[i - 1];//将数组的前一个元素的坐标给后一节
	}
	//更新蛇头
	snake->list[0].x += snake->dx;
	snake->list[0].y += snake->dy;
	
	Sleep(100);
	system("cls");//清屏
	//显示更新后的坐标
	init_wall(snake);
	show_game(snake);
}

//结束游戏
void end_game(Snake* snake)
{
	snake->coord.X = 25;
	snake->coord.Y = 30;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("游戏结束 得分为%d\n", snake->score);
	/*Sleep(1000);*/
	exit(0);//退出进程
}

//开始游戏
void start_game(Snake* snake)
{
	while (snake->list[0].x < 60 && snake->list[0].x >= 0 &&
		snake->list[0].y < 20 && snake->list[0].y >= 0)
	{
		//控制移动
		control_move(snake);
		//更新坐标
		move_snake(snake);
}
	}