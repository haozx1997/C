#include<stdio.h>
#include<string.h>
int main()
{
	int f[100];
	int i,j;
    while(scanf("%d",&i))
    {
    	
    	j=0;
        while(1)
        {
    	   f[j]=i%10;
    	   printf("%d ",f[j]);
    	   if(!(i/10)) break;
    	   i/=10;
    	   j++;
    	}
    	
	printf("\n");
	    for(i=0;i<5;i++)
	    {
	     	printf("%d ",f[i]);
	    }
	    	printf("\n");
	}
    
    

}

