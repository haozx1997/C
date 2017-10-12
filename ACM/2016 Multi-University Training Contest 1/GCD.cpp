#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

long long gcd(long long a,long long b)
{
	return !b?a:gcd(b,a%b);
}
long long ngcd(long long *a, long long n)  
{  
 if (n == 1)  
  return *a;  
  
 return gcd(a[n-1], ngcd(a, n-1));  
}  

int main()
{
	int T;
	scanf("%d",&T);
	for(int TT = 0;TT < T;TT++)
	{
		long long n;
		long long a[100010];
		scanf("%lld",&n);
		for(long long i = 0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			
		}
		
		long long  qn;
		scanf("%lld",&qn);
		for(long long  i = 0;i<qn;i++)
		{
			long long q1,q2;
			scanf("%lld%lld",&q1,&q2);
			q1--;q2--;
			long long an = q2-q1+1;
			long long da = ngcd(a+q1,an);
			printf("%lld\n",da); 
			
		}
	}
}

