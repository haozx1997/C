#include<bits/stdc++.h>
using namespace std;
vector<int> v[100100];
int n;
double z,r;
double all = 0;
/*
2 18 1
1 1
0 100
*/
int dfs(int me,double mg)
{
	mg *= (double)r;
//	printf("me %d\n",me);
	if(v[me][0] == 0)
	{
//		printf("king %d\n",me);
		
		all += ((double)v[me][1]*mg);
		return 0;
	}
	else
	{
	
		for(int i = 1;i <= v[me][0];i++)
		{
//			printf("f %d %d\n",me,v[me][i]);
			dfs(v[me][i],mg);
		}
		return 0;
	}
}


int main()
{
    
	scanf("%d%lf%lf",&n,&z,&r);
	for(int i = 0;i < n;i++)
	{
		v[i].clear();
	}
	r = 0.01*r;
	r = 1-r;
//	printf("		%.2f\n",r);;
	all = 0.0;
	for(int i = 0;i < n;i++)
	{
		int k,d;
		scanf("%d",&k);
		v[i].push_back(k);
		if(k == 0)
		{
			scanf("%d",&d);
			v[i].push_back(d);
		}
		else
		{
			for(int j = 0;j < k;j++)
			{
				scanf("%d",&d);
				v[i].push_back(d);
			}
			
		}
	//	printf("asd\n");
	}
//	printf("asd");
//	for(int i = 0;i < n;i++)
//	{
//		for(int j = 0;j <v[i].size();j++)
//		{
//			printf("%d ",v[i][j]);
//		}
//		printf("\n");
//	}
	for(int i = 1;i <= v[0][0];i++)
	{
		dfs(v[0][i],z);
	}
	
	int ans = (int)all;
	printf("%d\n",ans);
	
}
