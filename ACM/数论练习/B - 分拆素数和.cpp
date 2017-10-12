#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,i=0;
	int z[10009];
	int ifz[10009];//判断是否素数 
	memset(ifz,0,sizeof(ifz));//必初始化 
	for(a=2;a<10000;a++)
	  {
		for(b=2;b<a;b++)
		  {
		  	if((a%b)==0) break;
		  };
		if(b==a)
		  {
		  	z[i]=a;
		  	ifz[z[i]]=1;
		  	i++;
		  } ;
	  }  
	
	
	int  n; 
	while(scanf("%d",&n),n)
	{
		int ans=0,j,zz;
		for(j=0;z[j]<(n+1)/2;j++)
		 {
		 	  zz=n-z[j];
		 	  if(ifz[zz]) 
			   {
			   	 ans++;
		 	    
			   }
		 	  
		 }
		 printf("%d\n",ans);
	}
	
 } 
