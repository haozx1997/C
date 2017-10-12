#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
int p[26];
int colors[26][100];
pair<int,int> block[200];
int dp[200][200];
pair<int,int> mid[100][2][20];
int mid_sz[100][2];
void inline Add_mid0(int idx,int cnt,int cost)
{
	for(int i=0;i<mid_sz[idx][0];i++)
	{
		if(mid[idx][0][i].first<=cnt)
		{
			if(cost-cnt>=mid[idx][0][i].second-mid[idx][0][i].first) return;
		}
		else if(cost-cnt<=mid[idx][0][i].second-mid[idx][0][i].first) {swap(mid[idx][0][i],mid[idx][0][--mid_sz[idx][0]]); i--;}
	}
	mid[idx][0][mid_sz[idx][0]++]=make_pair(cnt,cost);
}
void inline Add_mid1(int idx,int cnt,int cost)
{
	for(int i=0;i<mid_sz[idx][1];i++)
	{
		if(mid[idx][1][i].first<=cnt)
		{
			if(cost>=mid[idx][1][i].second) return;
		}
		else if(mid[idx][1][i].second>=cost) {swap(mid[idx][1][i],mid[idx][1][--mid_sz[idx][1]]); i--;}
	}
	mid[idx][1][mid_sz[idx][1]++]=make_pair(cnt,cost);
}
/*
01001101011001100
10101
101001001
1001001001
3
ABABA
3
ABABBABBA
3
ABBABBABBA

3
BABBAABABAABBAABBBABBAABABAABBAABBBABBAABABAABBAABBBABBAABABAABBAABBBABBAABABAABBAABBBABBAABABAABBAABBBABBAABABAABBAABBBABBAABABAABBAABBBABBAABABAABBAABBBABBAABABAABBAABB
10010101001010100101001010

*/

char ss[1000];

bool is01(char c)
{
	if(c == '0'||c=='1')
	{
		return true;
	}
	return false;
}


int main()
{
	int m,n;
	char c,pre;
	int T,TT = 1;
	scanf("%d",&T);
	while(T--)
	{
		m = 3;
		
		n=0;
		memset(p,0,26<<2);
		scanf("%s",ss);
		int len = strlen(ss);
		int I = 0;
		pre = ss[0];
		for(int i = 1; i< len;i++)
		{
			block[n]=make_pair(pre-'0',p[pre-'0']);
			dp[n][n]=1;
			char ccc = ss[i];
			
			while(ccc == pre)
			{
				dp[n][n]++;
				ccc == ss
			 } 
			if(dp[n][n]>=m) dp[n][n]=1;
			else dp[n][n]=m-dp[n][n];
			colors[pre-'0'][p[pre-'0']++]=n++;
			if(!is01(c)) break;
			pre=c;
		}
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++) dp[j][i]=dp[j][i-1]+dp[i][i];
			int ci=block[i].second;
			mid[ci][0][0]=make_pair(m-dp[i][i],0);
			mid_sz[ci][0]=1;
			mid_sz[ci][1]=0;
			for(int cj=ci-1,j;cj>=0;cj--)
			{
				j=colors[block[i].first][cj];
				mid_sz[cj][0]=mid_sz[cj][1]=0;
				for(int ck=ci,k;ck>cj;ck--)
				{
					k=colors[block[i].first][ck];
					for(int i_mid=0;i_mid<mid_sz[ck][0];i_mid++)
					{
						int cost=dp[j+1][k-1]+mid[ck][0][i_mid].second;
						if(cost>=dp[j][i]) continue;
						if(dp[j][j]>mid[ck][0][i_mid].first)
						{
							Add_mid0(cj,m-dp[j][j]+mid[ck][0][i_mid].first,cost);
							dp[j][i]=min(dp[j][i],cost+dp[j][j]-mid[ck][0][i_mid].first);
						}
						else
						{
							Add_mid1(cj,m-dp[j][j],cost);
							dp[j][i]=cost;
						}
					}
					for(int i_mid=0;i_mid<mid_sz[ck][1];i_mid++)
					{
						int cost=dp[j+1][k-1]+mid[ck][1][i_mid].second;
						if(cost>=dp[j][i]) continue;
						if(dp[j][j]>mid[ck][1][i_mid].first)
						{
							Add_mid1(cj,m-dp[j][j]+mid[ck][1][i_mid].first,cost);
							dp[j][i]=cost;
						}
					}
				}
				for(int k=j-1;k>=0;k--) dp[k][i]=min(dp[k][i],dp[k][j-1]+dp[j][i]);
			}
		}
		printf("Case #%d: ",TT++);
		printf("%d\n",dp[0][n-1]);
	}
}
