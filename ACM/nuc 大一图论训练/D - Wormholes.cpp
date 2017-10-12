#include<stdio.h>

struct point
{
	int s,e,h;
}map[30000];

int n,m,w;
int dis[5200];
int map_num;
void newone(int a,int b,int c)
{
	map[map_num].s=a;
	map[map_num].e=b;
	map[map_num].h=c;
	map_num++;
}

int jj()
{
	
	for(int i=1;i<=n;i++)
	 {
	 	dis[i]=100000;
	 } 
	dis[1]=0;
		for(int i=1;i<n;i++)
	 for(int j=0;j<map_num;j++)
	  {
	  	if(dis[map[j].e]>dis[map[j].s]+map[j].h)
	  	 {
	  	 
		   dis[map[j].e]=dis[map[j].s]+map[j].h;
		   }
	  }
	for(int j=0;j<map_num;j++)
	  {
	  	if(dis[map[j].e]>dis[map[j].s]+map[j].h)
	  	 {
	  	 return 1;
		   }
	  }  
	return 0;
	 
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		map_num=0;
		scanf("%d%d%d",&n,&m,&w);
		int W,T,F;
		while(m--)
		{
			scanf("%d%d%d",&W,&T,&F);
			newone(W,T,F);
			newone(T,W,F);
		}
		while(w--)
		{
			scanf("%d%d%d",&W,&T,&F);
		    newone(W,T,-F);
		}
		int jjj=jj();
	    printf("%s\n",jjj?"YES":"NO");
    }
    return 0;
}
