#include"code.h"

//���ļ��ӿڴ���
FILE* open_file(char*dist,char* str)
{
	FILE* fp = fopen(dist, str);
	if (!fp)
	{
		perror("");
		return -1;
	}
	return fp;
}

//�����ļ�
void code_file()
{
	//��Ҫ���ܵ��ļ�
	FILE* fp = NULL;
	fp=open_file("./1.png", "rb");
	//�򿪼��ܵ�ַ
	FILE* fp1 = NULL;
	fp1 = open_file("./����.txt", "wb");
	//��ȡ
	char ch = 0;
	while (1)
	{
		if (feof(fp))
		{
			break;
		}
		ch = fgetc(fp);
		//����ǿת
		short tmp = (short)ch;
		//���м���
		tmp <<= 4;
		tmp = tmp | 0x8000;
		tmp += rand() % 16;
		//д���ļ�
		fprintf(fp1,"%hd" ,tmp);
	}
	fclose(fp);
	fclose(fp1);
}


//�����ļ�
void decode_file()
{
	//�򿪼��ܵ�ַ
	FILE* fp = NULL;
	fp = open_file("./����.txt", "rb");
	//�򿪽��ܵ�ַ
	FILE* fp1 = NULL;
	fp1 = open_file("./����.png", "wb");
	//��ȡ
	char ch = 0;
	short temp = 0;
	while (!feof(fp))
	{
		//��ȡ
		fscanf(fp, "%hd", &temp);
		//���н���
		temp <<= 1;
		temp >>= 5;
		(char)ch = (char)temp;
		fputc(ch,fp1);
	}
	fclose(fp);
	fclose(fp1);
}