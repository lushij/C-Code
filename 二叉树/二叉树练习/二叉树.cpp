#include"二叉树.h"


//初始化树
void init_tree(BiTree& tree)
{
	//树的根节点置空
	tree = NULL;

}

//插入数据
void insert_tree(BiTree& tree, List& L)
{
	char ch = 0;
	BiTree pnewtree = NULL;
	//队列的头，尾，新节点，当前节点的
	List tail = NULL, head = NULL, ListNew = NULL, Pcur = NULL;
	while (scanf("%c", &ch) != EOF)
	{
		if (ch=='\n')
		{
			break;
		}
		//为树的新节点开辟空间
		pnewtree = (BiTree)calloc(1, sizeof(Bitree));
		pnewtree->c = ch;
		//为队列新节点开辟空间
		ListNew = (List)calloc(1, sizeof(LNode));
		ListNew->ptree = pnewtree;//保存树的节点的地址
		if (tree == NULL)
		{
			tree = pnewtree;
			//队列的头既是尾,建议画图实战，多敲代码理解
			tail= ListNew;
			head = ListNew;
			Pcur= ListNew;//保存当前的父亲元素
		}
		else
		{
			//更新信息
			tail->next=ListNew;
			tail = ListNew;
			if (Pcur->ptree->Ltree == NULL)
			{
				Pcur->ptree->Ltree = pnewtree;

			}
			else
			{
				Pcur->ptree->Rtree = pnewtree;
				Pcur = Pcur->next;
			}
		}
	}
}

//遍历树  前序遍历
void ProReach(BiTree tree)
{
	//判断树是否为空
	if (tree == NULL)
	{
		return;
	}
	putchar(tree->c);//当前节点
	ProReach(tree->Ltree);//左子树
	ProReach(tree->Rtree);//右子树
}

//中序遍历
void Reach(BiTree tree)
{
	//判断树是否为空
	if (tree == NULL)
	{
		return;
	}
	Reach(tree->Ltree);//左子树
	putchar(tree->c);//当前节点
	Reach(tree->Rtree);//右子树
}

//后序遍历
void TalReach(BiTree tree)
{
	//判断树是否为空
	if (tree == NULL)
	{
		return;
	}
	TalReach(tree->Ltree);//左子树
	TalReach(tree->Rtree);//右子树
	putchar(tree->c);//当前节点
}