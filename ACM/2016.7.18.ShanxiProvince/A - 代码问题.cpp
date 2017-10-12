#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

int main()
{
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		if(a*b*c >= 100000)
		 printf("1\n");
		else 
		 printf("0\n"); 
	}
}
