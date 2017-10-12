#include<cstdio>
using namespace std;
const int N = 100005;
typedef long long ll;
ll h[N];
int n, left[N], right[N];
int main()
{
  while (scanf ("%d", &n), n)
  {
    for (int i = 1; i <= n; ++i)
      scanf ("%I64d", &h[i]), left[i] = right[i] = i;
    h[0] = h[n + 1] = -1;
    for (int i = 1; i <= n; ++i)
      while (h[left[i] - 1] >= h[i])
        left[i] = left[left[i] - 1];
    for (int i = n; i >= 1; --i)
      while (h[right[i] + 1] >= h[i])
        right[i] = right[right[i] + 1];
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
     {
     		printf("ll%d  rr%d\n",left[i],right[i]);
     	 if (h[i] * (right[i] - left[i] + 1) > ans) ans = h[i] * ll (right[i] - left[i] + 1);
    printf ("%I64d\n", ans);
	 }
  }
  return 0;
}
