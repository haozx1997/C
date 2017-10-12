/**
 *               ii.                                         ;9ABH,
 *              SA391,                                    .r9GG35&G
 *              &#ii13Gh;                               i3X31i;:,rB1
 *              iMs,:,i5895,                         .5G91:,:;:s1:8A
 *               33::::,,;5G5,                     ,58Si,,:::,sHX;iH1
 *                Sr.,:;rs13BBX35hh11511h5Shhh5S3GAXS:.,,::,,1AG3i,GG
 *                .G51S511sr;;iiiishS8G89Shsrrsh59S;.,,,,,..5A85Si,h8
 *               :SB9s:,............................,,,.,,,SASh53h,1G.
 *            .r18S;..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....,,.1H315199,rX,
 *          ;S89s,..,,,,,,,,,,,,,,,,,,,,,,,....,,.......,,,;r1ShS8,;Xi
 *        i55s:.........,,,,,,,,,,,,,,,,.,,,......,.....,,....r9&5.:X1
 *       59;.....,.     .,,,,,,,,,,,...        .............,..:1;.:&s
 *      s8,..;53S5S3s.   .,,,,,,,.,..      i15S5h1:.........,,,..,,:99
 *      93.:39s:rSGB@A;  ..,,,,.....    .SG3hhh9G&BGi..,,,,,,,,,,,,.,83
 *      G5.G8  9#@@@@@X. .,,,,,,.....  iA9,.S&B###@@Mr...,,,,,,,,..,.;Xh
 *      Gs.X8 S@@@@@@@B:..,,,,,,,,,,. rA1 ,A@@@@@@@@@H:........,,,,,,.iX:
 *     ;9. ,8A#@@@@@@#5,.,,,,,,,,,... 9A. 8@@@@@@@@@@M;    ....,,,,,,,,S8
 *     X3    iS8XAHH8s.,,,,,,,,,,...,..58hH@@@@@@@@@Hs       ...,,,,,,,:Gs
 *    r8,        ,,,...,,,,,,,,,,.....  ,h8XABMMHX3r.          .,,,,,,,.rX:
 *   :9, .    .:,..,:;;;::,.,,,,,..          .,,.               ..,,,,,,.59
 *  .Si      ,:.i8HBMMMMMB&5,....                    .            .,,,,,.sMr
 *  SS       :: h@@@@@@@@@@#; .                     ...  .         ..,,,,iM5
 *  91  .    ;:.,1&@@@@@@MXs.                            .          .,,:,:&S
 *  hS ....  .:;,,,i3MMS1;..,..... .  .     ...                     ..,:,.99
 *  ,8; ..... .,:,..,8Ms:;,,,...                                     .,::.83
 *   s&: ....  .sS553B@@HX3s;,.    .,;13h.                            .:::&1
 *    SXr  .  ...;s3G99XA&X88Shss11155hi.                             ,;:h&,
 *     iH8:  . ..   ,;iiii;,::,,,,,.                                 .;irHA
 *      ,8X5;   .     .......                                       ,;iihS8Gi
 *         1831,                                                 .,;irrrrrs&@
 *           ;5A8r.                                            .:;iiiiirrss1H
 *             :X@H3s.......                                .,:;iii;iiiiirsrh
 *              r#h:;,...,,.. .,,:;;;;;:::,...              .:;;;;;;iiiirrss1
 *             ,M8 ..,....,.....,,::::::,,...         .     .,;;;iiiiiirss11h
 *             8B;.,,,,,,,.,.....          .           ..   .:;;;;iirrsss111h
 *            i@5,:::,,,,,,,,.... .                   . .:::;;;;;irrrss111111
 *            9Bi,:,,,,......                        ..r91;;;;;iirrsss1ss1111
 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxx = 1010;
const ll mod = (ll)1e9+7;
ll s[maxx][maxx]; 


const ll Mod = 1000000007;
ll pow_mod(ll x,ll n,ll mod_val)
{
    ll ans = 1;
    ll t = x % mod_val;
    while(n)
    {
        if(n & 1)
        ans = ans * t % mod_val;
        n >>= 1;
        t = t * t % mod_val;
    }
    return ans;
}
ll C(ll n,ll m,ll p)    
{
    if(n < m)
        return 0;
    ll ans = 1;
    for(ll i = 1; i <= m; i ++)
    {
        ans = ans * (n + 1 - i) % p;
        ll x = pow_mod(i%p,p - 2,p);
        ans = ans * x % p;
    }
    return ans;
}
ll Lucas(ll n,ll m,ll p)
{
    if(m == 0)
        return 1;
    return C(n%p,m%p,p) * Lucas(n/p,m/p,p);
}


void init()
{
	memset(s,0,sizeof(s));
	for(int i = 0;i <maxx;i++ )
	{
		s[i][0] = 0ll;
		s[i][i] = s[i][1] = 1ll;
		
	}
	for(int i = 1;i < maxx;i++)
	{
		for(int j = 0;j < i;j++)
		{
			s[i][j] = (s[i-1][j-1]+((ll)j*s[i-1][j]%mod))%mod;
		}
	}
	
//	for(int i = 0;i <= maxx;i++)
//	{
//		for(int j = 0;j <= i;j++)
//		{
//			printf("%d ",s[i][j]);
//		}
//		puts("");
//	}
	
	
	
}


int main()
{
	init();
	int n,r,k,m;
	while(~scanf("%d%d%d%d",&n,&r,&k,&m))
	{
		ll stirling = 0ll;
		for(int i = 0;i <= m;i++)
		{
			stirling += s[r][i];
			stirling = stirling%mod;
		}
		ll ans = Lucas((n-(r-1)*(k-1)),r,mod);
	//	printf("%I64d\n",ans);
	//	printf("%I64d\n",stirling);
		ans = ans%mod;
		ans = (ans*stirling)%mod;
		printf("%I64d\n",ans);
		
	}
	




 return 0;
}


