#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;


//β�巨ʵ��
void add_tail_list(LNode* &L)//c++����
{
	int num = 0;
	L = (LinkList)malloc(sizeof(LNode));//����ͷ���Ŀռ� ע�� ͷ������һ���ڵ㲻һ����˼
	L->next = NULL;
	LNode* s, * r = L;//*sΪ�¿��ٵĿռ�  rʼ��ָ��β��
	printf("��������Ҫ��������ݣ�����0Ϊ����\n");
	scanf("%d",&num);
	while (num)
	{
		s= (LinkList)malloc(sizeof(LNode));
		s->data = num;
		r->next = s;//���½ڵ��β����ָ����  
		r = s;//rҪָ���µ�β��
		scanf("%d", &num);
	}
	r->next = NULL;//β���ָ����ֵnull
}

//�������� ��ӡ����
void print_list_1(LinkList List)
{
	List = List->next;//�ж��Ƿ�Ϊ��
	while (List)
	{
		printf("%d", List->data);
		List = List->next;
	}
}


int main()
{
	//β�巨��ϰ
	LNode* L = NULL;
	add_tail_list(L);
    print_list_1(L);
	return 0;
}