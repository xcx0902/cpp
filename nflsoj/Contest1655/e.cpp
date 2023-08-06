#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 20005, K = 25, T = 1200005;
typedef pair<int, int> pii;
int n, m, k, t, ans, dis[K][N], f[T][K], need[K];
vector<pii> g[N];

void dijkstra(int x) {
    memset(dis[x], 0x3f, sizeof(dis[x]));
    dis[x][x] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, x});
    while (!q.empty()) {
        int u = q.top().second, d = q.top().first; q.pop();
        if (d > dis[x][u]) continue;
        for (auto v: g[u]) {
            if (dis[x][v.first] > dis[x][u] + v.second) {
                dis[x][v.first] = dis[x][u] + v.second;
                q.push({dis[x][v.first], v.first});
            }
        }
    }
}

signed main() {
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    cin >> t;
    for (int i = 1, x, y; i <= t; i++) {
        cin >> x >> y;
        need[y - 1] |= 1 << (x - 2);
    }
    for (int i = 1; i <= k + 1; i++)
        dijkstra(i);
    if (k == 0) {
        cout << dis[1][n] << endl;
        return 0;
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= k; i++)
        if (!need[i])
            f[1 << (i - 1)][i] = dis[1][i + 1];
    for (int i = 1; i < (1 << k); i++)
        for (int j = 1; j <= k; j++)
            if ((i >> (j - 1)) & 1)
                for (int l = 1; l <= k; l++)
                    if ((i >> (l - 1)) & 1)
                        if ((i & need[j]) == need[j])
                            f[i][j] = min(f[i][j], f[i ^ (1 << (j - 1))][l] + dis[l + 1][j + 1]);
    ans = LONG_LONG_MAX;
    for (int i = 1; i <= k; i++)
        ans = min(ans, f[(1 << k) - 1][i] + dis[i + 1][n]);
    cout << ans << endl;
    return 0;
}