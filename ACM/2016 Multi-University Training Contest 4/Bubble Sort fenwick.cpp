#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;


int Lowbit(int x) //2^k
{
    return x & (-x);
}
struct fenwick
{
	int fa[100100];
	int fn;//数组大小
	void update(int t, int val)
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
int ans[100100];
int a[100100];

int main()
{
	int T;
	scanf("%d",&T);
	for(int TT = 0;TT < T;TT++)
	{	
		
		memset(fen.fa,0,sizeof(fen.fa));
		scanf("%d",&fen.fn);
		for(int i = 1;i <= fen.fn;i++)
		{
			scanf("%d",&a[i]);
			fen.update(a[i],1);
			ans[a[i]] = ((i-fen.getsum(a[i])
			+a[i]) - min(i,a[i]));
//			printf("%d %d %d %d\n",fen.fa[i],(i-fen.getsum(fen.fa[i])
//			+fen.fa[i]),min(i,fen.fa[i]),ans[fen.fa[i]]);
//			printf("%d %d %d %d\n\n",fen.fa[i],i,fen.getsum(fen.fa[i]),
//			fen.fa[i]);
//			for(int i = 1;i<=10;i++)
//			{
//				printf("!!%d %d %d\n",i,fen.fa[i],fen.getsum(i));
//			}
		}printf("Case #%d: ",TT+1);
		for(int i = 1;i <= fen.fn;i++)
		{
			
			printf("%d%c",ans[i]," \n"[i==fen.fn]);
		}
	}
	
}
