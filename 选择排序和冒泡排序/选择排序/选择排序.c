#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	
	for (i = 0; i < 10; i++)
	{
		int min = i;
		for (int j = i+1; j < 10; j++)
		{
			if (arr[min] > arr[j])
			{
				min = i;
			}
		}
		if (min != i)
		{
			int tmp = arr[min];
			arr[min] = arr[i];
			arr[i] = tmp;
		}

	}
	
	//±éÀúÊı×éÅÅĞò
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}