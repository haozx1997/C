#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
#include<queue>
using namespace std;



struct no
{
	int x,y;
	int step;
};



int STEP;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
char m[10][10] ;
////= {
////{"L........"},
////{"#....a.##"},
////{"######.##"},
////{"...##..##"},
////{".#...#.##"},
////{".##.##.##"},
////{".##....##"},
////{"...###.##"},
////{"##.######"},
////{"#.a...Q##"},
//};
char mm[10][10];
// = {
//{"L........"},
//{"#....a.##"},
//{"######.##"},
//{"...##..##"},
//{".#...#.##"},
//{".##.##.##"},
//{".##....##"},
//{"...###.##"},
//{"##.######"},
//{"#.a...Q##"},
//};
char mo[10][10] = {
{"........."},
{"#.......#"},
{"###..a..."},
{"...#...##"},
{".#.....##"},
{"....##.##"},
{"..a....##"},
{"...###.##"},
{"##.######"},
{"#.....Q##"},
};


int lx,ly;
int qx,qy;
int tr[30][5];
int istr[30];
int xmax,ymax;
int check(int xx,int yy)
{
	if(m[xx][yy] == '#'||xx<0||yy<0||xx>=xmax||yy>=ymax)
	 return 0;
	return 1;
}
int check_(int xx,int yy)
{
	if(mm[xx][yy] == '#'||xx<0||yy<0||xx>=xmax||yy>=ymax)
	 return 0;
	if(mm[xx][yy]>='a'&&mm[xx][yy]<='z') 
	 return -1;
	return 1;
}


int minn = 0;
int bfs()
{
	queue<no> q;
	no a,next,last;
	a.x = lx;
	a.y = ly;
	a.step = 0;
	m[lx][ly] = '#';
	q.push(a);
	while(!q.empty())
	{
		a = q.front();
		printf("aa %d   %d    %d  \n",a.x,a.y,a.step);
		q.pop();
		if(a.x == qx&&a.y == qy)
		{
			return a.step;
		}
		

		for(int i = 0;i < 4;i++)
		{
			next = a;
			next.x = a.x+dir[i][0];
			next.y = a.y+dir[i][1];
			if(check(next.x,next.y)) 
		 	  {
		 	  	next.step++; 
		 	  	if(m[next.x][next.y]>='a'&&m[next.x][next.y]<='z')
		 	  	{
		 	  		int aa = (int)m[next.x][next.y] - 'a';
		 	  		if(next.x == tr[aa][0]&&next.y == tr[aa][1])
		 	  		{
		 	  			m[next.x][next.y] = '#';
		 	  			next.x = tr[aa][2];
						next.y = tr[aa][3];
					   }
					 else
					 {
					 	m[next.x][next.y] = '#';
		 	  			next.x = tr[aa][0];
						next.y = tr[aa][1];
					   }
					    
		 	  		q.push(next);
				   }
				 else
				 {
				 	m[next.x][next.y]='#';
		 	  		
		 	  		q.push(next);
				 }  
		 	  	
			   }
		}
		
	}
	return -1;
}




void see()
{
	
	system("cls");
	printf("~GAME 迷宫\n"); 
	printf("wasd控制 L 的上下左右 找到 Q\n");
	printf("最短路是 %d →_→智障找不到\n",minn);
	printf("  %d %d  \n",lx,ly);
	printf("   当前步数 %d\n",STEP);
	for(int i = 0 ; i < 10;i++)
	{
		for(int j = 0;j<10;j++)
		{
			printf("%c",mm[i][j]);
		}
		printf("\n");
	}
	 
}

void sw(int x1,int y1,int x2,int y2)
{
	char T = mm[x1][y1];
	mm[x1][y1] = mm[x2][y2];
	mm[x2][y2] = T;
	
}

