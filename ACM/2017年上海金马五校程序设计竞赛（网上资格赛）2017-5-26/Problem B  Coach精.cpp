#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;


int num[5555];


//模板模块
int pre[5010];	
int find(int x)//查找根节点
{ 
    int r=x;
    while ( pre[r ] != r )//返回根节点 r
          r=pre[r ];
 
    int i=x , j ;
    while( i != r )//路径压缩
    {
         j = pre[ i ]; // 在改变上级之前用临时变量  j 记录下他的值 
         pre[ i ]= r ; //把上级改为根节点
         i=j;
    }
    return r ;
}
//模板模块
	
void link(int x,int y)//x y连通，
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
        pre[fx ]=fy;
}

int main()
{
		int n,m;
	int a,b;
	while(~scanf("%d%d",&n,&m))
	{
		memset(num,0,sizeof(num));
		memset(pre,0,sizeof(pre));
		
		for(int i = 1;i <= n;i++)
		{
			pre[i] = i;
		}
		for(int i=1;i<=m;i++)
	    {
	    	scanf("%d%d",&a,&b);
		    link(a,b);  
	    }
		if(n%3)
		{
			printf("No\n");
			continue;
		}
		if((2*n/3)>m)
		{
			printf("No\n");
			continue;
		}
		for(int i = 1;i <= n;i++)
		{
			num[find(i)]++;
	//		printf("%d %d\n",i,find(i));
		}
		int F = 0;
		for(int i = 1;i <= n;i++)
		{
	//		printf("		%d %d\n",i,num[i]);
			if(num[i]%3)
			{
				F = 1;
				break;
			}
		}
		if(F)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
		
		
	}


	
	
	
	
	
}
