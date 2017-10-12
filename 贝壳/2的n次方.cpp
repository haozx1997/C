#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long long two[32]=
{
	1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,
	262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,
	134217728,268435456,536870912,1073741824,2147483648
};

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
	for(int i = 0;i <32;i++)
	{
		printf("%lld,",pow(2,i));
	}
}
