#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Tree {
	char c;//�ڵ�
	struct Tree* Ltree;//������
	struct Tree* Rtree;//������
}Tree,*Bitree;

//��������
typedef struct listNode {
	Bitree p;//�������Ľڵ�ĵ�ַ
	struct listNode* next;
}Lnode,*LNode;

//��ʼ����
void init_tree(Bitree &tree)
{
	//���е�ͷ��㣬β��㣬��ǰ�ڵ�,�½ڵ�
	LNode head = NULL, tail = NULL,Listnew=NULL, pcur=NULL;//��������
	char c = 0;
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			break;
		}
		Bitree Pnew = (Tree*)calloc(1, sizeof(Tree));//Ϊ�����½ڵ㿪�ٿռ�
		Listnew = (LNode)calloc(1, sizeof(Lnode));//Ϊ�������е��½ڵ㿪�ٿռ�
		Pnew->c = c;
		Listnew->p = Pnew;//���������Ľڵ�ĵ�ַ
		if (tree == NULL)
		{
			tree = Pnew;//treeָ�����ĸ��ڵ�
			head = Listnew;//���е�һ���ڵ����ͷ��㣬����β���
			tail = Listnew;
			pcur = Listnew;//���浱ǰ����Ԫ�صĵ�ַ
		}
		else
		{
			//���¶�����Ϣ
			tail->next = Listnew;//���б����µĽڵ�
			tail = Listnew;
			if (pcur->p->Ltree == NULL)
			{
				pcur->p->Ltree = Pnew;//����������
			}
			else
			{
				pcur->p->Rtree = Pnew;//���������� 
				pcur = pcur->next;//�����������ˣ���������Ԫ��
			}

		}
		
	}
}


//����������
//ǰ�����
void freach(Bitree tree)
{
	if (tree == NULL)
	{
		return;
	}
	putchar(tree->c);//��ǰ�ڵ�
	//���õݹ�
	freach(tree->Ltree);//������
	freach(tree->Rtree);//������

}

int main()
{
	Tree* tree=NULL;//�������ڵ㣬�����ʼ����
	//��ʼ����
	init_tree(tree);
	//����������
	freach(tree);
	return 0;
}