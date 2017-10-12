#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;



long long ago(long long num1,char *oxa,long long num2)
{
	switch(oxa[0])
	{
		case 'O': 
		
			return num1|num2;
			break;
		case 'X': 
			return num1^num2;
			break;
		case 'A': 
			if(num2 == 0)
			return (long long)0;
			return num1&num2;
			break;
			
	}
}

int main()
{
	long long n;
	long long t[100010];
	char s[100100][5];
	while(~scanf("%lld",&n))
	{
		long long m;
		scanf("%lld",&m);
		for(int i = 0;i < n;i++)
		{
			scanf("%s%lld",s[i],&t[i]);
		}
		long long ans = 0;
		long long max = 0;
		long long ii ;
		
		for(long long i = 0;i <= m;i++)
		{
			ii = i;
			for(long long j = 0;j < n ;j++)
			{
				ii = ago(ii,s[j],t[j]);
			}
			
			
			ans = ii;
			
			if(ans>max)
			 {
			 	max = ans;
			 }
		}
		printf("%lld\n",max);
		
	}
	
	
	return 0;
	
}
