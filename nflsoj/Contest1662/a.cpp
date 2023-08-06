#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

const int N = 1000005, mod = 1e9 + 7;

int n, ans, sum[N], fac[N];
vector<int> g[N];

int dfs(int u) {
    int ret = 1;
    for (int v : g[u]) ret += dfs(v);
    sum[u] = ret;
    return ret;
}

int qpow(int a, int b, int p) {
    if (b == 0) return 1 % p;
    if (b == 1) return a % p;
    int tmp = qpow(a, b / 2, p) % p;
    if (b % 2)
        return tmp * tmp % p * a % p;
    else
        return tmp * tmp % p;
}

void init() {
    fac[1] = 1;
    for (int i = 2; i <= 1000000; i++) fac[i] = fac[i - 1] * i % mod;
}

signed main() {
    init();
    scanf("%lld", &n);
    for (int i = 1, u, v; i < n; i++) {
        u = read(), v = read();
        g[v].push_back(u);
    }
    dfs(1);
    ans = fac[n];
    for (int i = 1; i <= n; i++)
        ans = ans * qpow(sum[i], mod - 2, mod) % mod;
    printf("%lld\n", ans);
    return 0;
}