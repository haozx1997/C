#include<iostream>
#include<cstdio>
using namespace std;
int x,y,q;
void extend_Eulid(int a,int b){
    if(b==0){
    x=1;y=0;q=a;
    return;
    }
    extend_Eulid(b,a%b);
    int temp=x;
    x=y;
    y=temp-a/b*y;
    return ;
}
int main()
{
    int a,b;
    cin>>a>>b;
    extend_Eulid(a,b);
    printf("%d=(%d)*%d+(%d)*%d\n",q,x,a,y,b);
    return 0;
}
