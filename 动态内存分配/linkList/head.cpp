#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * Linklist;

//运用c++的引用来写一段链表结构
//含有头结点的头插法
void add_head_list(Linklist& L)
{
	L = (LNode*)malloc(sizeof(LNode));//申请头结点空间，头指针执行头节点
	L->next = NULL;//头结点
	int num = 0;
	//LNode*  <==>  Linklist
	printf("请输入你要插入的数据，输入0为结束\n");
	scanf("%d", &num);
	while (num)
	{
		//开辟新空间 也就是为新节点开辟的空间
		Linklist s = (LNode*)malloc(sizeof(LNode));//malloc需要引用头文件stdlib.h
		s->data = num;//新开辟的空间存放输入的值
		s->next = L->next;//新开辟的空间的指针域指向   原本头结点指向的指针域 
		L->next = s;//然后头结点执行的指针域  换成 新空间的数据域
		scanf("%d", &num);
	}
}

//遍历链表 打印链表
void print_list(Linklist L)
{
	L = L->next;
	while (L)
	{
		printf("%d", L->data);
		L = L->next;
	}
}
//int main()
//{
//	//运用c++的引用来写一段链表结构
//	LNode* newNode = NULL;
//	add_head_list(newNode);
//	print_list(newNode);
//	return 0;
//}