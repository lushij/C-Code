#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * Linklist;

//����c++��������дһ������ṹ
//����ͷ����ͷ�巨
void add_head_list(Linklist& L)
{
	L = (LNode*)malloc(sizeof(LNode));//����ͷ���ռ䣬ͷָ��ִ��ͷ�ڵ�
	L->next = NULL;//ͷ���
	int num = 0;
	//LNode*  <==>  Linklist
	printf("��������Ҫ��������ݣ�����0Ϊ����\n");
	scanf("%d", &num);
	while (num)
	{
		//�����¿ռ� Ҳ����Ϊ�½ڵ㿪�ٵĿռ�
		Linklist s = (LNode*)malloc(sizeof(LNode));//malloc��Ҫ����ͷ�ļ�stdlib.h
		s->data = num;//�¿��ٵĿռ��������ֵ
		s->next = L->next;//�¿��ٵĿռ��ָ����ָ��   ԭ��ͷ���ָ���ָ���� 
		L->next = s;//Ȼ��ͷ���ִ�е�ָ����  ���� �¿ռ��������
		scanf("%d", &num);
	}
}

//�������� ��ӡ����
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
//	//����c++��������дһ������ṹ
//	LNode* newNode = NULL;
//	add_head_list(newNode);
//	print_list(newNode);
//	return 0;
//}