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
#include<stdio.h>
#include<string.h>
#include<algorithm>

#define ll long long
using namespace std;
const int maxx = 10100;
const int MAXN=10100;
const int mod = 10007;
const int INF=0x7fffffff;

int miu[MAXN] ;

void get_miu(int maxn)
{
    int prime[MAXN],pnum=0;
    miu[1]= 1;
    for (int i=2;i<maxn;i++) miu[i]=-INF;
    for (int i=2;i<maxn;i++)
    {
        if (miu[i]==-INF)
        {
            miu[i]=-1;
            prime[++pnum]=i;
        }
        for (int j=1;j<=pnum;j++)
        {
            if (i*prime[j]>=maxn) break;
            if (i%prime[j]==0) miu[i*prime[j]]=0;
                else miu[i*prime[j]]=-miu[i];
        }
        
    }
}

int a[20000];

int num[20000];
int f[20000];

ll solve()
{
	memset(f,0,sizeof(f));
	for(int i = 1;i < maxx;i++)
	{
		for(int j = i;j < maxx;j+=i)
		{
			f[i] += num[j];
		}//puts("asd");
	}
	ll ans = 0ll;
	for(int i = 1;i < maxx;i++)
	{
		int now = f[i];
		if(now<4)
		{
			continue;
		}
		ans += (long long)miu[i]*(now)*(now-1)*(now-2)*(now-3)/24;
	}
	
	return ans;
	
}


int main()
{
	int n;
	get_miu(maxx);
	while(~scanf("%d",&n))
	{
		memset(num,0,sizeof(num));
		int maxn = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
			num[a[i]]++;
		}
		
		if(n<4)
		{
			printf("0\n");
		}
		else
		{
			printf("%lld\n",solve());
		}
		
	 } 





 return 0;
}


