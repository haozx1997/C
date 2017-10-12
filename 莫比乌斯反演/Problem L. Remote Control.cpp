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
 1 2 3 ↑
4 5 6 ↓
7 8 9
-- 0

 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxx = 1010;
const ll mod = (ll)1e9+7;
int main()
{
	int a[100];
	int u,d,_;
	while(~scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d",&a[1],&a[2],&a[3],&u,&a[4],&a[5],&a[6],&d,&a[7],&a[8],&a[9],&_,&a[0]))
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if(n == m)
		{
			printf("0\n");
			continue;
		}
		int ud = u*10+d;
		int sum = 0;
		for(int i = 0;i < 10;i++)
		{
			sum += a[i];
		}
		int z,minz;
		switch(ud)
		{
			case 0://都坏
				if(!(m/10))//个位
				{
					if(a[m] == 0)
					{
						printf("-1\n");
						break;
					}
					else
					{
						printf("1\n");
						break;
					}
				 }
				else//两位 
				{
					int n1,n2;
					n1 = m/10;
					n2 = m%10;
					if(a[n1]==0||a[n2] == 0||_ == 0)
					{
						printf("-1\n");
						break;
					}
					else
					{
						printf("3\n");
						break;
					}
				}  
				break;
			case 1://u坏
				z = (n-m+100)%100;
				if(!sum)
				{
					printf("%d\n",z);
					break;
				}
				minz = 999;
				for(int i = 0;i < 100;i++)
				{
					int zz;
					if(i<10)//个位
					{
						if(a[i] == 0)
						{
							continue;
						}
						zz = 1+((i-m+100)%100);
					} 
					else
					{
						int n1,n2;
						n1 = i/10;
						n2 = i%10;
						if(a[n1]==0||a[n2] == 0||_ == 0)
						{
							continue;
						}
						zz = 3+((i-m+100)%100);
						
					}
					minz = min(minz,zz);
				}
				printf("%d\n",min(minz,z));
				
				break;
			case 10: //d坏
				z = (m-n+100)%100;
				if(!sum)
				{
					printf("%d\n",z);
					continue;
				}
				minz = 999;
				for(int i = 0;i < 100;i++)
				{
					int zz;
					if(i<10)//个位
					{
						if(a[i] == 0)
						{
							continue;
						}
						zz = 1+((m-i+100)%100);
					} 
					else
					{
						int n1,n2;
						n1 = i/10;
						n2 = i%10;
						if(a[n1]==0||a[n2] == 0||_ == 0)
						{
							continue;
						}
						zz = 3+((m-i+100)%100);
						
					}
					minz = min(minz,zz);
				}
				printf("%d\n",min(minz,z));
				
				break;
			case 11://都好 
				z = min((m-n+100)%100,(n-m+100)%100);
				if(!sum)
				{
					printf("%d\n",z);
					continue;
				}
				minz = 999;
				for(int i = 0;i < 100;i++)
				{
					int zz;
					if(i<10)//个位
					{
						if(a[i] == 0)
						{
							continue;
						}
						zz = 1+((m-i+100)%100);
					} 
					else
					{
						int n1,n2;
						n1 = i/10;
						n2 = i%10;
						if(a[n1]==0||a[n2] == 0||_ == 0)
						{
							continue;
						}
						zz = 3+((m-i+100)%100);
						
					}
					minz = min(minz,zz);
				}
				z = min(minz,z);
				for(int i = 0;i < 100;i++)
				{
					int zz;
					if(i<10)//个位
					{
						if(a[i] == 0)
						{
							continue;
						}
						zz = 1+((i-m+100)%100);
					} 
					else
					{
						int n1,n2;
						n1 = i/10;
						n2 = i%10;
						if(a[n1]==0||a[n2] == 0||_ == 0)
						{
							continue;
						}
						zz = 3+((i-m+100)%100);
				//		printf("%d %d\n",i,zz);
					}
					minz = min(minz,zz);
				}
				printf("%d\n",min(minz,z));
				
				break;
				 
		}
		
	}
/*
1 1 1 1
1 1 1 1
1 1 1
1 1
23 52

0 0 1 1
1 1 1 1
1 1 1
1 1
23 52

*/



 return 0;
}


