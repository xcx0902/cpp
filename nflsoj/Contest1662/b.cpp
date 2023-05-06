#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200005, mod = 1e9 + 7;
int n, ans = 1, sz[N], f[N];
vector<int> g[N];

int qpow(int a, int b, int p) {
    if (b == 0) return 1 % p;
    if (b == 1) return a % p;
    int tmp = qpow(a, b / 2, p) % p;
    if (b % 2) return tmp * tmp % p * a % p;
    else return tmp * tmp % p;
}

void dfs1(int u, int fa) {
    // cerr<< "dfs1 " << u << " " << fa << endl;
    sz[u] = 1;
    for (int v: g[u])
        if (v != fa) {
            dfs1(v, u);
            // cerr << "size " << u << " added " << v << " while fa = " << fa << " = " << sz[u] << endl;
            sz[u] += sz[v];
        }
    // cerr<< "size " << u << " = " << sz[u] << endl;
    f[1] = f[1] * sz[u] % mod;
}

void dfs2(int u, int fa) {
    for (int v: g[u]) 
        if (v != fa) {
            f[v] = f[u] * (n - sz[v]) % mod * qpow(sz[v], mod - 2, mod) % mod;
            dfs2(v, u);
        }
}

signed main() {
    cin >> n;
    f[1] = 1;
    for (int i = 1, u, v; i < n; i++) {
        scanf("%lld%lld", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    // for (int i = 1; i <= n; i++)
        // cerr<< sz[i] << endl;
    // cerr<< endl;
    // for (int i = 1; i <= n; i++)
        // cerr<< f[i] << endl;
    // cerr<< endl;
    dfs2(1, 0);
    // for (int i = 1; i <= n; i++)
        // cerr<< f[i] << endl;
    // cerr<< endl;
    for (int i = 1; i <= n; i++)
        ans = ans * i % mod;
    for (int i = 1; i <= n; i++)
        printf("%lld\n", ans * qpow(f[i], mod - 2, mod) % mod);
    return 0;
}
