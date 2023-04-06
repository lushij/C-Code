#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode {
	int data;
	struct Lnode* next;
}LNode,*Linklist;


//头插法
void add_LinkList(LNode* &pHeader)
{
	//头结点
	pHeader = (Linklist)malloc(sizeof(LNode));
	pHeader->next = NULL;
	LNode* newNode = NULL;
	printf("请输入你要输入的数据，输入0为结束\n");
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


//插入数据进行修改
void insert_list(LNode*& pHeader)
{
	int oldVal = 0;
	int newVal = 0;
	printf("请输入你要在那个数据前面插入新数据\n");
	printf("旧数据为：");
	scanf("%d", &oldVal);
	printf("新数据为：");
	scanf("%d", &newVal);
	//进行辅助
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

	//进行更改,创建新节点
	Linklist newNode = (Linklist)malloc(sizeof(LNode));
	newNode->data = newVal;
	newNode->next = NULL;
	newNode->next =pCurrent;
	pPre->next= newNode;
}

//遍历链表
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
	//头插法初始化链表
	add_LinkList(pHeader);
	//遍历链表
	print_list(pHeader);
	//插入数据进行修改
	insert_list(pHeader);
	//遍历链表
	print_list(pHeader);

	return 0;
}