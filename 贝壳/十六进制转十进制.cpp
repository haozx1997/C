#include<string.h>
#include<stdio.h>

char x[10];

long long ago(int n)
{
	long long ans = 1;
	for(int i = 0 ;i < n ; i++)
	{
		ans *= 16;
	}
	return ans;
}

int xx(char xxx)
{
	if(xxx >= 'A'&&xxx <= 'Z')
	return xxx - 'A'+10;
	return xxx - '0';
	
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long fans = 0;
		scanf("%s",x);
		int ii = 0;
		for(int i = strlen(x) - 1;i >= 0 ;ii++,i--)
		{
			
			//printf("%d %d\n",xx(x[i]),ago(ii));
			fans += xx(x[i])*ago(ii);
		}
		printf("%lld\n",fans);
	}
}
