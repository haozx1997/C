#include<bits/stdc++.h>

using namespace std;


typedef long long LL;
const int INF=0x3f3f3f3f;
const int MAXN=210;
int N;
struct Node{
    LL x,y;
    /*Node(LL x=0,LL y=0):x(x),y(y){}*/
};
Node dt[MAXN];
/*LL cross(Node a,Node b){
    return a.x*b.y-a.y*b.x;
}
 
int cmp(Node a,Node b){
    if(cross(a,b)>=0)return 1;
    else return 0;
}*/
/*
Node operator - (Node a,Node b){
    return Node(a.x-b.x,a.y-b.y);
}*/
double getl(Node a,Node b){
    LL x=a.x-b.x,y=a.y-b.y;
    return sqrt(1.0*x*x+1.0*y*y);
}
bool judge(){
    //double temp=getl(dt[0],dt[N-1]);
    double ans;
    for(int i=0;i<N;i++)
	{
    //  if(temp!=getl(dt[i],dt[i-1]))return false;
	    double temp=INF;
	    int cnt=0;
	    for(int j=0;j<N;j++)
		{
            if(i==j)
				continue;
            if(getl(dt[i],dt[j])<temp)
				temp=getl(dt[i],dt[j]);
            if(i&&ans==temp)
				cnt++;
        }
        if(!i)
			ans=temp;
        //printf("%lf %d\n",ans,cnt);
        if(i)
			if(temp!=ans||cnt<2)
				return false;
    }
     
    /*double x=cross(dt[0]-dt[N-1],dt[0]-dt[1]);
    for(int i=1;i<N-1;i++){
        int y;
        if(x!=(y=cross(dt[i]-dt[i-1],dt[i]-dt[i+1]))){
            return false;
        }
    }
    if(x!=cross(dt[N-1]-dt[N-2],dt[N-1]-dt[0]))return false;*/
    return true;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++)
		{
			scanf("%lld",&dt[i].x);
			scanf("%lld",&dt[i].y);
			
		}
        //sort(dt,dt+N,cmp);
        //for(int i=1;i<N;i++)printf("%d\n",cross(dt[i],dt[i-1]));
        if(judge())puts("YES");
        else puts("NO");
    }
    return 0;
}


