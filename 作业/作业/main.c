#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	//题目：求出数组的第二大数，不使用冒泡排序算法
//	//简单
//	int a[10] = { 1,2,8,6,3,799,99,100,8,0 };
//	int max = 0;
//	int smax = 0;
//	if (*(a +0) > *(a + 1))
//	{
//		max = *(a + 0);
//		smax = *(a + 1);
//	}
//	else
//	{
//		max= *(a + 1);
//		smax = *(a + 0);
//	}
//	for (int i = 2; i < 10; i++)
//	{
//		if (*(a + i) > max)
//		{
//			int tmp = max;
//			max = *(a + i);
//			smax = tmp;
//		}
//		if (*(a + i) < max && *(a + i) > smax)
//		{
//			smax = *(a + i);
//		}
//	}
//	printf("第二大数是：%d", smax);
//
//	return 0;
//}