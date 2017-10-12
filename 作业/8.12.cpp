#include<stdio.h>
double f(double x) //函数
   {
    return x*x*x-5*x*x+16*x-80;
   }
double f1(double x) //导函数
   {
    return 3*x*x-10*x+16; 
   }
double F(double x0,int n) //迭代函数
   {
   	double x1;
   	for(;n>0;n--)
   	   {
   		x1=x0-f(x0)/f1(x0);
   		x0=x1;
	   }
	 return x0 ;
   }
int main()
{
	//用牛顿迭代法求方程x^3-5x^2+16x-80=0 的一个根。
	int x0,n,x;
	scanf("%d%d",&x0,&n);
	printf("%f",F(x0,n));
	return 0 ;
}

	
	
