#include<bits/stdc++.h>

using namespace std;

int main()
{
	char s[1000];
	while(~scanf("%s",s))
	{
		int len = strlen(s);
		int qh = 0;
		int F = 0;
		int a[1000];
		memset(a,0,sizeof(a));
		int an = 0;
		for(int i =0 ; i < len;i++)
		{
			if(s[i] == '@')
			{
				an++;
			}
			else
			{
				a[an]++;
			}
		}
		if(an == 0)
		{
			F = 1;
		}
		else if(a[0] == 0)
		{
			F = 1;
		}
		else if(a[an] == 0)
		{
			F = 1;
		}
		else
		{
			for(int i =1 ; i < an;i++)
			{
				if(a[i]<=1)
				{
					F = 1;
					break;
				}
			}
		}
		
//		for(int i =0 ; i <= an;i++)
//		{
//			printf("%d %d\n",i,a[i]);
//		}
		if(F)
		{
			printf("No solution\n");
		}
		else
		{
			printf("%c",s[0]);
			an--;
			for(int i = 1;i < len;i++)
			{
				if(s[i-1] == '@'&&an)
				{
					printf("%c,",s[i]);
					an--;
				}
				else
				{
					printf("%c",s[i]);
				}
			}
			puts("");
		}
	}




 return 0;
}
/*
a@aa@a
a@a@a
@aa@a
*/

