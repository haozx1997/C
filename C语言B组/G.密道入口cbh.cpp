#include<cstdio>
#include<cstring>
using namespace std;
int vis[20];
int a[20];
int sum = 0;
bool check()
{
	int q = a[0]*100+a[1]*10+a[2];
	int b = a[3]*100+a[4]*10+a[5];
	int c = a[6]*1000+a[7]*100+a[8]*10+a[9];
	if(q+b==c)
	return true;
	return false;
}
void dfs(int d,int x)
{
	a[d] = x;
	vis[x] = 1;
	if(d==9)
	{
		if(check())
		sum++;
		return ;
	}
	for(int i=0;i<=9;i++)
	{
		if(!vis[i])
		{
			vis[i]  =1;
			dfs(d+1,i);
			vis[i] = 0;
		}
	}
}
int main()
{
	int cases;
	scanf("%d",&cases);
	getchar();
	while(cases--)
	{
		sum  =0;
		char str[5];
		memset(vis,0,sizeof(vis));
		scanf("%s",str);
		for(int i=0;i<3;i++)
		{
			a[i] = str[i]-'0';
		}
		vis[a[0]] = 1;
		vis[a[1]] = 1;
		vis[a[2]] = 1;
		for(int i=0;i<=9;i++)
		{
			if(!vis[i])
			{
				vis[i] = 1;
				dfs(3,i);
				vis[i] = 0;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
 } 

