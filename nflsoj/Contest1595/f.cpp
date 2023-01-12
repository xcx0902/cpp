#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005, mod = 1000000007;
int n, a[N], f[N][2];
vector<int> g[N];

void dfs(int u, int fa) {
    f[u][0] = a[u] ^ 1;
    f[u][1] = a[u];
    for (int v: g[u])
        if (v != fa) {
            dfs(v, u);
            f[u][1] = (f[u][1] * (f[v][0] + f[v][1]) % mod + f[u][0] * f[v][1] % mod) % mod;
            f[u][0] = f[u][0] * (f[v][0] + f[v][1]) % mod;
        }
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << f[1][1] << endl;
    return 0;
}