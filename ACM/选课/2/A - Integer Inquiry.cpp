#include<stdio.h>
#include<string.h>
#include<iostream>
#include <algorithm>
using namespace std;

struct bign
{
	int len,s[105];
	bign operator + (const bign& b) const
	{
		bign c;
		c.len=0;
		printf("123");
		for(int i=0,g=0;g||i<max(len,b.len);i++)
		 {
		 	int x=g;
		 	if(i<len) x+=s[i];
		 	if(i<b.len) x+=b.s[i];
		 	c.s[c.len++]=x%10;
		 	g=x/10;
		 	printf("132");
		 	
		 }
		 printf("1111");
		return c;
	}
}x,y,z;

int main()
{
	char num[105],fin[105];
	memset(x.s,0,sizeof(x.s));
	while(scanf("%s",num),num[0]!='0')
	{
		for(int i=0;i<strlen(num);i++)
		 y.s[i]=num[i]-'0';
		for(int i=0;i<strlen(num);i++)
		 printf("%d",y.s[i]) ;
		printf("\n") ;
		 z=x + y;
		 for(int i=0;i<strlen(num);i++)
		 printf("%d",z.s[i]) ;
		 printf("\n") ;
	}
	    for(int i=0;i<strlen(num);i++)
	        fin[i]=x.s[i]+'0';
	printf("%s",fin);
	
	
	
 } 
