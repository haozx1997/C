#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int inf=99999999;
int n,k,a[101],f[101][101][6];
int find(int l,int r,int kk){	
if(l>r) return 0;	
if(f[l][r][kk]!=-1) 
return f[l][r][kk];	
f[l][r][kk]=inf;	
if(kk<k-1) f[l][r][kk]=min(f[l][r][kk],find(l,r,kk+1)+1);	
else if(kk==k-1) f[l][r][kk]=min(f[l][r][kk],find(l+1,r,0));	
for(int i=l+1;i<=r;i++)	  
if(a[i]==a[l]) f[l][r][kk]=min(f[l][r][kk],find(l+1,i-1,0)+find(i,r,min(k-1,kk+1)));	
return f[l][r][kk];}
int main(){	
	int T,TT = 1;
	scanf("%d",&T);
	char s[2000];
	while(T--)
	{
		scanf("%s",s);
		k = 3;
		n = strlen(s);
		memset(f,-1,sizeof(f));	
		for(int i =0 ; i < n;i++)
		{
			a[i] = (s[i]-'0');
		}
		printf("Case #%d: %d\n",TT++,find(1,n,0));
	}
	
	return 0;
	}
