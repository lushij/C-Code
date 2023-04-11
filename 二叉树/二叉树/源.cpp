#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int k = 0;

void dfs(char* arr)
{
   
    if (arr[k] == '#')
    {
        k++;
        return;
    }
    char r = arr[k++];
    dfs(arr);
    putchar(r);
    dfs(arr);

}


int main()
{
    char buf[100] = "";
    fgets(buf, sizeof(buf), stdin);
    buf[sizeof(buf) - 1] = '\0';
    dfs(buf);
    return 0;
}