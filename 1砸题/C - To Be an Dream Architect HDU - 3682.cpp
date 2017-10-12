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

int x[1010],y[1010],z[1010];
map<long long,bool>mm;
long long tr(int xx,int yy,int zz)
{
	return (long long)xx+((long long)yy*1000)+((long long)zz*1000000);
}
map<string,bool>pa;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		mm.clear();
		pa.clear();
		int n,m;
		scanf("%d%d",&n,&m);
		char c1,c2;
		int n1,n2;
		int ans = 0;
		if(m == 0)
		{
			printf("0\n");
			continue;
		}
		for(int i = 0; i < m;i++)
		{
	//		printf("%d i =-= %d \n",m,i);
			char s[1000];
			scanf("%s",s);
			string ss = s ;
			if(pa[ss])
			{
				continue;
			}
			
	//		printf("%s?\n",s);
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
		//	printf("st %d %d %c %c\n",st,len,s[0],s[st]);
			c2 = s[st];
			char* nn2;
			nn2 = &s[st+2];
			sscanf(nn2,"%d",&n2);
			char s2[1000];
			sprintf(s2,"%c=%d,%c=%d",c2,n2,c1,n1);
			string ss2 = s2;
			if(pa[ss2])
			{
				continue;
			}
			else
			{
				pa[ss2] = 1;
				pa[ss] = 1;
				
			}
	//		printf("	%c=%d,%c=%d\n",c1,n1,c2,n2);
			
			
			ans += n;
			switch(c1)
			{
				case 'X':
					if(x[n1])
					{
						ans--;
						if(c2 == 'Y')
						{
							if(mm[tr(n1,n2,x[n1])])
							{
								ans--;
							}
							else
							{
								mm[tr(n1,n2,x[n1])] = 1;
							}
						}
						else
						{
							if(mm[tr(n1,x[n1],n2)])
							{
								ans--;
							}
							else
							{
								mm[tr(n1,x[n1],n2)] = 1;
							}
						}
					}
					x[n1] = n2;
					break;
				case 'Y':
					if(y[n1])
					{
						ans--;
						if(c2 == 'X')
						{
							if(mm[tr(n2,n1,y[n1])])
							{
								ans--;
							}
							else
							{
								mm[tr(n2,n1,y[n1])] = 1;
							}
						}
						else
						{
							if(mm[tr(y[n1],n1,n2)])
							{
								ans--;
							}
							else
							{
								mm[tr(y[n1],n1,n2)] = 1;
							}
						}
					}
					y[n1] = n2;
					break;
				case 'Z':
					if(z[n1])
					{
						ans--;
						if(c2 == 'X')
						{
							if(mm[tr(n2,z[n1],n1)])
							{
								ans--;
							}
							else
							{
								mm[tr(n2,z[n1],n1)] = 1;
							}
						}
						else
						{
							if(mm[tr(z[n1],n2,n1)])
							{
								ans--;
							}
							else
							{
								mm[tr(z[n1],n2,n1)] = 1;
							}
						}
					}
					z[n1] = n2;
					break;
					
			}
			swap(c1,c2);
			swap(n1,n2);
	//		printf("???$$$$%c$$$$=%d,%c=%d\n",c1,n1,c2,n2);
	//		printf("???$$$$%c$$$$=%d,%c=%d\n",c1,n1,c2,n2);
	//		printf("???$$$$%c$$$$=%d,%c=%d\n",c1,n1,c2,n2);
//			if(c1 == 'Z')
//			{
//				puts("123123");
//			}
			if(c1 == 'X')
			{
				if(x[n1])
					{
						ans--;
						if(c2 == 'Y')
						{
							if(mm[tr(n1,,n2x[n1])])
							{
								ans--;
							}
							else
							{
								mm[tr(n1,,n2x[n1])] = 1;
							}
						}
						else
						{
							if(mm[tr(n1,x[n1],n2)])
							{
								ans--;
							}
							else
							{
								mm[tr(n1,x[n1],n2)] = 1;
							}
						}
					}
					x[n1] = n2;
			}
			else if(c1 == 'Y')
			{
				if(y[n1])
					{
						ans--;
						if(c2 == 'X')
						{
							if(mm[tr(n2,n1,y[n1])])
							{
								ans--;
							}
							else
							{
								mm[tr(n2,n1,y[n1])] = 1;
							}
						}
						else
						{
							if(mm[tr(y[n1],n1,n2)])
							{
								ans--;
							}
							else
							{
								mm[tr(y[n1],n1,n2)] = 1;
							}
						}
					}
					y[n1] = n2;
			}
			else if(c1 == 'Z')
			{
				//printf("%d %c %d\n",n1,c1,z[n1]);
					if(z[n1])
					{
						ans--;
						if(c2 == 'X')
						{
							if(mm[tr(n2,z[n1],n1)])
							{
								ans--;
							}
							else
							{
								mm[tr(n2,z[n1],n1)] = 1;
							}
						}
						else
						{
							if(mm[tr(z[n1],n2,n1)])
							{
								ans--;
							}
							else
							{
								mm[tr(z[n1],n2,n1)] = 1;
							}
						}
					}
					z[n1] = n2;
			}
			
		
		}
//		for(int i= 0;i < 5;i++)
//		{
//			printf("%d %d\n",i,y[i]);
//		}
		printf("%d\n",ans);
	}




 return 0;
}


