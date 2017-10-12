#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

int is2357(int num)
{
		while(!(num%2))
		{
			num /= 2;
		}
		while(!(num%3))
		{
			num /= 3;
		}
		while(!(num%5))
		{
			num /= 5;
		}
		while(!(num%7))
		{
			num /= 7;
		}	
		if(num == 1)
		return 1;
		return 0;
}

int pow(int x,int n)
{
	if(x == 0) return 0;
    if(n==0) return 1;
    else
    {
        while((n&1)==0)
        {
            n>>=1;
            x*=x;
        }
    }
    int result=x;
    n>>=1;
    while(n!=0)
    {
        x*=x;
    if((n&1)!=0)
        result*=x;
    n>>=1;
    }
    return result;
}
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		int a2 = 0;
		int a3 = 0;
		int a5 = 0;
		int a7 = 0;
		
		scanf("%d",&a);
		int aa = a;
		while(!(a%2))
		{
			a /= 2;
			a2++;
		}
		while(!(a%3))
		{
			a /= 3;
			a3++;
		}
		while(!(a%5))
		{
			a /= 5;
			a5++;
		}
		while(!(a%7))
		{
			a /= 7;
			a7++;
		}
	//	printf("%10d 2 %d 3 %d 5 %d 7 %d\n",a,a2,a3,a5,a7);
	//	printf("%d\n",aa/a);
		int remain = aa/a;
		for(;;a++)
		{
			if(is2357(a))
			{
				break;
			}
		}
		int ans = a*remain;
		printf("%d\n",ans);
	}
}
