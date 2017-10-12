
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
    int det[10][10];  
};  

Matrix yy;
  
  
Matrix matrix;  
  
Matrix Mul(Matrix x, Matrix y);  
Matrix Pow(int n);  
  
int main()  
{  
	int yyy[7][8] = { {1,2,1,0,0,0,0,0},
					  {1,0,0,0,0,0,0,0},
					  {0,0,0,1,4,6,4,1},
					  {0,0,0,0,1,3,3,1},
					  {0,0,0,0,0,1,2,1},
					  {0,0,0,0,0,0,1,1},
					  {0,0,0,0,0,0,0,1},
					  }; 
	for(int i = 0;i<7;i++)
	{
		for(int j = 0;j<8;j++)
		{
			yy.det[i][j] = yyy[i][j];
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
	ll mod = 2147493647; 
	scanf("%d",&T);
	while(T--)
	{
		int n;
		ll a,b;
		scanf("%d%I64d%I64d",&n,&a,&b);
		
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
                ret.det[i][j] += x.det[i][k] * y.det[k][j];  
            }  
            ret.det[i][j] %= m;  
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
