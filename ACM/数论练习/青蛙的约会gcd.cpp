#include<stdio.h>

int gcd(int a,int b)
{
	 return !b? a : gcd(b,a%b);
}

int extended_gcd(int a, int b, int &x, int &y) 
{
	int ret, tmp; 
	if (!b) 
	{
		x = 1;
		y = 0;
		return a;  
	} 
	
	ret = extended_gcd(b, a % b,x, y); 
	tmp = x;
	x = y; 
	y = tmp - a / b * y;
	return ret; 
} 
int main()
{
	int a,b,c,x,y,m,n,l;
	scanf("%d%d%d%d%d",&x,&y,&m,&n,&l);
	
	a=n-m;
	b=l;
	c=x-y;
	int t,z,d;
	d=extended_gcd(a,b,t,z);
	if(!(c%d))
	 {
	 	printf("Impossible\n");
	 	
	 } 
	
	
	printf("%d*%d+%d%d=%d\n",a,t,b,z,gcd(a,b)) ;
	
	
 } 
