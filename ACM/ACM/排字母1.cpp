#include<stdio.h>
int main()
{
	int n,i,j,k,l;
	char a;
	a='A';
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  {
	  	if(i==0)
		{
		  for(j=1;j<n-i;j++)
	  	    printf(" ");
	  	  printf("%c",a);
	  	  a++;
	  	  printf("\n");
	  	  continue;
		}
		for(j=1;j<n-i;j++)
	  	    printf(" ");
	  	  printf("%c",a);
	  	   a++;
	  	  for(k=0;k<1+2*(i-1);k++)
	  	    printf(" ");
	  	  printf("%c",a);
	  	   a++;
	  	   printf("\n");
	  }
	for(i=n-2;i>=0;i--)
	 {
	 	  if(i==0)
	 	  {
	 	  	for(j=1;j<n-i;j++)
	  	    printf(" ");
	  	    printf("%c",a);
	  	    a++;
	  	    printf("\n");
	   	    continue;
		   }
	      for(j=1;j<n-i;j++)
	  	    printf(" ");
	  	  printf("%c",a);
	  	   a++;
	  	  for(k=0;k<1+2*(i-1);k++)
	  	    printf(" ");
	  	  printf("%c",a);
	  	   a++;
	  	   printf("\n");
	   }  
	
	  
	  
}
