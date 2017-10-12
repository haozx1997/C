#include<bits/stdc++.h>

using namespace std;

int cc[500][500];

struct node
{
	int x,y;
	int id;
}p[600];

map<long long,int>have;


int ishave(int i1,int i2,int i3,int i4)
{
	int f[10];
	f[0] = i1;
	f[1] = i2;
	f[2] = i3;
	f[3] = i4;
	sort(f,f+4);
	if(have[(long long)f[0]+510*f[1]+510*510*f[2]+510*510*510*f[3]] == 0)
	{
		have[(long long)f[0]+510*f[1]+510*510*f[2]+510*510*510*f[3]] = 1;
	//	printf("ishave %d %d %d %d\n",i1,i2,i3,i4);
		return 0;
	}
	return 1;
}


int main()
{

	int n;
	
	while(~scanf("%d",&n))
	{
		memset(cc,0,sizeof(cc));
		memset(p,0,sizeof(p));
		
		have.clear();
		for(int i = 1;i <=n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x += 200;
			y += 200;
			cc[x][y] = i;
			p[i].x = x;
			p[i].y = y;
			p[i].id = i;
			
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				if(p[i].x-(p[j].y - p[i].y)<0||p[i].y+(p[j].x - p[i].x)>300)
				{
					continue;				
				}
				if(p[j].x-(p[j].y - p[i].y)<0||p[j].y+(p[j].x - p[i].x)>300)
				{
					continue;
				}
				if(p[i].x+(p[j].y - p[i].y)>300||p[i].y-(p[j].x - p[i].x)<0)
				{
					continue;
				}
				if(p[j].x+(p[j].y - p[i].y)>300||p[j].y-(p[j].x - p[i].x)<0)
				{
					continue;
				}
//				
				if(cc[p[i].x-(p[j].y - p[i].y)][p[i].y+(p[j].x - p[i].x)] != 0)
				{
					if(cc[p[j].x-(p[j].y - p[i].y)][p[j].y+(p[j].x - p[i].x)] != 0)
					{
						if(ishave(i,j,cc[p[i].x-(p[j].y - p[i].y)][p[i].y+(p[j].x - p[i].x)],cc[p[j].x-(p[j].y - p[i].y)][p[j].y+(p[j].x - p[i].x)]))
						{
							
						}
						else
						{
							ans++;
				//			printf("%d %d %d %d\n",i,j,cc[p[i].x-(p[j].y - p[i].y)][p[i].y+(p[j].x - p[i].x)],cc[p[j].x-(p[j].y - p[i].y)][p[j].y+(p[j].x - p[i].x)]);
						}
					}
				}
				

				
				
				if(cc[p[i].x+(p[j].y - p[i].y)][p[i].y-(p[j].x - p[i].x)] != 0)
				{
					if(cc[p[j].x+(p[j].y - p[i].y)][p[j].y-(p[j].x - p[i].x)] != 0)
					{
						if(ishave(i,j,cc[p[i].x+(p[j].y - p[i].y)][p[i].y-(p[j].x - p[i].x)],cc[p[j].x+(p[j].y - p[i].y)][p[j].y-(p[j].x - p[i].x)]))
						{
							
						}
						else
						{
							ans++;	
				//			printf("%d %d %d %d\n",i,j,cc[p[i].x+(p[j].y - p[i].y)][p[i].y-(p[j].x - p[i].x)],cc[p[j].x+(p[j].y - p[i].y)][p[j].y-(p[j].x - p[i].x)]);
						}
					}
				}
			}
		}
		printf("%d\n",ans);
		
	 } 
	




 return 0;
}

/*
6
0 0
0 1
1 0
1 1
2 0
2 1

6
0 0
0 1
2 0
2 1
1 0
1 1

6

1 0
1 1
2 0
2 1
0 0
0 1


*/





