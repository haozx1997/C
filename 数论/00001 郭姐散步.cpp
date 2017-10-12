
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int m = 1e9 + 7;
const int INF = 0x7fffffff;
const int N = 2;
int k;

struct Matrix {
    ll det[N][N];
};

Matrix yy,yyy;
ll one [2] [2] = {2,1,1,0};

Matrix matrix;



Matrix Mul(Matrix x, Matrix y)      //????
{
    Matrix ret;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ret.det[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                ret.det[i][j] += x.det[i][k] * y.det[k][j];
				ret.det[i][j] %= m;
            }

        }
    }
    return ret;
}

Matrix Pow(Matrix matrix,int n)       //???
{
    if (n == 1) {
        return matrix;
    }
    if (n & 1) {
        return Mul(matrix, Pow(matrix,n - 1));
    }
    Matrix t = Pow(matrix,n >> 1);
    return Mul(t, t);
}


int main()
{


	int T;
	scanf("%d",&T);
		for(int i = 0 ;i < 2;i++)
	{
		for(int j = 0 ;j < 2;j++)
		{
			yy.det[i][j] = one[i][j];		
		}	
	}
	yyy.det[0][0] = 7;
	yyy.det[1][0] = 3;
	while(T--)
	{
		ll n;
		scanf("%lld",&n);
		if(n <= 0)
		{
			printf("0\n");
			continue;
		}
		if(n == 1)
		{
			printf("3\n");
			continue;
		}
		if(n == 2)
		{
			printf("7\n");
			continue;
		}
		
		Matrix xx = Pow(yy,n-2);
		Matrix xxx = Mul(xx,yyy);
		long long a = xxx.det[0][0]% m;
//		long long b = xxx.det[1][0]% m;
//		ll ans = 2*a+3*b;
//		ans %= m;
		printf("%lld\n",a);
	}
    return 0;
}

