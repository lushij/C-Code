#include"qyt.h"


int main()
{
	Qyt* qyt = NULL;
	//��ȡ���ʸ���
	int n=get_line();
	//��ʼ������
	init_file(&qyt,n);
	/*
	* ��Ԫ���
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
		printf("��������Ҫ���ҵĵ��ʣ�");
		fgets(eng, sizeof(eng), stdin);
		eng[strlen(eng) - 1] = 0;//��eng����һ���ַ�����ֵΪ0��fgets�ı׶�
		ret=search_zh(eng, zh, n, qyt);
		if (ret == 1)
		{
			printf("�õ��ʷ���Ϊ:%s\n", zh);
		}
		else
		{
			printf("not found\n");
		}
	}

	//��Ԫ���
	//char eng[256] = "";
	//char zh[256] = "";
	//printf("��������Ҫ���ҵĵ��ʣ�");
	//fgets(eng, sizeof(eng), stdin);
	//eng[strlen(eng) - 1] = 0;//��eng����һ���ַ�����ֵΪ0��fgets�ı׶�
	//for (int i = 0; i < n; i++)
	//{
	//	if (strcmp(eng, qyt[i].eng) == 0)
	//	{
	//		printf("����Ϊ��%s\n", qyt[i].zh);
	//		break;
	//	}
	//}


	return 0;
}