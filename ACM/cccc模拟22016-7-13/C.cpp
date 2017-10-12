#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
#include<queue>
using namespace std;

struct no
{
	int x,y;
	int step;
};

int dir[4][2] = {0,1,0,-1,1,0,-1,0};
char m[10][10]={}
int lx,ly;
int qx,qy;
int tr[30][5];
int istr[30];
int xmax,ymax;
int check(int xx,int yy)
{
	if(m[xx][yy] == '#'||xx<0||yy<0||xx>=xmax||yy>=ymax)
	 return 0;
	return 1;
}

int bfs()
{
	queue<no> q;
	no a,next,last;
	a.x = lx;
	a.y = ly;
	a.step = 0;
	m[lx][ly] = '#';
	q.push(a);
	while(!q.empty())
	{
		a = q.front();
		printf("aa %d   %d    %d  \n",a.x,a.y,a.step);
		q.pop();
		if(a.x == qx&&a.y == qy)
		{
			return a.step;
		}
		

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
		 	  			m[next.x][next.y] = '#';
		 	  			next.x = tr[aa][2];
						next.y = tr[aa][3];
					   }
					 else
					 {
					 	m[next.x][next.y] = '#';
		 	  			next.x = tr[aa][0];
						next.y = tr[aa][1];
					   }
					    
		 	  		q.push(next);
				   }
				 else
				 {
				 	m[next.x][next.y]='#';
		 	  		
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
	while(T--)
	{
		memset(m,0,sizeof(m));
		memset(istr,0,sizeof(istr));
		
		
		scanf("%d%d",&xmax,&ymax);
		getchar();
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
		for(int i = 0;i < xmax;i++)
		{
			for(int j = 0;j < ymax;j++)
			{
				printf("%c",m[i][j]);
				
			}
			printf("\n\n");
		}
		printf("%d %d\n%d %d\n\n",lx,ly,qx,qy);
		for(int i = 0 ;i < 30;i++)
		{
			if(istr[i]!= 0)
			{
				printf("%c",'a'+i);
				for(int j = 0;j < 4;j++)
				printf("%d ",tr[i][j]);
				printf("\n");
			}
			
		}
		printf("          %d\n",bfs());
		
		
	}
	return 0;
}





