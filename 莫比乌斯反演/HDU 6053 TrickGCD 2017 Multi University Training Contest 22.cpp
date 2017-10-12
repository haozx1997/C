#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
const ll maxn = 200010;
const ll MAXN=200000+50;
const ll INF=0x7fffffff;
const int N = 1e5+4;
ll miu[MAXN] ;




bool notp[N];
int prime[N], pnum, mu[N];
void Mobius() {
    memset(notp, 0, sizeof(notp));
    mu[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!notp[i]) prime[++pnum] = i, mu[i] = -1;
        for (int j = 1; prime[j]*i < N; j++) {
            notp[prime[j]*i] = 1;
            if (i%prime[j] == 0) {
                mu[prime[j]*i] = 0;
                break;
            }
            mu[prime[j]*i] = -mu[i];
        }
    }
    for (int i = 0; i < N; i++) mu[i] = -mu[i];
}
ll a;

ll sum[MAXN];

long long quick_mul(ll a,ll b)
{
	
	ll yaoyuan = 0;
	while(b)
	{
		if(b&1)
		{
			yaoyuan = (yaoyuan+a)%mod;
		}
		a = (a+a)%mod;
		b>>=1; 
	}
	return yaoyuan;
}

//
ll PowMod(ll a, int m)
{
    if (a == 1 || m == 0) return 1;
    if (a == 0) return 0;
    ll res = 1;
    while (m)
    {
        if (m&1) res = res*a % mod;
        a = a*a % mod;
        m >>= 1;
    }
    return res;
}


long long quick_pow(ll a,int b)
{
//	printf("pow %I64d %I64d\n",a,b);
	if (a == 1 || b == 0) return 1;
    if (a == 0) return 0;
	ll yaoyuan = 1;
	while(b)
	{
		if(b&1)
		{
			yaoyuan = (yaoyuan*a)%mod;
		}
		a = (a*a)%mod;
		b>>=1; 
	}
	return yaoyuan;
}


int main()
{

	Mobius();
	
	
    long long n,x,y;
    int t;
    int TT = 1;
    
    
    scanf("%d",&t); 
    while(t--)
    {
    	
	memset(sum,0,sizeof(sum));
	
      	ll mina = INT_MAX;
    	ll maxa = 0;
        scanf("%I64d",&n);
        ll aaa = 1;
        int F = 0;
        for(ll i = 0;i<n;i++)
        {
            scanf("%I64d",&a);
            if(a == 1)
            {
                F = 1;
            }
           
            sum[a]++;
            mina = min(mina,a);
            maxa = max(maxa,a);
         } 
        if(F)
        {
            printf("Case #%d: %I64d\n",TT++,0);
            continue;
        }         
        for(ll i = 1;i<=maxa;i++)
        {
            sum[i] += sum[i-1];
         } 
        
         long long ans = (long long)0;
      //   printf("%d %d \n",mina,maxa);
        for(int i = 2; i <= mina;i++)
    	{
    		ll sum_ = mu[i];
    		if(!sum_)
    		{
    			continue;
			}
    		int braek = 0;
    		for(int j = 1;;j++)
    		{
    			int k = (j+1)*i-1;
    			if(k>maxa)
    			{
    				k = maxa;
				}
				if((sum[k]-sum[(j)*i-1]))
				{
					sum_ = (sum_*(quick_pow(j,sum[k]-sum[(j)*i-1])%mod))%mod;
				}
    			
    	//		printf("%d  sum_ ? %I64d,%I64d-%I64d %d %d\n",i,sum_,sum[(j+1)*i-1],sum[(j)*i-1],(j+1)*i-1,(j)*i-1);
    			if(((j+1)*i-1) >= maxa)
    			{
    				break;
				}
				
				
			}
		//	printf("sum_ %I64d\n",sum_);
			ans = ((ans + sum_)%mod);
		}
		 printf("Case #%d: %I64d\n",TT++,(ans+mod)%mod);
    }
/*
 此时每个k的贡献 = 1^(sum[2k-1]-sum[k-1]) * 2^(sum[3k-1]-sum[2k-1]) * 3^(sum[4k-1]-sum[3k-1]) ...
    
2
4
4 4 4 4
5 
2 3 4 2 3


HUAWEI GRA-UL10

A7JGK16607904435

8693810258060447

10267141

1781832231791816

*/    
    
 } 
