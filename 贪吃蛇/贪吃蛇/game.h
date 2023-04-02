#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <conio.h>
#include<time.h>
#define Width 60  //����UI����Ŀ��
#define High  20  //����UI����ĸ߶�




//�����ߵĲ���
typedef struct snake_body {
	int x;
	int y;
}s_body;

//�����ߵĲ���
typedef struct snake {
	s_body list[Width*High];//����  �����ÿһ�����궼��s_body����
	int size;//�ߵ�����Ĵ�С
	s_body food; //ʳ������
	int dx;//��x���ƶ�������
	int dy;//��y�ᶯ������
	int score;//�÷�
	s_body tail;
	s_body wall[Width * High];//�߽�
	COORD coord;//����λ��
}Snake;

//����UI�����С
void init_ui();
//��ʼ���߽�
void init_wall(Snake*snake);
//��ʼ���ߺ�ʳ��
void init_game(Snake*snake);
//��ʼ��ʳ�������
void init_food(Snake*snake);

//��ʾ����
void show_game(Snake*snake);

//��ʼ��Ϸ
void start_game(Snake* snake);

//������Ϸ
void end_game(Snake*snake);
//�����ƶ�
void control_move(Snake* snake);

//��������
void move_snake(Snake* snake);