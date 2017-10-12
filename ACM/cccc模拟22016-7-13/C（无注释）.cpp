#include<string.h>
#include<stdio.h>
#include<queue>
using namespace std;

struct no
{
	int x,y;
	int step;
};

int dir[4][2] = {0,1,0,-1,1,0,-1,0};
char m[70][70];
int vis[70][70];
int lx,ly;
int qx,qy;
int tr[30][5];
int istr[30];
int xmax,ymax;
int check(int xx,int yy)
{
	if(vis[xx][yy] == 1||m[xx][yy] == '#'||xx<0||yy<0||xx>=xmax||yy>=ymax)
	 return 0;
	return 1;
}

int bfs()
{
	queue<no> q;
	if(!q.empty())
	 q.pop();
	no a,next;
	a.x = lx;
	a.y = ly;
	vis[lx][ly] = 1;
	a.step = 0;
	m[lx][ly] = '#';
	q.push(a);
	while(!q.empty())
	{
		a = q.front();
		q.pop();
		
		

		for(int i = 0;i < 4;i++)
		{
			next = a;
			next.x = a.x+dir[i][0];
			next.y = a.y+dir[i][1];
			if(check(next.x,next.y)) 
		 	  {
		 	  	next.step++; 
		 	  	if(m[next.x][next.y]>='a'&&m[next.x][next.y]<='z')
		 	  	{
		 	  		int aa = (int)m[next.x][next.y] - 'a';
		 	  		if(next.x == tr[aa][0]&&next.y == tr[aa][1])
		 	  		{
		 	  			vis[next.x][next.y] = 1;
		 	  			next.x = tr[aa][2];
						next.y = tr[aa][3];
					   }
					 else
					 {
					 	vis[next.x][next.y] = 1;
		 	  			next.x = tr[aa][0];
						next.y = tr[aa][1];
					   }
					if(m[next.x][next.y] == 'Q')
		{
			return next.step;
		}    
		 	  		q.push(next);
				   }
				 else
				 {
				 	vis[next.x][next.y]= 1;
		 	  		if(m[next.x][next.y] == 'Q')
		{
			return next.step;
		}
		 	  		q.push(next);
				 }  
		 	  	
			   }
		}
		
	}
	return -1;
}





int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		memset(m,0,sizeof(m));
		memset(istr,0,sizeof(istr));
		memset(vis,0,sizeof(vis));
		memset(tr,0,sizeof(tr));
		
		
		scanf("%d%d",&xmax,&ymax);
		for(int i = 0;i < xmax;i++)
		{
			scanf("%s",m[i]);
			for(int j = 0;j < ymax;j++)
			{
				if(m[i][j] == 'L')
				{
					lx = i;
					ly = j;
				}
				if(m[i][j] == 'Q')
				{
					qx = i;
					qy = j;
				}
				if(m[i][j]>='a'&&m[i][j]<='z')
				{
					if(istr[(int)m[i][j]-'a' ]== 0)
					{
						tr[(int)m[i][j]-'a'][0] = i;
						tr[(int)m[i][j]-'a'][1] = j;
						istr[(int)m[i][j]-'a' ] = 1;
					}
					else
					{
						tr[(int)m[i][j]-'a'][2] = i;
						tr[(int)m[i][j]-'a'][3] = j;
					}
				}
				
			}
				
			
		} 
	
		printf("%d\n",bfs());
		
		
	}
	return 0;
}





