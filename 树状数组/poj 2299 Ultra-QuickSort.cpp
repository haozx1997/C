#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int a[500050];
int  b[500050];

int Lowbit(int x)
{
	return x & -x;
}

int fn;
int fa[500050];
void update(int t,int val)
{
	for(int i = t;i < fn;i += Lowbit(t) )
	{
		fa[i] += val;
	}
}
int sum(int x)
{
	int ans = 0;
	for(int i = x;i > 0;i -= Lowbit(i))
	{
		ans += fa[i];
	}
	return ans;
}
int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		memset(fa,0,sizeof(fa));
		for(int i = 0;i < n; i++)
		{
			scanf("%d",&a[i]);
			b[i] = a[i];
		 } 
		sort(a,a+n);
		int size = unique(a,a+n) - a;
		for(int i = 0; i < n; i++)
		{
			b[i] = lower_bound(a,a+size,b[i]) - a + 1;
		 }
		long long ans = 0;
		fn = n;
		for(int i = n-1;i >= 0;i--)
		{
			ans += sum(b[i]);
			update(b[i],1);
		}
		printf("%I64d\n",ans);
	}
}

