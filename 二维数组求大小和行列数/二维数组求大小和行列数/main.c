#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[3][4] = { 0 };
	int n = sizeof(a) / sizeof(a[0][0]);
	//��ά����a[0]����һ��
	int row = sizeof(a) / sizeof(a[0]);
	//��=һ�еĴ�С����һ��Ԫ�صĴ�С
	int col = sizeof(a[0]) / sizeof(a[0][0]);
	printf("%d %d %d", n, row, col);
	return 0;
}