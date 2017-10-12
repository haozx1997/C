#include<stdio.h>
#include<string.h>
#include<math.h>



int main()
{
	int T;
	long long k,s,n,i;
	scanf("%d",&T);
	while(T--)
	{
	
		double si;
		scanf("%lld",&k);
		si=sqrt(2*k+0.25)-0.5;
		if(si-(int)si>0) s=(int)++si;
		else s=(int)si;
		printf("%d",s);
		k=k-(s-1)*s/2;
		n=k%9;
		if(!n) n=9;
		printf("%d\n",n);
		
	}
}
