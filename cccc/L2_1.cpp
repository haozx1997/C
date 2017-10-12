#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<set>
using namespace std;
int a[100][10010];
int all[100];

double same(int a1,int a2)
{
	int t;
	if(all[a1]>all[a2])
	{
		t = a1;
		a1 = a2;
		a2 = t;
	}
	int same_n = 0;
	for(int i = 0;i<all[a1];i++)
	{
		for(int j = 0;j<all[a2];j++)
		{
			if(a[a1][i]==a[a2][j])
			{
				
				same_n++;
				break;
			}
			if(a[a1][i]<a[a2][j])
			{
				
				break;
			}
			
		}
	}
	
	return (double)(same_n)/(all[a1]+all[a2]-same_n)*100;
}

int main()
{
	int N;
	scanf("%d",&N);
	int M;
	set<int> S;
	for(int J = 1;J<=N;J++)
	{
		
		scanf("%d",&all[J]);
		int set_a;
		for(int i= 0;i<all[J];i++)
		{
			scanf("%d",&set_a);
			S.insert(set_a);
		}
		all[J] = S.size();
		set<int>::iterator it;
		int i = 0;
		for(it=S.begin();it!=S.end();it++)
		{
			a[J][i++] = *it;
		}
		S.clear();
	}
	
	int K;
	scanf("%d",&K);
	while(K--)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		
		printf("%.2f%c\n",same(t1,t2),'%');
		
	}
}
