#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode, * linkList;

//void add_head_list(linkList& L)
//{
//	L = (linkList)malloc(sizeof(Lnode));//�����¿ռ䣬����ͷ�ڵ�
//	L->next = NULL;
//	int num = 0;
//	printf("��������Ҫ��������ݣ�����0����\n");
//	scanf("%d", &num);
//	while (num)
//	{
//		linkList s = (linkList)malloc(sizeof(Lnode));//�����¿ռ�
//		s->data = num;
//		s->next = L->next;
//		L->next = s;
//		scanf("%d", &num);
//	}
//
//}

//β�巨
void add_tail_list(linkList& L)
{
	L = (linkList)malloc(sizeof(Lnode));//�����¿ռ䣬����ͷ�ڵ�
	L->next = NULL;
	int num = 0;
	linkList s, r = L;
	printf("��������Ҫ��������ݣ�����0����\n");
	scanf("%d", &num);
	while (num)
	{
		linkList s = (linkList)malloc(sizeof(Lnode));//�����¿ռ�
		s->data = num;
		r->next = s;
		r = s;
		scanf("%d", &num);
	}

}

//��������
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
	//����c++��������дһ������ṹ
	Lnode* newNode = NULL;
	//add_head_list(newNode);
	add_tail_list(newNode);
	print_list(newNode);
	return 0;
}