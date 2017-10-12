#include<stdio.h>
#include<math.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		
		int a,b,sum,f=0;
		double n;
		scanf("%d",&a);
		getchar(); 
		a=a>0?a:-a;
		n=sqrt(2*(double)a+0.25)-0.5;
		b=(n-(int)n)?(int)(n+1):(int)n; 
		for(sum=(1+b)*b/2;(sum-a)%2;b++,f=1)
		 sum=(1+b)*b/2;
		if(f) b--;
		if(!a) b=3;
		printf("%d\n",b);
		if(T)printf("\n");
	}
	return 0;
}
