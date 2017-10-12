#include<bits/stdc++.h>

using namespace std;

long long n,m;
long long Lowbit(long long  x) //2^k
{
    return x & (-x);
}
long long fa[300100];
long long fn;
struct fenwick
{
	//数组大小          //一定要赋值 
	void update(long long t, long long val)//位置，值 
	{
		for(long long i = t;i <= fn ;i += Lowbit(i))
		{
			fa[i] += val;
		}
	}
	long long getsum(int x)
	{
		if(x<=0)
		{
			return (long long)0;
		}
		long long ans=(long long )0;
	    for(long long i=x; i>(long long) 0; i-=Lowbit(i))
	        ans += fa[i];
	    return ans;
	}
	 
}fen;


long long a[300100];
long long b[300100];

int main()
{
	while(~scanf("%I64d%I64d",&n,&m))
	{
		fn = n;
		memset(fa,0,sizeof(fa));
		for(long long i = (long long)1;i <= n;i++)	
		{
			scanf("%I64d",&a[i]);
		}
		
		while(m--)
		{
			long long l,r;
			scanf("%I64d%I64d",&l,&r);
			
			fen.update(l,1);
			fen.update(r+1,-1);
			
			
		}
		sort(a+1,a+n+1);
		for(int i =1;i <= n;i++)
		{
			b[i] = fen.getsum(i);
v 		}
		sort(b+1,b+n+1);
		long long ans = (long long )0;
		for(int i =1;i <= n;i++)
		{
			ans += (b[i]*a[i]);
		}
		printf("%I64d\n",ans);
		
	}	




 return 0;
}


