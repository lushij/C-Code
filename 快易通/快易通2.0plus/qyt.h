#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FileName  "./qyt.txt"

//ֻ������������

//���п��������뷭��
typedef struct qyt {
	char *eng;
	char *zh;
}Qyt,*QYT;


//���ļ��ӿ�
FILE* open_file(char* str);

//��ȡ���ʸ���
int get_line();


//���˵���
void filtration_file(char*buf);

//��ʼ������
void init_file(Qyt**qyt,int n);

//���ҷ���
int search_zh(char *eng,char*zh,int n,Qyt*qyt);