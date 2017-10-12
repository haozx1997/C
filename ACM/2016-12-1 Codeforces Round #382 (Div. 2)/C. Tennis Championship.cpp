#include<stdio.h>
#define ll long long

ll a[100];

void init()
{
	a[1]=2;
    a[2]=3;
    for(int i=3;i<=85;i++)
    {
    	a[i]=a[i-1]+a[i-2];
	}        
}

int main()
{
    
    ll x;
    init();
    while (scanf("%lld",&x)!=EOF)
    {
    	for(int i=85;i>=1;i--)
	        if(x>=a[i])
		    {
		        printf("%d\n",i);
		        break;
		    }
	    
	}
    return 0;
}
