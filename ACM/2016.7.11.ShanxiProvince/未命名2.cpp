#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>


int main()
{
	int s;
	scanf("%d",&s);
	if(s == 1)
	 {
	 	printf("0\n");
	 	return 0;
	 }
	for(int i = 1;;i++)
	{
		if(s%2)
		{
			s = (3*s+1)/2;
		}
		else
		{
			s /=2;
		}
		if(s == 1)
		{
			printf("%d\n",i);
			return 0; 
		}
	}
}
#include<algorithm>
