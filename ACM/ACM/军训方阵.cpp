#include<stdio.h>
#include<math.h>
int main()
{
	int i,a,b,n=1;
	while(scanf("%d",&i)!=EOF)
	{
	  printf("Case %d:\n",n);
	   for(a=1;a<=sqrt(i);a++)
	      if(i%a==0) printf("%d * %d\n",a,i/a);
	   n++;
	   printf("\n");
    }
    return 0;
}
