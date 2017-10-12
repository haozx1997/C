#include<bits/stdc++.h>

using namespace std;
vector<int> v;
vector<int> :: iterator it;
int op,k,vv[10][600],vi;
int in(int op,int k)
{
	int val = k+op*1000;
	if(vv[op][k] == -1)
	{
		v.push_back(val);
		return 0;
	}
	for(it = v.begin(); it!=v.end();it++)
	{
		if(*it == val)
		{//printf("vla %d\n",val);
			v.erase(it);
			break;
		}
	}
	v.push_back(val);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		int m[600][600];
		
		v.clear();
		memset(m,0,sizeof(m));
		memset(vv,-1,sizeof(vv));
		
		for(int i = 0;i < q;i++)
		{
			scanf("%d%d%d",&op,&k,&vi);
			k--;
			in(op,k);
			vv[op][k] = vi;
//			for(it = v.begin(); it!=v.end();it++)
//			{
//				printf("%d ",*it);
//			}
//			printf("\n");
		}
		
		for(it = v.begin(); it!=v.end();it++)
		{
			//printf("%d %d %d\n",(*it)%10,(*it)/1000,vv[(*it)%10][(*it)/1000]);
			int op = ((*it)/1000)%10,k = (*it)%500,vi = vv[op][(*it)%500];
			if(op == 1)
			{
				for(int i = 0;i < n;i++)
				{
					m[k][i] = vi;
				}
			}
			else
			{
				for(int i = 0;i < n;i++)
				{
					m[i][k] = vi;
				}
			}
		}
		
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n-1;j++)
			{
				printf("%d ",m[i][j]);
			}
			printf("%d\n",m[i][n-1]);
		}
		
	}




 return 0;
}


