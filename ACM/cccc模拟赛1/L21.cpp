#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
int z[10000];
int isz(int a)
{
	if(a==1||a==0)
	 return 0;
	for(int i = 2;i*i<=a;i++)
	{
		if(!(a%i))
		 return 0;
	}
	return 1;
}


int main()
{
	int a,b,ii= 0;
	for(a=2;a<10000;a++)
	  {
		for(b=2;b<a;b++)
		  {
		  	if((a%b)==0) break;
		  };
		if(b==a)
		  {
		  	z[ii]=a;
 	        
		  	ii++;
		  } ;
	  }  
	int n ;
	int zz = 0; 
	while(~scanf("%d",&n))
	{
		zz = 0; 
		if(isz(n))
		{
			printf("%d\n",n);
			continue;
		}
		int f = 0;
		while(1)
		{
			
			if(!(n%z[zz]))
			{if(f)
			{
				printf("*");
			}
				f = 1;
				printf("%d",z[zz]);
				
				if(isz(n/z[zz]))
				{
					break;
				}
				n /=z[zz];
			}
			else 
			{
				zz++;
			}
		}
		printf("*%d\n",n/z[zz]);
	}
}
