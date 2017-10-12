#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
#define PAU putchar(' ')
#define ENT putchar('\n')
using namespace std;
const int maxn=500+10;
struct node{
    int num,color;
}ball[maxn];char s[2000];
int f[maxn][maxn],a[maxn],m,n;

inline void write(int x){
    if(x==0){putchar('0');return;}if(x<0)putchar('-'),x=-x;
    int len=0,buf[15];while(x)buf[len++]=x%10,x/=10;
    for(int i=len-1;i>=0;i--)putchar(buf[i]+'0');return;
}
void init(){
    scanf("%s",s);
	
		n = strlen(s);
		
		for(int i =0 ; i < n;i++)
		{
			a[i] = (s[i]-'0');
		}memset(f,-1,sizeof(f));	
    int bal=a[1],num=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=bal){
            ball[++m].num=num;
            ball[m].color=bal;
            num=1;bal=a[i];
        }else num++;
        if(i==n){
            ball[++m].num=num;
            ball[m].color=bal;
        }
    }
    puts("sad");
    return;
}
void work(){
    for(int i=1;i<=m;i++)
        if(ball[i].num>1)f[i][i]=1;
        else f[i][i]=2;
    for(int p=2;p<=m;p++){
        for(int i=1;i+p-1<=m;i++){
            int j=i+p-1;
            if(ball[i].color==ball[j].color){
                if(ball[i].num+ball[j].num==2)f[i][j]=f[i+1][j-1]+1;
                else f[i][j]=f[i+1][j-1];
            }
            for(int k=i;k<j;k++)f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
        }
    }
    return;
}
void print(){
    write(f[1][m]);
    puts("");
    return;
}
int main(){
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		init();work();print();
	}
return 0;}
