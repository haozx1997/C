#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int p,qq;
struct node{
	int x;
	int step;
}tmp;
int vis[9999999];
void bfs()
{
	if(p>=qq){
		printf("%d\n",p-qq);
		return;
	}
	queue<node>q;
	memset(vis,0,sizeof(vis));
	tmp.x = p;
	vis[p] = 1;
	tmp.step = 1;
	q.push(tmp);
	while(!q.empty())
	{
		node fr = q.front();
		q.pop();
		for(int i=0;i<3;i++)
		{
			int nx = fr.x;
			if(i==0)
				nx++;
			if(i==1)
				nx--;
			if(i==2)
			nx*=2;
			if(nx==qq)
			{
				printf("%d\n",fr.step);
				return ;
			}
			if(!vis[nx]&&nx<=100000&&nx>=0)
			{
				vis[nx] = 1;
				node nfr;
				nfr.step = fr.step+1;
				nfr.x = nx;
				q.push(nfr);
			}
		}
	}
}
int main()
{
	while(~scanf("%d%d",&p,&qq))
	{
		;
	bfs();
	}
	return 0;
}

