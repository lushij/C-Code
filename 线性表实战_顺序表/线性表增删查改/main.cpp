#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct Sqlist {
	int data[50];
	int len;//数据的长度

}Sqlist;


//插入数据
int inisert_L(Sqlist* L, int pos, int newdata)
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
	L->data[pos - 1] = newdata;//插入位置和下标差1
	L->len++;//长度加1
	return 1;
}

//遍历数据
void pint(Sqlist L)
{
	for (int i = 0; i < L.len; i++)
	{
		printf("%d ", L.data[i]);
	}
}


//删除数据
int  delList(Sqlist& L,int j,int &x)//c++引用
{
	//判断删除位置是否合法
	if (j<1 || j>L.len)
	{
		return 0;
	}
	//保存删除数据
	x = L.data[j - 1];
	for (int i = j-1 ; i < L.len-1 ; i++)
	{
		L.data[i] = L.data[i+1];
	}
	L.len--;
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
	int ret = inisert_L(&L, 2, 999);//插入数据接口
	if (ret)
	{
		printf("insert success\n");
		pint(L);
		printf("\n");
	}
	else
	{
		printf("error\n");
	}
	int x = 0;
	ret = delList(L, 5,x);
	printf("删除数据为：%d\n", x);
	printf("-----------------\n");
	pint(L);
	return 0;
}