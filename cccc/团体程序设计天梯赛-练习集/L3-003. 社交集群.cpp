#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;
set<int> s;
int map[1000];

int intr[1010][1010];
int intrn[1010];
int pi[1010][1010];
int pin[1010];
int pre[1010];
int imax;

//ģ��ģ��
	
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
	s.clear();
	memset(intr,0,sizeof(intr));
	memset(intrn,0,sizeof(intrn));
	memset(map,0,sizeof(map));
	
	int imax = 0;
	int t;
	scanf("%d",&t);
	for(int i = 0;i < t;i++)
	{
		
		scanf("%d",&pin[i]);
		char USELESS[10];
		scanf("%s",USELESS);
		for(int j = 0;j < pin[i];j++)
		{
			
			int inters;
			scanf("%d",&inters);
			pi[i][j] = inters;
		}
		
	}
	//ģ��ģ��
		
		for(int i = 0;i < t;i++)
	{
		pre[i] = i;
	}
	
	for(int i = 0;i < t-1;i++)
	{
		for(int j = i+1 ;j < t;j++ )
		{
			for(int ii = 0;ii < pin[i];ii++)
			{
				for(int jj = 0;jj < pin[j];jj++)
				{
				//	printf(" %d %d %d %d %d\n",i,ii,j,jj,pi[i][ii] == pi[j][jj]);
					if(pi[i][ii] == pi[j][jj])
					{
						link(i,j);
						printf("   !%d %d\n",i,j);
						break;
					}
				}
			}
		}
	}
	
	
	
	//ģ��ģ��
	
	for(int i = 0;i < t;i++)
	{
		find(i);
	}

	
	


	for(int i = 0;i < t;i++)
	{
		printf("!!!%d %d\n",i,pre[i]);
	}
	for(int i = 0;i < t;i++)
	{
		map[pre[i]]++;
		s.insert(pre[i]);
	}
	
	//���ÿ���������� ��С 
	sort(map,map+t);
	printf("%d\n",s.size());
	for(int i = t-1;i > t-s.size();i--)
	{
		printf("%d ",map[i]);
	}
	printf("%d\n",map[t-s.size()]);
	
	
	
	
	
	
}
