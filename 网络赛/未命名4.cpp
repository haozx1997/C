#include<functional>
#include <algorithm>
#include  <iostream>
#include   <ctype.h>
#include   <cstring>
#include   <fstream>
#include    <cstdio>
#include    <vector>
#include    <string>
#include     <cmath>
#include     <deque>
#include     <stack>
#include     <queue>
#include      <list>
#include       <set>
#include       <map>
#define INF 0X7FFFFFFF
#define PI acos(-1.0)
typedef long long ll;
using namespace std;
const int N = 1e6;
inline int getint()
{
	int w = 0, q = 0;
	char c = getchar();
	while ((c<'0' || c>'9') && c != '-') c = getchar();
	if (c == '-') q = 1, c = getchar();
	while (c >= '0'&&c <= '9') w = w * 10 + c - '0', c = getchar();
	return q ? -w : w;
}
ll n, m;
int main() {
	while (cin >> n >> m) {
		ll ans = 0, t = 0;
		int x = n, y = m;
		while (true) {
			if (n == m) {
				break;
			}
			if (n == m + 2) {
				break;
			}
			if (n < m) {
				n = n + x - 1;
				t++;
			}
			if (m < n) {
				m = m + y - 1;
				ans += t;
			}
		}
		printf("%lld\n", n - ans * 2);
	}
	return 0;
}

