#include"������.h"

int main()
{
	BiTree tree;
	List L = NULL;
	//��ʼ����
	init_tree(tree);
	//��������
	insert_tree(tree, L);

	//������  ǰ�����
	printf("ǰ�����Ϊ��");
	ProReach(tree);
	printf("\n");
	//�������
	printf("�������Ϊ��");
	Reach(tree);
	printf("\n");
	//�������
	printf("�������Ϊ��");
	TalReach(tree);
	printf("\n");
	return 0;
}