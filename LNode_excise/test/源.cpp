#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode, * linkList;

void add_head_list(linkList& L)
{
	L = (linkList)malloc(sizeof(Lnode));//�����¿ռ䣬����ͷ�ڵ�
	L->next = NULL;
	Lnode* s;//��������ʱ���ٿռ�
	int num = 0;
	printf("��������Ҫ��������ݣ�����0����\n");
	scanf("%d", &num);
	while (num)
	{
		s = (linkList)malloc(sizeof(Lnode));//�����¿ռ�
		s->data = num;
		s->next = L->next;
		L->next = s;
		scanf("%d", &num);
	}

}

void print_list(linkList L)
{
	L->next = NULL;
	while (L->next != NULL)
	{
		printf("%d", L->data);
		L = L->next;
	}
}
int main()
{
	Lnode* newNode = NULL;
	add_head_list(newNode);
	print_list(newNode);

	return 0;
}