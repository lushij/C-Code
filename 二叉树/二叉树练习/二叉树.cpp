#include"������.h"


//��ʼ����
void init_tree(BiTree& tree)
{
	//���ĸ��ڵ��ÿ�
	tree = NULL;

}

//��������
void insert_tree(BiTree& tree, List& L)
{
	char ch = 0;
	BiTree pnewtree = NULL;
	//���е�ͷ��β���½ڵ㣬��ǰ�ڵ��
	List tail = NULL, head = NULL, ListNew = NULL, Pcur = NULL;
	while (scanf("%c", &ch) != EOF)
	{
		if (ch=='\n')
		{
			break;
		}
		//Ϊ�����½ڵ㿪�ٿռ�
		pnewtree = (BiTree)calloc(1, sizeof(Bitree));
		pnewtree->c = ch;
		//Ϊ�����½ڵ㿪�ٿռ�
		ListNew = (List)calloc(1, sizeof(LNode));
		ListNew->ptree = pnewtree;//�������Ľڵ�ĵ�ַ
		if (tree == NULL)
		{
			tree = pnewtree;
			//���е�ͷ����β,���黭ͼʵս�����ô������
			tail= ListNew;
			head = ListNew;
			Pcur= ListNew;//���浱ǰ�ĸ���Ԫ��
		}
		else
		{
			//������Ϣ
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

//������  ǰ�����
void ProReach(BiTree tree)
{
	//�ж����Ƿ�Ϊ��
	if (tree == NULL)
	{
		return;
	}
	putchar(tree->c);//��ǰ�ڵ�
	ProReach(tree->Ltree);//������
	ProReach(tree->Rtree);//������
}

//�������
void Reach(BiTree tree)
{
	//�ж����Ƿ�Ϊ��
	if (tree == NULL)
	{
		return;
	}
	Reach(tree->Ltree);//������
	putchar(tree->c);//��ǰ�ڵ�
	Reach(tree->Rtree);//������
}

//�������
void TalReach(BiTree tree)
{
	//�ж����Ƿ�Ϊ��
	if (tree == NULL)
	{
		return;
	}
	TalReach(tree->Ltree);//������
	TalReach(tree->Rtree);//������
	putchar(tree->c);//��ǰ�ڵ�
}