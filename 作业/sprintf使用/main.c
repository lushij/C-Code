#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	//int sprintf ( char * str, const char * format, ... );
	//返回值是成功时，返回写入的字符总数。
	//此计数不包括自动附加在字符串末尾的额外空字符。 
	//失败时，返回一个负数。
	/* sprintf example */

	//printf函数是打印在屏幕上
	//sprintf是组包函数是把数据存放在包内


	char buffer[50];
	int n, a = 5, b = 3;
	n = sprintf(buffer, "%d plus %d is %d", a, b, a + b);
	printf("[%s] is a string %d chars long\n", buffer, n);
	return 0;
}