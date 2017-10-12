#include<bits/stdc++.h>
#define ll long long
using namespace std;

char s[200][200];
int n,m;
int main()
{
	/*
	3 1
R
R
B
	
	*/
	while(~scanf("%d%d",&n,&m))
	{
		for(int i = 0 ;i < n;i++)
		{
			scanf("%s",s[i]);
		}
		int F = 0,f = 0;
		for(int i = 0;i < m;i++)
		{
			
			if(s[0][i]!=s[0][0]||n%3)
			{
				f-=2;
				break;
			}
		}
		for(int i = 0;i < n;i++)
		{
			if(s[i][0]!=s[0][0]||m%3)
			{
				f--;
				break;
			}
		}
	//	printf("%d\n",s[0][0]==s[n/3*2][0]);
		if(f == 0||f == -3)
		{
			puts("NO");
			continue;
		}
		if(f == -1)// ¡ª¡ª 
		{
			F = 0;
			int o = n/3;
			if(s[0][0]==s[n/3][0]||s[n/3*2][0]==s[n/3][0]||s[0][0]==s[n/3*2][0])
			{
				puts("NO");//
				continue;
			}
			if((n%3))
			{
				puts("NO");
				continue;
			}
			for(int i = 0;i < n/3;i++)
			{
				for(int j = 0;j < m;j++)
				{
					if(s[0][0]!=s[i][j])
					{
						F = 1;
						break;
					}
				}
				if(F)
				{
					break;
				}
			}
			if(F)
			{
				puts("NO");
				continue;
			}
			for(int i = n/3;i < n/3*2;i++)
			{
				for(int j = 0;j < m;j++)
				{
					if(s[n/3][0]!=s[i][j])
					{
						F = 1;
						break;
					}
				}
				if(F)
				{
					break;
				}
			}
			if(F)
			{
				puts("NO");
				continue;
			}
			for(int i = n/3 *2;i < n;i++)
			{
				for(int j = 0;j < m;j++)
				{
					if(s[n/3 *2][0]!=s[i][j])
					{
						F = 1;
						break;
					}
				}
				if(F)
				{
					break;
				}
			}
			if(F)
			{
				puts("NO");
				continue;
			}
		}
	//	puts("FUCK");
		if(f == -2)
		{
			F = 0;
			if(s[0][0]==s[0][m/3]||s[0][m/3*2]==s[0][m/3]||s[0][0]==s[0][m/3*2])
			{
				puts("NO");
				continue;
			}
			if((m%3))
			{
				puts("NO");
				continue;
			}
			for(int i = 0;i < n;i++)
			{
				for(int j = 0;j < m/3;j++)
				{
					if(s[0][0]!=s[i][j])
					{
						F = 1;
						break;
					}
				}
				if(F)
				{
					break;
				}
			}
			if(F)
			{
				puts("NO");
				continue;
			}
			for(int i = 0;i < n;i++)
			{
				for(int j = m/3;j < m/3*2;j++)
				{
					if(s[0][m/3]!=s[i][j])
					{
						F = 1;
						break;
					}
				}
				if(F)
				{
					break;
				}
			}
			if(F)
			{
				puts("NO");
				continue;
			}
			for(int i = 0;i < n;i++)
			{
				for(int j = m/3*2;j < m;j++)
				{
					if(s[0][m/3*2]!=s[i][j])
					{
						F = 1;
						break;
					}
				}
				if(F)
				{
					break;
				}
			}
			if(F)
			{
				puts("NO");
				continue;
			}
			
		}
		puts("YES");
		
	}

/*
6 5
RRRRR
RRRRR
BBBBB
BBBBB
GGGGG
GGGGG
 
4 3
BRG
BRG
BRG
BRG
 
6 7
RRRGGGG
RRRGGGG
RRRGGGG
RRRBBBB
RRRBBBB
RRRBBBB
 
4 4
RRRR
RRRR
BBBB
GGGG
1 3
GRB

*/


 return 0;
}


