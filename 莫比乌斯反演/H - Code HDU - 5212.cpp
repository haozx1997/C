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
const int mod = 10007;

int gcd(int a,int b)
{
	return !b ? a : gcd(b,a%b); 
}



int a[20000];

int f[20000];
int factor[20000];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(factor,0,sizeof(factor));
		int maxn = 0;
		for(int i = 0;i < n;i++)//输入的时候把每个数的因子保存到factor[]; 
		{
			scanf("%d",&a[i]);
			maxn = max(maxn,a[i]);
			for(int j = 1;j*j <= a[i];j++)
			{
				if(!(a[i]%j))
				{
					factor[j]++;
					if((a[i]/j)!=j)
					{
						factor[a[i]/j]++;
					}
				}
			}
		}
		//f[i]为 公因子只是i的数 的对数(Aka. cp)("对三，要不起 "的对，不是log)
		//  注意这个  只^ 字  
		//gcd是最大,所以 f[i] = factor[i]*factor[i]后要减去  公因子是i倍数的f[] 
		int ans = 0;
		for(int i = maxn;i >= 1;i--)
		{
			f[i] = factor[i]*factor[i]%mod;
			for(int j = i*2;j <= maxn;j+=i)//因为这个for 用来减 
			{
				f[i] = ((f[i]-f[j]+mod)%mod);
			}
			int now = i*(i-1)%mod;// gcd(a[i],a[j])*(gcd(a[i],a[j])-1)
			ans = ((ans + f[i]*now)%mod);// f[i]*now就是(gcd为i的cp的数量)*(  gcd(a[i],a[j])*(gcd(a[i],a[j])-1)   ) 
			
		}
		printf("%d\n",ans);
		
	 } 





 return 0;
}


