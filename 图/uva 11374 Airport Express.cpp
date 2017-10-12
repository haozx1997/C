#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
#include <iostream>
using namespace std;  
  
const int INF = 1000000000;  
const int maxn =  500 + 5;  
struct Edge{  
    int from,to,dist;  
};  
  
struct HeapNode{  
    int d,u;  
    bool operator < (const HeapNode& rhs) const{  
        return d > rhs.d;  
    }  
};  
  
struct Dijkstra{  
    int n,m;  
    vector<Edge> edges;  
    vector<int> G[maxn];  
    bool done[maxn];  
    int d[maxn];  
    int p[maxn];  
  
    void init(int n){  
        this -> n = n;  
        for(int i = 0;i < n;i++)    G[i].clear();  
        edges.clear();  
    }  
  
    void AddEdges(int from,int to,int dist){  
        edges.push_back((Edge){from,to,dist});  
        m = edges.size();  
        G[from].push_back((m-1));  
    }  
  
    void dijkstra(int s){  
        priority_queue<HeapNode> Q;  
        for(int i = 0;i < n;i++)    d[i] = INF;  
        d[s] = 0;  
        memset(done,0,sizeof(done));  
        Q.push((HeapNode){0,s});  
        while(!Q.empty()){  
            HeapNode x = Q.top();Q.pop();  
            int u = x.u;  
            if(done[u]) continue;  
            done[u] = true;  
            for(int i = 0;i < G[u].size();i++){  
                Edge& e = edges[G[u][i]];  
                if(d[e.to] > d[u] + e.dist){  
                    d[e.to] = d[u] + e.dist;  
                    p[e.to] = e.from;  
                    Q.push((HeapNode){d[e.to],e.to});  
                }  
            }  
        }  
    }  
  
    void getpath(int s,int e,vector<int>& path){  
        int pos = e;  
        while(1){  
            path.push_back(pos);  
            if(pos == s)  
                break;  
            pos = p[pos];  
        }  
    }  
}; 

int n,s,e;
Dijkstra sol[2];
vector<int> path;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int time,shouldin,shouldout;
	int cln;
	int myFirstTime = 0;
	while(scanf("%d%d%d",&n,&s,&e) != EOF)
	{
		if(myFirstTime)
		 printf("\n");
		myFirstTime = 1;
		sol[0].init(n);
		sol[1].init(n);
		path.clear();
		s--;e--;
		scanf("%d",&cln);
		for(int i = 0;i < cln;i++)
		{
			int ou_,in_,v_;
			scanf("%d%d%d",&ou_,&in_,&v_);
			ou_--;in_--;
			sol[0].AddEdges(ou_,in_,v_);
			sol[1].AddEdges(ou_,in_,v_);
			sol[0].AddEdges(in_,ou_,v_);
			sol[1].AddEdges(in_,ou_,v_);
		}
		sol[0].dijkstra(s);
		sol[1].dijkstra(e);
		shouldin = -1;
		time = sol[0].d[e];
		int eln;//expensive line num
		scanf("%d",&eln);
		while(eln--)
		{
			int ou_,in_,v_;
			scanf("%d%d%d",&in_,&ou_,&v_);
			ou_--;in_--;
			if(v_+sol[0].d[in_]+sol[1].d[ou_]<time)
			{
				time = v_+sol[0].d[in_]+sol[1].d[ou_];
				shouldin = in_;
				shouldout = ou_;
			}
			if(v_+sol[0].d[ou_]+sol[1].d[in_]<time)
			{
				time = v_+sol[0].d[ou_]+sol[1].d[in_];
				shouldin = ou_;
				shouldout = in_;
			}
		}
		if(shouldin == -1)
		{
			sol[0].getpath(s,e,path);
			reverse(path.begin(),path.end());
//			for(int i = 0; i < path.size();i++)
//			{
//				printf("%d%c",path[i]+1," \n"[i == path.size()-1]);
//			}
			for(int i = 0;i < path.size()-1;i++)  
                printf("%d ",path[i]+1);  
            printf("%d\n",e+1); 
			printf("Ticket Not Used\n");  
            printf("%d\n",time);
		}
		else
		{
			sol[0].getpath(s,shouldin,path);
			reverse(path.begin(),path.end());
			sol[1].getpath(e,shouldout,path);
//			for(int i = 0; i < path.size();i++)
//			{
//				printf("%d%c",path[i]+1," \n"[i == path.size()-1]);
//			}
			for(int i = 0;i < path.size()-1;i++)  
                printf("%d ",path[i]+1);  
            printf("%d\n",e+1); 
			printf("%d\n",shouldin+1);  
            printf("%d\n",time);			
		}
		
	}
	
 } 




 
