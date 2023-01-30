#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
    int dis, id;
    bool operator < (const node& a) const { return dis > a.dis; }
};

const int INF = 1e9;
int n, m, vis[5005], t[5005], h[5005], dis[5005];
vector<pair<int, int>> g[5005];

bool spfa(int s) {
    queue<int> q;
    memset(h, 63, sizeof h);
    h[s] = 0, vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (auto v: g[u])
            if (h[v.first] > h[u] + v.second) {
                h[v.first] = h[u] + v.second;
                if (!vis[v.first]) {
                    vis[v.first] = 1;
                    q.push(v.first);
                    t[v.first]++;
                    if (t[v.first] == n + 1)
                        return false;
                }
            }
    }
    return true;
}

void dijkstra(int s) {
    priority_queue<node> q;
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    memset(vis, 0, sizeof vis);
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int u = q.top().id; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto v: g[u])
            if (dis[v.first] > dis[u] + v.second) {
                dis[v.first] = dis[u] + v.second;
                if (!vis[v.first])
                    q.push({dis[v.first], v.first});
            }
    }
    return;
}

signed main() {
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++)
        g[0].push_back({i, 0});
    if (!spfa(0)) {
        cout << -1 << endl;
        return 0;
    }
    for (int u = 1; u <= n; u++)
        for (auto &v: g[u])
            v.second += h[u] - h[v.first];
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        int ans = 0;
        for (int j = 1; j <= n; j++)
            if (dis[j] == INF) ans += j * INF;
            else ans += j * (dis[j] + h[j] - h[i]);
        cout << ans << endl;
    }
    return 0;
}