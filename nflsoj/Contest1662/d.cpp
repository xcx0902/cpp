#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5, mod = 1e9 + 7;

int n, f[N], ans[N];
vector<int> pre[N], suf[N], g[N];

void dfs1(int u, int fa) {
    f[u] = 1;
    for (int v: g[u])
        if (v != fa) {
            dfs1(v, u);
            f[u] = f[u] * (f[v] + 1) % mod;
        }
}

void dfs2(int u, int fa) {
    // cerr << "dfs2 " << u << " " << fa << endl;
    ans[u] = f[u];
    for (int v: g[u]) {
        pre[u].push_back(f[v] + 1);
        suf[u].push_back(f[v] + 1);
    }
    // cerr << "inited pre & suf" << endl;
    // cerr << "pre.size() = " << pre[u].size() << endl;
    // cerr << "suf.size() = " << suf[u].size() << endl;
    for (int i = 1; i < pre[u].size(); i++)
        pre[u][i] = pre[u][i - 1] * pre[u][i] % mod;
    // cerr << "calced pre" << endl;
    // cerr << "pre.size() = " << pre[u].size() << endl;
    // cerr << "suf.size() = " << suf[u].size() << endl;
    for (int i = (int)suf[u].size() - 2; i >= 0; i--)
        suf[u][i] = suf[u][i + 1] * suf[u][i] % mod;
    // cerr << "calced suf" << endl;
    int p = 0;
    for (int v: g[u]) {
        if (v != fa) {
            f[u] = (p > 0? pre[u][p - 1] : 1) * (p < suf[u].size() - 1? suf[u][p + 1] : 1) % mod;
            f[v] = f[v] * (f[u] + 1) % mod;
            dfs2(v, u);
        }
        p++;
    }
} 

signed main() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        scanf("%lld%lld", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // cerr << "Before dfs1" << endl;
    dfs1(1, 0);
    // cerr << "Before dfs2" << endl;
    dfs2(1, 0);
    // cerr << "Before output" << endl;
    for (int i = 1; i <= n; i++)
        printf("%lld\n", ans[i]);
    cout << endl;
    return 0;
}
