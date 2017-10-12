#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;
set<int> s;
int map[1000];

int intr[1010][1010];
int intrn[1010];
int pi[1010][1010];
int pin[1010];
int pre[1010];
int imax;


int find(int x)//查找根节点
{ 
    int r=x;
    while ( pre[r ] != r )//返回根节点 r
          r=pre[r ];
 
    int i=x , j ;
    while( i != r )//路径压缩
    {
         j = pre[ i ]; // 在改变上级之前用临时变量  j 记录下他的值 
         pre[ i ]= r ; //把上级改为根节点
         i=j;
    }
    return r ;
}
void link(int x,int y)//x y连通，
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
        pre[fx ]=fy;
}





void linkint(int l1,int l2)
{
	for(int i = 1;i < intrn[l1];i++)
	{
		link(intr[l1][0],intr[l1][i]);
	//	printf("        link  %d %d\n",intr[l1][0],intr[l1][i]);
	}
	for(int i = 0;i < intrn[l2];i++)
	{
		link(intr[l1][0],intr[l2][i]);
	//	printf("        link  %d %d\n",intr[l1][0],intr[l2][i]);
	}
	
}


int main()
{
	s.clear();
	memset(intr,0,sizeof(intr));
	memset(intrn,0,sizeof(intrn));
	memset(map,0,sizeof(map));
	
	int imax = 0;
	int t;
	scanf("%d",&t);
	for(int i = 0;i < t;i++)
	{
		
		scanf("%d",&pin[i]);
		char USELESS[10];
		scanf("%s",USELESS);
		for(int j = 0;j < pin[i];j++)
		{
			
			int inters;
			scanf("%d",&inters);
			inters > imax ? imax = inters:imax = imax;
			intr[inters][intrn[inters]++] = i;
			pi[i][j] = inters;
		}
		
	}
	
	for(int i = 0;i <= imax;i++)
	{
//		printf("%d ->",i);
		for(int j = 0;j < intrn[i];j++)
		{
//			printf("%d ",intr[i][j]);
		}
//		printf("\n");
	}
	for(int i = 0;i < t;i++)
	{
//		printf("人%d　-> ",i);
		for(int j = 0;j < pin[i];j++)
		{
//			printf("%d ",pi[i][j]);
		}
//		printf("\n");
	}
		for(int i = 0;i < t;i++)
	{
		pre[i] = i;
	}
	
	for(int i = 0;i <= imax;i++)
	{
		if(intrn[i] > 1)
		{
			for(int j = 1;j < intrn[i];j++)
			{
	//			printf("     link %d %d\n",intr[i][j],intr[i][j-1]);
				link(intr[i][j],intr[i][j-1]);
			}
//			printf("\n");
		}
	}
	for(int i = 0;i < t;i++)
	{
		
		for(int j = 1;j < pin[i];j++)
		{
//			printf("lineint %d %d\n",pi[i][j - 1],pi[i][j]);
			linkint(pi[i][j - 1],pi[i][j]);
			
		}
//		printf("\n");
	}

	for(int i = 0;i < t;i++)
	{
//		printf("!!!%d %d\n",i,f[i]);
	}
	for(int i = 0;i < t;i++)
	{
		map[pre[i]]++;
		s.insert(pre[i]);
	}
	sort(map,map+t);
	printf("%d\n",s.size());
	for(int i = t-1;i > t-s.size();i--)
	{
		printf("%d ",map[i]);
	}
	printf("%d\n",map[t-s.size()]);
	
	
	
	
}
