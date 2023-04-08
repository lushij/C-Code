#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int mycompre(char*pj, char* pm)
{
	int* data1 = (int*)pj;
	int* data2 = (int*)pm;
	if (*data1 < *data2)
	{
		return 1;
	}
	else 
	{
		return 0;
	}

}
//回调函数实现
void my_qsort(void* arr, int sz, int elsesz,int(*mycompre)(void*,void*))
{
	char* tmp = malloc(sizeof(char*));
	for (int i = 0; i < sz; i++)
	{
		int minOrMax = i;
		for (int j = i + 1; j < sz; j++)
		{
			//获取j的地址
			char* pj = (char*)arr + elsesz * j;//越过每一个数据的字节长度
			//获取minOrMax的地址
			char* pm = (char*)arr + elsesz * minOrMax;
			if (mycompre(pj, pm))
			{
				minOrMax = j;
			}
		}
		if (minOrMax != i)
		{
			char* pj = (char*)arr + elsesz *i ;
			//获取minOrMax的地址
			char* pm = (char*)arr + elsesz * minOrMax;
			memcpy(tmp, pj, elsesz);
			memcpy(pj, pm, elsesz);
			memcpy(pm, tmp, elsesz);
		}
	}
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
}




int main()
{
	int arr[10] = { 1,3,4,5,9,6,7,10,11,22 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]),mycompre);
	//遍历数组排序
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}