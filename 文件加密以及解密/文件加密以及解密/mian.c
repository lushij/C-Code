#include"code.h"

int main()
{
	srand((unsigned int)time(NULL));
	//进行加密
	code_file();
	//进行解密
	decode_file();
	return 0;
}