int FF = 0;
int ctrl()
{
	
	if(lx==qx&&ly==qy)
	{
		return 1;
	}STEP++;
	if(FF)
	{
		for(int i = 0;i<30;i++)
		{
			if(istr[i])
			{
				mm[tr[i][0]][tr[i][1]] = mo[tr[i][0]][tr[i][1]];
				mm[tr[i][2]][tr[i][3]] = mo[tr[i][2]][tr[i][3]];
				 
			}
		}
		FF = 0;
	}
	char asd;
	asd = getch();
	
	switch(asd)
	{
		case 'w':
		case 'W':
			if(check_(lx-1,ly) == 1)
			{
				mm[lx][ly] = mo[lx][ly];
				mm[lx-1][ly] = 'L';
				lx = lx-1;
				ly = ly;
				
			}
			else if(check_(lx-1,ly) == 0)
			{
				//DO NOTHING;
			}
			else if(check_(lx-1,ly) == -1)
			{
				mm[lx][ly] = mo[lx][ly];
				FF = 1;  
				int aaa = (int)mm[lx-1][ly] - 'a';
				if(lx-1 == tr[aaa][0]&&ly == tr[aaa][1])
		 	  		{
		 	  			mm[tr[aaa][2]][tr[aaa][3]] = 'L';
		 	  			lx = tr[aaa][2];
		 	  			ly = tr[aaa][3];
		 	  			
					   }
					 else
					 {
					 	mm[tr[aaa][0]][tr[aaa][1]] = 'L';
					 	lx = tr[aaa][0];
		 	  			ly = tr[aaa][1];
					   }
				
			}
			
			break;
		case 's':
		case 'S':
			if(check_(lx+1,ly) == 1)
			{
				mm[lx][ly] = mo[lx][ly];
				mm[lx+1][ly] = 'L';
				lx = lx+1;
				ly = ly;
			}
			else if(check_(lx+1,ly) == 0)
			{
				//DO NOTHING;
			}
			else if(check_(lx+1,ly) == -1)
			{
				mm[lx][ly] = mo[lx][ly];
				FF = 1;  
				int aaa = (int)mm[lx+1][ly] - 'a';
				if(lx+1 == tr[aaa][0]&&ly == tr[aaa][1])
		 	  		{
		 	  			mm[tr[aaa][2]][tr[aaa][3]] = 'L';
		 	  			lx = tr[aaa][2];
		 	  			ly = tr[aaa][3];
					   }
					 else
					 {
					 	mm[tr[aaa][0]][tr[aaa][1]] = 'L';
					 	lx = tr[aaa][0];
		 	  			ly = tr[aaa][1];
					   }
				
			}
			
			break;
		case 'a':
		case 'A':
			if(check_(lx,ly-1) == 1)
			{
				mm[lx][ly] = mo[lx][ly];
				mm[lx][ly-1] = 'L';
				lx = lx;
				ly = ly-1;
			}
			else if(check_(lx,ly-1) == 0)
			{
				//DO NOTHING;
			}
			else if(check_(lx,ly-1) == -1)
			{
				mm[lx][ly] = mo[lx][ly];
				FF = 1;  
				int aaa = (int)mm[lx][ly-1] - 'a';
				if(lx == tr[aaa][0]&&ly-1 == tr[aaa][1])
		 	  		{
		 	  			mm[tr[aaa][2]][tr[aaa][3]] = 'L';
		 	  			lx = tr[aaa][2];
		 	  			ly = tr[aaa][3];
					   }
					 else
					 {
					 	mm[tr[aaa][0]][tr[aaa][1]] = 'L';
					 	lx = tr[aaa][0];
		 	  			ly = tr[aaa][1];
					   }
			
			}
			break;
		case 'd':
		case 'D':
			if(check_(lx,ly+1) == 1)
			{
				mm[lx][ly] = mo[lx][ly];
				mm[lx][ly+1] = 'L';
				lx = lx;
				ly = ly+1;
			}
			else if(check_(lx,ly+1) == 0)
			{
				//DO NOTHING;
			}
			else if(check_(lx,ly+1) == -1)
			{
				mm[lx][ly] = mo[lx][ly];
				FF = 1;  
				int aaa = (int)mm[lx][ly+1] - 'a';
				if(lx == tr[aaa][0]&&ly+1 == tr[aaa][1])
		 	  		{
		 	  			mm[tr[aaa][2]][tr[aaa][3]] = 'L';
		 	  			lx = tr[aaa][2];
		 	  			ly = tr[aaa][3];
					   }
					 else
					 {
					 	mm[tr[aaa][0]][tr[aaa][1]] = 'L';
					 	lx = tr[aaa][0];
		 	  			ly = tr[aaa][1];
					   }
				
			}
			
			break;
				
	}
	
	see();
	
	
	
	return 0;
}
int main()
{
	STEP = 0;
		xmax = ymax =10;
		for(int i = 0;i < xmax;i++)
		{
			for(int j = 0;j < ymax;j++)
			{
				 mm[i][j] = m[i][j] = mo[i][j];
			}
		}
		mm[0][0] = m[0][0] = 'L';

		
		
		
		for(int i = 0;i < xmax;i++)
		{
			
			for(int j = 0;j < ymax;j++)
			{
				if(m[i][j] == 'L')
				{
					lx = i;
					ly = j;
				}
				if(m[i][j] == 'Q')
				{
					qx = i;
					qy = j;
				}
				if(m[i][j]>='a'&&m[i][j]<='z')
				{
					if(istr[(int)m[i][j]-'a' ]== 0)
					{
						tr[(int)m[i][j]-'a'][0] = i;
						tr[(int)m[i][j]-'a'][1] = j;
						istr[(int)m[i][j]-'a' ] = 1;
					}
					else
					{
						tr[(int)m[i][j]-'a'][2] = i;
						tr[(int)m[i][j]-'a'][3] = j;
					}
				}
				
			}
				
			
		}
	
	
	
		minn = bfs();
		see();
		
		while(!ctrl());
		see();
		for(int i = 0;i < 20;i++)
		printf("!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("!!!!!!!!!!过了!!!!!!!!!!\n");
		for(int i = 0;i < 20;i++)
		
		printf("!!!!!!!!!!!!!!!!!!!!!!!!\n");
		
	system("pause");
	return 0;
}






