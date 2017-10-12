#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

int Lowbit(int x) //2^k
{
    return x & (-x);
}

struct fenwick
{
	int fa[1000100];
	int fn;//数组大小          //一定要赋值 
	void update(int t, int val)//位置，值 
	{
		for(int i = t;i <= fn ;i += Lowbit(i))
		{
			fa[i] += val;
		}
	}
	long long getsum(int x)
	{
		long long ans=0;
	    for(int i=x; i>0; i-=Lowbit(i))
	        ans += (long long)fa[i];
	    return ans;
	}
	 
}fen;



int r;
long long a[1000100];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(fen.fa,0,sizeof(fen.fa));
		
		scanf("%d",&r);
		fen.fn = r;
		int n;
		scanf("%d",&n);
		long long sum = 0;
		for(int i = 0;i < n;i++)
		{
			int t,l,w,h;
			scanf("%d%d%d%d",&t,&l,&w,&h);
			
			for(int j = 0; j < w;j++)
			{
				fen.update(t+j,h);
			}
			sum += (w*h);
		}
		long long half = ceil(sum/2);
		int halo = 0;
		for(int i = 1 ; i < r;i++)
		{
			a[i] = fen.getsum(i);
			if(a[i]>=half)
			{
				halo = i;
				break;
			}
		}
		
//		for(int i =  0;i < 10;i++)
//		{
//			printf("%d %d\n",i,fen.getsum(i));
//		}
		
			for(int i = halo;;i++)
			{
				if(fen.getsum(i)>a[halo])
				{
					printf("%d\n",i);
					break;
				}
			}
		
		
		
		
		
		
		
	}




 return 0;
}


