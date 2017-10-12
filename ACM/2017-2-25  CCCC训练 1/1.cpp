#include<stdio.h>
int gcd(int a,int b)//greatest common divisor
{
//    while(a!=0)
//    {
//        int c = b % a;
//        b = a;
//        a = c;
//    }
//    return b;
    return a == 0 ? b : gcd(b % a,a);
}
int  lcm(int a ,int b)//lowest common multiple
{

	return (long long)a*b/gcd(a,b);//ûlong long 10^18
                                // int 10^9
}
int main()
{
	int n;
	scanf("%d",&n); 
	while(n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d %d\n",gcd(a,b),lcm(a,b));
	}
 }
