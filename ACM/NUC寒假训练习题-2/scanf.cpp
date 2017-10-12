#include<stdio.h>
#include<string.h>

int main()
{
	char a[1005],b[1005],c[1005],d[1005];
	
	while(scanf("%s%s",a,b)!=EOF)
	{
		int i;
		for(i=0;i<strlen(a);i++)
		 a[i]=a[i]-'0';
		 b[0]=b[0]-'0';
		 for(i=strlen(a)-1;i>=0;i--)
		 c[i]=0;
		 for(i=strlen(a)-1;i>=0;i--)
		 {
		 	
		 	c[i]=c[i]+a[i]*b[0];
		 	
		 	if(c[i]>9) 
		 	  {
		 	  	c[i-1]=c[i]/10;
				  
		 	  	c[i]-=(c[i-1])*10;
		 	  
			   }
		 }
		  
		 for(i=0;i<strlen(a);i++)
		   
		printf("%d",c[i]);
	}}
