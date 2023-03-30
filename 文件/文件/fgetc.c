#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
	/*
	* #include <stdio.h>
	int fgetc(FILE * stream);
	功能：从stream指定的文件中读取一个字符
	参数：
		   stream：文件指针
	返回值：
		   成功：返回读取到的字符
		   失败：-1
	* 
	int fputc(int ch, FILE* stream);
	功能：将ch转换为unsigned char后写入stream指定的文件中
	参数：
	ch：需要写入文件的字符
	stream：文件指针
	返回值：
	成功：成功写入文件的字符
	失败：返回 - 1
	注意：可以是二进制文件
	*/

	/*
	* #include <stdio.h>
	 char * fgets(char * str, int size, FILE * stream);
	功能：从stream指定的文件内读入字符，保存到str所指定的内存空间，
	直到出现换行字符、读到文件结尾或是已读了size - 1个字符为止，
	最后会自动加上字符 '\0' 作为字符串结束。
	参数：
       str：字符串
       size：指定最大读取字符串的长度（size - 1）
       stream：文件指针
	返回值：
       成功：成功读取的字符串
       读到文件尾或出错： NULL
	* 
	* 
	#include <stdio.h>
	int fputs(const char * str, FILE * stream);
	功能：将str所指定的字符串写入到stream指定的文件中，字符串结束符 '\0'  不写入文件。
	参数：
		   str：字符串
		   stream：文件指针
	返回值：
		   成功：0
		   失败：-1
	注意：fgets  fputs 只能是文本文件
	 */

//fopen的返回值:  如果成功返回FILE结构体地址,失败返回NULL
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