#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;//������
    struct LNode* next;
}LNode, * LinkList;
//LNode*�ǽṹ��ָ�룬��LinkList��ȫ�ȼ۵�
//����3,4,5,6,7,9999
LinkList list_head_insert(LNode* L)
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
    return L;
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

//ͷ�巨���½�����
int main() {
    LinkList L;//L������ͷָ�룬�ǽṹ��ָ������
    L=list_head_insert(&L);//�������ݿ���Ϊ3 4 5 6 7 9999,ͷ�巨�½�����
    print_list(L);//�����ӡ
    return 0;
}
