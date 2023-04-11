#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MaxSize 5

//特性是先进先出（First In First Out，FIFO）

typedef struct S {
	int data[MaxSize];//数组最大存储MaxSize-1个数据
	int front, rear;//队头 队尾
}SQueue;

//初始化队列
void init_squeue(SQueue &s) 
{
	s.front = s.rear = 0;//初始化队列为空
}

//插入数据
void insert_squeue(SQueue &s,int x)
{
	//判断队列是否为满 (Q.rear+1)%MaxSize==Q.front
	if ((s.rear + 1) % MaxSize == s.front)
	{
		return;
	}
	//插入数据
	s.data[s.rear] = x;
	//更新队尾
	s.rear = (s.rear + 1) % MaxSize;//因为是循环多以要加1模最大容量才是真正的下标
}

//退出数据
void outSqueue(SQueue &s, int &x)
{
	//判断是否为空
	if (s.front == s.rear)
	{
		return;
	}
	x = s.data[s.front];
	s.front = (s.front + 1) % MaxSize;

}
int main()
{
	SQueue s;
	//初始化队列
	init_squeue(s);
	//插入数据
	insert_squeue(s,2);
	insert_squeue(s,3);
	insert_squeue(s,5);
	insert_squeue(s,6);
	//出队
	int x = 0;//接入出队元素
	outSqueue(s, x);
	outSqueue(s, x);
	printf("out count is %d\n ", x);

	return 0;
}