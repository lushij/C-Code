#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FileName  "./qyt.txt"

//只声明，不定义

//进行拷贝单词与翻译
typedef struct qyt {
	char *eng;
	char *zh;
}Qyt,*QYT;


//打开文件接口
FILE* open_file(char* str);

//获取单词个数
int get_line();


//过滤单词
void filtration_file(char*buf);

//初始化单词
void init_file(Qyt**qyt,int n);

//查找翻译
int search_zh(char *eng,char*zh,int n,Qyt*qyt);