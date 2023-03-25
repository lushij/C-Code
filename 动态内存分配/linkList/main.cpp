#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;


//尾插法实现
void add_tail_list(LNode* &L)//c++引用
{
	int num = 0;
	L = (LinkList)malloc(sizeof(LNode));//申请头结点的空间 注意 头结点与第一个节点不一个意思
	L->next = NULL;
	LNode* s, * r = L;//*s为新开辟的空间  r始终指向尾部
	printf("请输入你要插入的数据，输入0为结束\n");
	scanf("%d",&num);
	while (num)
	{
		s= (LinkList)malloc(sizeof(LNode));
		s->data = num;
		r->next = s;//把新节点给尾结点的指针域  
		r = s;//r要指向新的尾部
		scanf("%d", &num);
	}
	r->next = NULL;//尾结点指针域赋值null
}

//遍历链表 打印链表
void print_list_1(LinkList List)
{
	List = List->next;//判断是否为空
	while (List)
	{
		printf("%d", List->data);
		List = List->next;
	}
}


int main()
{
	//尾插法练习
	LNode* L = NULL;
	add_tail_list(L);
    print_list_1(L);
	return 0;
}