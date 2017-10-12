#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

const int mod = (int)1e9+7;
const int MAXN=50000+50;
const int INF=0x7fffffff;

int miu[MAXN] ;
int pre[MAXN] ;

#define FI(n) FastIO::read(n)
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], obuf[SIZE], str[60];
    int bi = SIZE, bn = SIZE, opt;
    int read(char *s) {
        while (bn) {
            for (; bi < bn && buf[bi] <= ' '; bi++);
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        int sn = 0;
        while (bn) {
            for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        s[sn] = 0;
        return sn;
    }
    bool read(int& x) {
        int n = read(str), bf;
         
        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
};

void get_miu(int maxn)
{
    int prime[MAXN],pnum=0;
    miu[1]= pre[1] = 1;
    for (int i=2;i<maxn;i++) miu[i]=-INF;
    for (int i=2;i<maxn;i++)
    {
        if (miu[i]==-INF)
        {
            miu[i]=-1;
            prime[++pnum]=i;
        }
        for (int j=1;j<=pnum;j++)
        {
            if (i*prime[j]>=maxn) break;
            if (i%prime[j]==0) miu[i*prime[j]]=0;
                else miu[i*prime[j]]=-miu[i];
        }
        pre[i] = pre[i-1]+miu[i];
    }
}

int solve(int a,int b,int c,int d,int k)//Ä¬ÈÏa==1 c==1 
{
	if(k == 0)
		{
			return 0;
		}
		b = b/k;
		d = d/k;
		if(b>d)
		{
			int t = b;
			b = d;
			d = t;
		}
		int ans = 0;
		for(int i = 1,pos;i <= b;i = pos+1)
		{
			 pos = min(b/(b/i),d/(d/i));
			ans =ans +((pre[pos]-pre[i-1])*(b/i)*(d/i));
		}
		return ans;
 } 

int main()
{
	memset(miu,0,sizeof(miu));
	get_miu(MAXN);
//	for(int i = 1; i <= 10;i++)
//	{
//		printf("%d %d\n",i,miu[i]);
//	}
	int T,Tc = 1; 
	FI(T);
	while(T--)
	{
		int a,b,c,d,k;
		FI(a);FI(b);FI(c);FI(d);FI(k);
		int ans = solve(1,b,1,d,k)+solve(1,a-1,1,c-1,k)-solve(1,b,1,c-1,k)-solve(1,a-1,1,d,k);
		printf("%d\n",ans);
	}
 return 0;
}


