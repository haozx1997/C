#include<stdio.h>
#include<algorithm>
#include<string.h>
#define N 100010
using namespace std;
struct p
{
	int x,y;
	int id;	
}pt[N];

bool cmp( p a, p b)
{
	if(a.y != b.y )
	 return a.y > b.y;
	return  a.x < b.x;
}

int c[N];
int lowbit(int x)
{
	return x & (-x);
}
void update(int x,int val)
{
	while(x <= N)
	{
		c[x] += val;
		x +=lowbit(x);	
	}
}
int sum(int x)
{
	int ans = 0;
	while(x > 0)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	int n;
	int ans[N];
	while(scanf("%d",&n),n)
	{
		memset(ans,0,sizeof(ans));
		memset(c,0,sizeof(c));
		int xx,yy;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d",&pt[i].x,&pt[i].y);
			pt[i].x++;
			pt[i].y++;
			pt[i].id = i;
		}
		sort(pt+1,pt+1+n,cmp);
//		for(int i = 1;i <= n;i++)
//		{
//			printf("%d %d\n",pt[i].x,pt[i].y);
//		}
	//	printf("'__________________'\n");
		xx = yy = -1; 
		int lans = 0;
		for(int i = 1; i <= n;i++)
		{
			
			if((xx!=pt[i].x)||(yy!=pt[i].y))
			 {
			 	ans[pt[i].id] = sum(pt[i].x);
			 	xx = pt[i].x;
			 	yy = pt[i].y;
			 	lans = ans[pt[i].id];
			 	
			 }
			else
			 {
			 //	printf("?");
			 	ans[pt[i].id] = lans; 
			 }
		//	 printf("xxyy%d %d\n",xx,yy);
		//	 printf("%d %d %d\n",i,ans[pt[i].id],pt[i].id);
			update(pt[i].x,1);
		}
		for(int i = 1; i <= n;i++)
		{
			printf("%d%c",ans[i]," \n"[i==n]);
		}
		
		
	}
}
