#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#include <stdlib.h>
#define MaxSize 50 
typedef int  ElemType;

//ջ�Ƚ����
typedef struct {
	ElemType data[MaxSize];//���� 
	int top;//ջ��
}SqStack;


//��ʼ��ջ
void init_stack(SqStack& L)
{
	L.top = -1;//��ʾΪ��
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack& S) 
{
	if (S.top == -1)
		return true; 
	else
		return false;
}

//��ջ
int  insert_stack(SqStack& L ,int x )
{
	//�ж��Ƿ�Ϊ��
	if (L.top == MaxSize - 1)
	{
		return -1;
	}
	L.data[++L.top] = x;
	
	return 1;
}
//��վ
bool outStack(SqStack &L, int &x)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (StackEmpty(L))
	{
		return false;
	}
	//��վԪ��
	x = L.data[L.top--];
	return true;

}
int main()
{
	SqStack L;
	//��ʼ��ջ
	init_stack(L);
	//��ջ
	insert_stack(L,5);
	//��վ
	int x = 0;
	outStack(L, x);
	printf("��վԪ��Ϊ��%d\n", x);
	return 0;
}