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
 
5

2 1
200 6
100 5

2 2
200 6
100 5

2 1
1 1
1 1

2 2
1 1
1 1

8 5
5 7
6 6
6 8
7 5
7 9
8 6
8 8
9 7

10 3 
1 2
1 1
1 4
1 5
2 3 
2 6
2 7
8 8
8 9 
8 7

10 4
1 2
1 1
1 4
1 5
2 3 
2 6
2 7
8 8
8 9 
8 7
10 2 
1 2
1 1
1 4
1 5
2 3 
2 6
2 7
8 8
8 9 
8 7
 
 
 */
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>

#define ll long long
using namespace std;
const int maxx = 1010;
const ll mod = (ll)1e9+7;

struct node
{
	int x,y;
	
	bool operator <(const node &xx)const
	{
		if(y == xx.y)
		{
			return x < xx.x;
		}
		return y < xx.y;
	}
}p[300];


int n,m;
set<int>S;
set<int>::iterator it;

int s[300];

int main()
{
	int T;
	//scanf("%d",&T);
	while(1)
	{
		memset(p,0,sizeof(p));
		scanf("%d%d",&n,&m);
		for(int i = 0;i < n;i++)
		{
			
			scanf("%d%d",&p[i].x,&p[i].y);
			S.insert(p[i].x);
		}
		if(m == 1)
		{
			printf("4\n");
			continue;
		}
		sort(p,p+n);
		for(int i = 0;i < n;i++)
		{
			printf("%d %d\n",p[i].x,p[i].y);
			
		}
		int sn = 0;
		for(it = S.begin();it!=S.end();it++)
		{
			s[sn++] = *it;
		}
//		for(int i = 0;i < sn;i++)
//		{
//			printf("%d ",s[i]);
//		}
		int w = 0;
		int ans = INT_MAX;
		for(int i = 0;i < sn;i++)
		{
			for(int j = i;j < sn;j++)
			{
				w = 2;
				int be=  0,bei = 0;
				int in = 0;
				int en = 0,eni = 0;
				be = p[bei].y;
				en = p[eni].y;
				
			//	printf("%d %d\n",en,be);
				while(1)
				{
					printf("in %d %d %d  %d  %d\n",i,j,s[i],s[j],in);
					if(in < m)
					{
						
						//eni++;
						en = p[eni].y;
					//	printf("?%d %d\n",eni,p[eni].y);
							
						for(;p[eni].y == en&&eni<n;eni++)
						{
							printf("	%d %d %d \n",eni,p[eni].x,p[eni].y);
							if(p[eni].x<=s[j]&&p[eni].x>=s[i])
							{
								printf("		%d %d %d \n",eni,p[eni].x,p[eni].y);
								in++;
							}
							
						}
					//	printf("iiii %d %d\n",bei,eni);
						if(eni>=n)
						{
							break;
						}
					}
					else
					{
						int now = (p[eni].y - p[bei].y+2)*(p[eni].x - p[bei].x+2);
						if(ans>now)
						{
							ans = now;
							printf("%d %d %d %d\n",p[bei].x,p[bei].y,p[eni].x,p[eni].y);
						}
						
						bei++;
						be = p[bei].y;
						for(;p[bei].y == be;bei++)
						{
							if(p[bei].x<=s[j]&&p[bei].x>=s[i])
							{
								in--;
							}
							
						}
					}
				}
			}
			
		}
	
		
		
		printf("%d\n",ans);
		
	}




 return 0;
}


