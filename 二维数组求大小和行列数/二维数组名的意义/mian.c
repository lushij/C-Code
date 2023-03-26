#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	//读取字符串的函数的区别
	char ch[20] = "";
	//scanf("%s", ch);//缺点：遇到空格会暂停读取,如果内存不够但是输入字符大于开辟内存空间，会造成内存污染
	//printf("%s", ch);


	//gets(ch);//优点：遇到\n会暂停读取，缺点：如果内存不够但是输入字符大于开辟内存空间，会造成内存污染
	//printf("%s", ch);



	//建议以后读取字符使用fets函数，更安全一点
	fgets(ch, sizeof(ch), stdin);//更安全一点，但是会读取回车键\n，需配合自动把\n改为\0
	ch[strlen(ch) - 1] = 0;//须引用string.h
	printf("%s", ch);
	return 0;
}