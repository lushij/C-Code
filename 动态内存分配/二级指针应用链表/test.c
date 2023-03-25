#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;
}Node,*LNode;

void add_head_list(LNode *L,int val)//等价于Node**L
{
	//在这里LNode-->Node *  完全等价
	LNode newNode = (LNode)malloc(sizeof(Node));//开辟新空间
	//进行判断是否为空指针
	if (newNode == NULL)
	{
		printf("error:the failed in the add_head_list.\n");
		exit(1);
	}
	//头插法
	newNode->val = val;
	newNode->next = *L;
	*L = newNode;

}


int main()
{
	 Node* L=NULL;
	 add_head_list(&L,1);
	 add_head_list(&L,2);
	 add_head_list(&L,3);
	 add_head_list(&L,4);
	 add_head_list(&L,5);
	return 0;
}