#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int VM=520;
const int EM=2520;
const int INF=0x3f3f3f3f;

struct Edge{
    int u,v;
    int cap;
}edge[EM<<1];

int n,m,k;
int cnt,dis[VM];

void addedge(int cu,int cv,int cw){
    edge[cnt].u=cu;     edge[cnt].v=cv;     edge[cnt].cap=cw;
    
    printf("%d%d%d\n",edge[cnt].u,edge[cnt].v,edge[cnt].cap);
    
}

int Bellman_ford(){
    for(int i=1;i<=n;i++)
        dis[i]=INF;
    dis[1]=0;
    	for(int i=1;i<=n;i++)
		 printf("dis[%d]=%d",i,dis[i]);
    for(int i=1;i<n;i++)    //n-1���ɳ�
        for(int j=0;j<cnt;j++)  //ö��ÿ����
            if(dis[edge[j].v]>dis[edge[j].u]+edge[j].cap)
                {
                	printf("$$dis[%d]=%d dis[%d]=%d %d\n",edge[j].v,dis[edge[j].v],edge[j].u,dis[edge[j].u],edge[j].cap);
                	dis[edge[j].v]=dis[edge[j].u]+edge[j].cap;
                	printf("!!dis[%d]=%d dis[%d]=%d %d\n",edge[j].v,dis[edge[j].v],edge[j].u,dis[edge[j].u],edge[j].cap);
				}
    for(int j=0;j<cnt;j++)
        if(dis[edge[j].v]>dis[edge[j].u]+edge[j].cap)   //�ж��Ƿ���ڸ�Ȩ��
            return 0;
    return 1;
}

int main(){

    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        cnt=0;
        int u,v,w;
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        while(k--){
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,-w);
        }
        int ans=Bellman_ford();
        printf("%s\n",ans==0?"YES":"NO");
    }
    return 0;
}
