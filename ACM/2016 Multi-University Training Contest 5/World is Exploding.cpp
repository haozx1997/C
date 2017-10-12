#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

///////////////////记得按 for(int i = 1;i <= 10;i++)
///////////////////不要按 for(int i = 0;i < 10;i++)
///////////////////    ALL 

int Lowbit(int x) //2^k
{
    return x & (-x);
}

struct fenwick
{
	int fa[100100];
	int fn;//数组大小          //一定要赋值 
	void update(int t, int val)//位置，值 
	{
		for(int i = t;i <= fn ;i += Lowbit(i))
		{
			fa[i] += val;
		}
	}
	int getsum(int x)
	{
		int ans=0;
	    for(int i=x; i>0; i-=Lowbit(i))
	        ans += fa[i];
	    return ans;
	}
	 
}fen;



int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int a[50005];
		int s[50005];
		__int64 lb[50005],ls[50005],rb[50005],rs[50005];
		__int64 ans,sum,sum_;
		ans = sum = sum_ = 0;
		for(int i = 0;i < n; i++)
		{
			scanf("%d",&a[i]);
			s[i] = a[i];
		}
		int Max = 0;
		sort(a,a+n);
		int size = unique(a,a+n) - a;
		for(int i = 0;i < n; i++)
		{
			s[i] = lower_bound(a,a+size,s[i]) - a + 1;
			Max = max(Max,s[i]);
		 } 
		fen.fn = n;
		memset(fen.fa,0,sizeof(fen.fa));
		for(int i = 0;i < n;i++)
		{
			ls[i] = fen.getsum(s[i]-1);
			lb[i] = fen.getsum(Max) - fen.getsum(s[i]);
		//	printf("%d %d %d\n",i,ls[i],lb[i]);
			fen.update(s[i],1);
			sum += ls[i];
		 } 
		memset(fen.fa,0,sizeof(fen.fa));
		for(int i = n-1;i >= 0;i--)
		{
			rs[i] = fen.getsum(s[i]-1);
			rb[i] = fen.getsum(Max) - fen.getsum(s[i]);
		//	printf("%d %d %d\n",i,rs[i],rb[i]);
			fen.update(s[i],1);
			sum_ += rs[i];
		 } 
		ans = sum*sum_;
		
		for(int i = 0;i < n; i++)
		{
			ans -= ls[i]*rs[i]+rs[i]*rb[i]+lb[i]*rb[i]+lb[i]*ls[i];
			//ans -= ls[i]*rs[i]+ls[i]*rb[i]+lb[i]*rs[i]+lb[i]*rb[i];
		 } 
		printf("%I64d\n",ans); 
		 
	}
	return 0;
}

