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
            x%=10;
        }
    }
    int result=x;
    n>>=1;
    while(n!=0)
    {
        x*=x;
        x%=10;
    if((n&1)!=0)
        {
        	result*=x;
        	result%=10;
		}
    n>>=1;
    }
    
    return result%10;
}

int main()
{
	int n,i;
	while(~scanf("%d%d",&n,&i))
	{
		n%=10;
		printf("%d\n",pow(n,i));
	}
}
