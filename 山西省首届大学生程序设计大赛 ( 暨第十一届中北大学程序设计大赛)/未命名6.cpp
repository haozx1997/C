#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

int fa[100010];
int zu[1000];
int find(int x)
{
	if(fa[x]!=x)
	fa[x]=find(fa[x]);
	return fa[x];
}
map<int,int>map;
int main()

{
	int n,m;
	int a,b;
	for(int i = 1;i<=n;i++)
	{
		fa[i] = i;
	}
	scanf("%d%d",&n,&m);
	for(int i = 0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		a = find(a);
		b = find(b);
		fa[a] = b;
	}
	memset(zu,0,sizeof(zu));

	for(int i = 1;i<=n;i++)
	{
		zu[find(i)]++;
		
	}
	sort(zu,)
	
}
