#include<stdio.h>
#define ll long long

ll n,m;

ll mul(ll a, ll b, ll mod) {
    a = (a % mod + mod) % mod;
    b = (b % mod + mod) % mod;

    ll ret = 0;
    while(b){
        if(b&1){
            ret += a;
            if(ret >= mod) ret -= mod;
        }
        b >>= 1;
        a <<= 1;
        if(a >= mod) a -= mod;
    }
    return ret;
}

int main()
{
	
	while(~scanf("%I64d%I64d",&n,&m))
	{
		ll ans = mul(n,n-1,m);
		int f = 0;
		if(!ans)
		{
			printf("%I64d divides %I64d!\n",m,n);
			continue;
		}
		for(int i = n-2;i>1;i--)
		{
		//	printf("ans = %I64d i = %I64d\n",ans,i);
			ans = mul(ans,i,m);
			if(!ans)
			{
				f = 1;				
				break;
			}
		}
		if(f)
		{
			printf("%I64d divides %I64d!\n",m,n);
		}
		else
		{
			printf("%I64d does not divides %I64d!\n",m,n);
		}
		
	}
 } 
