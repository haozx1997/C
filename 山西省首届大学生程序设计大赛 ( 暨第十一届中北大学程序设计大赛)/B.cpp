

/*
15
10
1 4
1 5
1 6
6 3
6 2
7 8
7 9
7 10
14 15
14 13

*/

#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

int fa[100010];
int zu[100100];
int find(int x)
{
	if(fa[x]!=x)
	fa[x]=find(fa[x]);
	return fa[x];
}
int main()

{
	
	int n,m;
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++)
	{
		fa[i] = i;
	}
	
	for(int i = 0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		a = find(a);
		b = find(b);
		fa[a] = b;
	}
	
	
	for(int i = 1;i<=n;i++)
	{
	//	printf("%d  %d \n",i,find(i));
		zu[find(i)]++;
		
	}
	int max= 0;
	for(int i = 1;i<=n;i++)
	{
		max = zu[find(i)]>max?zu[find(i)]:max; 
		
	}
	int  one;
	for(int i = 1;i<=n;i++)
	{
		if(max == zu[i])
		{
			one = i;
			break;
		 } 
		
	}
	int j= 0;
	int ans[101100];
	for(int i = 1;i<=n;i++)
	{
		if(find(i)==one)
		{
			ans[j++] = i;
		 } 
		
	}
	
	
	
	
	sort(ans,ans+(--j));
	printf("%d\n",max);
	for(int i = 0 ;i<j+1;i++)
	 {
	 	printf("%d ",ans[i]);
	 }
}
