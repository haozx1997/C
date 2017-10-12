#include<stdio.h>
main()
{
	int m;      /*用switch语句编写程序，实现输入月份，显示季节。*/
	char s[20];
	scanf("%d",&m);
	switch((m-1)/3)
	{
		case 0:printf("春");break;
		case 1:printf("夏");break;
		case 2:printf("秋");break;
		case 3:printf("冬");break;
	}
	
}
