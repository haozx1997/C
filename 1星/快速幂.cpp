#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
const long long M = 1e10+7;
using namespace std;
ll pow_mod(ll x,ll n)
{
    ll ret = 1;
    while(n)
    {
        if(n & 1)
            ret = ret * x % Mod;
        n >>= 1;
        x = x * x % Mod;
    }
    return ret;
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
            x %= M;
        }
    }
    int result=x;
    n>>=1;
    while(n!=0)
    {
        x*=x;
        x %= M;
    if((n&1)!=0)
        result*=x;
        result %= M;
    	n>>=1;
    }
    return result;
}

int main()
{
	int n,i;
	while(~scanf("%d%d",&n,&i))
	{
		printf("%d\n",pow(n,i));
	}
}
