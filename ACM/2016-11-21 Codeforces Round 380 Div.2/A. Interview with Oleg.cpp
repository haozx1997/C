#include<stdio.h>
#include<string.h>


int main()
{
	freopen("1.in","r",stdin);
	int n;
	char s[200];
	while(~scanf("%d%s",&n,s))
	{
		
		for(int i = 0;i < n;i++)
		{
			int f = 0;
			if(s[i] == 'o')
			{
				for(int j = i+1;j < n;j += 2)
				{
					if(s[j] == 'g' && s[j+1] == 'o')
					{	
						i++;i++;
						f++;
					}
					else
					{
						break;
					}
				}
				if(f)
				{
					printf("***");
				}
				else
				{
					printf("o");
				}
				//printf("F %d\n",f);
				
				
			}
			else
			{
				printf("%c",s[i]);
			}
		}
		printf("\n");
	}
}
