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



long long tr(int xx,int yy,int zz)
{
	return (long long)xx+((long long)yy*1000)+((long long)zz*1000000);
}
vector<long long>mm;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		
		mm.clear();
		int n,m;
		scanf("%d%d",&n,&m);
		char c1,c2;
		int n1,n2;
		
		if(m == 0)
		{
			printf("0\n");
			continue;
		}
		for(int i = 0; i < m;i++)
		{
			char s[1000];
			scanf("%s",s);

			int st = 0;
			int len =strlen(s);
			for(int j = 0;j < len;j++)
			{
				if(s[j] == ',')
				{
					st = j;
					s[j] = 0;
					break;
				}
			}
			c1 = s[0];
			char* nn1;
			nn1 = &s[2];
			sscanf(nn1,"%d",&n1);
			st++;
			c2 = s[st];
			char* nn2;
			nn2 = &s[st+2];
			sscanf(nn2,"%d",&n2);
			
			
			
			
			switch(c1)
			{
				case 'X':
					
					{
						
						if(c2 == 'Y')
						{
							for(int i = 1;i <= n;i++)
							{
								mm.push_back(tr(n1,n2,i));
							}
						}
						else
						{
							for(int i = 1;i <= n;i++)
							{
								mm.push_back(tr(n1,i,n2));
							}
						}
					}
					break;
					
				case 'Y':
				
					{
						
						if(c2 == 'X')
						{
							for(int i = 1;i <= n;i++)
							{
								mm.push_back(tr(n2,n1,i));
							}
						}
						else
						{
							for(int i = 1;i <= n;i++)
							{
								mm.push_back(tr(i,n1,n2));
							}
						}
					}
					
					break;
				case 'Z':
					
					{
						
						if(c2 == 'X')
						{
							for(int i = 1;i <= n;i++)
							{
								mm.push_back(tr(n2,i,n1));
							}
						}
						else
						{
							for(int i = 1;i <= n;i++)
							{
								mm.push_back(tr(i,n2,n1));
							}
						}
					}
					
					break;
					
			}
			
		
		}
	//	printf("suze %d \n",mm.size());
		sort(mm.begin(),mm.end());
		int ans = unique(mm.begin(),mm.end())-mm.begin();
		printf("%d\n",ans);
	}




 return 0;
}


