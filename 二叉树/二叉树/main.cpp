#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Tree {
	char c;//节点
	struct Tree* Ltree;//左子树
	struct Tree* Rtree;//右子树
}Tree,*Bitree;

//辅助队列
typedef struct listNode {
	Bitree p;//保存树的节点的地址
	struct listNode* next;
}Lnode,*LNode;

//初始化树
void init_tree(Bitree &tree)
{
	//队列的头结点，尾结点，当前节点,新节点
	LNode head = NULL, tail = NULL,Listnew=NULL, pcur=NULL;//辅助队列
	char c = 0;
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			break;
		}
		Bitree Pnew = (Tree*)calloc(1, sizeof(Tree));//为树的新节点开辟空间
		Listnew = (LNode)calloc(1, sizeof(Lnode));//为辅助队列的新节点开辟空间
		Pnew->c = c;
		Listnew->p = Pnew;//保存新树的节点的地址
		if (tree == NULL)
		{
			tree = Pnew;//tree指向树的根节点
			head = Listnew;//队列第一个节点既是头结点，又是尾结点
			tail = Listnew;
			pcur = Listnew;//保存当前父亲元素的地址
		}
		else
		{
			//更新队列信息
			tail->next = Listnew;//队列保存新的节点
			tail = Listnew;
			if (pcur->p->Ltree == NULL)
			{
				pcur->p->Ltree = Pnew;//保存左子树
			}
			else
			{
				pcur->p->Rtree = Pnew;//保存右子树 
				pcur = pcur->next;//左右子树满了，更换父亲元素
			}

		}
		
	}
}


//遍历二叉树
//前序遍历
void freach(Bitree tree)
{
	if (tree == NULL)
	{
		return;
	}
	putchar(tree->c);//当前节点
	//采用递归
	freach(tree->Ltree);//左子树
	freach(tree->Rtree);//右子树

}

int main()
{
	Tree* tree=NULL;//建立根节点，必须初始化空
	//初始化树
	init_tree(tree);
	//遍历二叉树
	freach(tree);
	return 0;
}