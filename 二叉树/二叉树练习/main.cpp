#include"二叉树.h"

int main()
{
	BiTree tree;
	List L = NULL;
	//初始化树
	init_tree(tree);
	//插入数据
	insert_tree(tree, L);

	//遍历树  前序遍历
	printf("前序遍历为：");
	ProReach(tree);
	printf("\n");
	//中序遍历
	printf("中序遍历为：");
	Reach(tree);
	printf("\n");
	//后序遍历
	printf("后序遍历为：");
	TalReach(tree);
	printf("\n");
	return 0;
}