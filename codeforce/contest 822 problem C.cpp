
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
		return x.cost<y.cost;
	}
	return x.last < y.last;
}



map<long long ,long long> where;


int main()
{
	while(~scanf("%I64d%I64d",&n,&x))
	{
	
		for(long long i = 0;i < n;i++)
		{
			long long a,b,c;
			scanf("%I64d%I64d%I64d",&day[i].st,&b,&day[i].cost);
			day[i].last = b - day[i].st;
			hl[i] = day[i];
		}
		sort(hl,hl+n,cmp1);
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
		}
		long long ans = 100000000000000000;
		for(long long i = 0;i < n;i++)
		{
			long long v1 = day[i].st;
			long long v2s = v1+day[i].last;
			long long v2ls = x - 2 - day[i].last;
			node eg;
			eg.last = v2ls;
		//	long long findst = lower_bound(hl,hl+n,eg) - hl;
			if(where.count(v2ls) == 0 )
			{
				continue;
			}
			long long findst = where[v2ls];
	//		printf("%d %d %d\n",findst,v2ls,v2s);
			for(long long j = findst;j < n;j++)
			{
		//		printf("j = %d\n",j);
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
			
		}
		if(ans == 100000000000000000)
		{
			printf("-1\n");
			continue;
		}
		printf("%I64d\n",ans);
		
	}
	



 return 0;
}


