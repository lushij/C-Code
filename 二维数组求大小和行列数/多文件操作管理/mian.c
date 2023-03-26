#define _CRT_SECURE_NO_WARNINGS 1

#include"my_math.h"
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	int max = my_max(a, b);
	int min = my_min(a, b);
	printf("max=%d,min=%d", max, min);
	return 0;
}