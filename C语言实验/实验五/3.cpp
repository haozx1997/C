#include<string.h>
#include<stdio.h>
int main()
{//���ʵ���ַ����Ŀ������� ʹ��strcpy����
	char t[1000],f[1000];
	printf("please input f:\n");
	gets (f);
	strcpy(t,f);
	printf("output t:\n");
	puts(t);
	return 0;
}

