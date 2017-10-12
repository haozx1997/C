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
const int maxn = 4000;
const ll mod = (ll)1e9+7;

int a[200010][3];
int b[200010];
int tree[4000];
int lowbit(int x){return x & (-x);}
int get(int x){int ret = 0;for(int i = x ; i > 0; i -= lowbit(i))ret += tree[i];return ret;}
void update(int x,int val){for(int i = x; i < maxn; i += lowbit(i))tree[i] += val;}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(tree,0,sizeof(tree));
		int an = 0;
		int bn = 0;
		
		for(int i = 0; i < n;i++)
		{
			int aa,bb;
			scanf("%d",&aa);
			switch(aa)
			{
				case 5 :
					a[an++][0] = aa;
					break;
				case 1 :
				case 3 :
					scanf("%d",&bb);
					a[an][0] = aa;
					a[an++][1] = bb;
					break;
				case 2 :
				case 4 :
				case 6 :
					b[bn++] = aa;
					break;
			}
		}
		int ans = 0;
		int notake = 0;
		for(int i = 0;i < bn;i++)
		{
			switch(b[i])
			{
				case 2:
					ans += notake;
					notake = 0;
					break;
				case 4:
					notake = 0;
					break;
				case 6:
					notake++;
					break;
					
			}
		}
		int x;
		int now = 0;
//		for(int i = 0;i <an;i++)
//		{
//			printf("%d %d %d \n",i,a[i][0],a[i][1]);
//		}
		for(int i = 0;i < an;i++)
		{
			switch(a[i][0])
			{
				case 1:
					now = a[i][1];
					x = get(a[i][1] - 1);
					ans+=x;
//					printf("X  %d %d %d\n",i,x,a[i][1]);
//					for(int i  =0 ; i  <10;i++)
//					{
//						printf("%d ",get())
//					}
					break;
				case 3:
					if(now>a[i][1])
					{
						ans++;
					}
					else
					{
//						printf("up %d %d\n",i,a[i][1]);
						update(a[i][1],1);
					}
					
					
					break;
				case 5:
					memset(tree,0,sizeof(tree));
					
					break;
					
			}
		}
		printf("%d\n",ans);
		
		
		
	 } 




 return 0;
}


