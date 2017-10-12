#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
 
int frd[200];
int enm[200][200];
int n,m,k;
int find(int x)
{
		if(frd[x]!=x)
		{
			frd[x]=find(frd[x]);
		}
		
		return frd[x];
}
int main()
{
  memset(enm,0,sizeof(enm));
  scanf("%d%d%d",&n,&m,&k);
  int a,b,c;
  int i;
  for(i=1;i<=n;i++)
    frd[i]=i;
    for(int i=1;i<=m;i++)
    {
      scanf("%d%d%d",&a,&b,&c);
      if(c==1)
      {
	      	a=find(a);
	      b=find(b);
	      frd[a]=b;
		}
		else
		{
			enm[a][b]=-c;
			enm[b][a]=-c;
		}
    }
    for(int i=1;i<=k;i++)
    {
      scanf("%d%d",&a,&b);
      int aa = a;
      int bb = b;
      a=find(a);
      b=find(b);
      //printf("%d %d %d\n",a,b,enm[aa][bb]);
    if(a==b&&enm[aa][bb])
        printf("OK but...\n");
    else if(a==b&&!enm[aa][bb])
        printf("No problem\n");
    else if(a!=b&&enm[aa][bb])
    	printf("No way\n");
    else if(a!=b&&!enm[aa][bb])
    	printf("OK\n");
    }
  return 0;
}
