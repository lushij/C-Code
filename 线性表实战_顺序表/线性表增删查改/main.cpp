#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct Sqlist {
	int data[50];
	int len;//���ݵĳ���

}Sqlist;


//��������
int inisert_L(Sqlist* L, int pos, int newdata)
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
	L->data[pos - 1] = newdata;//����λ�ú��±��1
	L->len++;//���ȼ�1
	return 1;
}

//��������
void pint(Sqlist L)
{
	for (int i = 0; i < L.len; i++)
	{
		printf("%d ", L.data[i]);
	}
}


//ɾ������
int  delList(Sqlist& L,int j,int &x)//c++����
{
	//�ж�ɾ��λ���Ƿ�Ϸ�
	if (j<1 || j>L.len)
	{
		return 0;
	}
	//����ɾ������
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
	//���ó���
	L.len = 6;
	int ret = inisert_L(&L, 2, 999);//�������ݽӿ�
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
	printf("ɾ������Ϊ��%d\n", x);
	printf("-----------------\n");
	pint(L);
	return 0;
}