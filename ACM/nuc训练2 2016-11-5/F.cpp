#include<stdio.h>
#include<string.h> 

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		int a[200],an = 0;
		int b[200],bn = 0;
		getchar();
		for(int II = 1;II <= n;II++)
		{//getchar();
			char s[200];
			char com[200];
			gets(s);
			int len = strlen(s);
			int ii = 0;
			for(int i = len-8;i<len;i++)
			{
				//printf("%c ",s[i]);
				com[ii++] = s[i];
			}
			com[ii] = '\0';
			int get = 1;
			//printf("com   !%s!\n",com);
			if(strcmp(com," no good") == 0)
			{
				get = 0;
			}
			if(II%2)
			{
				a[an++] = get;
			}
			else
			{
				b[bn++] = get;
			}
		}
		for(int i = 0; i < (n+1)/2;i++)
		{
			printf("%d ",i+1);
		}
		printf("Score\n");
		int score = 0;
		for(int i = 0 ;i < an;i++)
		{
			if(a[i])
			{
				printf("O ");
				score++;
			}
			else
			{
				printf("X ");
			}
		}
		printf("%d\n",score);
		score = 0;
		for(int i = 0 ;i < bn;i++)
		{
			if(b[i])
			{
				printf("O ");
				score++;
			}
			else
			{
				printf("X ");
			}
		}
		if(an>bn)
		{
			printf("- ");
		}
		printf("%d\n",score);
		
	}
}
