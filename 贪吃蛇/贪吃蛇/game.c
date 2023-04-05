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

//��ʼ��ʳ�������
void init_food(Snake* snake)
{
	srand((unsigned)time(NULL));//���������
	snake->food.x = rand() % 60;
	snake->food.y = rand() % 20;
}

//��ʼ���ߺ�ʳ��
void init_game(Snake* snake)
{
	//��ʼ����ͷ����
	snake->list[0].x = Width / 2;
	snake->list[0].y = High / 2;
	//��ʼ����β����
	snake->list[1].x = (Width / 2) - 1;
	snake->list[1].y = High / 2;
	//��ʼ���ߵ�����Ĵ�С
	snake->size = 2;
	//��ʼ��ʳ�������
	init_food(snake);
	//��ʼ���ߵ��ƶ�����
	snake->dx = 1;
	snake->dy = 0;
	//��ʼ������
	snake->score = 0;
}


//��ʼ���߽�
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

//��ʾ����
void show_game(Snake* snake)
{
	//��ʾ�� ע��: ÿ����ʾ�߻�ʳ��,��Ҫ������ʾ��λ��,(����λ��)
	for (int i = 0; i < snake->size; i++)
	{
		snake->coord.X = snake->list[i].x;
		snake->coord.Y = snake->list[i].y;
		//window�����ʾ�ӿڣ�ֱ�����ü���
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
	//window�����ʾ�ӿڣ�ֱ�����ü���
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("#");
	//��ԭ��β�͵�λ����ʾΪ�ո�
	snake->coord.X = snake->tail.x;
	snake->coord.Y = snake->tail.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf(" ");
	
}


//�����ƶ�
void control_move(Snake* snake)
{
	char  key = 0;
	while (_kbhit()) //�ж��Ƿ��°���,���²�����0 
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
	//��¼β�͵�����
	snake->tail.x = snake->list[snake->size - 1].x;
	snake->tail.y = snake->list[snake->size - 1].y;
	//�����ߵ���������,����ͷ
	for (int i = snake->size - 1; i > 0; i--)
	{
		snake->list[i] = snake->list[i - 1];//�������ǰһ��Ԫ�ص��������һ��
	}
	//������ͷ
	snake->list[0].x += snake->dx;
	snake->list[0].y += snake->dy;
	
	Sleep(100);
	system("cls");//����
	//��ʾ���º������
	init_wall(snake);
	show_game(snake);
}

//������Ϸ
void end_game(Snake* snake)
{
	snake->coord.X = 25;
	snake->coord.Y = 30;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("��Ϸ���� �÷�Ϊ%d\n", snake->score);
	/*Sleep(1000);*/
	exit(0);//�˳�����
}

//��ʼ��Ϸ
void start_game(Snake* snake)
{
	while (snake->list[0].x < 60 && snake->list[0].x >= 0 &&
		snake->list[0].y < 20 && snake->list[0].y >= 0)
	{
		//�����ƶ�
		control_move(snake);
		//��������
		move_snake(snake);
}
	}