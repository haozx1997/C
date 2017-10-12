#include <bits/stdc++.h>
#define ll long long
/*#define INF 2147483647
#define mem_INF 2139062143
#define ll_INF 9223372036854775807
#define eps 1e-8
#define fuckrand() ( ( rand() << 15 ) ^ rand() )*/
using namespace std;
inline int read() {
	int x = 0,tmp = 1;char ch = getchar();
	while( ch < '0' || ch > '9' ) { if( ch == '-' ) tmp = -1; ch = getchar();}
	while( ch >= '0' && ch <= '9'){ x = x * 10 + ch - '0'; ch = getchar(); }
	return x * tmp;
}
inline ll readll() {
	ll x = 0,tmp = 1;char ch = getchar();
	while( ch < '0' || ch > '9' ) {if ( ch == '-' ) tmp = -1; ch = getchar();}
	while( ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar(); }
	return x * tmp;
}
struct LAOXU {
	ll a, b;
	LAOXU(): a(0), b(0) {}
	LAOXU( ll _a, ll _b ): a(_a), b(_b) {}
	bool operator < ( const LAOXU& x ) const {
		return a + b > x.a + x.b;
	}
};
LAOXU BANZHANG[3010];
ll f[3010][3010];
struct query {
	ll x;
	int num, ans;
	query(): x(0), num(0), ans(0) {}
} que[300010];
inline bool cmp( const query& a, const query& b ) {
	return a.x > b.x;
}
inline bool cmp_2( const query& a, const query& b ) {
	return a.num < b.num;
}
#define BZ BANZHANG
int main() {
	//freopen( "hunter.in", "r", stdin );
	//freopen( "hunter.out", "w", stdout );
	int N = read(), M = read(); ll D = readll();
	for( int i = 1 ; i <= N ; ++ i ) BZ[i].a = readll();
	for( int i = 1 ; i <= N ; ++ i ) BZ[i].b = readll();
	memset( f, 127, sizeof( f ) );
	for( int i = 0 ; i <= N ; ++ i ) f[i][0] = 0;
	sort( BZ + 1, BZ + 1 + N );
	for( int i = 1 ; i <= N ; ++ i ) {
		for( int j = 0 ; j < i ; ++ j )
			f[i][j + 1] = min( f[i - 1][j + 1], f[i - 1][j] + ( BZ[i].a + D * j ) * ( BZ[i].b + D * j ) );
	}
	for( int i = 1 ; i <= M ; ++ i ) {
		que[i].x = readll();
		que[i].num = i;
	}
	sort( que + 1, que + 1 + M, cmp );
	int j = N;
	for( int i = 1 ; i <= M ; ++ i ) {
		while( que[i].x <= f[N][j] && j >= 0 ) j --;
		que[i].ans = j;
	}
	sort( que + 1, que + 1 + M, cmp_2 );
	for( int i = 1 ; i <= M ; ++ i ) printf( "%d ", que[i].ans ); 

	return 0;
}
