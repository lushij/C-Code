#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0x11223344;
	//��λ�ֽ�-->��λ�ֽ�
	char* p = &a;
	printf("%x\n", *p);//44-->�͵�ַ��ŵ�λ�ֽ�
	printf("%x\n", *(p + 1));
	printf("%x\n", *(p + 2));
	printf("%x\n", *(p + 3));//11-->�ߵ�ַ��Ÿ�λ�ֽ�
	return 0;
}