#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;


int lowbit(int x)
{
	return x&(-x);
}

int cc[1010][1010];
int n;
void change(int a,int b,int c,int d)
{
	for(int i = c;i > 0;i -= lowbit(i))
	{
		for(int j = d;j > 0;j -= lowbit(j))
		{
			cc[i][j] += 1;
		}
	}
	for(int i = (a-1);i > 0;i -= lowbit(i))
	{
		for(int j = (b-1);j > 0;j -= lowbit(j))
		{
			cc[i][j] += 1;
		}
	}
	for(int i = (a-1);i > 0;i -= lowbit(i))
	{
		for(int j = d;j > 0;j -= lowbit(j))
		{
			cc[i][j] -= 1;
		}
	}
	for(int i = c;i > 0;i -= lowbit(i))
	{
		for(int j = (b-1);j > 0;j -= lowbit(j))
		{
			cc[i][j] -= 1;
		}
	}
	
	
}

int _01(int x,int y)
{
	int ans = 0;
	for(int i = x;i <= n;i += lowbit(i))
	{
		for(int j = y;j <= n;j += lowbit(j))
		{
			ans += cc[i][j];
		}
	}
	return (ans%2);
}


int main()
{
	int T;
	int F = 0;
	scanf("%d",&T);
	while(T--)
	{
		
		if(F) printf("\n");
		F++;
		int qn;
		scanf("%d%d",&n,&qn);
		memset(cc,0,sizeof(cc));
		while(qn--)
		{
			char ch[10];
			int a,b,c,d;
			scanf("%s",ch);
			if(ch[0] == 'Q')
			{
				scanf("%d%d",&a,&b);
				printf("%d\n",_01(a,b));
			}
			else
			{
				scanf("%d%d%d%d",&a,&b,&c,&d);
				change(a,b,c,d);
			}
		}
		
	}
}
