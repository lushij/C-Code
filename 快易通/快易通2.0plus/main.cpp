#include"qyt.h"


int main()
{
	Qyt* qyt = NULL;
	//获取单词个数
	int n=get_line();
	//初始化单词
	init_file(&qyt,n);
	/*
	* 单元检测
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", qyt[i].eng);
		printf("%s\n", qyt[i].zh);
	}*/
	int i = 0;
	char eng[256] = "";
	char zh[256] = "";
	int ret = 0;
	while (1)
	{
		printf("请输入你要查找的单词：");
		fgets(eng, sizeof(eng), stdin);
		eng[strlen(eng) - 1] = 0;//把eng最后的一个字符给赋值为0，fgets的弊端
		ret=search_zh(eng, zh, n, qyt);
		if (ret == 1)
		{
			printf("该单词翻译为:%s\n", zh);
		}
		else
		{
			printf("not found\n");
		}
	}

	//单元检测
	//char eng[256] = "";
	//char zh[256] = "";
	//printf("请输入你要查找的单词：");
	//fgets(eng, sizeof(eng), stdin);
	//eng[strlen(eng) - 1] = 0;//把eng最后的一个字符给赋值为0，fgets的弊端
	//for (int i = 0; i < n; i++)
	//{
	//	if (strcmp(eng, qyt[i].eng) == 0)
	//	{
	//		printf("翻译为：%s\n", qyt[i].zh);
	//		break;
	//	}
	//}


	return 0;
}