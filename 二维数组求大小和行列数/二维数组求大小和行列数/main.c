#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[3][4] = { 0 };
	int n = sizeof(a) / sizeof(a[0][0]);
	//二维数组a[0]代表一行
	int row = sizeof(a) / sizeof(a[0]);
	//列=一行的大小除以一个元素的大小
	int col = sizeof(a[0]) / sizeof(a[0][0]);
	printf("%d %d %d", n, row, col);
	return 0;
}