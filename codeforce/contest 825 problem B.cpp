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

char m[20][20];
int __(int i,int j)
{
	if(i>9||j>9||i<0||j<0)
	{
		return 0;
	}
	if(m[i][j]!='X')
	{
		return 0;
	}
	return 1;
}


int _(int x,int y)
{
//	printf("%d %d\n",x,y);
	int ans = 1;
	for(int i = 1;;i++)
	{
		if(__(x+i,y))
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	for(int i = 1;;i++)
	{
		if(__(x-i,y))
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	if(ans>=5)
	{
		return 1;
	}
	ans = 1;
	for(int i = 1;;i++)
	{
		if(__(x,y+i))
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	for(int i = 1;;i++)
	{
		if(__(x,y-i))
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	if(ans>=5)
	{
		return 1;
	}
	ans = 1;
	for(int i = 1;;i++)
	{
		if(__(x+i,y+i))
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	for(int i = 1;;i++)
	{
		if(__(x-i,y-i))
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	if(ans>=5)
	{
		return 1;
	}
	ans = 1;
	for(int i = 1;;i++)
	{
		if(__(x-i,y+i))
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	for(int i = 1;;i++)
	{
		if(__(x+i,y-i))
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	if(ans>=5)
	{
		return 1;
	}
		
	
	return 0;
}



int main()
{
	while(~scanf("%s",m[0]))
	{
		for(int i = 1; i < 10;i++)
		{
			scanf("%s",&m[i]);
		}
		
		int F = 0;
		for(int i = 0;i < 10;i++ )
		{
			for(int j = 0 ;j < 10;j++)
			{
			//	cout<<m[i][j];
				if(m[i][j] == '.')
				{
				//	printf("?%c?%d %d",m[i][j],i,j);
					m[i][j] = 'X';
					if(_(i,j))
					{
						F = 1;
						break;
					}
					
					m[i][j] = '.';
					
				}
			}
		//	puts("");
			if(F)
			{
				break;
			}
		}
//		for(int i = 0; i < 10;i++)
//		{
//			printf("%s\n",m[i]);
//		}
		
		if(F)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
		
		
		
	}
/*
XX.XX.....
.....OOOO.
..........
..........
..........
..........
..........
..........
..........
..........

*/


 return 0;
}


