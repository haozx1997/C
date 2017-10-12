#include<stdio.h>
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
	int a,b,x, y, z;
	scanf("%d%d",&a,&b);
	z=extended_gcd(a,b, x, y);
	printf("%d %d %d\n",z,x,y);
	return 0;
}

