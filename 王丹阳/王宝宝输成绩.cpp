#include<stdio.h>
int main()
{
	printf("请王宝宝输入成绩：\n");
	int s;
	scanf("%d",&s);
	switch(s/10)
	{
		case 9 : printf("A等\n");
		case 8 : printf("B等\n");
		case 7 : printf("C等\n");
		case 6 : printf("D等\n");
		default  : printf("E等\n");
		
	}
 } 
