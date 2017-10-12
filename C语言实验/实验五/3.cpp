#include<string.h>
#include<stdio.h>
int main()
{//编程实现字符串的拷贝功能 使用strcpy函数
	char t[1000],f[1000];
	printf("please input f:\n");
	gets (f);
	strcpy(t,f);
	printf("output t:\n");
	puts(t);
	return 0;
}

