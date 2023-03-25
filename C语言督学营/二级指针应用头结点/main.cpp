#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;//������
    struct LNode* next;
}LNode, * LinkList;
//LNode*�ǽṹ��ָ�룬��LinkList��ȫ�ȼ۵�
//����3,4,5,6,7,9999
void list_head_insert(LNode*& L)
{
    L = (LinkList)malloc(sizeof(LNode));//����ͷ���ռ䣬ͷָ��ָ��ͷ���
    L->next = NULL;
    ElemType x;
    scanf("%d", &x);
    LNode* s;//����ָ��������½��
    while (x != 9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;//s��nextָ��ԭ������ĵ�һ�����
        L->next = s;//ͷ����next��ָ���½��
        scanf("%d", &x);
    }
}
//β�巨�½�����
void list_tail_insert(LNode*& L)//c++����
{
    L = (LinkList)malloc(sizeof(LNode));//����ͷ���ռ䣬ͷָ��ָ��ͷ���
    L->next = NULL;
    ElemType x;
    scanf("%d", &x);
    LNode* s, * r = L;//s������ָ��������½�㣬rʼ��ָ������β��
    while (x != 9999)
    {
        s = (LinkList)malloc(sizeof(LNode));//Ϊ�½������ռ�
        s->data = x;
        r->next = s;//�½���β����nextָ��
        r = s;//rҪָ���µ�β��
        scanf("%d", &x);
    }
    r->next = NULL;//��β����nextΪNULL
}

void print_list(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");
}

//ͷ�巨��β�巨���½�����
int main() {
    LinkList L;//L������ͷָ�룬�ǽṹ��ָ������
    //    list_head_insert(L);//�������ݿ���Ϊ3 4 5 6 7 9999,ͷ�巨�½�����
    list_tail_insert(L);
    print_list(L);//�����ӡ
    return 0;
}
