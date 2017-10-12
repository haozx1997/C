#include<stdio.h>

int M[1010][1010];
int t[1010];
int n,m,q;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				scanf("%d",&M[i][j]);
			}
		}
		while(q--)
		{
			int a,x,y;
			scanf("%d%d%d",&a,&x,&y);
			
			switch(a)
			{
				case 1 :x--;y--;
					for(int i = 0;i<m;i++)
					 {
					 	t[i] = M[x][i];
					 	M[x][i] = M[y][i];
					 	M[y][i] = t[i];
					 }break;
				case 2 : x--;y--;
					for(int i = 0;i<n;i++)
					 {
					 	t[i] = M[i][x];
					 	M[i][x] = M[i][y];
					 	M[i][y] = t[i];
					 }
					break;
				case 3 : x--;
					for(int i = 0;i<m;i++)
					 {
					 	M[x][i]+=y;
					 }				
					break;
				case 4 : x--;
					for(int i = 0;i<n;i++)
					 {
					 	M[i][x]+=y;
					 }					
					break;
				
			}
		}
		int j;
		for(int i = 0;i<n;i++)
		{
			for(j = 0;j<m-1;j++)
			{
				printf("%d ",M[i][j]);
			}
			printf("%d",M[i][j]);
			printf("\n");
		}
		
	}
}
