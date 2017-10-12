#include<stdio.h>
int main()
{
	int t;
	int f,a,b,c,i,j,i0,j0;
	scanf("%d",&t);
	while(t--)
	{
		i0=1000;j0=1000;f=0;
		scanf("%d%d%d",&a,&b,&c);
	    if((c%2)==1)
	     {
	     	printf("Impossible\n");continue;
		 }
		for(i=0;i<1000;i++)
		 for(j=0;j<1000;j++)
		  if(((a*i+b*j)==c/2)&&(i+j)<(i0+j0))
		  {
		  	f=1;
		  	i0=i;
		  	j0=j;
		  }
		if(f)
		 printf("%d %d\n",i0*2,j0*2);
		else
		  printf("Impossible\n");
		  
	}
}
