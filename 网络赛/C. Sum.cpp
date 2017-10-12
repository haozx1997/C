

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
////////////////////////��?�䨮����?a��?//////////////////////////////////////
typedef int cap_type;
#define MAX_V 200 + 30 + 16

// ��?����������?��?��??��11��?�ꡧ??��??�騨Y��??�顤��?����?��
struct edge
{
	int to, rev;
	cap_type cap;

	edge(int to, cap_type cap, int rev) : to(to), cap(cap), rev(rev)
	{}
};

vector <edge> G[MAX_V];   // ��?��?����?������������?
int level[MAX_V];      // ?����?��??���?��??����?����o?
int iter[MAX_V];       // �̡�?��??��??��????���?��?��??-??��D��?��?

// ?����??D?����?��?��?�䨮from��?to��?��Y��??acap��?��?
void add_edge(int from, int to, int cap)
{
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size() - 1));
}

// ����1yBFS????�䨮?���?3?�����??����?����o?
void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty())
	{
		int v = que.front();
		que.pop();
		for (int i = 0; i < G[v].size(); ++i)
		{
			edge &e = G[v][i];
			if (e.cap > 0 && level[e.to] < 0)
			{
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

// ����1yDFS?��?��??1??��
cap_type dfs(int v, int t, cap_type f)
{
	if (v == t)
	{
		return f;
	}
	for (int &i = iter[v]; i < G[v].size(); ++i)
	{
		edge &e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to])
		{
			cap_type d = dfs(e.to, t, min(f, e.cap));
			if (d > 0)
			{
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}

	return 0;
}

// ?��?a�䨮s��?t��?��?�䨮����
cap_type max_flow(int s, int t)
{
	cap_type flow = 0;
	for (;;)
	{
		bfs(s);
		if (level[t] < 0)
		{
			return flow;
		}
		memset(iter, 0, sizeof(iter));
		cap_type f;
		while ((f = dfs(s, t, 0x3f3f3f3f3f3f3f3f)) > 0)
		{
			flow += f;
		}
	}
}

///////////////////////////////��?�䨮����?����?/////////////////////////////////////
int main()
{
	freopen("1.out","w",stdout);
	int nn  = 300;
    for(int i=2;i<=nn;i++)
    {
        for(int j=0;j<nn;j++) G[j].clear();
        for(int j=0;j<i;j++)
            for(int k=j+1;k<i;k++)
            add_edge(j,k,k^j);
        printf("%d\n",max_flow(0,i-1));
    }
    return 0;
}

