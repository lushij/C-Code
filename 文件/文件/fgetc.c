#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
	/*
	* #include <stdio.h>
	int fgetc(FILE * stream);
	���ܣ���streamָ�����ļ��ж�ȡһ���ַ�
	������
		   stream���ļ�ָ��
	����ֵ��
		   �ɹ������ض�ȡ�����ַ�
		   ʧ�ܣ�-1
	* 
	int fputc(int ch, FILE* stream);
	���ܣ���chת��Ϊunsigned char��д��streamָ�����ļ���
	������
	ch����Ҫд���ļ����ַ�
	stream���ļ�ָ��
	����ֵ��
	�ɹ����ɹ�д���ļ����ַ�
	ʧ�ܣ����� - 1
	ע�⣺�����Ƕ������ļ�
	*/

	/*
	* #include <stdio.h>
	 char * fgets(char * str, int size, FILE * stream);
	���ܣ���streamָ�����ļ��ڶ����ַ������浽str��ָ�����ڴ�ռ䣬
	ֱ�����ֻ����ַ��������ļ���β�����Ѷ���size - 1���ַ�Ϊֹ��
	�����Զ������ַ� '\0' ��Ϊ�ַ���������
	������
       str���ַ���
       size��ָ������ȡ�ַ����ĳ��ȣ�size - 1��
       stream���ļ�ָ��
	����ֵ��
       �ɹ����ɹ���ȡ���ַ���
       �����ļ�β����� NULL
	* 
	* 
	#include <stdio.h>
	int fputs(const char * str, FILE * stream);
	���ܣ���str��ָ�����ַ���д�뵽streamָ�����ļ��У��ַ��������� '\0'  ��д���ļ���
	������
		   str���ַ���
		   stream���ļ�ָ��
	����ֵ��
		   �ɹ���0
		   ʧ�ܣ�-1
	ע�⣺fgets  fputs ֻ�����ı��ļ�
	 */

//fopen�ķ���ֵ:  ����ɹ�����FILE�ṹ���ַ,ʧ�ܷ���NULL
int main()
{
	FILE* fp = fopen("fgetc.txt", "w");
	if (!fp)
	{
		perror("");
		exit(1);
	}
	char ch[] = "hello";
	fputs(ch, fp);
	fclose(fp);
	return 0;
}