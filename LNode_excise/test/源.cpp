#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode, * linkList;

void add_head_list(linkList& L)
{
	L = (linkList)malloc(sizeof(Lnode));//创建新空间，开辟头节点
	L->next = NULL;
	Lnode* s;//插入数据时开辟空间
	int num = 0;
	printf("请输入你要插入的数据，输入0结束\n");
	scanf("%d", &num);
	while (num)
	{
		s = (linkList)malloc(sizeof(Lnode));//创建新空间
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