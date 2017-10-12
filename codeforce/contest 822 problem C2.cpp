
#include<bits/stdc++.h>

using namespace std;
long long n,x;
struct node
{
	long long st;
	long long last;
	long long cost;
	bool operator < (const node& qwe) const
	{
		return qwe.last>last;
	}
}day[220000],hl[220000];

bool cmp(node x,node y)
{
	return x.st<y.st;
}
bool cmp1(node x,node y)
{
	if(x.last == y.last)
	{
		if(x.cost==y.cost)
		{
			return x.st>y.st;
		}
		return x.cost<y.cost;
	}
	return x.last < y.last;
}



long long where[220000];


long long bn,en;
int main()
{
	freopen("1.out","r",stdin);
	while(~scanf("%I64d%I64d",&n,&x))
	{
		memset(where,-1,sizeof(where));
		for(long long i = 0;i < n;i++)
		{
			long long a,b,c;
			scanf("%I64d%I64d%I64d",&day[i].st,&b,&day[i].cost);
			day[i].last = b - day[i].st;
			hl[i] = day[i];
		}
		printf("wtf\n");
		sort(hl,hl+n,cmp1);
		printf("wtf\n");
		sort(day,day+n,cmp);
		
		
//		puts("");
//		for(long long i = 0;i < n;i++)
//		{
//			printf("%d %d %d \n",hl[i].st,hl[i].last,hl[i].cost);
//		}
//		
//		for(long long i = 0;i < n;i++)
//		{
//				printf("	%d %d %d \n",day[i].st,day[i].last,day[i].cost);
//		}
		for(long long i = n-1;i >= 0;i--)
		{
			where[hl[i].last] = i;
		}printf("wtf\n");
		
		long long ans = 100000000000000000;
		for(long long i = 0;i < n;i++)
		{
			long long v1 = day[i].st;
			long long v2s = v1+day[i].last;
			long long v2ls = x - 2 - day[i].last;
			
			if(v2ls<0)
			{
				continue;
			}
			long long findst = where[v2ls];
			if(findst == -1)
			{
				continue; 
			}
	//		printf("%d %d %d\n",findst,v2ls,v2s);
			for(long long j = findst;j < n;j++)
			{
				printf("%lld %lld %lld\n",day[i].st,hl[j].st,day[i].last+hl[j].last+2 );
				if(hl[j].last>v2ls )
				{
					break;
				}
				if(hl[j].st>v2s)
				{
					ans = min(ans,(day[i].cost+hl[j].cost));
					break;
				}
		//		printf("%d %d\n",day[i].st,hl[j].st);
				
				
			}
			
		}return 0;
		if(ans == 100000000000000000)
		{
			printf("-1\n");
			continue;
		}
		printf("%I64d\n",ans);
		
	}
	



 return 0;
}


