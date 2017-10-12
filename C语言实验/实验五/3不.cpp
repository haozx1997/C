#include<string.h>
#include<stdio.h>
int main()
{//编程实现字符串的拷贝功能 不使用strcpy函数
	char t[1000],f[1000];
	int i;
	printf("please input f:\n");
	gets (f);
	for(i=0;i<strlen(f);i++)
	 t[i]=f[i];
	printf("please input t:\n");
	puts(t);
	return 0;
}

