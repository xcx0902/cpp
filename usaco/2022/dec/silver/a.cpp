#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, avg, a[200005], diff[200005];
vector<tuple<int, int, int>> ans;
vector<int> g[200005];

void dfs1(int u, int fa) {
    diff[u] = a[u] - avg;
    for (int v: g[u])
        if (v != fa) {
            dfs1(v, u);
            diff[u] += diff[v];
        }
}

void dfs2(int u, int fa) {
    for (int v: g[u])
        if (v != fa) {
            if (diff[v] >= 0) dfs2(v, u);
            if (diff[v] > 0) ans.emplace_back(v, u, diff[v]);
        }
    for (int v: g[u])
        if (v != fa && diff[v] < 0)
            ans.emplace_back(u, v, -diff[v]), dfs2(v, u);
}

signed main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], avg += a[i];
    avg /= n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    cout << ans.size() << endl;
    for (auto x: ans) {
        int u, v, w;
        tie(u, v, w) = x;
        cout << u << " " << v << " " << w << endl;
    }
    return 0;
}