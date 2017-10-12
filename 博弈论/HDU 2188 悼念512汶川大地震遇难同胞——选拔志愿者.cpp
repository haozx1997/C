#include<stdio.h>
int main(){int T;scanf("%d",&T);while(T--){int n,m;scanf("%d%d",&n,&m);if(m>=n)printf("Grass\n");else if(n%(m+1))printf("Grass\n");else printf("Rabbit\n");}}
