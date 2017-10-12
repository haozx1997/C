#include<stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	 {
	 	if(n==1||n==0) 
	 	 {
	 	 	printf("%d: %d\n",n,1);
	 	 	continue;
		  }
	 	 
	 	int ans=2,i;
	 	for(i=2;i*i<n;i++) 
	 	{
	 		if(!(n%i)) ans+=2;
		 }
		
		if(i*i==n) ans++; 
	 	printf("%d: %d\n",n,ans);
	 }
}
