#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, * LinkList;


LinkList Create_List(LinkList L)
{
    //头插法
    LNode* s;
    int x;
    L = (LNode*)malloc(sizeof(LNode));//创建头结点
    L->next = NULL;//开始时头结点为空
    scanf_s("%d", &x);
    while (x != 999)
    {
        s = (LinkList)malloc(sizeof(LNode));//开辟新空间
        s->data = x;//把s节点数据域赋值x
        s->next = L->next;//使L连接第一个节点
        L->next = s;//头结点接着新节点
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

