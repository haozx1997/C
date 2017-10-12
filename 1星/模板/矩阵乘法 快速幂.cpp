
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

const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
int k, m;

struct Matrix {
    int det[20][20];
};

Matrix yy;


Matrix matrix;



Matrix Mul(Matrix x, Matrix y)      //????
{
    Matrix ret;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            ret.det[i][j] = 0;
            for (int k = 0; k < 10; ++k) {
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
	m = 9973;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,p;
		scanf("%d%d",&n,&p);
		for(int i = 0; i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				scanf("%d",&yy.det[i][j]);
			}
		}
		Matrix xx = Pow(yy,p);
		int ans = 0;
		for(int i = 0 ;i < n;i++)
		{
			ans += xx.det[i][i];
			ans %= m;
		}
		printf("%d\n",ans);
	}
    return 0;
}

