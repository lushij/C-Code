#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//C++引用必须.cpp文件后缀
//使用了引用后，在子函数内的操作和函数外操作手法一致，
//这样编程效率较高，对于初学者理解也非常方便，王道数据结
//构书籍中均采用了这种手法。

void modiy_print(int &b)//在这里&表示c++的引用，与C语言的&意义不同

{
	b = 10;
}

//int main()
//{
//	//C++引用必须.cpp文件后缀
//	int a = 0;
//	modiy_print(a);
//	//经过modiy_print（）后 a的值变为10；
//	printf("modiy_print after is %d\n", a);
//	return 0;
//}