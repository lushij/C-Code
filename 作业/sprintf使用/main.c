#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	//int sprintf ( char * str, const char * format, ... );
	//����ֵ�ǳɹ�ʱ������д����ַ�������
	//�˼����������Զ��������ַ���ĩβ�Ķ�����ַ��� 
	//ʧ��ʱ������һ��������
	/* sprintf example */

	//printf�����Ǵ�ӡ����Ļ��
	//sprintf����������ǰ����ݴ���ڰ���


	char buffer[50];
	int n, a = 5, b = 3;
	n = sprintf(buffer, "%d plus %d is %d", a, b, a + b);
	printf("[%s] is a string %d chars long\n", buffer, n);
	return 0;
}