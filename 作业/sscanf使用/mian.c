#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{

    
    //sscanf �������
    //sscanf(buf, "��ʽ", ����);//��buf�����ݸ�ʽ�����������
   
    //%d    0-9���ַ�
    int  year = 0;
    int  month = 0;
    int day = 0;
    char  buf[1024] = "beijing:2018:t:10:20";
    //scanf("%d:%d:%d",&year,&month,&day);//�Ӽ��̰�����Ӧ�ĸ�ʽ��ȡ����
    sscanf(buf, "beijing:%d:t:%d:%d", &year, &month, &day);//��buf�а�����Ӧ�ĸ�ʽ��ȡ����
	return 0;
}