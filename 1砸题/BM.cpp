#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)x.size())

typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 1e4 + 10;
ll n; int _; vector<int> Md;
ll res[maxn], base[maxn], _c[maxn], _md[maxn];

ll my_pow(ll a, ll b) {
    ll ret = 1, t = a % mod;
    while (b) {
        if (b & 1) { ret *= t; ret %= mod; }
        b >>= 1; t *= t; t %= mod;
    }
    return ret;
}
void mul(ll *a, ll *b, int k) {
    for (int i = 0; i < k + k; ++i) { _c[i] = 0; }
    for (int i = 0; i < k; ++i) if (a[i]) {
        for (int j = 0; j < k; ++j) {
            _c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
        }
    }
    for (int i = k + k - 1; i >= k; --i) if (_c[i]) {
        for (int j = 0; j < SZ(Md); ++j) {
            _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % mod;
        }
    }
    for (int i = 0; i < k; ++i) { a[i] = _c[i]; }
}
int solve(ll n, vector<int> a, vector<int> b) {
    ll ret = 0, pnt = 0; int k = SZ(a); Md.clear();
    for (int i = 0; i < k; ++i) { _md[k - 1 - i] = -a[i]; _md[k] = 1; }
    for (int i = 0; i < k; ++i) {
        if (_md[i] != 0) { Md.push_back(i); }
    }
    for (int i = 0; i < k; ++i) { res[i] = base[i] = 0; }
    res[0] = 1; while ((1ll << pnt) <= n) { ++pnt; }
    for (int p = pnt; p >= 0; --p) {
        mul(res, res, k);
        if ((n >> p) & 1) {
            for (int i = k - 1; i >= 0; --i) { res[i + 1] = res[i]; }
            res[0] = 0;
            for (int j = 0; j < SZ(Md); ++j) {
                res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % mod;
            }
        }
    }
    for (int i = 0; i < k; ++i) { ret = (ret + res[i] * b[i]) % mod; }
    if (ret < 0) { ret += mod; } return ret;
}
vector<int> BM(vector<int> s) {
    vector<int> C(1, 1), B(1, 1);
    int L = 0, m = 1, b = 1; ll d, c;
    for (int n = 0; n < SZ(s); ++n) {
        d = 0;
        for (int i = 0; i < L + 1; ++i) {
            d = (d + 1ll * C[i] * s[n - i]) % mod;
        }
        if (d == 0) { ++m; continue; } vector<int> T = C;
        c = mod - d * my_pow(b, mod - 2) % mod;
        while (SZ(C) < SZ(B) + m) { C.push_back(0); }
        for (int i = 0; i < SZ(B); ++i) {
            C[i + m] = (C[i + m] + c * B[i]) % mod;
        }
        if (2 * L <= n) { L = n + 1 - L; B = T; b = d; m = 1; }
        else { ++m; }
    }
    return C;
}
int gao(vector<int> a, ll n) {
    vector<int> c = BM(a); c.erase(c.begin());
    for (int i = 0; i < SZ(c); ++i) { c[i] = (mod - c[i]) % mod; }
    return solve(n, c, vector<int>(a.begin(), a.begin() + SZ(c)));
}

int main() {
#ifdef __AiR_H
    freopen("1002.in", "r", stdin);
#endif // __AiR_H
    while (scanf("%lld", &n) != EOF) {
        printf("%lld\n", gao(vector<int>{1,5,11,36,95,281,781,2245,6336,18061,51205,145601,413351}, n - 1));
    }
    return 0;
}

