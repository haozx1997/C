#include<stdio.h>
#include<string.h>

char s[10200];
int is(int a,int b,int c)
{
//	printf("%d %d %d\n",a,b,c);
	a--;b--;c--;
	if(s[a] == 'y'&&s[b] == 'r'&&s[c] == 'x')
	{
		return 1;
	}
	if(s[a] == 'x'&&s[b] == 'r'&&s[c] == 'y')
	{
		return 1;
	}
	
	return 0;
	
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans = 0;
		scanf("%s",s);
		int len = strlen(s);
		int a ;
		for(int m = 2;;m++)
		{
			for(a = 1;;a++)
			{
			//	printf("%d\n",m);
				if((a*m*m)>len)
				{
					break;
				}
				if(is(a,a*m,a*m*m))
				{
					ans++;
				}
			}
			if(a==1&&(a*m*m)>len)
				{
					break;
				}
		}
		printf("%d\n",ans);
	}
 } 
