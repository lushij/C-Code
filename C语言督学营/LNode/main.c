#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, * LinkList;


LinkList Create_List(LinkList L)
{
    //ͷ�巨
    LNode* s;
    int x;
    L = (LNode*)malloc(sizeof(LNode));//����ͷ���
    L->next = NULL;//��ʼʱͷ���Ϊ��
    scanf_s("%d", &x);
    while (x != 999)
    {
        s = (LinkList)malloc(sizeof(LNode));//�����¿ռ�
        s->data = x;//��s�ڵ�������ֵx
        s->next = L->next;//ʹL���ӵ�һ���ڵ�
        L->next = s;//ͷ�������½ڵ�
        scanf_s("%d", &x);
    }
    return L;
}

int main()
{
    LNode* L=NULL ;
    L= Create_List(L);
    return 0;
}

