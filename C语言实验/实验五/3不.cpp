#include<string.h>
#include<stdio.h>
int main()
{//���ʵ���ַ����Ŀ������� ��ʹ��strcpy����
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

