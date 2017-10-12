#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

int gcd(int a,int b)
 {
 	return !b ? a : gcd(b,a%b);
 }
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		int a[200];
		memset(a,-1,sizeof(a));
		scanf("%d%d",&n,&m);
		for(int i = 0;i < m;i++)
		{
			int ii,ia;
			scanf("%d%d",&ii,&ia);
			a[ii] = ia;
		}
		for(int i = 1;i < 3;i++)//a1a2¸³Öµ 
		{
			if(a[i] == -1)
			{
				if(a[i-1] == -1)
				 {
				 	a[i] = 100;
				 }
				 else
				 {
				 	a[i] = a[i-1];
				 }
			}
		}

		for(int i = n;i>2;i--)
		{
			if(a[i] == -1)
			{
				if(a[i+1] == -1)
				{
					a[i] = 0;
				}
				else
				{
					a[i] = a[i+1];
				}
			}
		}
		int sum1 = a[1] + a[2];
		int sum2 = 0;
		for(int i = 1;i <= n;i++)
		{
			sum2 += a[i];
		}
		int GCD = gcd(sum1,sum2);
		printf("%d/%d\n",sum1/GCD,sum2/GCD);
		
		
	}
}
