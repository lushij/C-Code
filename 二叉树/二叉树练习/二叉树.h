#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


//定义树的结构体
typedef struct tree {
	char c;//树的数
	struct tree* Ltree;//左子树
	struct tree* Rtree;//右子树
}Bitree,*BiTree;



//树的辅助队列
typedef struct list {
	BiTree ptree;//保存树的根节点的地址
	struct list* next;
}LNode,*List;


//初始化树
void init_tree(BiTree &tree);

//插入数据
void insert_tree(BiTree& tree, List& L);

//遍历树  前序遍历
void ProReach(BiTree tree);
//中序遍历
void Reach(BiTree tree);
//后序遍历
void TalReach(BiTree tree);