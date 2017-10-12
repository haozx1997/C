#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x)
#define FOR(x,start,y) for(ll x = start; x <= y; x ++)
#define SC(x) scanf("%d",&x)
const  ll Mod = 1e9 + 7;
const int maxn = 30000 + 2;
string st[maxn];
struct Node
{
	Node()
	{
		cnt = 0;
	}
	string ss[maxn];
	int cnt;
}a[maxn];
bool cmp(Node xs,Node ys)
{
	return xs.cnt > ys.cnt;
}
bool cmps(string xs,string ys)
{
	return xs < ys;
}
map<string,int>ms,pos,m;
int main()
{
	string s;
	int len = 0;
	while( cin >> s)
	{
		ms.clear();m.clear();pos.clear();
		string temp = s;
		sort(temp.begin(),temp.end());
		if(!ms[temp])
		{
			st[len ++] = temp,pos[temp] = len - 1;
			a[len - 1].ss[a[len - 1].cnt ++] = s;
			m[s] = 1;
		}
		if(!m[s])
		{
			int poss = pos[temp];
			a[poss].ss[a[poss].cnt ++] = s; 
		}
		ms[temp] ++;
	}
	sort(a,a+len,cmp);
	len = min(len,5);
	for(int i = 0; i < len; i ++)
	{
		sort(a[i].ss,a[i].ss + a[i].cnt,cmps);
		printf("Group of size %d: ",a[i].cnt);
		for(int j = 0; j < a[i].cnt; j ++)
		{
			cout << a[i].ss[j] << " ";
		}
		printf(".\n");
	}
	return 0;
}
