#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode, * linkList;

//void add_head_list(linkList& L)
//{
//	L = (linkList)malloc(sizeof(Lnode));//创建新空间，开辟头节点
//	L->next = NULL;
//	int num = 0;
//	printf("请输入你要插入的数据，输入0结束\n");
//	scanf("%d", &num);
//	while (num)
//	{
//		linkList s = (linkList)malloc(sizeof(Lnode));//创建新空间
//		s->data = num;
//		s->next = L->next;
//		L->next = s;
//		scanf("%d", &num);
//	}
//
//}

//尾插法
void add_tail_list(linkList& L)
{
	L = (linkList)malloc(sizeof(Lnode));//创建新空间，开辟头节点
	L->next = NULL;
	int num = 0;
	linkList s, r = L;
	printf("请输入你要插入的数据，输入0结束\n");
	scanf("%d", &num);
	while (num)
	{
		linkList s = (linkList)malloc(sizeof(Lnode));//创建新空间
		s->data = num;
		r->next = s;
		r = s;
		scanf("%d", &num);
	}

}

//遍历链表
void print_list(linkList L)
{
	L=L->next;
	while (L)
	{
		printf("%d", L->data);
		L = L->next;
	}
}

int main()
{
	//运用c++的引用来写一段链表结构
	Lnode* newNode = NULL;
	//add_head_list(newNode);
	add_tail_list(newNode);
	print_list(newNode);
	return 0;
}