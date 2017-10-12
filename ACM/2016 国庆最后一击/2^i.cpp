#include<stdio.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;
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
	for(int i = 0 ;i < 32;i++)
	printf("%lld,",pow(2,i));
}


