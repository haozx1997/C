#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n,row,line,goal,all;
bool islight[210][210];
bool iscan[210][210];
bool used[25];
int dx[4][2];
int dy[4][2];
void make()
{
	dx[0][0]=-1;dx[0][1]=0;dx[1][0]=0;dx[1][1]=1;
	dy[0][0]=0;dy[0][1]=1;dy[1][0]=1;dy[1][1]=0;
	dx[2][0]=1;dx[2][1]=0;dx[3][0]=0;dx[3][1]=-1;
	dy[2][0]=0;dy[2][1]=-1;dy[3][0]=-1;dy[3][1]=0;
}
struct node
{
	int x,y;
	node(){}
	node(int a,int b){x=a;y=b;}
}a[25];
bool dfs(int s,int cnt,int step)
{
	int i,t;
	bool flag,flag1,flag2,flag3;
	if(step==goal)
		return cnt==all;
	for(i=s;i<n;i++)
	{
		if(used[i])
			continue;
		t=cnt;
		flag1=flag2=flag3=0;
		if(a[i].x>0)
		{
			if(!iscan[a[i].x-1][a[i].y])
				continue;
			if(!islight[a[i].x-1][a[i].y])
			{
				t++;
				islight[a[i].x-1][a[i].y]=1;
				flag1=1;
			}
		}
		if(a[i].y<line-1)
		{
			if(!iscan[a[i].x][a[i].y+1])
				continue;
			if(!islight[a[i].x][a[i].y+1])
			{
				t++;
				islight[a[i].x][a[i].y+1]=1;
				flag2=1;
			}
		}
		if(!islight[a[i].x][a[i].y])
		{
			t++;
			islight[a[i].x][a[i].y]=1;
			flag3=1;
		}
		flag=dfs(i+1,t,step+1);
		if(flag1)
			islight[a[i].x-1][a[i].y]=0;
		if(flag2)
			islight[a[i].x][a[i].y+1]=0;
		if(flag3)
			islight[a[i].x][a[i].y]=0;
		if(flag)
			return 1;
	}
	return 0;
}
bool isbeyond(int x,int y)
{
	return x<0||y<0||x>=row||y>=line;
}
int main()
{
	string s;
	int i,j,k,cnt,ans;
	make();
	while(cin>>row>>line)
	{
		if(row==0&&line==0)
			break;
		n=all=0;
		memset(iscan,0,sizeof(iscan));
		for(i=0;i<row;i++)
		{
			cin>>s;
			for(j=0;j<line;j++)
			{
				if(s[j]=='.')
				{
					a[n++]=node(i,j);
					iscan[i][j]=1;
					all++;
				}
			}
		}
		ans=16;
		for(i=0;i<n;i++)
		{
			for(j=0;j<4;j++)
			{
				cnt=1;
				memset(islight,0,sizeof(islight));
				for(k=0;k<2;k++)
				{
					if(isbeyond(a[i].x+dx[j][k],a[i].y+dy[j][k]))
						continue;
					if(!iscan[a[i].x+dx[j][k]][a[i].y+dy[j][k]])
						break;
					islight[a[i].x+dx[j][k]][a[i].y+dy[j][k]]=1;
					cnt++;
				}
				if(k<2)
					continue;
				islight[a[i].x][a[i].y]=1;
				for(goal=1;goal<=n;goal++)
				{
					if(dfs(0,cnt,1))
					{
						ans=min(ans,goal);
						break;
					}
				}
			}
		}
		if(n==0)
			ans=0;
		else if(ans==16)
			ans=-1;
		cout<<ans<<endl;
	}
	return 0;
}
