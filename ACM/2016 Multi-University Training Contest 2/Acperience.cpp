#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

long long gcd(long long  a,long long  b)
 {
 	if(a < b)
    {
        long long  t = a;
        a = b;
        b = t;
    }
 	return !b ? a : gcd(b,a%b);
 }
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long w;
		long long sum = 0;
		long long sum2 = 0;
		long long n;
		scanf("%I64d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%I64d",&w);
			if(w<0)
			 w = 0-w;
			 sum += w;
			 sum2 += w*w;
		}
		long long num1 = n*sum2 - sum*sum;
		long long GCD = gcd(num1,n);
		printf("%I64d/%I64d\n",num1/GCD,n/GCD);
		
	}
	return 0;
 } 
