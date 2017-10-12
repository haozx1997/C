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

const ll mod = 1e9+7;
char s[10010];

char q[505][1010];
int h[1010];
int nn;




int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		nn = 0;
		memset(q,0,sizeof(q));
		int len = strlen(s);
		int now = 0;
		int qs = 0;
		for(int i = 0; i < len;i++)
		{
			if(s[i] == '(')
			{
				
				if(now == 0)
				{
					qs = i+1;
				}
				else
				{
					
				}
				
			}
			else if(s[i] == ')')
			{
				if(now == 0)
				{
					s[i] = 0;
					strcpy(q[nn],&s[qs]);
					now++;
				}
				else
				{
						
					h[nn] = s[i-1]-'0';
					if(nn%2)
					{
						for(int j = qs-1;j<=i;j++)
						{
							s[j] = '@';
						}
					}
					else
					{
						for(int j = qs-1;j<=i;j++)
						{
							s[j] = '!';
						}
					}
					nn++;
					now = 0;
				}
			}
		}
//		for(int i = 0;i < nn;i++)
//		{
//			printf("%d %s %d\n",i,q[i],h[i]);
//		}
		ll ans = 0;
		now = 0;
		for(int i = 0;i < len;i++)
		{
			if(s[i]<='9'&&s[i]>='0')
			{
				ans = ans*10+(s[i]-'0');
				ans %= mod;
			}
			else if(s[i] == '@')
			{
				int lenq = strlen(q[now]);
				for(int j = 0;j < h[now];j++)
				{
					
					for(int jj = 0;jj < lenq;jj++)
					{
						ans = ans*10+(q[now][jj]-'0');
						ans %= mod;
					}
				}
				i += (lenq+6);
				i--;
				now++;
			}
			else
			{
				int lenq = strlen(q[now]);
				for(int j = 0;j < h[now];j++)
				{
					
					for(int jj = 0;jj < lenq;jj++)
					{
						ans = ans*10+(q[now][jj]-'0');
						ans %= mod;
					}
				}
				i += (lenq+6);
				i--;
				now++;
			}
			
		}
		ans%=mod;
		printf("%I64d\n",ans);
		
	}





 return 0;
}


