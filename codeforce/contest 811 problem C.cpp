#include<bits/stdc++.h>

using namespace std;

long long a[100100];
int n;

long long b[100100];
int bn;


int main()
{
	while(~scanf("%d",&n))
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%I64d",&a[i]);	
		}	
		sort(a,a+n);
		bn = 1;
		long long pre = a[0];
		b[0] = a[0];
		for(int i = 1;i < n;i++)
		{
			if(a[i] != pre)
			{
				b[bn++] = a[i];
				pre = a[i];
			}
		}
		
		for(int i = 0;i < bn;i++)
		{
			printf("%I64d ",b[i]);	
		}
		printf(" \n");
		
		
		
	}	




 return 0;
}


