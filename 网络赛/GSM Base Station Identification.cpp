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
#define ws 8.66025404

using namespace std;
const int maxx = 1010;
const ll mod = (ll)1e9+7;

const double inf = 0x3f3f3f3f;
const double eps = 1e-9;


struct node
{
	double x,y;
}p[30][30];

double dis(double x,double y,node pp)
{
	return sqrt((x-pp.x)*(x-pp.x)+(y-pp.y)*(y-pp.y));
}


int main()
{
	p[0+15][0+15].x = 0;
	p[0+15][0+15].y = 0;
	
	for(int i = 1+15;i < 13+15;i++)
	{
		p[0+15][i].x = p[0+15][i-1].x+ws/2;
		p[0+15][i].y = p[0+15][i-1].y+7.5;
		 
	}
	for(int i = -1+15;i > -13+15;i--)
	{
		
		p[0+15][i].x = p[0+15][i+1].x-ws/2;
		p[0+15][i].y = p[0+15][i+1].y-7.5;
		 
	}
	for(int i = 1+15;i < 13+15;i++)
	{
		for(int j = -11+15;j < 13+15;j++)
		{
			p[i][j].x = p[i-1][j].x+ws;
			p[i][j].y = p[i-1][j].y;
			
		}
		
	}
	for(int i = -1+15;i > -13+15;i--)
	{
		for(int j = -11+15;j < 13+15;j++)
		{
			p[i][j].x = p[i+1][j].x-ws;
			p[i][j].y = p[i+1][j].y;
			
		}
		
	}

	double x,y;
	double ax,ay;
	
	int out[100][2];
//	while(~scanf("%lf%lf",&x,&y))
//	{
//		
//	}
	for(int t = 0;t < 10;t++)
	{
	 	scanf("%lf%lf",&x,&y);
		x += 15.0;
		y += 15.0;
		double minn = inf;
		for(int i = -13+15;i < 13+15;i++)
		{
			for(int j = -11+15;j < 13+15;j++)
			{
				if(dis(x,y,p[i][j])<minn)
				{
					minn = dis(x,y,p[i][j]);
					ax = i;
					ay = j;
					
				}
			}
			
		}
		out[t][0] = ax-15-1;
		out[t][1] = ay-15-2;
		
	}
	for(int i = 0; i< 9;i++)
	{
		printf("[%d,%d], ",out[i][0],out[i][1]);
	}
		printf("[%d,%d]\n",out[9][0],out[9][1]);
 return 0;
}


