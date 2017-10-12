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

char mapp[1010][1010];
int vis[1010][1010];
int mapF[1010][1010];
int visF[1010][1010];

int n,m;
int px,py;
int fx[1010],fy[1010];
int fn;
struct node
{
	int x,y;
	int step;
};
struct nodeF
{
	int x,y;
	int step;
};

int dir[4][2] = {1,0,-1,0,0,1,0,-1};

bool checkF(nodeF nex)
{
	int x = nex.x;
	int y = nex.y;
	if(visF[x][y] == 1)
	{
		return 0;
	}
	if(mapp[x][y] == '#')
	{
		return 0;
	}
	if(mapp[x][y] == 'F')
	{
		return 0;
	}
	if(mapp[x][y] == '?')
	{
		return 0;
	}
	
	return 1;
}

void bfsF()
{
	nodeF now,nex;
	queue<nodeF>QF;
	while(!QF.empty())
	{
		QF.pop();
	}
	for(int i = 0; i < fn;i++ )
	{
		now.x = fx[i];
		now.y = fy[i];
		now.step = 0;
		visF[now.x][now.y] = 1 ;
		mapF[now.x][now.y] = 0 ;
		QF.push(now);
	}
	while(!QF.empty())
	{
		now = QF.front();
		QF.pop();
		
		for(int i =0; i < 4;i++)
		{
			nex.x = now.x+dir[i][0];
			nex.y = now.y+dir[i][1];
			nex.step = now.step+1;
			if(checkF(nex))
			{
				QF.push(nex);
				visF[nex.x][nex.y] = 1 ;
				mapF[nex.x][nex.y] = nex.step ;
			}
		}
	}
	return ;	
}
bool check(node nex)
{
	int x = nex.x;
	int y = nex.y;
	if(vis[x][y] == 1)
	{
		return 0;
	}
	if(mapp[x][y] == '#')
	{
		return 0;
	}
	if(mapp[x][y] == 'F')
	{
		return 0;
	}
	if(mapF[x][y]<=nex.step)
	{
		return 0;
	}
	return 1;
}
int bfs()
{
	node now,nex;
	queue<node>Q;
	while(!Q.empty())
	{
		Q.pop();
	}
	now.x = px;
	now.y = py;
	now.step = 0;
	vis[now.x][now.y] = 1 ;
	Q.push(now);
	while(!Q.empty())
	{
		now = Q.front();
		Q.pop();
		if(mapp[now.x][now.y] == '?')
		{
			return now.step;
		}
		for(int i =0; i < 4;i++)
		{
			nex.x = now.x+dir[i][0];
			nex.y = now.y+dir[i][1];
			nex.step = now.step+1;
			if(check(nex))
			{
				Q.push(nex);
				vis[nex.x][nex.y] = 1 ;
			}
		}
	}
	return -1;	
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		memset(visF,0,sizeof(visF));
		memset(mapF,0x3f3f3f3f,sizeof(mapF));
		memset(fx,0,sizeof(fx));
		memset(fy,0,sizeof(fy));
		
		fn = 0;
		scanf("%d%d",&n,&m);
		for(int i = 0;i <= n+1;i++)
		{
			mapp[i][0] = '?';
			mapF[i][0] = 1e9;
			
		}
		for(int j = 0; j <= m+1;j++)
		{
			mapp[0][j] = '?';
			mapp[n+1][j] = '?';
			mapF[0][j] = 1e9;
			mapF[n+1][j] = 1e9;
			
		}
		
		for(int i = 1;i <= n;i++)
		{
			scanf("%s",&mapp[i][1]);
		}
		for(int i = 0;i <= n+1;i++)
		{
			mapp[i][m+1] = '?';
			mapp[i][m+2] = 0;
			mapF[i][m+1] = 1e9;
			mapF[i][m+2] = 1e9;
			
		}
//		for(int i = 0;i <= n+1;i++)
//		{
//			printf("%s\n",mapp[i]);
//		}
		
		for(int i = 0;i <= n+1;i++)
		{
			for(int j = 0; j <= m+1;j++)
			{
				if(mapp[i][j] == 'J')
				{
					px = i;
					py = j;
				}
				if(mapp[i][j] == 'F')
				{
					fx[fn] = i;
					fy[fn++] = j;
					
				}
			}
		}
		bfsF();
//		for(int i = 0; i <=n+1;i++)
//		{
//			for(int j = 0;j <=m+1;j++)
//			{
//				printf("%d ",mapF[i][j]);
//			}
//			puts("");
//		}
		int ans = bfs();
		if(ans == -1)
		{
			puts("IMPOSSIBLE");
		}
		else
		{
			printf("%d\n",ans);
		}
		
		
	}

/*

2
4 4
####
#JF#
#..#
#..#
3 3
###
#J.
#.F
2
4 4
####
#JF#
#.F#
#..#
3 3
###
#J.
#.F
3 3
###
#J.
#F.

4 4
F###
#J.#
#..#
####

*/


 return 0;
}


