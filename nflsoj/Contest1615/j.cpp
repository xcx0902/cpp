#include <bits/stdc++.h>
using namespace std;

int n;
double ans;
vector<int> g[100005];

void dfs(int u, int fa, int dis) {
    ans += 1.0 / dis;
    for (int v: g[u])
        if (v != fa)
            dfs(v, u, dis + 1);
}

signed main() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 1);
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}