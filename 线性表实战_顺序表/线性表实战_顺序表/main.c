#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct Sqlist {
	int data[50];
	int len;//���ݵĳ���

}Sqlist;

int inisert_L(Sqlist *L,int pos,int new )
//�������ݽӿ�
{
	//�����ж��Ƿ񲻷���
	if (pos<1 || pos>L->len)
	{
		return 0;
	}
	//�ж�����
	if (L->len == 50)
	{
		return 0;
	}
	for (int j = L->len + 1; j >= pos; j--)
	{
		//����ƶ�
		L->data[j] = L->data[j - 1];
	}
	L->data[pos - 1] = new;//����λ�ú��±��1
	L->len++;//���ȼ�1
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
	//���ó���
	L.len = 6;
	int ret=inisert_L(&L,2,999);//�������ݽӿ�
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