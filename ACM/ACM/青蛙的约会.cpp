#include<stdio.h>
int main()
{
   int x,y,m,n,l,i;
   while(scanf("%d%d%d%d%d",&x,&y,&m,&n,&l)!=EOF)
	 {
	 	for(i=1;;i++)
	 	  {
		      if(((x+i*m)%l)==((y+i*n)%l))
	 	        {
		           printf("%d\n",i);
		           break;
	            }
	          if((((x+i*m)%l)==x)&&(((y+i*n)%l)==y))
	             {       
	     	         printf("Impossible\n");
		             break;
		         }
	     }
	 }
	 return 0;
}

