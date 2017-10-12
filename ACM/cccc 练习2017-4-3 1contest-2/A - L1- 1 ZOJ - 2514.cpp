#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
	int n;
	char s[1010][2][20];
	
	while(scanf("%d",&n),n)
	{
		for(int i = 0;i< n;i++)
		{
			scanf("%s%s",s[i][0],s[i][1]);
		}
		int ans[1010];
		int ansn = 0;
		
		for(int i = 0;i<n;i++)
		{
			int f = 0;
			for(int j = 0;j< strlen(s[i][1]);j++)
			{
				
				if(s[i][1][j] == '1')
				{
					s[i][1][j] = '@';
					f = 1;
				}
				else if(s[i][1][j] == '0')
				{
					s[i][1][j] = '%';
					f = 1;	
				}
				else if(s[i][1][j] == 'l')
				{
					s[i][1][j] = 'L';
					f = 1;	
				}
				else if(s[i][1][j] == 'O')
				{
					s[i][1][j] = 'o';
					f = 1;	
				}
				
			}
			if(f)
			{
				ans[ansn++] = i;
			}
		}
		if(ansn)
		{
			printf("%d\n",ansn);
			for(int i = 0;i<ansn;i++)
			{
				printf("%s %s\n",s[ans[i]][0],s[ans[i]][1]);
			}
		}
		else
		{
			printf("No account is modified.\n");
		}
	}
}
