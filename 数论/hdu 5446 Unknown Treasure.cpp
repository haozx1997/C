#include<stdio.h>
#define LL long long
#define ll long long

#define N 10001000

const int maxn = 1e5 + 5;

ll fac[maxn], inv[maxn];

ll pow_mod(ll a, int n, int mod) {
    ll ret = 1;
    while (n) {
        if (n&1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

void init(int n) {
    fac[0] = 1;
    for (int i = 1; i < n; i++) fac[i] = fac[i-1] * i % n;
    inv[n-1] = pow_mod(fac[n-1], n-2, n);
    for (int i = n - 2; i >= 0; i--) inv[i] = inv[i+1] * (i+1) % n;
}

ll C (int n, int m, int mod) {
    if (m > n || m < 0 || n < 0) return    0;
    return fac[n] * inv[m] % mod * inv[n-m] % mod;
}

ll lucas(ll n, ll m, int mod) {
    if (m == 0) return 1;
 //   printf("%lld %lld %d\n",lucas(n / mod, m / mod, mod) , C(n % mod, m % mod, mod) , mod);
    return lucas(n / mod, m / mod, mod) * C(n % mod, m % mod, mod) % mod;
}
long long q_mul( long long a, long long b, long long mod ) //快速计算 (a*b) % mod
{
    long long ans = 0;  // 初始化
    while(b)                //根据b的每一位看加不加当前a
    {
        if(b & 1)           //如果当前位为1
        {
            b--;
            ans =(ans+ a)%mod;   //ans+=a
        }
        b /= 2;                         //b向前移位
        a = (a + a) % mod;          //更新a

    }
    return ans;
}

__int64 result,d;
int flag;
__int64 gcd(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
   __int64 t,ret;
   if(!b)
   {
     x = 1;
     y = 0;
     return a;
   }
   ret=gcd(b,a%b,x,y);
   t=x;
   x=y;
   y=t-a/b*y;
   return ret;
}
void fun(__int64 a,__int64 b,__int64 n)
{
   __int64 x,y;
   d=gcd(a,n,x,y);
   if(b%d!=0)
    flag =1;
    result=(x*(b/d)%n+n)%n;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL n,m,p[50];
		int k;
		scanf("%I64d%I64d%d",&n,&m,&k);
		for(int i = 0;i < k;i++)
		{
			scanf("%I64d",&p[i]);
		}
		LL b[50];
		for(int i = 0;i < k;i++)
		{
			init(p[i]);
			b[i] = lucas(n,m,p[i]);
		 }
		for(int i = 0;i < k;i++)
		{
			printf("%d %I64d\n",i,b[i]);
		 }

		LL ans = fun(b,p,k);
		printf("%I64d\n",ans);

	}
}
