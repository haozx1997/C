#include<stdio.h>
#define ll long long
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct we
{
	ll t;
	ll w;
	ll c;
}tm[300300];


int cmp(we a,we b)
{
	return a.t>b.t;
}
int cmp1(we a,we b)
{
	return a.c<b.c;
}
	int n;
void see()
{
	for(int i = 0; i < n;i++)
	{
		printf("%I64d  %I64d  %I64d\n", tm[i].t, tm[i].w, tm[i].c);
	}
}
int main()
{

	while(~scanf("%d",&n))
	{
		for(int i = 0 ;i < n; i++)
		{
			scanf("%I64d%I64d",&tm[i].t,&tm[i].w);
			tm[i].c = tm[i].w-tm[i].t+1;
		}
		sort(tm+1,tm+n,cmp);
		see()
		ll tt = tm[0].t;
		ll ww = tm[0].w;
		int rank = 0; 
		for(int i = 0 ;i < n; i++)
		{	
			rank = i;
			if(tm[i].t<tt)
			{
				break;
			}
		}
		
		if(rank == 0)
		{
			printf("1\n");
			continue;
		}
		ll have = min(tt - tm[rank].t,ww - tt);
		sort(tm+1,tm+rank,cmp1);
		see()
		int go = 0;
		for(int i = 1;i<rank;i++)
		{
			have -= tm[i].c;
			if(have < 0)
			{
				go = i-1;
				break;
			}
		}
		printf("%d %d\n",rank,go);
		printf("%d\n",rank-go);
				

	}
 } 
