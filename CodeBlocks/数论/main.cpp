
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


const int INF = 0x7fffffff;
const ll m = (ll)2147493647;

struct Matrix {
    ll det[10][10];
};

Matrix yy,xx;


Matrix matrix;

Matrix Mul(Matrix x, Matrix y);
Matrix Pow(int n);

int main()
{
#ifdef Floyd
    freopen("in.txt", "r", stdin);
#endif // Floyd
	ll yyy[7][7] = { {1,2,1,0,0,0,0},
					  {1,0,0,0,0,0,0},
					  {0,0,1,4,6,4,1},
					  {0,0,0,1,3,3,1},
					  {0,0,0,0,1,2,1},
					  {0,0,0,0,0,1,1},
					  {0,0,0,0,0,0,1},
					  };
	for(int i = 0;i<7;i++)
	{
		for(int j = 0;j<7;j++)
		{
			matrix.det[i][j] = yyy[i][j];
		}
	}
//	for(int i = 0;i<7;i++)
//	{
//		for(int j = 0;j<8;j++)
//		{
//			printf("%d ",yy.det[i][j]);
//		}
//		puts("");
//	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		ll a,b;
		scanf("%d%I64d%I64d",&n,&a,&b);
		a %= m;
		b %= m;
		if(n == 1)
        {
            printf("%I64d\n",a);
            continue;
        }
        if(n == 2)
        {
            printf("%I64d\n",b);
            continue;
        }

		yy = Pow(n-2);
		xx.det[0][0] = b;
		xx.det[1][0] = a;
		xx.det[2][0] = 81;
		xx.det[3][0] = 27;
		xx.det[4][0] = 9;
		xx.det[5][0] = 3;
		xx.det[6][0] = 1;
        Matrix ans = Mul(yy,xx);
        ll ANS = ans.det[0][0]%m;
        printf("%I64d\n",ANS);
	}


    return 0;
}

Matrix Mul(Matrix x, Matrix y)      //????
{
    Matrix ret;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            ret.det[i][j] = 0;
            for (int k = 0; k < 10; ++k) {
                ret.det[i][j] += (x.det[i][k] %m)* (y.det[k][j]%m);
                ret.det[i][j] %= m;
            }

        }
    }
    return ret;
}

Matrix Pow(int n)       //???
{
    if (n == 1) {
        return matrix;
    }
    if (n & 1) {
        return Mul(matrix, Pow(n - 1));
    }
    Matrix t = Pow(n >> 1);
    return Mul(t, t);
}
