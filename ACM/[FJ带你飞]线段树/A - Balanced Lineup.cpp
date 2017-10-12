#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

 
#define ls u << 1
#define rs u << 1 | 1
#define lson l, mid, u << 1
#define rson mid + 1, r, u << 1 | 1
#define INF 0x3f3f3f3f
 
using namespace std;
typedef long long ll;
const int M = 5e4 + 100;
int Max[M << 2],Min[M << 2];
 
void pushup(int u){
    Max[u] = max(Max[ls],Max[rs]);
    Min[u] = min(Min[ls],Min[rs]);
}
 
void build(int l,int r,int u){
    if(l == r){
        scanf("%d",&Max[u]);
        Min[u] = Max[u];
    }
    else {
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
        pushup(u);
    }
}
 
int query(int L,int R,int l,int r,int u,int flag){ //区间查找最大最小值
    int mid = (l + r) >> 1;
    if(L <= l && R >= r){
        return flag ? Max[u] : Min[u];
    }
    int res;
    if(flag){
        res = 0;
        if(L <= mid) res = max(query(L,R,lson,flag),res);
        if(R > mid) res = max(query(L,R,rson,flag),res);
    }
    else {
        res = INF;
        if(L <= mid) res = min(query(L,R,lson,flag),res);
        if(R > mid) res = min(query(L,R,rson,flag),res);
    }
    return res;
}
 
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,n,1);
    while(m--){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",query(x,y,1,n,1,1) - query(x,y,1,n,1,0));
    }
    return 0;
}
