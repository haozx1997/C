#include<stdio.h>
int ext_euclid(int a, int b, int &x, int &y) 
{
 	int ret, tmp; 
	  if (!b) 
	  { 
		x = 1;
		y = 0;
		return a;
	  } 
	  ret = ext_euclid(b, a % b, x, y); 
 	  tmp = x;
	  x = y;
	  y = tmp - a / b * y;
      return ret; 
} 


int China(int B[],int W[],int k)   
   {      
       int i;   
       int d,x,y,a=0,m,n=1;   
       for(i=0;i<k;i++)   
       n*=W[i];   
       for(i=0;i<k;i++)   
       {
          m=n/W[i];   
          d=ext_euclid(W[i],m,x,y);   
          a=(a+y*m*B[i])%n;
          printf("%d %d %d\n",y,m,B[i]);
       }   
       
       if(a>0)
	   return a;   
       else
	   return a;   
   } 


int main()
{
	int a[1010],r[1010];
	int T;
	while(scanf("%d",&T)!=EOF)
	{
		for(int i=0;i<T;i++)
		 scanf("%d%d",&a[i],&r[i]);
		printf("%d\n",China(a,r,T));
	}
}
