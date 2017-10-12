#include<bits/stdc++.h>

using namespace std;
#define ll long long

const ll Mod = 1000000007;

ll phi[3010100];
ll eul_list(ll n)
{  
	phi[1] = 1; 
    for(int i=2; i<=n; ++i)  
        phi[i] = 0;  
     
    for(int i=2; i<=n; ++i) 
		if((phi[i] == 0))  
	        for(int j=i; j<=n; j+=i)  
	        {  
	            if(phi[j] == 0) 
					phi[j] = j;  
	            phi[j] = phi[j]/i * (i-1);  
	        }  
}

ll phd(ll x)
{
	if(x <3000000)
	{
		return phi[x];
	}

    ll ret = x,i;
    for(i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            ret = ret - ret/i;
            x/=i;	
            while(x%i==0)
            x/=i;	
        }
    }
    if(x>1)
    ret = ret - ret/x;
    return ret;

}

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

ll pow(ll x,ll n)
{
	if(x == 0) return 0;
    if(n==0) return 1;
    else
    {
        while((n&1)==0)
        {
            n>>=1;
            x*=x;
            x %= Mod;
        }
    }
    ll result=x;
    n>>=1;
    while(n!=0)
    {
        x*=x;
        x %= Mod;
    if((n&1)!=0)
        result*=x;
        result %= Mod;
    	n>>=1;
    }
    return result;
}

int main()
{

	ll n = 0;
	int T;
	scanf("%d",&T);
	eul_list(3000010);
	while(T--)
	{
		scanf("%I64d",&n);
		ll sum = (ll) 0;
		ll med;
		for(ll i = (ll)1; (i*i) <= n;i++)
		{
			
			if((!(n%i)))
			{
				if((i%2))
				{
			//		printf("	%I64d\n",i);
					med = pow_mod((ll)2,n/i)*phd(i)%Mod;
			//		printf("med %I64d\n",med);
					sum += med;
					sum %= Mod;
			//		printf("med %I64d  sum %I64d   i %I64d  \n",med,sum,i);
				}
				if((i*i)!=n)
				{
					if((n/i)%2)
					{
			//			printf("	%I64d\n",n/i);
						med = pow_mod((ll)2,i)*phd(n/i)%Mod;
			//			printf("med %I64d\n",med);
						sum += med;
						sum %= Mod;
				//		printf("med %I64d  sum %I64d   i %I64d  \n",med,sum,n/i);
					}
				}
				
			}
			
		}
		printf("%I64d\n",sum * pow_mod(n,Mod - 2) % Mod);
	}



 return 0;
}

/**/
