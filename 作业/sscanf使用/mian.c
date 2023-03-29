#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{

    
    //sscanf 拆包函数
    //sscanf(buf, "格式", 数据);//将buf的内容格式化输出到数据
   
    //%d    0-9的字符
    int  year = 0;
    int  month = 0;
    int day = 0;
    char  buf[1024] = "beijing:2018:t:10:20";
    //scanf("%d:%d:%d",&year,&month,&day);//从键盘按照相应的格式获取数据
    sscanf(buf, "beijing:%d:t:%d:%d", &year, &month, &day);//从buf中按照相应的格式获取数据
	return 0;
}