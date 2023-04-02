#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0x11223344;
	//高位字节-->低位字节
	char* p = &a;
	printf("%x\n", *p);//44-->低地址存放低位字节
	printf("%x\n", *(p + 1));
	printf("%x\n", *(p + 2));
	printf("%x\n", *(p + 3));//11-->高地址存放高位字节
	return 0;
}