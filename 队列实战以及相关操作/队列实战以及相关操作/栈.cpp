#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#include <stdlib.h>
#define MaxSize 50 
typedef int  ElemType;

//栈先进后出
typedef struct {
	ElemType data[MaxSize];//数组 
	int top;//栈顶
}SqStack;


//初始化栈
void init_stack(SqStack& L)
{
	L.top = -1;//表示为空
}

//判断栈是否为空
bool StackEmpty(SqStack& S) 
{
	if (S.top == -1)
		return true; 
	else
		return false;
}

//入栈
int  insert_stack(SqStack& L ,int x )
{
	//判断是否为满
	if (L.top == MaxSize - 1)
	{
		return -1;
	}
	L.data[++L.top] = x;
	
	return 1;
}
//出站
bool outStack(SqStack &L, int &x)
{
	//判断栈是否为空
	if (StackEmpty(L))
	{
		return false;
	}
	//出站元素
	x = L.data[L.top--];
	return true;

}
int main()
{
	SqStack L;
	//初始化栈
	init_stack(L);
	//入栈
	insert_stack(L,5);
	//出站
	int x = 0;
	outStack(L, x);
	printf("出站元素为：%d\n", x);
	return 0;
}