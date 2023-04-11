#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MaxSize 5

//�������Ƚ��ȳ���First In First Out��FIFO��

typedef struct S {
	int data[MaxSize];//�������洢MaxSize-1������
	int front, rear;//��ͷ ��β
}SQueue;

//��ʼ������
void init_squeue(SQueue &s) 
{
	s.front = s.rear = 0;//��ʼ������Ϊ��
}

//��������
void insert_squeue(SQueue &s,int x)
{
	//�ж϶����Ƿ�Ϊ�� (Q.rear+1)%MaxSize==Q.front
	if ((s.rear + 1) % MaxSize == s.front)
	{
		return;
	}
	//��������
	s.data[s.rear] = x;
	//���¶�β
	s.rear = (s.rear + 1) % MaxSize;//��Ϊ��ѭ������Ҫ��1ģ������������������±�
}

//�˳�����
void outSqueue(SQueue &s, int &x)
{
	//�ж��Ƿ�Ϊ��
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
	//��ʼ������
	init_squeue(s);
	//��������
	insert_squeue(s,2);
	insert_squeue(s,3);
	insert_squeue(s,5);
	insert_squeue(s,6);
	//����
	int x = 0;//�������Ԫ��
	outSqueue(s, x);
	outSqueue(s, x);
	printf("out count is %d\n ", x);

	return 0;
}