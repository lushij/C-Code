#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <conio.h>
#include<time.h>
#define Width 60  //定义UI界面的宽度
#define High  20  //定义UI界面的高度




//定义蛇的部分
typedef struct snake_body {
	int x;
	int y;
}s_body;

//定义蛇的部分
typedef struct snake {
	s_body list[Width*High];//身体  身体的每一节坐标都是s_body类型
	int size;//蛇的身体的大小
	s_body food; //食物坐标
	int dx;//蛇x轴移动的坐标
	int dy;//蛇y轴动的坐标
	int score;//得分
	s_body tail;
	s_body wall[Width * High];//边界
	COORD coord;//光标的位置
}Snake;

//测试UI界面大小
void init_ui();
//初始化边界
void init_wall(Snake*snake);
//初始化蛇和食物
void init_game(Snake*snake);
//初始化食物的坐标
void init_food(Snake*snake);

//显示界面
void show_game(Snake*snake);

//开始游戏
void start_game(Snake* snake);

//结束游戏
void end_game(Snake*snake);
//控制移动
void control_move(Snake* snake);

//更新坐标
void move_snake(Snake* snake);