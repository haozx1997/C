#include<stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		int ans=0;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int i,j;
		for(i=a;i<=b;i++)
		 for(j=c;j<=d;j++)
		  {
		  	if((i^j)>ans) ans=i^j;

		  }
		printf("%d\n",ans);  
	}
	
	
	return 0;
}
