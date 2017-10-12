#include<bits/stdc++.h>

using namespace std;

map<char,int> good;

char wtf[100];
char wtf2[100100];
char wtf3[100100];

int main()
{	
	while(~scanf("%s",wtf))
	{
		int wlen = strlen(wtf);
		for(int i = 0;i < wlen;i++)
		{
			good[wtf[i]] = 1;
		}
		
		scanf("%s",wtf2);
		int len2 = strlen(wtf2);
		int xx = 0;
		for(int i = 0;i < len2;i++)
		{
			if(wtf2[i] == '*')
			{
				xx = 1;
				break;
			}
		}
		int n;
		scanf("%d",&n);
		while(n--)
		{
			int F = 0;
			scanf("%s",wtf3);
			int len3 = strlen(wtf3);
			if(len3>len2)
			{
				puts("NO");
				continue;
			}
			if(len2 == len3)
			{
				for(int i = 0;i<len3;i++)
				{
					if(wtf2[i] != wtf3[i])
					{
						if(wtf2[i] == '?')
						{
							if(good[wtf3[i]] == 0)
							{
								F = 1;
								break;
							}
						}
						else if(wtf2[i] == '*')
						{
							F = 1;
							if(good[wtf3[i]] == 0)
							{
								F = 0;
							}
						}
						else
						{
							F = 1;
							break;
						}
					}
					if(F == 1)
					{
						break;
					}
				}
			
			}
			else if(xx = 1)
			{
				int j = 0;
				for(int i = 0;i<len2;i++,j++)
				{
				//	printf("%d %c 	%d %c\n",wtf2[i],wtf3[j]);
					if(wtf2[i] != wtf3[j])
					{
						if(wtf2[i] == '?')
						{
							if(good[wtf3[j]] == 0)
							{
								F = 1;
								break;
							}
						}
						else if(wtf2[i] == '*')
						{
							j--;
						}
						else
						{
							F = 1;
							break;
						}
					}
					if(F == 1)
					{
						break;
					}
				}
			}
			else
			{
				F = 1;
			}
			if(F)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
			
		}
		
		
	}





 return 0;
}


