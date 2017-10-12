#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1010;
const ll mod = (ll)1e9+7;
const ll MAXN=100000+50;
const ll INF=0x7fffffff;

ll miu[MAXN] ;


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

long long quick_pow(ll a,ll b)
{
	ll yaoyuan = 1;
	while(b)
	{
		if(b&1)
		{
			yaoyuan = quick_mul(yaoyuan,a)%mod;
		}
		a = quick_mul(a,a)%mod;
		b>>=1; 
	}
	return yaoyuan;
}


void get_miu()
{
    ll prime[MAXN],pnum=0;
    miu[1]=1;
    for (ll i=2;i<maxn;i++) miu[i]=-INF;
    for (ll i=2;i<maxn;i++)
    {
        if (miu[i]==-INF)
        {
            miu[i]=-1;
            prime[++pnum]=i;
        }
        for (ll j=1;j<=pnum;j++)
        {
            if (i*prime[j]>=maxn) break;
            if (i%prime[j]==0) miu[i*prime[j]]=0;
                else miu[i*prime[j]]=-miu[i];
        }
    }
}
ll a[100010];

ll b[100010];



int main()
{
	memset(miu,0,sizeof(miu));
	
	get_miu();
	
	
    ll n,x,y;
    int t;
    int TT = 1;
    ll mina = INT_MAX;
    scanf("%d",&t); 
    while(t--)
    {
       
        scanf("%I64d",&n);
        ll aaa = 1;
        int F = 0;
        for(ll i = 0;i<n;i++)
        {
            scanf("%I64d",&a[i]);
            if(a[i] == 1)
            {
                F = 1;
            }
            aaa = aaa*a[i];
            aaa = aaa%mod;
            mina = min(mina,a[i]);
         } 
        if(F)
        {
            printf("Case #%d: %I64d\n",TT++,0);
            continue;
        }         
         
        
         long long ans = (long long)0;
        for(int i = 1; i <= mina;i++)
    	{
    		ll sum = miu[i];
    		sum = ((sum*aaa)%mod);
    		sum = ((sum*quick_pow(quick_pow(i,n),mod-2))%mod);
    		
    		
    		
			ans = ((ans+sum)%mod);
		}
		
		 
        
        printf("Case #%d: %I64d\n",TT++,(aaa-ans+mod)%mod)
    		
    }
/*

2
4
4 4 4 4
5 
2 3 4 2 3

*/    
    
 } 
