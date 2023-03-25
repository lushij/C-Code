#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	int data;
	struct LNode* next;

}LNode,*Linklist;


void add_head_list(Linklist& L)
{
	
	L = (Linklist)malloc(sizeof(LNode));
	L->next = NULL;
	int num = 0;
	LNode* s;
	printf("请输入你要插入的数据，输入0为结束\n");
	scanf("%d", &num);
	while (num)
	{
		s= (Linklist)malloc(sizeof(LNode));
		s->data = num;
		s->next = L->next;
		L->next = s;
		scanf("%d", &num);
	}

}

void print_list(Linklist L)
{
	L = L->next;
	while (L)
	{
		printf("%d", L->data);
		L = L->next;
	}

}
int main()
{
	LNode* newNode = NULL;
	add_head_list(newNode);
	print_list(newNode);
	return 0;
}