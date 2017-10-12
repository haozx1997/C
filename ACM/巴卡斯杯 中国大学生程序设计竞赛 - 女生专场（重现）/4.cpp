#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

char map[1010][1010];
char girl[5]={"g","i","r","l"};
char cat[4]={"c","a","t"}; 

int bfs(int i,int j)
{
	if()
}



int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i = 0;i<n;i++)
		{
			scanf("%s",map[i]);

		}
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				bfs(i,j);
			}
			
		}
		
		
		
		
		
		
		
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				printf("%c",map[i][j]);
			}
			printf("\n");
		}
	}
}

