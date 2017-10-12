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

char s[10][10];
int c[10][10];

//void se()
//{
//	puts("!!!!!");
//	{
//		for(int i = 0;i < 4;i++)
//		{
//			for(int j = 0;j < 4;j++)
//			{
//				printf("%d",c[i][j]);
//			}
//			puts("");
//		}
//	}
//	puts("!!!!!");
//}

set<int> SS[10][10];

int main()
{
	int T,TT = 1;
	scanf("%d",&T);
	while(T--)
	{
		for(int i = 0;i < 4;i++)
		{
			scanf("%s",s[i]);
		}
		printf("Case #%d:\n",TT++);
		for(int i = 0;i < 4;i++)
		{
			for(int j = 0;j < 4;j++)
			{
				if(s[i][j] == '*')
				{
					c[i][j] = 0;
				}
				else
				{
					c[i][j] = s[i][j]-'0';
				}
			}
		}
//		for(int i = 0;i < 4;i++)
//		{
//			for(int j = 0;j < 4;j++)
//			{
//				printf("%d",c[i][j]);
//			}
//			puts("");
//		}
//		int out = 0;
//		for(int II = 0;II < 100;II++)
//		{
//			out = 0;
//			for(int i = 0;i < 4;i++ )
//			{
//				int n0 = 0;	
//				int j0;
//				for(int j = 0;j < 4;j++)
//				{
//					if(c[i][j] == 0)
//					{
//						n0++;
//						j0 = j;
//					}//
//				}
//				if(n0 == 1)
//				{
//					c[i][j0] = 10 - c[i][0] - c[i][1] - c[i][2] - c[i][3];
//					out++;
//				}
//				if(n0 == 0)
//				{
//					out++;
//				}
//			}
//		
//			for(int i = 0;i < 4;i++ )
//			{
//				int n0 = 0;	
//				int j0;
//				for(int j = 0;j < 4;j++)
//				{
//					if(c[j][i] == 0)
//					{
//						n0++;
//						j0 = j;
//					}
//				}
//				if(n0 == 1)
//				{
//					c[j0][i] = 10 - c[0][i] - c[1][i] - c[2][i] - c[3][i];
//					out++;
//				}
//				if(n0 == 0)
//				{
//					out++;
//				}
//			}
//			
//			{
//				int n0 = 0;
//				int j0;
//				if(c[0][0] == 0)
//				{
//					n0++;
//					j0 = 0;
//				}
//				if(c[0][1] == 0)
//				{
//					n0++;
//					j0 = 1;
//				}
//				if(c[1][0] == 0)
//				{
//					n0++;
//					j0 = 10;
//				}
//				if(c[1][1] == 0)
//				{
//					n0++;
//					j0 = 11;
//				}
//				if(n0 == 1)
//				{
//					c[j0/10][j0%10]= 10-c[0][0]-c[0][1]-c[1][0]-c[1][1];
//				}
//				if(n0 == 0)
//				{
//					out++;
//				}
//			}
//			//se();
//			{
//				int n0 = 0;
//				int j0;
//				if(c[0][2] == 0)
//				{
//					n0++;
//					j0 = 2;
//				}
//				if(c[0][3] == 0)
//				{
//					n0++;
//					j0 = 3;
//				}
//				if(c[1][2] == 0)
//				{
//					n0++;
//					j0 = 12;
//				}
//				if(c[1][3] == 0)
//				{
//					n0++;
//					j0 = 13;
//				}
//				if(n0 == 1)
//				{
//					c[j0/10][j0%10] = 10-c[0][2]-c[0][3]-c[1][2]-c[1][3];
//				}
//				if(n0 == 0)
//				{
//					out++;
//				}
//			}//se();puts("?");
//			{
//				int n0 = 0;
//				int j0;
//				if(c[2][0] == 0)
//				{
//					n0++;
//					j0 = 20;
//				}
//				if(c[2][1] == 0)
//				{
//					n0++;
//					j0 = 21;
//				}
//				if(c[3][0] == 0)
//				{
//					n0++;
//					j0 = 30;
//				}
//				if(c[3][1] == 0)
//				{
//					n0++;
//					j0 = 31;
//				}
//				if(n0 == 1)
//				{
//					c[j0/10][j0%10] = 10-c[2][0]-c[2][1]-c[3][0]-c[3][1];
//				}
//				if(n0 == 0)
//				{
//					out++;
//				}
//			}//se();
//			{
//				int n0 = 0;
//				int j0;
//				if(c[2][2] == 0)
//				{
//					n0++;
//					j0 = 22;
//				}
//				if(c[2][3] == 0)
//				{
//					n0++;
//					j0 = 23;
//				}
//				if(c[3][2] == 0)
//				{
//					n0++;
//					j0 = 32;
//				}
//				if(c[3][3] == 0)
//				{
//					n0++;
//					j0 = 33;
//				}
//				if(n0 == 1)
//				{
//					c[j0/10][j0%10] = 10-c[2][2]-c[2][3]-c[3][2]-c[3][3];
//				}
//				if(n0 == 0)
//				{
//					out++;
//				}
//			}
//		//	se();
//		//	printf("out %d\n",out);
//		}
//		//se();
		for(int II = 0;II < 100;II++)
		{
			
			for(int i = 0; i < 4;i++)
			{
				for(int j = 0 ;j < 4;j++)
				{
					SS[i][j].clear();
					SS[i][j].insert(0);
				}
			}
//			for(int i = 0; i < 4;i++)
//			{
//				for(int j = 0 ;j < 4;j++)
//				{
//					for(int jj = 0;jj < 4;jj++)
//					{
//						SS[i][j].insert(c[i][jj]);
//					}
//				}
//			}
//			for(int i = 0; i < 4;i++)
//			{
//				for(int j = 0 ;j < 4;j++)
//				{
//					for(int jj = 0;jj < 4;jj++)
//					{
//						SS[j][i].insert(c[jj][i]);
//					}
//				}
//			}
//			
			for(int i = 0; i < 4;i++)
			{
				for(int j = 0 ;j < 4;j++)
				{
					for(int jj = 0;jj < 4;jj++)
					{
						SS[i][j].insert(c[i][jj]);
					}
					for(int jj = 0;jj < 4;jj++)
					{
						SS[i][j].insert(c[jj][j]);
					}
					
				}
			}


			{
				SS[0][0].insert(c[0][0]);
				SS[0][0].insert(c[0][1]);
				SS[0][0].insert(c[1][0]);
				SS[0][0].insert(c[1][1]);
				
				SS[0][1].insert(c[0][0]);
				SS[0][1].insert(c[0][1]);
				SS[0][1].insert(c[1][0]);
				SS[0][1].insert(c[1][1]);
				
				SS[1][0].insert(c[0][0]);
				SS[1][0].insert(c[0][1]);
				SS[1][0].insert(c[1][0]);
				SS[1][0].insert(c[1][1]);
				
				SS[1][1].insert(c[0][0]);
				SS[1][1].insert(c[0][1]);
				SS[1][1].insert(c[1][0]);
				SS[1][1].insert(c[1][1]);
				
			}
			
			{
				SS[0][2].insert(c[0][2]);
				SS[0][2].insert(c[0][3]);
				SS[0][2].insert(c[1][2]);
				SS[0][2].insert(c[1][3]);
				
				SS[0][3].insert(c[0][2]);
				SS[0][3].insert(c[0][3]);
				SS[0][3].insert(c[1][2]);
				SS[0][3].insert(c[1][3]);
				
				SS[1][2].insert(c[0][2]);
				SS[1][2].insert(c[0][3]);
				SS[1][2].insert(c[1][2]);
				SS[1][2].insert(c[1][3]);
				
				SS[1][3].insert(c[0][2]);
				SS[1][3].insert(c[0][3]);
				SS[1][3].insert(c[1][2]);
				SS[1][3].insert(c[1][3]);
				
			}
			{
				SS[2][0].insert(c[2][0]);
				SS[2][0].insert(c[2][1]);
				SS[2][0].insert(c[3][0]);
				SS[2][0].insert(c[3][1]);
				
				SS[2][1].insert(c[2][0]);
				SS[2][1].insert(c[2][1]);
				SS[2][1].insert(c[3][0]);
				SS[2][1].insert(c[3][1]);
				
				SS[3][0].insert(c[2][0]);
				SS[3][0].insert(c[2][1]);
				SS[3][0].insert(c[3][0]);
				SS[3][0].insert(c[3][1]);
				
				SS[3][1].insert(c[2][0]);
				SS[3][1].insert(c[2][1]);
				SS[3][1].insert(c[3][0]);
				SS[3][1].insert(c[3][1]);
				
			}
			{
				SS[2][2].insert(c[2][2]);
				SS[2][2].insert(c[2][3]);
				SS[2][2].insert(c[3][2]);
				SS[2][2].insert(c[3][3]);
				
				SS[2][3].insert(c[2][2]);
				SS[2][3].insert(c[2][3]);
				SS[2][3].insert(c[3][2]);
				SS[2][3].insert(c[3][3]);
				
				SS[3][2].insert(c[2][2]);
				SS[3][2].insert(c[2][3]);
				SS[3][2].insert(c[3][2]);
				SS[3][2].insert(c[3][3]);
				
				SS[3][3].insert(c[2][2]);
				SS[3][3].insert(c[2][3]);
				SS[3][3].insert(c[3][2]);
				SS[3][3].insert(c[3][3]);
				
			}
			
			
			for(int i = 0; i < 4;i++)
			{
				for(int j = 0 ;j < 4;j++)
				{
				//	printf("%d %d %d\n",i,j,SS[i][j].size());
					if(SS[i][j].size() == 4&&c[i][j]==0)
					{
				//		puts("???");
						for(int jj = 1; jj < 5;jj++)
						{
							if(SS[i][j].count(jj) == 0)
							{
								c[i][j] = jj;
								break;
							}
						}
					}
				}
			}
		}
		
		
		for(int i = 0;i < 4;i++)
		{
			for(int j = 0;j < 4;j++)
			{
				printf("%d",c[i][j]);
			}
			puts("");
		}
		
	 } 

/*



.......xx
.........
.........
..xxxxx..
.xoooox..
.xoo.oxx.
.xoooox..
.xxxxxxxo
....ooooo




1
**12
*3*4
2***
****



1
*41*
**3*
2*41
4*2*


1
**1*
*3*4
2***
**4*



*/


 return 0;
}


