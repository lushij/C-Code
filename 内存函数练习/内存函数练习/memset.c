#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int num = 0;
	//void * memset ( void * ptr, int value, size_t num );
	memset(&num, 1, 3);
	printf("%d", num);

	return 0;
}