#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	//const int a = 10;
	////a = 20;//这样更改值是不行的
	////下面的这样可以更改a的值
	//int* p = &a;
	//*p = 20;
	//printf("%d\n", *p);



	////example2
	//int a = 10;
	//int const* p = &a;
	////*p = 20;//这样也不可以更改了
	////下面的就可以更改了

	//int** q = &p;
	//**q = 20;
	//printf("%d\n", **q);


	//总结：const修饰谁，谁不能被修改，需要通过访问地址才可以会更改

	return 0;
}