#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


//�������Ľṹ��
typedef struct tree {
	char c;//������
	struct tree* Ltree;//������
	struct tree* Rtree;//������
}Bitree,*BiTree;



//���ĸ�������
typedef struct list {
	BiTree ptree;//�������ĸ��ڵ�ĵ�ַ
	struct list* next;
}LNode,*List;


//��ʼ����
void init_tree(BiTree &tree);

//��������
void insert_tree(BiTree& tree, List& L);

//������  ǰ�����
void ProReach(BiTree tree);
//�������
void Reach(BiTree tree);
//�������
void TalReach(BiTree tree);