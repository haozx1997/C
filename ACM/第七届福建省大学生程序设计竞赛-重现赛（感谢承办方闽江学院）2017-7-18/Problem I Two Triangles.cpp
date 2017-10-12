#include<stdio.h>

using namespace std;

struct pp
{
	int x,y;
}p[100];

struct tt
{
	int x1;
	int x2;
	int x3;
	int dd[10];
	
}t1,t2;
int dis2(int int1,int int2)
{
	pp p1 = p[int1];
	pp p2 = p[int2];
	
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

int cc(int ii,int ij,int jj)
{
	pp p1,p2;
	p1.x = p[ij].x - p[ii].x;
	p1.y = p[ij].y - p[ii].y;
	
	p2.x = p[jj].x - p[ij].x;
	p2.y = p[jj].y - p[ij].y;
	
	return p1.x*p2.y - p2.x*p1.y;
}
int sam(tt t1,tt t2)
{
	
	t1.dd[0] = dis2(t1.x1,t1.x2);
	t1.dd[1] = dis2(t1.x2,t1.x3);
	t1.dd[2] = dis2(t1.x3,t1.x1);
	
	t2.dd[0] = dis2(t2.x1,t2.x2);
	t2.dd[1] = dis2(t2.x2,t2.x3);
	t2.dd[2] = dis2(t2.x3,t2.x1);
	
	if(cc(t1.x1,t1.x2,t1.x3) == 0)
	{
		return 0;
	}
	if(cc(t2.x1,t2.x2,t2.x3) == 0)
	{
		return 0;
	}	
	if((t1.dd[0] == t2.dd[0])&&(t1.dd[1] == t2.dd[1])&&(t1.dd[2] == t2.dd[2]))
	{
		return 1;
	}
	if((t1.dd[0] == t2.dd[0])&&(t1.dd[1] == t2.dd[2])&&(t1.dd[2] == t2.dd[1]))
	{
		return 1;
	}
	if((t1.dd[0] == t2.dd[1])&&(t1.dd[1] == t2.dd[0])&&(t1.dd[2] == t2.dd[2]))
	{
		return 1;
	}
	if((t1.dd[0] == t2.dd[1])&&(t1.dd[1] == t2.dd[2])&&(t1.dd[2] == t2.dd[0]))
	{
		return 1;
	}
	if((t1.dd[0] == t2.dd[2])&&(t1.dd[1] == t2.dd[1])&&(t1.dd[2] == t2.dd[0]))
	{
		return 1;
	}
	if((t1.dd[0] == t2.dd[2])&&(t1.dd[1] == t2.dd[0])&&(t1.dd[2] == t2.dd[1]))
	{
		return 1;
	}
	
	return 0;
}





int to(tt t,int i)
{
	switch(i)
	{
		case 1:
			return t.x2;
		case 2:
			return t.x3;
		case 0:
			return t.x1;
			
	}
}

int sam2(tt t1,tt t2)
{
	t1.dd[0] = dis2(t1.x1,t1.x2);
	t1.dd[1] = dis2(t1.x2,t1.x3);
	t1.dd[2] = dis2(t1.x3,t1.x1);
	
	t2.dd[0] = dis2(t2.x1,t2.x2);
	t2.dd[1] = dis2(t2.x2,t2.x3);
	t2.dd[2] = dis2(t2.x3,t2.x1);
	if((t1.dd[0]==t1.dd[1])||(t1.dd[0]==t1.dd[2])||(t1.dd[2]==t1.dd[1]))
	{
//		printf("fuck\n");
		return 1;
	}
	int m = 0,mm = 1000;
	int t1m1,t1ca,t1m3,t1m2;
	for(int i = 0;i < 3;i++)
	{
		if(m<t1.dd[i])
		{
			m = t1.dd[i];
			t1m3 = i;
		}
		if(mm>t1.dd[i])
		{
			mm = t1.dd[i];
			t1m1 = i;
		}
	}
	t1m2 = 3 - t1m1 - t1m3;
	
	t1ca = cc(to(t1,t1m1),to(t1,t1m2),to(t1,t1m3));
	
	int t2m1,t2ca,t2m3,t2m2;
	m = 0;mm = 1000;
	for(int i = 0;i < 3;i++)
	{
		if(m<t2.dd[i])
		{
			m = t2.dd[i];
			t2m3 = i;
		}
		if(mm>t2.dd[i])
		{
			mm = t2.dd[i];
			t2m1 = i;
		}
	}
	
	t2m2 = 3 - t2m1 - t2m3;
	
	t2ca = cc(to(t2,t2m1),to(t2,t2m2),to(t2,t2m3));
//	printf("	%d %d %d %d %d %d\n",t2m1,t2m2,t2m3,t1m1,t1m2,t1m3);
	
//	printf("	ca %d %d %d %d %d %d %d %d\n",t1ca,t2ca,to(t1,t1m1),to(t1,t1m2),to(t1,t1m3),to(t2,t2m1),to(t2,t2m2),to(t2,t2m3));
	if(t2ca == t1ca)
	{
		return 1;
	}
	return 0;
	
	
}




int main()
{
	int T;
	scanf("%d",&T);
	for(int I = 0; I < T;I++)
	{
		int n;
		int ans = 0;
		scanf("%d",&n);
		int all[100];
		for(int i = 0; i < n;i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			all[i] = i;
		}
		
		for(int i1 = 0;i1 < n-2;i1++)
		{
			t1.x1 = i1;
		
			for(int i2 = i1+1;i2 < n-1;i2++)
			{
				t1.x2 = i2;
				for(int i3 = i2+1;i3 < n;i3++)
				{
					t1.x3 = i3;
					for(int j1 = 0;j1 < n-2;j1++)
					{
						if(j1 == i1||j1 == i2||j1 == i3)
						{
							continue;
						}
						t2.x1 = j1;
						for(int j2 = j1+1;j2 < n-1;j2++)
						{
							if(j2 == i1||j2 == i2||j2 == i3)
							{
								continue;
							}
							t2.x2 = j2;
							for(int j3 = j2+1;j3 < n;j3++)
							{
								if(j3 == i1||j3 == i2||j3 == i3)
								{
									continue;
								}	
								t2.x3 = j3;
								
								if(sam(t2,t1))
								{
									if(sam2(t2,t1))
									{
										ans++;
						//				printf("%d %d %d   %d %d %d\n",t1.x1,t1.x2,t1.x3,t2.x1,t2.x2,t2.x3);
									}
								}
							}
						}
					}
		
			
					
					
				}
			}
		}
		
		
		
		printf("Case %d: %d\n",I+1,ans);
	}




 return 0;
}


