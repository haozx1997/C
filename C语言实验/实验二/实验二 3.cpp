#include<stdio.h>
main()
{
	int m;      /*��switch����д����ʵ�������·ݣ���ʾ���ڡ�*/
	char s[20];
	scanf("%d",&m);
	switch((m-1)/3)
	{
		case 0:printf("��");break;
		case 1:printf("��");break;
		case 2:printf("��");break;
		case 3:printf("��");break;
	}
	
}
