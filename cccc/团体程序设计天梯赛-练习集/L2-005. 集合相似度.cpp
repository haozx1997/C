#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;


int n[70][10010];
int n_len[70];
int add_n[10010];

double same(int n1,int n2)
{
	memset(add_n,0,sizeof(add_n));
	n1--;n2--;
	int i;
	for(i = 0;i < n_len[n1];i++)
	{
		add_n[i] = n[n1][i];
	}
	for(i = n_len[n1];i < n_len[n1] + n_len[n2];i++)
	{
		add_n[i] = n[n2][i-(n_len[n1])];
	}
//	for(i = 0;i < (n_len[n1] + n_len[n2]);i++)
//	{
//		printf("%d ",add_n[i]);
//	}
//	printf("\n");
	set <int> s1;
	for(i = 0;i < n_len[n1];i++)
	{
		s1.insert(n[n1][i]);
	}
	set <int> s2;
	for(i = 0;i < n_len[n2];i++)
	{
		s2.insert(n[n2][i]);
	}
	set <int> s3;
	for(i = 0;i < (n_len[n1] + n_len[n2]) ;i++)
	{
		s3.insert(add_n[i]);
	}
	double kill = s1.size()+s2.size()-s3.size();
	kill /=(double)s3.size();
	
	
	
	
	return kill;
}


int main()
{
	int N;
	int qn;
	memset(n,0,sizeof(n));
	memset(n_len,0,sizeof(n_len));
	scanf("%d",&N);
	for(int i = 0;i < N; i++)
	{
		scanf("%d",&n_len[i]);
		for(int j = 0;j < n_len[i];j++)
		{
			scanf("%d",&n[i][j]);
		}
	}
	scanf("%d",&qn);
	while(qn--)
	{
		int q1,q2;
		scanf("%d%d",&q1,&q2);
		printf("%.2f",same(q1,q2)*100);
		printf("%c\n",'%');
	}
	
	
	
	
	
	
	
		
 } 
