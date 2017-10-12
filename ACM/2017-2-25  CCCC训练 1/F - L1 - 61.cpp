#include<stdio.h>

long long z[20000];
long long Z(long long n)
{
	long long a,b,i=0;
	
	for(a=2;a<20000;a++)
	  {
		for(b=2;b<a;b++)
		  {
		  	if((a%b)==0) break;
		  };
		if(b==a)
		  {
		  	z[i]=a;
		  	i++;
		  } ;
	  } 
	return z[n];
}
int main()
{
	long long NN;Z(2147483647);
	scanf("%lld",&NN);
	while(NN--)
	{
	
		long long a,b,i;
		scanf("%lld",&a);
		printf("%lld=",a);
		if(a == 1)
		{
			printf("1\n");
			continue;
		}
		for(i=0;a!=1;)
		{
			if(a%z[i]) i++;
			else
			 {	a=a/z[i];
			 	if(a!=1)
			 	{
			 		
			 
			 	printf("%lld*",z[i]);
				 }
				 else
				 {
				 	printf("%lld\n",z[i]);
				 }
			 }
		}
	}
	return 0;
} 
