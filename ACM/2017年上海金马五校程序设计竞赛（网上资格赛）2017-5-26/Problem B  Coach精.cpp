#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;


int num[5555];


//ģ��ģ��
int pre[5010];	
int find(int x)//���Ҹ��ڵ�
{ 
    int r=x;
    while ( pre[r ] != r )//���ظ��ڵ� r
          r=pre[r ];
 
    int i=x , j ;
    while( i != r )//·��ѹ��
    {
         j = pre[ i ]; // �ڸı��ϼ�֮ǰ����ʱ����  j ��¼������ֵ 
         pre[ i ]= r ; //���ϼ���Ϊ���ڵ�
         i=j;
    }
    return r ;
}
//ģ��ģ��
	
void link(int x,int y)//x y��ͨ��
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
