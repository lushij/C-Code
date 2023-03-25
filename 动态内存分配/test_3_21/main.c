#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


//typedef �ؼ���
typedef struct node_s {
	int val;
	struct node_S* next;
} Node;

Node* add_to_list(Node* list, int val)
{
	//��̬�ڴ濪�٣��������ӽ���������
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("����malloc failed in add_to_list\n");
		exit(1);//�˳�
	}
	//ͷ�巨
	newNode->val = val;//�����򱣴�����
	newNode->next = list;//ָ����������һ������
	return newNode;
}


//�����ӡ����
Node* print_list(Node*list)
{
	//�ȴ�ӡ���һ�����ݣ�
	printf("%d ", list->val);
	//Ȼ��ִ����һ��ָ����
	Node* p = list->next;
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}

}

int main()
{
	//���54321
	Node* list = NULL;
	list=add_to_list(list, 1);
	list=add_to_list(list, 2);
	list=add_to_list(list, 3);
	list=add_to_list(list, 4);
	list=add_to_list(list, 5);
	//��ӡ����
	print_list(list);

	return 0;
}