#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


//typedef 关键字
typedef struct node_s {
	int val;
	struct node_S* next;
} Node;

Node* add_to_list(Node* list, int val)
{
	//动态内存开辟，进行连接交换的作用
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("错误：malloc failed in add_to_list\n");
		exit(1);//退出
	}
	//头插法
	newNode->val = val;//数据域保存数据
	newNode->next = list;//指针域连接下一个链表
	return newNode;
}


//链表打印数据
Node* print_list(Node*list)
{
	//先打印最后一个数据，
	printf("%d ", list->val);
	//然后执行下一个指针域
	Node* p = list->next;
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}

}

int main()
{
	//结果54321
	Node* list = NULL;
	list=add_to_list(list, 1);
	list=add_to_list(list, 2);
	list=add_to_list(list, 3);
	list=add_to_list(list, 4);
	list=add_to_list(list, 5);
	//打印链表
	print_list(list);

	return 0;
}