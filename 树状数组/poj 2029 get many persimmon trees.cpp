#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 1000

int cc[N][N];
int n;
int lowbit(int x)
{
	return x&(-x);
}

void update2(int x,int y,int val)
{
	for(int i = x; i < N;i += lowbit(i))
	{
		for(int j = y; j < N; j += lowbit(j))
		{
			cc[i][j] += val;
		}
	}
}

int sum2(int x,int y)
{
	int ans = 0;
	for(int i = x;i > 0;i -= lowbit(i))
	{
		for(int j = y;j > 0;j -= lowbit(j))
		{
			ans += cc[i][j];
		}
	}
	return ans;
}

int sum5(int x1,int y1,int x2,int y2)
{
	
	int s1,s2,s3,s4,s5;
	s1 = sum2(x1-1,y1-1);
	s2 = sum2(x2,y1-1);
	s3 = sum2(x1-1,y2);
	s4 = sum2(x2,y2);
//	printf("%d %d %d %d    %d %d %d %d\n",x1,y1,x2,y2,s1,s2,s3,s4);
	s5 = s4 - s3 - s2 + s1;
	return s5;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		memset(cc,0,sizeof(cc));
		int xx,yy;
		int px,py;
		scanf("%d%d",&xx,&yy);
	//	printf("%d\n",sum2(xx,yy));
		for(int i = 0;i < n;i++)
		{
			scanf("%d%d",&px,&py);
			update2(px,py,1);
//			printf("%d\n",sum2(xx,yy));
		}
		int s,t;
		scanf("%d%d",&s,&t);
		int maX = 0;
		int sss;
//		for(int i = 1;i <= xx;i++)
//		{
//			for(int j = 1;j <= yy;j++)
//			{
//				printf("sum %d %d %d\n",i,j,sum2(i,j));
//			}
//		}
		for(int i = 1; i <= (xx-s+1);i++)
		{
			for(int j = 1; j <= (yy-t+1);j++)
			{
				sss = sum5(i,j,i+s-1,j+t-1);
		//		printf("ssss  %d\n",sss);
				if(sss > maX)
				{
					maX = sss;
				}
			}
		}
		printf("%d\n",maX);
	}
}

