#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
int n;
void see(int *x)
{
	for(int i = 1;i<=n;i++)
	{
		printf("%d ",x[i]);
		
	}
	printf("\n");
}

int main()
{
	
	scanf("%d",&n);
	int a[100100];
	int o[100100];
	int l[100100];
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		l[a[i]] = i;
		o[i] = a[i];	
	}	
	sort(a+1,a+n+1);
	see(o);
	see(a);
	see(l);
	int ans = 0;
	for(int i = n; i > 0;i--)
	{
		int now = a[i];
		if(l[a[i]] == -1)
		{
			continue;
		}
		
		ans++;
		for(int j = l[a[i]]+1;j<=n;j++)
		{
			if(l[o[j]] == -1)
			{
				continue;
			}
			if(o[j] > now)
			{
				continue;
			}
			if(o[j] < now)
			{
				l[o[j]] = -1;
			}
		}
		
	}
	see(l);
	printf("%d\n",ans);
}
