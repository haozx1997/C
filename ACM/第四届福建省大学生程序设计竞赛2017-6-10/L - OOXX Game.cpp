#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{	
	int T;
	scanf("%d",&T);
	for(int II = 0;II < T;II++)
	{
		char s[500][500];
		int n,m;
		scanf("%d%d",&n,&m);
		int o = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%s",s[i]);
			for(int j = 0; j<m;j++)
			{
				if(s[i][j] == 'o'||s[i][j] == 'O')
				{
					o++;
				}
			}
		}
		
		
		if((o%2))
		{
			printf("Case %d: Maze\n",II+1);
		}
		else
		{
			printf("Case %d: Fat brother\n",II+1);
		}
	}





 return 0;
}



