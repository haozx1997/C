#include<stdio.h>

int main()
{
	char name[20];
	int i;
	for(i=0;i<20;i++)       //name[1-20]±íÊ¾Ãû×Ö 
	  scanf("%c",&name[i]);
	printf("%c",name[3]);
}

