#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	//��ȡ�ַ����ĺ���������
	char ch[20] = "";
	//scanf("%s", ch);//ȱ�㣺�����ո����ͣ��ȡ,����ڴ治�����������ַ����ڿ����ڴ�ռ䣬������ڴ���Ⱦ
	//printf("%s", ch);


	//gets(ch);//�ŵ㣺����\n����ͣ��ȡ��ȱ�㣺����ڴ治�����������ַ����ڿ����ڴ�ռ䣬������ڴ���Ⱦ
	//printf("%s", ch);



	//�����Ժ��ȡ�ַ�ʹ��fets����������ȫһ��
	fgets(ch, sizeof(ch), stdin);//����ȫһ�㣬���ǻ��ȡ�س���\n��������Զ���\n��Ϊ\0
	ch[strlen(ch) - 1] = 0;//������string.h
	printf("%s", ch);
	return 0;
}