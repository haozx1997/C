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


int WTF[30];

char ss[100100];

void init()
{
	WTF[1] = 5;
	WTF[2] = 5;
	WTF[3] = 5;
	WTF[4] = 5;
	WTF[5] = 5;
	WTF[6] = 5;
	WTF[7] = 5;
	WTF[8] = 5;
	WTF[9] = 5;
	WTF[10] = 5;
	
	WTF[11] = 4;
	WTF[12] = 4;
	WTF[13] = 4;
	WTF[14] = 4;
	WTF[15] = 4;
	
	WTF[16] = 3;
	WTF[17] = 3;
	WTF[18] = 3;
	WTF[19] = 3;
	WTF[20] = 3;
	
	WTF[21] = 2;
	WTF[22] = 2;
	WTF[23] = 2;
	WTF[24] = 2;
	WTF[25] = 2;
	
	
}

int main()
{
	init();
	
	while(~scanf("%s",ss))
	{
		int r = 25;
		int s = 0;
		int len = strlen(ss);
		int l = 0;
		int lll = 0;
		for(int i = 0;i < len;i++)
		{
		//printf(" r %d s  %d\n",r,s);
			if(ss[i] == 'L')
			{
				l = 0;
				if(r < 20)
				{
					s--;
					if(s<0)
					{
						r++;
						s = WTF[r]-1;
					}
				}
				else if(r == 20)
				{
					s--;
					if(s<0)
					{
						s = 0;
					}
				}
			}
			else
			{
				l++;
				s++;
		//		printf("%d\n",l);
				if(l >= 3&&(r>=6&&r<=25))
				{
					s++;
				}
				if(s>WTF[r])
				{
					s -= WTF[r];
					r--;
					if(r == 0)
					{
						break;
					}
				}
			}
		//	printf(" r %d s  %d\n\n",r,s);
		}
		if(r)
		{
			printf("%d\n",r);
		}
		else
		{
			printf("Legend\n");
		}
		
		
	}


/*
WW

WLWLWLWL

WWWWWWWWWLWWL
*/

 return 0;
}
