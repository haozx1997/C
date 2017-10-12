#include<stdio.h>
int main()
{
  unsigned long a[100000],i,x,h,l;
  int n;
  a[1]=1;
  for(i=2;i<=100000;i++)
   {
   	a[i]=a[i-1]+i;
   }
   for(i=1;i<=1000;i++)
    a[i]=a[i]*2;
   scanf("%d",&n);
   while (n--)
   {
   	scanf("%d",&x);
   	if(x%2) 
	   {
	    printf("Poor HuJie!");
	    printf("\n");
       continue;
	   }
    for(i=1;i<=100000;i++)
     if(a[i]>=x) 
	 {h=i;
	 l=(x-a[i-1])/2;
	 break;
	 }
     printf("%d %d",h,l);
     printf("\n");
   }
   
   return 0;
}
