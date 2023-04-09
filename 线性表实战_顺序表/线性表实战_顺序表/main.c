#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct Sqlist {
	int data[50];
	int len;//数据的长度

}Sqlist;

int inisert_L(Sqlist *L,int pos,int new )
//插入数据接口
{
	//进行判断是否不符合
	if (pos<1 || pos>L->len)
	{
		return 0;
	}
	//判断满了
	if (L->len == 50)
	{
		return 0;
	}
	for (int j = L->len + 1; j >= pos; j--)
	{
		//向后移动
		L->data[j] = L->data[j - 1];
	}
	L->data[pos - 1] = new;//插入位置和下标差1
	L->len++;//长度加1
	return 1;
}


void pint(Sqlist L)
{
	for (int i = 0; i < L.len; i++)
	{
		printf("%d ", L.data[i]);
	}
}
int main()
{
	Sqlist L;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.data[3] = 4;
	L.data[4] = 5;
	L.data[5] = 6;
	//设置长度
	L.len = 6;
	int ret=inisert_L(&L,2,999);//插入数据接口
	if (ret)
	{
		printf("insert success\n");
		pint(L);
	}
	else
	{
		printf("error\n");
	}
	return 0;
}