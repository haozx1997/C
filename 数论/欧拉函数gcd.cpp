#include<stdio.h>
#include<string.h> 
#define ll long long

ll eul(ll n)
{
    ll ret=1,i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            n/=i,ret*=i-1;
            while(n%i==0)
            n/=i,ret*=i;
        }
    }
    if(n>1)
    ret*=n-1;
    return ret;
}

int main()
{
	ll n;
	while(~scanf("%I64d",&n))
	{
		ll ans = 0;
		for(ll i = 1; i*i<=n;i++)
		{
			if((n%i) == 0)
			{
				ans += eul(i)*n/i;
				if(i*i!=n)
				 ans += eul(n/i)*i;
			//	printf("%I64d\n",i); 
			}
		}
		printf("%I64d\n",ans);
	}
}
