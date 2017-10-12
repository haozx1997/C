#include<stdio.h>
#include<string.h>

const int _K=50268147,_B=6082187,_P=100000007;

int _X;
inline int get_rand(int _l,int _r){
	_X=((long long)_K*_X+_B)%_P;
	return _X%(_r-_l+1)+_l;
}
int n,m,k,seed;
int xx[1000006],yy[1000006];
int x[1000006],y[1000006];
void Init(){
	scanf("%d%d%d%d",&n,&m,&k,&seed);
	_X=seed;
	for (int i=1;i<=k;++i)
	{
		x[i]=get_rand(1,n);
		xx[x[i]] = 1;
		y[i]=get_rand(1,m);
		yy[y[i]] = 1;
	}
		
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(xx,0,sizeof(xx));
		memset(yy,0,sizeof(yy));
		
		Init();
		int ansx = 0,ansy = 0;
		for(int i = 1;i <= n;i++)
		{
			ansx+=xx[i];
		}
		for(int i = 1;i <= m;i++)
		{
			ansy+=yy[i];
		}
		printf("%d %d\n",n-ansx,m-ansy);
			
	}	
}
