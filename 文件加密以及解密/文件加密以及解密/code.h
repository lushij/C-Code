#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>


//打开文件接口创建
FILE* open_file(char*dist ,char* str);

//加密文件
void code_file();

//解密文件
void decode_file();