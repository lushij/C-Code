#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode {
	int data;
	struct Lnode* next;
}LNode,*Linklist;


//ͷ�巨
void add_LinkList(LNode* &pHeader)
{
	//ͷ���
	pHeader = (Linklist)malloc(sizeof(LNode));
	pHeader->next = NULL;
	LNode* newNode = NULL;
	printf("��������Ҫ��������ݣ�����0Ϊ����\n");
	int num = 0;
	scanf("%d", &num);
	while (num)
	{
		newNode = (Linklist)malloc(sizeof(LNode));
		newNode->data = num;
		newNode->next = pHeader->next;
		pHeader->next = newNode;
		scanf("%d", &num);
	}
}


//�������ݽ����޸�
void insert_list(LNode*& pHeader)
{
	int oldVal = 0;
	int newVal = 0;
	printf("��������Ҫ���Ǹ�����ǰ�����������\n");
	printf("������Ϊ��");
	scanf("%d", &oldVal);
	printf("������Ϊ��");
	scanf("%d", &newVal);
	//���и���
	Linklist pPre = pHeader;
	Linklist pCurrent = pHeader->next;
	while (pCurrent != NULL)
	{
		if (pCurrent->data == oldVal)
		{
			break;
		}
		pPre = pCurrent;
		pCurrent = pCurrent->next;
		
	}

	//���и���,�����½ڵ�
	Linklist newNode = (Linklist)malloc(sizeof(LNode));
	newNode->data = newVal;
	newNode->next = NULL;
	newNode->next =pCurrent;
	pPre->next= newNode;
}

//��������
void print_list(LNode* pHeader)
{
	pHeader = pHeader->next;
	while (pHeader)
	{
		printf("%d ", pHeader->data);
		pHeader = pHeader->next;
	}
	printf("\n");
}
int main()
{
	LNode* pHeader = NULL;
	//ͷ�巨��ʼ������
	add_LinkList(pHeader);
	//��������
	print_list(pHeader);
	//�������ݽ����޸�
	insert_list(pHeader);
	//��������
	print_list(pHeader);

	return 0;
}