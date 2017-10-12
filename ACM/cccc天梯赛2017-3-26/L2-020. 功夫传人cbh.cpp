#include<cstdio>
struct node{
	int id;
	int b; 
}tmp[100005];
int ii=0;
int par[100005];
int find(int x,int d)
{
	if(x==par[x])
	return d;
	return find(par[x],d+1);
}
int main()
{
	int n,k,b,be;
	double z,r;
	scanf("%d%lf%lf",&n,&z,&r);
	for(int i=0;i<n;i++)
	par[i]= i;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		if(k==0)
		{
			scanf("%d",&be);
			tmp[ii].b = be;
			tmp[ii].id = i;
			ii++;
		}
		else
		{
			for(int j=0;j<k;j++)
			{
				scanf("%d",&b);
				par[b] = i;
			}
		}
	}
	double sum=0.0;
	for(int i=0;i<ii;i++)
	{
		double zz = z;
		int d = find(tmp[i].id,0);
		for(int j=0;j<d;j++)
		{
			zz-=zz*r/100.0;
		}
		sum+=zz*tmp[i].b;
	}
	int ssum = sum;
	printf("%d\n",ssum);
	return 0;
}

