#include<bits/stdc++.h>

using namespace std;

struct node
{
	int ii;
	int v;
	int now;
	bool operator<(const node& T)const
	{
		return v < T.v;
	}
}a[200];


int cmp(node a,node b)
{
	return a.ii<b.ii;
}
/*
6 12
2 2 2 4 4 4
*/

int main()
{	
	int n,w;
	while(~scanf("%d%d",&n,&w))
	{
		memset(a,0,sizeof(a));
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i].v);
			a[i].ii = i;
			w -= ceil((double)a[i].v/2);
			a[i].now = ceil((double)a[i].v/2);
		}
		if(w < 0)
		{
			printf("-1\n");
			continue;
		}
		sort(a,a+n);
		

		
		for(int i = n-1;i >=0 ;i--)
		{
			if(w>=(a[i].v/2))
			{
				w -= (a[i].v/2);
				a[i].now = a[i].v;
			}
			else
			{
				a[i].now += w;
				break;
			}
			
		}
		
		sort(a,a+n,cmp);
		printf("%d",a[0].now);
		for(int i = 1;i < n;i++)
		{
			printf(" %d",a[i].now);
		}
		printf("\n");
		
	}





 return 0;
}


