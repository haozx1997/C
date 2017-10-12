#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node
{
	int x,y,z;
	int step;
};

	int n,mm,h;int j,jj;
int sx,sy,sz;
int i;
int dir[6][3]={0,0,1,0,0,-1,0,1,0,0,-1,0,1,0,0,-1,0,0};
char m[50][50][50];
int check(int zz,int xx,int yy)
{
	if(zz<1||zz>h||xx<1||xx>n||yy<1||yy>mm||m[zz][xx][yy] == '#')
	 return 0;
	return 1;
}

int bfs()
{
	queue<node> q;
	node a,next;
	a.x=sx;
	a.y=sy;
	a.z=sz;
	a.step = 0;
	m[sz][sx][sy]='#';
	q.push(a);
	while(!q.empty())
	 {
	 	
	 	a=q.front();
	//	printf("%d %d %d %d %c\n",a.z,a.x,a.y,a.step,m[a.z][a.x][a.y]);
	 	q.pop();
	 	if(m[a.z][a.x][a.y] == 'E')
	 	 return a.step;
	 	
		for(i=0;i<6;i++)
		 {
		 	next=a;
		 	next.x=a.x+dir[i][1];
		 	next.y=a.y+dir[i][2];
		 	next.z=a.z+dir[i][0];
		 	
		 	if(check(next.z,next.x,next.y)) 
		 	  {
		 	  	next.step++;
		 	  	if(m[next.z][next.x][next.y] == 'E')
	 			 return next.step;
		 	  	m[next.z][next.x][next.y]='#';
		 	  	
		 	  	q.push(next);
		 	  	
			   }
		  } 
	 }
	  return -2;
	

}




int main()
{
//	freopen("1.in","r",stdin);
	

	while(~scanf("%d%d%d",&h,&n,&mm))
	{
		if(h == 0)
		{
			return 0;
		}
		
		
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=n;j++)
			{
			  	scanf("%s",&m[i][j][1]);
			}
			getchar();
		}
	  	
	  	for(i=1;i<=h;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(jj=1;jj<=mm;jj++)
				{
					if(m[i][j][jj] == 'S')
					{
						sz = i;
						sx = j;
						sy = jj;
					}
				}
			  	
			  	
			}
		}
//		printf("sss %d %d %d\n",sz,sx,sy); 
//		for(i=0;i<=h+1;i++)
//		{
//			for(j=0;j<=n+1;j++)
//			{
//				for(jj=0;jj<=mm+1;jj++)
//				{
//					printf("%c",m[i][j][jj]);
//				}
//				printf("\n");
//				
//			}
//			printf("\n");
//				
//		}
		int ans = bfs();
		if(ans == -2)
		{
			printf("Trapped!\n");			
		}	
		else
		{
			printf("Escaped in %d minute(s).\n",ans);
		}		  	  
	}
	

}
