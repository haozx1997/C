#include<bits/stdc++.h>

using namespace std;

struct node
{
	vector<int> V;
	int deep;
	int far;
	int get;
	int wai;//Who am I?
}p[1000100];

vector<int>::iterator it;
int n,m;
int vis[1000100];

int bfs1()
{
	memset(vis,0,sizeof(vis));
	queue<node>Q;

	node now,next;
	p[1].deep = 0;
	now = p[1];
	vis[1] = 1;
	Q.push(now);
	
//	printf("Q   %d\n",!Q.empty());
	while(!Q.empty())
	{
		now = Q.front();
		
		Q.pop();
		for(it = now.V.begin();it!=now.V.end();it++)
		{
			next = p[*it];
			if(vis[next.wai] == 0)
			{
				p[next.wai].deep = now.deep+1;
				vis[next.wai] = 1;
				Q.push(p[next.wai]);
			}
		}
	}
}
int ans;
int bfs2()
{
	ans = p[m].deep;
	memset(vis,0,sizeof(vis));
	queue<node>Q2;

	node now2,next2;
	p[m].far = 0;
	p[m].get = 1;
	now2 = p[m];
	vis[m] = 1;
	Q2.push(now2);
	while(!Q2.empty())
	{
		now2 = Q2.front();
		Q2.pop();
		for(it = now2.V.begin();it!=now2.V.end();it++)
		{
			next2 = p[*it];
//			printf("%d %d\n",now2.wai,next2.wai);
			p[next2.wai].far = now2.far+1;
			if(vis[next2.wai] == 0&&(p[next2.wai].far<p[next2.wai].deep))
			{
				
				ans = max(ans,next2.deep );
				vis[next2.wai] = 1;
				Q2.push(p[next2.wai]);
			}
		}
	}
}

int main()
{
	
	while(~scanf("%d%d",&n,&m))
	{
		memset(p,0,sizeof(p));
		for(int i = 0;i<n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			p[a].V.push_back(b);
			p[a].wai = a;
			p[b].V.push_back(a);
			p[b].wai = b;
			
		}
//		puts("wtf");
		
		bfs1();
//		puts("wtf");
		bfs2();
//		puts("wtf");
//		for(int i = 1; i <= n;i++)
//		{
//			printf("%d %d %d\n",p[i].wai,p[i].deep,p[i].far);
//		}
		printf("%d\n",ans*2);
		
		
	}




 return 0;
}
/*
4 3
1 2
2 3
2 4
 
5 2
1 2
2 3
3 4
2 5

*/

