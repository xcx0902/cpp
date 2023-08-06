#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, m, ans, vis[N];
vector<int> g[N];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1, ans++;
    for (int v: g[u])
        dfs(v);
}

int main() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        dfs(i);
    }
    cout << ans - n - m << endl;
    return 0;
}
