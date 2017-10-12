
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
ll k, m;

struct Matrix {
    ll det[5][5];
};

Matrix yy;


Matrix matrix;



Matrix Mul(Matrix x, Matrix y)      //????
{
    Matrix ret;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ret.det[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
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

   // freopen("in.txt", "r", stdin);  

	m = 10007;
	ll n,x,y;

	while(~scanf("%lld%lld%lld",&n,&x,&y))
	{
		x %= m;
		y %= m;
		Matrix x0;
		x0.det [0][0] = 2;
		x0.det [0][1] = 1;
		x0.det [0][2] = 1;
		x0.det [0][3] = 1;
		int yyy[4][4] = 
		{
			1    ,   0  ,   0,   0,
			x*x  , x*x  ,  x ,   1,
			2*x*y, 2*x*y,  y ,   0,
			  y*y,  y*y ,  0 ,   0, 
		};
		for(int i = 0 ;i < 4;i++)
		{
			for(int j = 0 ;j < 4;j++)
			{
				yy.det[i][j] = yyy[i][j];
			}
		}
		Matrix ans  = Pow(yy,n-1);
		Matrix anss  = Mul(x0,ans);
		printf("%lld\n",anss.det[0][0]%m);
		
	}
    return 0;
}

