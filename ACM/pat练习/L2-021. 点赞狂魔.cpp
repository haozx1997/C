#include<bits/stdc++.h>

using namespace std;

struct node
{
	char name[200];
	double a;
	int b;
}pp[2000];


int cmp(node aa,node bb)
{
	if(aa.b == bb.b)
	{
		return aa.a<bb.a;
	}
	return aa.b>bb.b;
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(pp,0,sizeof(pp));
		for(int i = 0;i < n;i++)
		{
			scanf("%s",&pp[i].name);
			int nn;
			
			
			
			scanf("%d",&nn);
			
			set<int>S;
			S.clear();
			for(int ii = 0;ii < nn;ii++)
			{
				int z;
				scanf("%d",&z);
				S.insert(z);
			}
			
			pp[i].b = S.size();
			//printf("%d\n",pp[i].b);
			pp[i].a = (double)nn/pp[i].b;
		}
		
		sort(pp,pp+n,cmp);
//		for(int i = 0;i < n;i++)
//		{
//			printf("%s %d %.2f\n",pp[i].name,pp[i].b,pp[i].a);
//		}
//		
		if(n>=3)
		{
			printf("%s %s %s\n",pp[0].name,pp[1].name,pp[2].name);
			
		}
		if(n == 2)
		{
			printf("%s %s -\n",pp[0].name,pp[1].name);
			
		}
		if(n == 1)
		{
			printf("%s - -\n",pp[0].name);
			
		}
		
		
	}





 return 0;
}


