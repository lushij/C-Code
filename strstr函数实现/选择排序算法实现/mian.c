#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void my_sort(char* arr[], int count)//char*arr[]==char**arr
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count; i++)
	{
		int min = i;
		for (j = i + 1; j < count; j++)
		{
			if (strcmp(arr[min], arr[j]) > 0 )//参数1大于参数2
			{
				min = j;
			}
		}
		if (min != i)
		{
			char *tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}


void print_arr(char**arr,int  len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%s ", arr[i]);
	}

}

int main()
{
	char* arr[] = { "lele","xiaohua","xiaohong","tao" };
	int len = sizeof(arr) / sizeof(arr[0]);
	my_sort(arr,len);
	print_arr(arr, len);
	return 0;
}