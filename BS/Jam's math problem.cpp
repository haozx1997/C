#include<stdio.h>
int main()
{
	int T,f;
	long a,b,c,q,p,k,m;
	scanf("%d",&T);
	while(T--)
	{
		f=0;
		scanf("%d%d%d",&a,&b,&c);
		for(q=1;q<=a;q++)
		 if(a%q==0)
		  {
		  	for(k=1;k<=c;k++)
		  	 {
		  	   	if(c%k==0)
		  	   	 {
		  	   	 	p=a/q;
		  	   	 	m=c/k;
		  	   	 	if(q*k+m*p==b)
		  	   	 	 {
		  	   	 	 	f=1;
		  	   	 	 	break;
					   }
				 }
			 }
			 if(f)break;
		  }
		if(f) printf("YES\n");
		else  printf("NO\n");
	}
	return 0;
 } 
