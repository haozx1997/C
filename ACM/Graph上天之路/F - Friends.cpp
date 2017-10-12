#include<stdio.h>
#include<string.h>
#include<math.h>
struct all
{
	int x,y;
}fr[500050];


int cit[30050];
int ans[30050];
int fr_num;
int group_i;

void newone(int aa,int bb)
{
	fr[fr_num].x=aa;
	fr[fr_num++].y=bb;
}


void group(int xx,int yy)
{
	
	if(cit[xx]==0&&cit[yy]==0)
	 {
	 	group_i++;
	 	cit[xx]=cit[yy]=group_i;
	 	
	 }
	 
	 else
	{
	 if(cit[xx]==0&&cit[yy]!=0) cit[xx]=cit[yy];
	 
	 if(cit[yy]==0&&cit[xx]!=0) cit[yy]=cit[xx];
	 if(cit[xx]!=0&&cit[yy]!=0) 
	  {
	  	if(cit[xx]>cit[yy]) cit[xx]=cit[yy];
	  	if(cit[xx]<cit[yy]) cit[yy]=cit[xx];
	  	if(cit[xx]==cit[yy]) ;
	  }
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		int a,b;
		memset(cit,0,sizeof(cit));
		memset(ans,0,sizeof(ans));
		fr_num=0;
		group_i=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		 {
		 	scanf("%d%d",&a,&b);
		 	newone(b,a);
			newone(a,b);
		 }
		for(int j=0;j<(int)sqrt(n);j++)
		for(int i=0;i<fr_num;i++)
		 group(fr[i].x,fr[i].y) ;
		
		for(int i=1;i<=n;i++) 
		 {
		 	ans[cit[i]]++;
		 }
		 int anss=0;
		 
		 for(int i=1;i<=group_i;i++)
		  if(ans[i]>anss) anss=ans[i];
		  printf("%d\n",anss);
		 	
	}
 } 
