#include<stdio.h>
int main()
{
   int t,n,m,i;
   char s[20];
   scanf("%d",&t);
   while(t--)
   {
   	  scanf("%d%d%s",&n,&m,&s);
   	  double w,sum=0;
   	  for(i=0;i<m;i++)
   	   {
		  scanf("%lf",&w);
		  sum+=w;
   	  }
   	  printf("The scores of Class %s's is %.2lf.\n",s,sum*n);
   }
   return 0;
}
