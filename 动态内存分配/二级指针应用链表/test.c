#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;
}Node,*LNode;

void add_head_list(LNode *L,int val)//�ȼ���Node**L
{
	//������LNode-->Node *  ��ȫ�ȼ�
	LNode newNode = (LNode)malloc(sizeof(Node));//�����¿ռ�
	//�����ж��Ƿ�Ϊ��ָ��
	if (newNode == NULL)
	{
		printf("error:the failed in the add_head_list.\n");
		exit(1);
	}
	//ͷ�巨
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