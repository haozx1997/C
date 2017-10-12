#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
#define clr(x,y) memset(x,y,sizeof x)
#define INF 0x3f3f3f3f
const int maxn = 5000 + 10;
int a[maxn][maxn];
char s[maxn];
void read(int &x)
{
    x = 0;char ch = getchar();
    while(ch < '0' || ch > '9')ch = getchar();
    while(ch >= '0' && ch <= '9')x = x * 10 + ch - '0',ch = getchar();
}
int len;
int calc(int k)
{
    int ret = INF;
    for(double i = k + 0.5;(int)i < len - k + 1; i += 0.5)
    {
       int temp = 0;
       for(int j = (int)i + 1; j <= i + k; j ++)
       {
           temp += a[int(2 * i - 1)][j];
           	printf(	"	%d %d %d\n",i,j,a[i][j]);
           cout <<i <<" " << int(2 * i - j) << " " <<  j<< "         " << a[int(2 * i - 1)][j] << endl;
        }
       ret = min(ret,temp);
       cout <<  k << " " <<  i << " " << (int)i + 1 <<" " << temp << endl;
       for(int j = i + 2; j + k - 1 <= len && int(2 * i) - j - k + 1 >= 1; j ++)
       {
           temp -= a[int(2 * i) - j + 1][j - 1];temp += a[int( 2.0 * i) - j + 1 - k][int(j + k - 1)];
//           cout<< k << "    " <<  i << "    "  << j  << "         " << temp << endl;
       }

       ret = min(ret,temp);
    }
    return ret;
}
int main()
{
    int n,m,k;int Tcase;read(Tcase);
    while(Tcase --)
    {
        read(m);
        scanf("%s",s + 1);
        len = strlen(s + 1);
        for(int i = 1; i <= len; i ++)
            for(int j = i + 1;j <= len; j ++)
        {
            a[i][j] = abs( int(s[i] - s[j]));
		//	cout << i << " " << j << " " << a[i][j] << endl;
			printf(	"	%d %d %d\n",i,j,a[i][j]);
			
        }

        int l = 1,r = len/2;
        int ans = 0;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(calc(mid) <= m)
            {
                ans = mid;l = mid + 1;
            }else r = mid - 1;
        }
        printf("%d\n",ans);
    }
    return 0;
}

