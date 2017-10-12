#include<algorithm>
#include<cstdio>
#include<cstring>
#define MAX 110000
using namespace std;
int n;
int ans;
struct Tree
{
	int l,r;
	int minn,add;
};
Tree tree[MAX*3];

void pushup(int x)
{
	int tmp=2*x;
	tree[x].minn=min(tree[tmp].minn,tree[tmp+1].minn);
}


void pushdown(int x)
{
	int tmp=2*x;
	tree[tmp].add+=tree[x].add;
	tree[tmp+1].add+=tree[x].add;
	tree[tmp].minn+=tree[x].add;
	tree[tmp+1].minn+=tree[x].add;
	tree[x].add=0;
}

void build(int l,int r,int x)
{
	tree[x].l=l;
	tree[x].r=r;
	tree[x].add=0;
	if(l==r)
	{
		int asd;
		scanf("%d",&asd);
		tree[x].minn=tree[x].add=asd;
		return ;
	}
	int tmp=x<<1;
	int mid=(l+r)>>1;
	build(l,mid,tmp);
	build(mid+1,r,tmp+1);
	pushup(x);	 //??????????sum??,?????pushup
}


void update(int l,int r,int c,int x)
{
	if(r<tree[x].l||l>tree[x].r)
		return ;
	if(l<=tree[x].l&&r>=tree[x].r)
	{
		tree[x].add+=c;
		tree[x].minn+=c;
		return ;
	}
	if(tree[x].add)
		pushdown(x);
	int tmp=x<<1;
	update(l,r,c,tmp);	//  !!!
	update(l,r,c,tmp+1);
	pushup(x);
}


void query(int l,int r,int x)
{
	if(r<tree[x].l||l>tree[x].r)		 //????????????
		return ;
	if(l<=tree[x].l&&r>=tree[x].r)	  //???????????
	{
		ans = min(ans,tree[x].minn);
		return ;
	}
	if(tree[x].add)
		pushdown(x);
	int tmp=x<<1;
	int mid=(tree[x].l+tree[x].r)>>1;
	if(r<=mid)
		query(l,r,tmp);
	else if(l>mid)
		query(l,r,tmp+1);
	else
	{
		query(l,mid,tmp);
		query(mid+1,r,tmp+1);
	}
}


int  main()
{
	while(scanf("%d",&n))
	{
		if(n==0)
		break;
		build(1,n,1);
	//	for(int i=0;i<n;i++)
		{
				int l,r;
				scanf("%d%d",&l,&r);
				update(l,r,10,1);
		}
		for(int i=1;i<=n;i++)
		{
			ans = INT_MAX;
			query(i,i,1);
			if(i!=1)
			printf(" ");
			printf("%d",ans);
		}
		printf("\n");
	}
	return 0;
}
/*
10
1
2
3
4
5
6
7
8
9
10
4 6

*/
