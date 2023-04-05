#include"code.h"

//打开文件接口创建
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

//加密文件
void code_file()
{
	//打开要加密的文件
	FILE* fp = NULL;
	fp=open_file("./1.png", "rb");
	//打开加密地址
	FILE* fp1 = NULL;
	fp1 = open_file("./加密.txt", "wb");
	//读取
	char ch = 0;
	while (1)
	{
		if (feof(fp))
		{
			break;
		}
		ch = fgetc(fp);
		//进行强转
		short tmp = (short)ch;
		//进行加密
		tmp <<= 4;
		tmp = tmp | 0x8000;
		tmp += rand() % 16;
		//写入文件
		fprintf(fp1,"%hd" ,tmp);
	}
	fclose(fp);
	fclose(fp1);
}


//解密文件
void decode_file()
{
	//打开加密地址
	FILE* fp = NULL;
	fp = open_file("./加密.txt", "rb");
	//打开解密地址
	FILE* fp1 = NULL;
	fp1 = open_file("./解密.png", "wb");
	//读取
	char ch = 0;
	short temp = 0;
	while (!feof(fp))
	{
		//读取
		fscanf(fp, "%hd", &temp);
		//进行解密
		temp <<= 1;
		temp >>= 5;
		(char)ch = (char)temp;
		fputc(ch,fp1);
	}
	fclose(fp);
	fclose(fp1);
}